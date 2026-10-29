#!/bin/sh
# Cross-compiles R Departures on a workstation with Docker, into
# dist/<arch>/RDepartures, resources attached.
#
#   tools/cross-build.sh x86       the hybrid's x86 gcc, haiku/cross-compiler:x86_gcc2h-r1beta4
#   tools/cross-build.sh x86_64    haiku/cross-compiler:x86_64-r1beta4
#   tools/cross-build.sh arm64     container with a Haiku arm64 build tree
#   tools/cross-build.sh all
#
#   ARM64_CONTAINER   default haiku-builder
#   ARM64_GENERATED   default /root/renku-arm64-work/generated.arm64
#
# The x86 build uses the hybrid's secondary x86 compiler, not its primary gcc2,
# so on an x86_gcc2 system it runs on the x86 secondary architecture (the
# rdepartures_x86 package). rc and xres come from the arm64 tree's host tools,
# which handle any ELF.
set -e

HERE="$(cd "$(dirname "$0")/.." && pwd)"
SRCS="src/App.cpp src/Board.cpp src/Data.cpp src/Station.cpp"
FLAGS="-O2 -s -Wall -Wno-multichar -o RDepartures $SRCS"
LIBS="-lbe -ltranslation"
ARM64_CONTAINER="${ARM64_CONTAINER:-haiku-builder}"
ARM64_GENERATED="${ARM64_GENERATED:-/root/renku-arm64-work/generated.arm64}"

attach_resources()
{
	OUT="$1"
	( cd "$HERE" && tar cf - src/app.rdef -C "$OUT" RDepartures ) \
		| docker exec -i "$ARM64_CONTAINER" sh -c "
			set -e
			W=/tmp/rdep-res-\$\$; mkdir -p \$W && cd \$W && tar xf -
			T=$ARM64_GENERATED/objects/linux/arm64/release/tools
			RC=\$T/rc/rc; [ -x \$RC ] || RC=\$T/rc
			export LD_LIBRARY_PATH=$ARM64_GENERATED/objects/linux/lib
			\$RC -o app.rsrc src/app.rdef >&2
			\$T/xres -o RDepartures app.rsrc >&2
			tar cf - RDepartures; rm -rf \$W" \
		| tar xf - -C "$OUT"
}

build()
{
	ARCH="$1"
	OUT="$HERE/dist/$ARCH"
	mkdir -p "$OUT"
	case "$ARCH" in
	x86)
		( cd "$HERE" && tar cf - src ) \
			| docker run --rm -i --platform linux/amd64 haiku/cross-compiler:x86_gcc2h-r1beta4 sh -c "
				set -e
				mkdir -p /work && cd /work && tar xf -
				/tools/cross-tools-x86/bin/i586-pc-haiku-g++ $FLAGS $LIBS >&2
				tar cf - RDepartures" \
			| tar xf - -C "$OUT"
		;;
	x86_64)
		( cd "$HERE" && tar cf - src ) \
			| docker run --rm -i --platform linux/amd64 haiku/cross-compiler:x86_64-r1beta4 sh -c "
				set -e
				mkdir -p /work && cd /work && tar xf -
				x86_64-unknown-haiku-g++ $FLAGS $LIBS >&2
				tar cf - RDepartures" \
			| tar xf - -C "$OUT"
		;;
	arm64)
		GEN="$ARM64_GENERATED"
		P="$GEN/objects/haiku/arm64/packaging/packages_build/minimum"
		WORK="/tmp/rdep-cross-$$"
		( cd "$HERE" && tar cf - src ) \
			| docker exec -i "$ARM64_CONTAINER" sh -c "
				set -e
				mkdir -p $WORK/sysroot/boot/system $WORK/lib && cd $WORK && tar xf -
				ln -sfn $P/hpkg_-haiku_devel.hpkg/contents/develop $WORK/sysroot/boot/system/develop
				SYSLIBS=\$(ls -d $GEN/build_packages/gcc_syslibs-*-arm64/lib | head -1)
				ln -sfn \$SYSLIBS/libstdc++.so.6 $WORK/lib/libstdc++.so
				ln -sfn \$SYSLIBS/libgcc_s.so.1 $WORK/lib/libgcc_s.so
				$GEN/cross-tools-arm64/bin/aarch64-unknown-haiku-g++ --sysroot=$WORK/sysroot \
					-L$P/hpkg_-haiku.hpkg/contents/lib -L$WORK/lib $FLAGS $LIBS >&2
				tar cf - RDepartures
				rm -rf $WORK" \
			| tar xf - -C "$OUT"
		;;
	*)
		echo "usage: $0 x86|x86_64|arm64|all" >&2
		exit 1
		;;
	esac
	attach_resources "$OUT"
	file "$OUT/RDepartures"
}

if [ "$1" = all ]; then
	for a in x86 x86_64 arm64; do
		build $a
	done
else
	build "$1"
fi
