# R Departures

<img src="docs/icon.png" width="64" alt="">

[English](README.md) | [日本語](README.ja.md) | **한국어** | [Italiano](README.it.md)

RenkuOS (HaikuOS)용 공항 출발 안내판입니다. 창 테두리 없이 전체 화면으로 나옵니다.
도쿄역, 서울역, 런던 빅토리아역, 시드니 센트럴역의 열차 안내판도 있습니다.
글자 하나하나가 플립(split flap)이라, 내용이 바뀌면 다른 글자들을 거쳐 넘어가며 한
줄씩 차례로 바뀝니다. 항공사 칸은 항공사 색상으로 된 플랩 한 장입니다.

![인천, 한국어](docs/incheon.png)

## pkgman으로 설치

| Haiku | 저장소 추가 |
| --- | --- |
| 32비트 x86 (x86_gcc2) | `pkgman add-repo https://pkgman.rainygirl.com/x86_gcc2` |
| x86_64 | `pkgman add-repo https://pkgman.rainygirl.com/x86_64` |
| arm64 | `pkgman add-repo http://pkgman.rainygirl.com/arm64` |

```sh
pkgman install rdepartures
```

**Deskbar -> Applications**에서 **R Departures**를 실행합니다. 플랩 폰트(TeX Gyre
Heros Condensed Bold)도 패키지가 함께 설치합니다.

