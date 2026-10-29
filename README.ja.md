# R Departures

<img src="docs/icon.png" width="64" alt="">

[English](README.md) | **日本語** | [한국어](README.ko.md) | [Italiano](README.it.md)

RenkuOS (HaikuOS) 用の空港出発案内板です。ウィンドウ枠なしの全画面で表示します。
東京駅、ソウル駅、ロンドン・ヴィクトリア駅、シドニー・セントラル駅の列車案内もあります。
文字の一つ一つがパタパタ (反転フラップ) で、内容が変わると別の文字を経てめくれ、
一行ずつ順に切り替わります。航空会社の欄は、その航空会社の色のフラップ一枚です。

![成田、日本語](docs/narita.png)

## pkgman でインストール

| Haiku | リポジトリの追加 |
| --- | --- |
| 32 ビット x86 (x86_gcc2) | `pkgman add-repo https://pkgman.rainygirl.com/x86_gcc2` |
| x86_64 | `pkgman add-repo https://pkgman.rainygirl.com/x86_64` |
| arm64 | `pkgman add-repo http://pkgman.rainygirl.com/arm64` |

```sh
pkgman install rdepartures
```

**Deskbar -> Applications** から **R Departures** を起動します。フラップの
フォント (TeX Gyre Heros Condensed Bold) もパッケージが一緒にインストールします。

