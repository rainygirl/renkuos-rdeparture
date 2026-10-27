# R Departures

<img src="docs/icon.png" width="64" alt="">

**English** | [日本語](README.ja.md) | [한국어](README.ko.md) | [Italiano](README.it.md)

An airport departures board for RenkuOS (HaikuOS), full screen and without a
window border -- and the train boards of Tokyo, Seoul, London Victoria and
Sydney Central. Every character is a split flap: when something changes the
flaps rattle through other letters and settle, row after row, and the airline
column is one flap per airline in its colours.

![Narita, in Japanese](docs/narita.png)

## Install with pkgman

| Haiku | Add the repository |
| --- | --- |
| 32-bit x86 (x86_gcc2) | `pkgman add-repo https://pkgman.rainygirl.com/x86_gcc2` |
| x86_64 | `pkgman add-repo https://pkgman.rainygirl.com/x86_64` |
| arm64 | `pkgman add-repo http://pkgman.rainygirl.com/arm64` |

```sh
pkgman install rdepartures
```

Then start **R Departures** from **Deskbar -> Applications**. The package also
installs the flap font, TeX Gyre Heros Condensed Bold.

The same boards are also a screen saver:
[R Departures screen saver](https://github.com/rainygirl/rdepartures-screensaver) (`pkgman install rdepartures_screensaver`).

If `pkgman add-repo` fails with `Operation not supported`, the network kit of
that image has no TLS; use `http://` instead of `https://`.

## Airports

Seoul Incheon (ICN), Tokyo Narita (NRT), Hong Kong (HKG), London Heathrow
(LHR), Paris Charles de Gaulle (CDG), Milan Malpensa (MXP), Venice Marco Polo (VCE), New York JFK (JFK)
and San Francisco (SFO). Pick one with the gear in the top right corner; the board remembers it.

Each board shows its own local time, summer time included, and switches
language every eight seconds:

1. the language of the airport's country,
2. English, where that is not English already,
3. each destination in its own language -- Seoul as 서울, Taipei as 臺北,
   Athens as ΑΘΗΝΑ -- with its remarks in that language where the board has
   the words.

![Narita, each destination in its own language](docs/narita-destinations.png)
![Hong Kong](docs/hongkong.png)
![Paris](docs/paris.png)
![Venice](docs/venice.png)

The flights are real routes with plausible flight numbers, gates and times;
the timetable is generated, the same every day, with a few delays and
cancellations decided by the date. It is not live data. Remarks follow the
clock: check-in, gate open, boarding, final call, gate closed, departed.

![Flaps changing](docs/flipping.png)

## Railway stations

The last four entries in the gear menu are railway stations. They are not flap
boards: each looks like the departure screens of that station.

### Tokyo Station

A JR station board: the LED and LCD style above the platforms there, the
departure time, destination, track in the line's colour, the train on the
line's colour, and for each train which of the main stations it stops at (○)
or passes (─). Four boards take turns every twelve seconds, each in Japanese
and then English:

- Tokaido Shinkansen: Nozomi, Hikari, Kodama, with the unreserved cars
- Tohoku, Yamagata, Akita, Joetsu and Hokuriku Shinkansen: Hayabusa, Komachi,
  Yamabiko, Nasuno, Tsubasa, Toki, Tanigawa, Kagayaki, Hakutaka, Asama
- Tokaido Line, Ueno-Tokyo Line, Yokosuka Line (the platforms below ground)
  and the Odoriko limited express
- Chuo Line: Rapid, Chuo and Ome Special Rapid, Azusa and Kaiji

Like the flights, the trains everywhere are a generated timetable of the real
services, not live data.

![Tokaido Shinkansen](docs/tokyo-shinkansen.png)
![The Shinkansen to the north](docs/tokyo-north.png)
![Tokaido, Ueno-Tokyo and Yokosuka lines, in English](docs/tokyo-tokaido-line.png)

### Seoul Station

Korail's departure screen: the train type on its colour (KTX, KTX-Cheongryong,
KTX-Sancheon, ITX-Saemaeul, Mugunghwa), train number, destination, departure
time, platform and remarks (on time, boarding, closing, delayed), in Korean,
English, Japanese and Chinese in turn. After each destination, in small type, the
stations the train stops at; a list too long for its space slides to its end
and back.

![Seoul Station](docs/seoul.png)
![Seoul Station, in English](docs/seoul-english.png)

### London Victoria

A column per train, as on the screens above the platforms at Victoria: time,
destination and route, then *Wait* with a raised hand until the platform is
called, *Platform* with someone walking once it is, *Cancelled* with a cross,
or an expected time when late. Below it, the calling points with their times,
a page at a time when they do not fit, and the length of the train.

![London Victoria](docs/victoria.png)

### Sydney Central

The wall of portrait screens on the concourse, under orange tabs for Sydney
services, Intercity & Events and Regional services and a teal one for Metro:
a screen per line or platform with the line (T1, T2, T4, T8, T9, M1), the
destination and route, the stations, the platform, the cars and stopping
pattern and the minutes to the next train, then the following services. The
City Circle screens list six trains; intercity and regional ones lead with the
departure time and mark booked-seats-only trains; one screen is a notice.
Stations that do not fit move up, one way, until the last of them shows, and
start again from the top. On a screen wider than 16:9 the wall is one row of
taller screens, four of them for Sydney services.

![Sydney Central](docs/sydney-central-concourse.png)

Each station keeps its own local time, summer time included.

## Keys

| Key | |
| --- | --- |
| Esc, Q | quit |
| Right arrow, space | next airport (the stations after San Francisco) |
| Left arrow | previous airport |

The mouse pointer hides after three seconds.

## Build from source

On Haiku:

```sh
make install
```

builds `RDepartures` and copies it to `~/config/non-packaged/apps/R Departures`,
with the board font (TeX Gyre Heros Condensed Bold) in
`~/config/non-packaged/data/fonts/otfonts`; the font is picked up after the
next restart. The code is C++98, so the default `g++` builds it on a 32-bit
x86 (gcc2) hybrid as well.

On a workstation with Docker, `tools/cross-build.sh all` cross-builds
`dist/x86/` (gcc2), `dist/x86_64/` and `dist/arm64/`.

`RDepartures --snapshot board.png --size 1600x768 --airport CDG` renders the
board off-screen and saves it, for checking it without a screen. Quit a
running board first: a second launch is handed to it instead.

## Not affiliated

Airline names and colours are used to make the board look like one; no logos
are included, and nothing here is endorsed by any airline, airport or railway.

## AI disclosure

R Departures was developed with the assistance of AI coding tools (Anthropic's
Claude).

## License

MIT for the code. `fonts/texgyreheroscn-bold.otf` (TeX Gyre Heros, by
B. Jackowski and J. M. Nowacki) is under the GUST Font License
(`fonts/GUST-FONT-LICENSE.txt`).