같은 안내판을 스크린세이버로도 쓸 수 있습니다:
[R Departures 스크린세이버](https://github.com/rainygirl/rdepartures-screensaver) (`pkgman install rdepartures_screensaver`).

`pkgman add-repo`가 `Operation not supported`로 실패하면 그 이미지의 네트워크
킷에 TLS가 없는 것입니다. `https://` 대신 `http://`를 사용하세요.

## 공항

인천(ICN), 나리타(NRT), 홍콩(HKG), 히드로(LHR), 샤를 드골(CDG), 밀라노 말펜사(MXP),
베네치아 마르코 폴로(VCE), 뉴욕 JFK(JFK), 샌프란시스코(SFO). 오른쪽 위 톱니바퀴를 눌러 고르면 다음 실행 때도
그 공항으로 시작합니다.

안내판은 그 공항의 현지 시각(서머타임 포함)으로 움직이고, 8초마다 언어가 바뀝니다.

1. 공항이 있는 나라의 언어
2. 영어(그 나라 언어가 영어가 아닐 때)
3. 목적지마다 그 나라의 언어 -- 서울은 서울, 타이베이는 臺北, 아테네는 ΑΘΗΝΑ.
   비고도 안내판에 그 말이 있으면 그 언어로 나옵니다.

![나리타, 목적지 언어](docs/narita-destinations.png)
![홍콩](docs/hongkong.png)
![파리](docs/paris.png)
![베네치아](docs/venice.png)

항공편은 실제 노선에 그럴듯한 편명, 탑승구, 시각을 붙인 것입니다. 시간표는 매일
같게 만들어지고, 지연과 결항 몇 편은 날짜에 따라 정해집니다. 실시간 데이터는
아닙니다. 비고는 시각에 따라 수속중, 탑승구 열림, 탑승중, 마감 임박, 탑승 마감,
출발로 바뀝니다.

![플랩이 바뀌는 중](docs/flipping.png)

## 기차역

톱니바퀴 메뉴의 마지막 네 항목은 기차역입니다. 플립이 아니라 각 역의 실제 안내 화면처럼
나옵니다.

### 도쿄역

JR 역 안내판입니다. 승강장 위의
LED/LCD 안내판처럼 발차 시각, 행선지, 노선 색상의 승강장 번호와 열차명, 그리고 주요
정차역마다 정차(○)와 통과(─)를 보여 줍니다. 안내판 4개가 12초마다 바뀌고, 각각
일본어 다음 영어로 나옵니다.

- 도카이도 신칸센: 노조미, 히카리, 고다마, 자유석 호차
- 도호쿠·야마가타·아키타·조에쓰·호쿠리쿠 신칸센: 하야부사, 고마치, 야마비코, 나스노,
  쓰바사, 도키, 다니가와, 가가야키, 하쿠타카, 아사마
- 도카이도선, 우에노도쿄라인, 요코스카선(지하 승강장), 특급 오도리코
- 주오선: 쾌속, 주오특쾌, 오메특쾌, 특급 아즈사·가이지

모든 역의 열차도 항공편과 마찬가지로 실제 운행 계통을 바탕으로 만든 시간표이며
실시간 데이터가 아닙니다.

![도카이도 신칸센](docs/tokyo-shinkansen.png)
![북쪽 방면 신칸센](docs/tokyo-north.png)
![도카이도선·우에노도쿄라인·요코스카선, 영어](docs/tokyo-tokaido-line.png)

### 서울역

코레일 출발 안내 화면입니다. 열차 종류(KTX, KTX-청룡, KTX-산천, ITX-새마을, 무궁화호)를
그 색상으로, 열차번호, 행선지, 출발시각, 타는곳, 비고(정상운행, 탑승중, 탑승마감, 지연)를
보여 주고, 한국어·영어·일본어·중국어로 번갈아 나옵니다. 행선지 뒤에는 그 열차의
정차역이 작은 글씨로 나오고, 칸보다 길면 끝까지 갔다가 되돌아옵니다.

![서울역](docs/seoul.png)
![서울역, 영어](docs/seoul-english.png)

### 런던 빅토리아역

빅토리아역 승강장 위 화면처럼 열차마다 세로 칸 하나입니다. 시각, 행선지와 경유지,
그리고 승강장이 안내되기 전에는 손바닥과 *Wait*, 안내되면 걷는 사람과 *Platform*,
취소되면 X와 *Cancelled*, 늦으면 예상 시각이 나옵니다. 그 아래로 정차역과 시각(넘치면
쪽을 나눠서), 맨 아래에 열차 길이가 나옵니다.

![런던 빅토리아역](docs/victoria.png)

### 시드니 센트럴역

콘코스의 세로형 화면 벽입니다. 주황 탭(Sydney services, Intercity & Events, Regional
services)과 청록 탭(Metro) 아래로, 노선·승강장마다 화면 하나에 노선 배지(T1, T2, T4, T8,
T9, M1), 행선지와 경유지, 정차역, 승강장, 객차 수와 정차 방식, 다음 열차까지 남은 분,
그리고 그 뒤 열차들(Following Services)을 보여 줍니다. City 순환선 화면은 열차 6편을,
시외·장거리 화면은 출발 시각을 먼저 보여 주고 지정석 전용 열차를 표시합니다. 화면 하나는
안내문입니다. 칸에 다 들어가지 않는 정차역은 마지막 역이 보일 때까지 위로 올라간 뒤 처음부터
다시 시작합니다. 16:9보다 가로로 긴 화면에서는 키가 큰 화면 한 줄로 나오고, Sydney
services는 4칸이 됩니다.

![시드니 센트럴역](docs/sydney-central-concourse.png)

역마다 그 도시의 현지 시각(서머타임 포함)으로 움직입니다.

## 키

| 키 | |
| --- | --- |
| Esc, Q | 종료 |
| 오른쪽 화살표, 스페이스 | 다음 공항(샌프란시스코 다음은 기차역들) |
| 왼쪽 화살표 | 이전 공항 |

마우스 포인터는 3초 동안 움직이지 않으면 숨겨집니다.

## 소스에서 빌드

Haiku에서:

```sh
make install
```

`RDepartures`를 빌드해 `~/config/non-packaged/apps/R Departures`에 복사하고,
안내판 폰트(TeX Gyre Heros Condensed Bold)를
`~/config/non-packaged/data/fonts/otfonts`에 넣습니다. 폰트는 다시 시작한 뒤부터
쓰입니다. 코드는 C++98이라 32비트 x86(gcc2) 하이브리드에서도 기본 `g++`로
빌드됩니다.

Docker가 있는 작업용 머신에서는 `tools/cross-build.sh all`로 `dist/x86/`(gcc2가 아닌
하이브리드의 보조 x86 컴파일러), `dist/x86_64/`, `dist/arm64/`를 크로스 빌드합니다.

`RDepartures --snapshot board.png --size 1600x768 --airport CDG`는 화면 없이
안내판을 그려 파일로 저장합니다. 안내판이 이미 떠 있으면 그쪽으로 넘어가므로 먼저
종료하세요.

## 관계 없음

항공사 이름과 색상은 안내판처럼 보이게 하려고 쓴 것입니다. 로고는 넣지 않았고,
어느 항공사나 공항, 철도 회사도 이 프로그램을 승인하지 않았습니다.

## AI 고지

R Departures는 AI 코딩 도구(Anthropic의 Claude)의 도움을 받아 개발되었습니다.

## 라이선스

코드는 MIT. `fonts/texgyreheroscn-bold.otf`(TeX Gyre Heros, B. Jackowski,
J. M. Nowacki)는 GUST Font License(`fonts/GUST-FONT-LICENSE.txt`)입니다.