同じ案内板はスクリーンセーバーとしても使えます:
[R Departures スクリーンセーバー](https://github.com/rainygirl/rdepartures-screensaver) (`pkgman install rdepartures_screensaver`)。

`pkgman add-repo` が `Operation not supported` で失敗する場合、そのイメージの
ネットワークキットには TLS がありません。`https://` の代わりに `http://` を
使ってください。

## 空港

仁川 (ICN)、成田 (NRT)、香港 (HKG)、ヒースロー (LHR)、シャルル・ド・ゴール (CDG)、
ミラノ・マルペンサ (MXP)、ヴェネツィア・マルコ・ポーロ (VCE)、ニューヨーク JFK (JFK)、
サンフランシスコ (SFO)。
右上の歯車から選ぶと、次に起動したときもその空港で始まります。

案内板はその空港の現地時刻 (夏時間を含む) で動き、8 秒ごとに言語が変わります。

1. 空港のある国の言語
2. 英語 (その国の言語が英語でない場合)
3. 行先ごとにその国の言語 -- ソウルは 서울、台北は 臺北、アテネは ΑΘΗΝΑ。
   備考も、案内板にその言葉があればその言語で表示します。

![成田、行先の言語](docs/narita-destinations.png)
![香港](docs/hongkong.png)
![パリ](docs/paris.png)
![ヴェネツィア](docs/venice.png)

便は実在の路線に、もっともらしい便名・ゲート・時刻を付けたものです。時刻表は毎日
同じように作られ、いくつかの遅延と欠航は日付で決まります。リアルタイムのデータでは
ありません。備考は時刻に応じて搭乗手続中、ゲートオープン、搭乗中、最終案内、
搭乗締切、出発済と変わります。

![フラップが切り替わるところ](docs/flipping.png)

## 鉄道駅

歯車メニューの最後の 4 項目は鉄道駅です。パタパタではなく、それぞれの駅の実際の案内
画面のように表示します。

### 東京駅

JR の駅の発車標です。ホーム上の
LED・液晶の案内板のように、発車時刻、行先、路線色ののりば番号と列車名、そして主な
停車駅ごとの停車 (○) と通過 (─) を表示します。4 つの案内板が 12 秒ごとに切り替わり、
それぞれ日本語のあと英語で表示されます。

- 東海道新幹線: のぞみ、ひかり、こだま、自由席の号車
- 東北・山形・秋田・上越・北陸新幹線: はやぶさ、こまち、やまびこ、なすの、つばさ、
  とき、たにがわ、かがやき、はくたか、あさま
- 東海道線、上野東京ライン、横須賀線 (地下ホーム)、特急踊り子
- 中央線: 快速、中央特快、青梅特快、特急あずさ・かいじ

どの駅の列車も便と同じく、実際の運行系統をもとに作った時刻表で、リアルタイムの
データではありません。

![東海道新幹線](docs/tokyo-shinkansen.png)
![北へ向かう新幹線](docs/tokyo-north.png)
![東海道線・上野東京ライン・横須賀線、英語](docs/tokyo-tokaido-line.png)

### ソウル駅

KORAIL の出発案内画面です。列車種別 (KTX、KTX青龍、KTX山川、ITXセマウル、ムグンファ号)
をその色で、列車番号、行先、発車時刻、のりば、備考 (定刻、乗車中、締切、遅れ) を表示し、
韓国語・英語・日本語・中国語で順に切り替わります。行先の後ろには、その列車の停車駅が
小さな文字で表示され、欄に収まらなければ端まで進んでから戻ります。

![ソウル駅](docs/seoul.png)
![ソウル駅、英語](docs/seoul-english.png)

### ロンドン・ヴィクトリア駅

ヴィクトリア駅のホーム上の画面のように、列車ごとに縦の欄が一つです。時刻、行先と経由地、
そしてのりばが案内されるまでは手のひらと *Wait*、案内されると歩く人と *Platform*、
運休なら × と *Cancelled*、遅れていれば見込み時刻を表示します。その下に停車駅と時刻
(入りきらなければページ送り)、一番下に列車の長さを表示します。

![ロンドン・ヴィクトリア駅](docs/victoria.png)

### シドニー・セントラル駅

コンコースに並ぶ縦長の画面の壁です。オレンジのタブ (Sydney services、Intercity &
Events、Regional services) と青緑のタブ (Metro) の下に、路線・のりばごとの画面があり、
路線記号 (T1、T2、T4、T8、T9、M1)、行先と経由地、停車駅、のりば、両数と停車パターン、
次の列車までの分数、続く列車 (Following Services) を表示します。City 循環線の画面は
6 本、都市間・地方列車の画面は発車時刻を先に出し、全席指定の列車を示します。1 枚は
お知らせの画面です。入りきらない停車駅は、最後の駅が見えるまで上へ流れ、また先頭から
始まります。16:9 より横長の画面では縦長の画面が 1 列に並び、Sydney services は 4 枚に
なります。

![シドニー・セントラル駅](docs/sydney-central-concourse.png)

どの駅もその都市の現地時刻 (夏時間を含む) で動きます。

## キー

| キー | |
| --- | --- |
| Esc、Q | 終了 |
| 右矢印、スペース | 次の空港 (サンフランシスコの次は鉄道駅) |
| 左矢印 | 前の空港 |

マウスポインターは 3 秒動かさないと隠れます。

## ソースからビルド

Haiku で:

```sh
make install
```

`RDepartures` をビルドして `~/config/non-packaged/apps/R Departures` にコピーし、
案内板のフォント (TeX Gyre Heros Condensed Bold) を
`~/config/non-packaged/data/fonts/otfonts` に入れます。フォントは再起動後に
使われます。コードは C++98 なので、32 ビット x86 (gcc2) ハイブリッドでも既定の
`g++` でビルドできます。

Docker のある作業用マシンでは `tools/cross-build.sh all` で `dist/x86/` (gcc2 ではなく
ハイブリッドの副 x86 コンパイラ)、`dist/x86_64/`、`dist/arm64/` をクロスビルドします。

`RDepartures --snapshot board.png --size 1600x768 --airport CDG` は画面なしで
案内板を描いてファイルに保存します。案内板が起動中だとそちらに渡されるので、
先に終了してください。

## 無関係であること

航空会社の名前と色は案内板らしく見せるために使っています。ロゴは含まれておらず、
どの航空会社・空港・鉄道会社もこのプログラムを承認していません。

## AI の利用について

R Departures は AI コーディングツール (Anthropic の Claude) の支援を受けて
開発しました。

## ライセンス

コードは MIT。`fonts/texgyreheroscn-bold.otf` (TeX Gyre Heros、B. Jackowski、
J. M. Nowacki) は GUST Font License (`fonts/GUST-FONT-LICENSE.txt`) です。
