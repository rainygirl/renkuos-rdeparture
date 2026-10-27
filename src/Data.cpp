/*
 * The board's data. Names fit the destination field: 16 cells, where a
 * Hangul, kana or Han character takes two.
 */

#include "Data.h"

#include <stdio.h>
#include <string.h>




// #pragma mark - cities


static const City kCities[] = {
	// code, { English, Korean, Japanese, French, Italian, Traditional Chinese },
	// native, lang
	{ "TYO", { "TOKYO", "도쿄", "東京", "TOKYO", "TOKYO", "東京" }, "東京", LANG_JA },
	{ "OSA", { "OSAKA", "오사카", "大阪", "OSAKA", "OSAKA", "大阪" }, "大阪", LANG_JA },
	{ "FUK", { "FUKUOKA", "후쿠오카", "福岡", "FUKUOKA", "FUKUOKA", "福岡" }, "福岡", LANG_JA },
	{ "SPK", { "SAPPORO", "삿포로", "札幌", "SAPPORO", "SAPPORO", "札幌" }, "札幌", LANG_JA },
	{ "OKA", { "OKINAWA", "오키나와", "沖縄", "OKINAWA", "OKINAWA", "沖繩" }, "沖縄", LANG_JA },
	{ "SEL", { "SEOUL", "서울", "ソウル", "SÉOUL", "SEUL", "首爾" }, "서울", LANG_KO },
	{ "BJS", { "BEIJING", "베이징", "北京", "PÉKIN", "PECHINO", "北京" }, "北京", LANG_ZH },
	{ "SHA", { "SHANGHAI", "상하이", "上海", "SHANGHAI", "SHANGHAI", "上海" }, "上海", LANG_ZH },
	{ "HKG", { "HONG KONG", "홍콩", "香港", "HONG KONG", "HONG KONG", "香港" }, "香港", LANG_ZHT },
	{ "TPE", { "TAIPEI", "타이베이", "台北", "TAIPEI", "TAIPEI", "台北" }, "臺北", LANG_ZHT },
	{ "SIN", { "SINGAPORE", "싱가포르", "シンガポール", "SINGAPOUR", "SINGAPORE", "新加坡" }, "SINGAPURA", LANG_OTHER },
	{ "BKK", { "BANGKOK", "방콕", "バンコク", "BANGKOK", "BANGKOK", "曼谷" }, "BANGKOK", LANG_OTHER },
	{ "MNL", { "MANILA", "마닐라", "マニラ", "MANILLE", "MANILA", "馬尼拉" }, "MAYNILA", LANG_OTHER },
	{ "CEB", { "CEBU", "세부", "セブ", "CEBU", "CEBU", "宿霧" }, "SUGBO", LANG_OTHER },
	{ "SGN", { "HO CHI MINH CITY", "호찌민", "ホーチミン", "HÔ CHI MINH", "HO CHI MINH", "胡志明市" }, "TP. HỒ CHÍ MINH", LANG_OTHER },
	{ "HAN", { "HANOI", "하노이", "ハノイ", "HANOÏ", "HANOI", "河內" }, "HÀ NỘI", LANG_OTHER },
	{ "DPS", { "BALI", "발리", "バリ", "BALI", "BALI", "峇里" }, "DENPASAR", LANG_OTHER },
	{ "KUL", { "KUALA LUMPUR", "쿠알라룸푸르", "クアラルンプール", "KUALA LUMPUR", "KUALA LUMPUR", "吉隆坡" }, "KUALA LUMPUR", LANG_OTHER },
	{ "ULN", { "ULAANBAATAR", "울란바토르", "ウランバートル", "OULAN-BATOR", "ULAN BATOR", "烏蘭巴托" }, "УЛААНБААТАР", LANG_OTHER },
	{ "SYD", { "SYDNEY", "시드니", "シドニー", "SYDNEY", "SYDNEY", "悉尼" }, "SYDNEY", LANG_EN },
	{ "AKL", { "AUCKLAND", "오클랜드", "オークランド", "AUCKLAND", "AUCKLAND", "奧克蘭" }, "TĀMAKI MAKAURAU", LANG_OTHER },
	{ "LAX", { "LOS ANGELES", "로스앤젤레스", "ロサンゼルス", "LOS ANGELES", "LOS ANGELES", "洛杉磯" }, "LOS ANGELES", LANG_EN },
	{ "SFO", { "SAN FRANCISCO", "샌프란시스코", "サンフランシスコ", "SAN FRANCISCO", "SAN FRANCISCO", "三藩市" }, "SAN FRANCISCO", LANG_EN },
	{ "NYC", { "NEW YORK", "뉴욕", "ニューヨーク", "NEW YORK", "NEW YORK", "紐約" }, "NEW YORK", LANG_EN },
	{ "SEA", { "SEATTLE", "시애틀", "シアトル", "SEATTLE", "SEATTLE", "西雅圖" }, "SEATTLE", LANG_EN },
	{ "HNL", { "HONOLULU", "호놀룰루", "ホノルル", "HONOLULU", "HONOLULU", "檀香山" }, "HONOLULU", LANG_EN },
	{ "CHI", { "CHICAGO", "시카고", "シカゴ", "CHICAGO", "CHICAGO", "芝加哥" }, "CHICAGO", LANG_EN },
	{ "BOS", { "BOSTON", "보스턴", "ボストン", "BOSTON", "BOSTON", "波士頓" }, "BOSTON", LANG_EN },
	{ "MIA", { "MIAMI", "마이애미", "マイアミ", "MIAMI", "MIAMI", "邁阿密" }, "MIAMI", LANG_EN },
	{ "LAS", { "LAS VEGAS", "라스베이거스", "ラスベガス", "LAS VEGAS", "LAS VEGAS", "拉斯維加斯" }, "LAS VEGAS", LANG_EN },
	{ "DEN", { "DENVER", "덴버", "デンバー", "DENVER", "DENVER", "丹佛" }, "DENVER", LANG_EN },
	{ "YVR", { "VANCOUVER", "밴쿠버", "バンクーバー", "VANCOUVER", "VANCOUVER", "溫哥華" }, "VANCOUVER", LANG_EN },
	{ "YYZ", { "TORONTO", "토론토", "トロント", "TORONTO", "TORONTO", "多倫多" }, "TORONTO", LANG_EN },
	{ "YUL", { "MONTREAL", "몬트리올", "モントリオール", "MONTRÉAL", "MONTRÉAL", "滿地可" }, "MONTRÉAL", LANG_FR },
	{ "MEX", { "MEXICO CITY", "멕시코시티", "メキシコシティ", "MEXICO", "CITTÀ D. MESSICO", "墨西哥城" }, "CIUDAD DE MÉXICO", LANG_ES },
	{ "CUN", { "CANCUN", "칸쿤", "カンクン", "CANCÚN", "CANCÚN", "坎昆" }, "CANCÚN", LANG_ES },
	{ "GRU", { "SAO PAULO", "상파울루", "サンパウロ", "SÃO PAULO", "SAN PAOLO", "聖保羅" }, "SÃO PAULO", LANG_OTHER },
	{ "LON", { "LONDON", "런던", "ロンドン", "LONDRES", "LONDRA", "倫敦" }, "LONDON", LANG_EN },
	{ "EDI", { "EDINBURGH", "에든버러", "エディンバラ", "ÉDIMBOURG", "EDIMBURGO", "愛丁堡" }, "EDINBURGH", LANG_EN },
	{ "DUB", { "DUBLIN", "더블린", "ダブリン", "DUBLIN", "DUBLINO", "都柏林" }, "DUBLIN", LANG_EN },
	{ "PAR", { "PARIS", "파리", "パリ", "PARIS", "PARIGI", "巴黎" }, "PARIS", LANG_FR },
	{ "NCE", { "NICE", "니스", "ニース", "NICE", "NIZZA", "尼斯" }, "NICE", LANG_FR },
	{ "MRS", { "MARSEILLE", "마르세유", "マルセイユ", "MARSEILLE", "MARSIGLIA", "馬賽" }, "MARSEILLE", LANG_FR },
	{ "TLS", { "TOULOUSE", "툴루즈", "トゥールーズ", "TOULOUSE", "TOLOSA", "圖盧茲" }, "TOULOUSE", LANG_FR },
	{ "MIL", { "MILAN", "밀라노", "ミラノ", "MILAN", "MILANO", "米蘭" }, "MILANO", LANG_IT },
	{ "ROM", { "ROME", "로마", "ローマ", "ROME", "ROMA", "羅馬" }, "ROMA", LANG_IT },
	{ "NAP", { "NAPLES", "나폴리", "ナポリ", "NAPLES", "NAPOLI", "拿坡里" }, "NAPOLI", LANG_IT },
	{ "PMO", { "PALERMO", "팔레르모", "パレルモ", "PALERME", "PALERMO", "巴勒莫" }, "PALERMO", LANG_IT },
	{ "VCE", { "VENICE", "베네치아", "ヴェネツィア", "VENISE", "VENEZIA", "威尼斯" }, "VENEZIA", LANG_IT },
	{ "CTA", { "CATANIA", "카타니아", "カターニア", "CATANE", "CATANIA", "卡塔尼亞" }, "CATANIA", LANG_IT },
	{ "FRA", { "FRANKFURT", "프랑크푸르트", "フランクフルト", "FRANCFORT", "FRANCOFORTE", "法蘭克福" }, "FRANKFURT", LANG_DE },
	{ "MUC", { "MUNICH", "뮌헨", "ミュンヘン", "MUNICH", "MONACO BAVIERA", "慕尼黑" }, "MÜNCHEN", LANG_DE },
	{ "BER", { "BERLIN", "베를린", "ベルリン", "BERLIN", "BERLINO", "柏林" }, "BERLIN", LANG_DE },
	{ "ZRH", { "ZURICH", "취리히", "チューリッヒ", "ZURICH", "ZURIGO", "蘇黎世" }, "ZÜRICH", LANG_DE },
	{ "VIE", { "VIENNA", "빈", "ウィーン", "VIENNE", "VIENNA", "維也納" }, "WIEN", LANG_DE },
	{ "AMS", { "AMSTERDAM", "암스테르담", "アムステルダム", "AMSTERDAM", "AMSTERDAM", "阿姆斯特丹" }, "AMSTERDAM", LANG_OTHER },
	{ "CPH", { "COPENHAGEN", "코펜하겐", "コペンハーゲン", "COPENHAGUE", "COPENAGHEN", "哥本哈根" }, "KØBENHAVN", LANG_OTHER },
	{ "MAD", { "MADRID", "마드리드", "マドリード", "MADRID", "MADRID", "馬德里" }, "MADRID", LANG_ES },
	{ "BCN", { "BARCELONA", "바르셀로나", "バルセロナ", "BARCELONE", "BARCELLONA", "巴塞隆拿" }, "BARCELONA", LANG_ES },
	{ "LIS", { "LISBON", "리스본", "リスボン", "LISBONNE", "LISBONA", "里斯本" }, "LISBOA", LANG_OTHER },
	{ "ATH", { "ATHENS", "아테네", "アテネ", "ATHÈNES", "ATENE", "雅典" }, "ΑΘΗΝΑ", LANG_OTHER },
	{ "IST", { "ISTANBUL", "이스탄불", "イスタンブール", "ISTANBUL", "ISTANBUL", "伊斯坦堡" }, "İSTANBUL", LANG_OTHER },
	{ "DXB", { "DUBAI", "두바이", "ドバイ", "DUBAÏ", "DUBAI", "杜拜" }, "DUBAI", LANG_OTHER },
	{ "DOH", { "DOHA", "도하", "ドーハ", "DOHA", "DOHA", "多哈" }, "DOHA", LANG_OTHER },
};
static const int kCityCount = sizeof(kCities) / sizeof(kCities[0]);


// #pragma mark - airlines


static const Airline kAirlines[] = {
	{ "KE", "KOREAN AIR", { 0, 158, 219 }, { 255, 255, 255 } },
	{ "OZ", "ASIANA", { 172, 26, 47 }, { 255, 255, 255 } },
	{ "7C", "JEJU AIR", { 255, 90, 0 }, { 255, 255, 255 } },
	{ "LJ", "JIN AIR", { 140, 190, 30 }, { 20, 40, 20 } },
	{ "JL", "JAL", { 204, 0, 0 }, { 255, 255, 255 } },
	{ "NH", "ANA", { 19, 68, 143 }, { 255, 255, 255 } },
	{ "GK", "JETSTAR", { 255, 120, 0 }, { 30, 30, 30 } },
	{ "MM", "PEACH", { 210, 50, 140 }, { 255, 255, 255 } },
	{ "CA", "AIR CHINA", { 200, 16, 46 }, { 255, 255, 255 } },
	{ "MU", "CHINA EASTERN", { 0, 62, 126 }, { 255, 255, 255 } },
	{ "CX", "CATHAY", { 0, 101, 100 }, { 255, 255, 255 } },
	{ "BR", "EVA AIR", { 0, 112, 60 }, { 255, 210, 80 } },
	{ "CI", "CHINA AIRLINES", { 215, 0, 108 }, { 255, 255, 255 } },
	{ "SQ", "SINGAPORE", { 249, 159, 28 }, { 0, 38, 100 } },
	{ "TG", "THAI", { 90, 30, 120 }, { 255, 200, 230 } },
	{ "PR", "PHILIPPINE", { 0, 59, 149 }, { 255, 255, 255 } },
	{ "VN", "VIETNAM AIR", { 0, 103, 127 }, { 255, 210, 120 } },
	{ "OM", "MIAT", { 0, 70, 140 }, { 255, 255, 255 } },
	{ "UA", "UNITED", { 0, 93, 170 }, { 255, 255, 255 } },
	{ "DL", "DELTA", { 0, 58, 112 }, { 255, 255, 255 } },
	{ "AA", "AMERICAN", { 150, 160, 170 }, { 10, 40, 90 } },
	{ "B6", "JETBLUE", { 0, 56, 118 }, { 255, 255, 255 } },
	{ "AS", "ALASKA", { 1, 66, 106 }, { 255, 255, 255 } },
	{ "WN", "SOUTHWEST", { 48, 76, 178 }, { 255, 191, 39 } },
	{ "AC", "AIR CANADA", { 240, 20, 40 }, { 255, 255, 255 } },
	{ "BA", "BRITISH AIRWAYS", { 7, 52, 110 }, { 255, 255, 255 } },
	{ "VS", "VIRGIN", { 225, 22, 60 }, { 255, 255, 255 } },
	{ "AF", "AIR FRANCE", { 0, 32, 91 }, { 255, 255, 255 } },
	{ "LH", "LUFTHANSA", { 249, 186, 0 }, { 5, 22, 77 } },
	{ "KL", "KLM", { 0, 161, 222 }, { 255, 255, 255 } },
	{ "IB", "IBERIA", { 215, 25, 45 }, { 255, 205, 0 } },
	{ "TP", "TAP", { 0, 150, 60 }, { 255, 255, 255 } },
	{ "EI", "AER LINGUS", { 0, 98, 114 }, { 255, 255, 255 } },
	{ "TK", "TURKISH", { 199, 10, 12 }, { 255, 255, 255 } },
	{ "LX", "SWISS", { 225, 0, 15 }, { 255, 255, 255 } },
	{ "OS", "AUSTRIAN", { 210, 0, 30 }, { 255, 255, 255 } },
	{ "SK", "SAS", { 0, 40, 100 }, { 255, 255, 255 } },
	{ "A3", "AEGEAN", { 0, 50, 120 }, { 140, 200, 255 } },
	{ "AZ", "ITA AIRWAYS", { 0, 71, 187 }, { 255, 255, 255 } },
	{ "U2", "EASYJET", { 255, 102, 0 }, { 255, 255, 255 } },
	{ "VY", "VUELING", { 255, 200, 0 }, { 60, 60, 60 } },
	{ "EK", "EMIRATES", { 215, 25, 33 }, { 255, 255, 255 } },
	{ "QR", "QATAR", { 92, 6, 50 }, { 255, 255, 255 } },
	{ "QF", "QANTAS", { 228, 0, 0 }, { 255, 255, 255 } },
	{ "NZ", "AIR NZ", { 70, 70, 70 }, { 255, 255, 255 } },
	{ "AM", "AEROMEXICO", { 11, 35, 67 }, { 255, 255, 255 } },
	{ "UO", "HK EXPRESS", { 91, 44, 131 }, { 255, 255, 255 } },
};
static const int kAirlineCount = sizeof(kAirlines) / sizeof(kAirlines[0]);


// #pragma mark - routes


static const Route kIncheon[] = {
	{ "TYO", "KE", 703, 3 }, { "TYO", "OZ", 102, 2 }, { "TYO", "7C", 1102, 2 },
	{ "OSA", "KE", 721, 2 }, { "OSA", "LJ", 221, 2 }, { "FUK", "OZ", 132, 2 },
	{ "SPK", "KE", 765, 1 }, { "OKA", "LJ", 231, 1 }, { "BJS", "KE", 851, 2 },
	{ "BJS", "CA", 124, 1 }, { "SHA", "OZ", 361, 2 }, { "SHA", "MU", 5042, 2 },
	{ "HKG", "CX", 411, 2 }, { "HKG", "KE", 607, 1 }, { "TPE", "BR", 169, 1 },
	{ "TPE", "CI", 163, 1 }, { "SIN", "SQ", 607, 2 }, { "BKK", "TG", 659, 1 },
	{ "MNL", "PR", 467, 1 }, { "CEB", "7C", 2405, 1 }, { "SGN", "VN", 409, 2 },
	{ "HAN", "KE", 679, 1 }, { "DPS", "KE", 629, 1 }, { "ULN", "OM", 302, 1 },
	{ "LAX", "KE", 17, 1 }, { "SFO", "UA", 892, 1 }, { "NYC", "KE", 81, 1 },
	{ "SEA", "DL", 196, 1 }, { "HNL", "KE", 53, 1 }, { "YVR", "AC", 64, 1 },
	{ "LON", "BA", 18, 1 }, { "PAR", "AF", 267, 1 }, { "FRA", "LH", 713, 1 },
	{ "MIL", "KE", 927, 1 }, { "SYD", "QF", 88, 1 }, { "DXB", "EK", 323, 1 },
	{ "IST", "TK", 91, 1 }, { "AMS", "KL", 856, 1 },
};

static const Route kNarita[] = {
	{ "SEL", "KE", 702, 2 }, { "SEL", "JL", 951, 1 }, { "SEL", "7C", 1101, 2 },
	{ "BJS", "NH", 955, 1 }, { "SHA", "JL", 877, 2 }, { "HKG", "CX", 509, 2 },
	{ "TPE", "BR", 197, 2 }, { "TPE", "CI", 107, 1 }, { "SIN", "SQ", 637, 1 },
	{ "SIN", "JL", 711, 1 }, { "BKK", "NH", 805, 1 }, { "MNL", "PR", 431, 1 },
	{ "SGN", "VN", 301, 1 }, { "HAN", "JL", 751, 1 }, { "ULN", "OM", 502, 1 },
	{ "KUL", "JL", 723, 1 }, { "LAX", "JL", 62, 1 }, { "SFO", "UA", 838, 1 },
	{ "NYC", "JL", 4, 1 }, { "CHI", "NH", 12, 1 }, { "HNL", "NH", 182, 1 },
	{ "HNL", "JL", 784, 1 }, { "YVR", "AC", 4, 1 }, { "LON", "BA", 6, 1 },
	{ "PAR", "AF", 275, 1 }, { "FRA", "LH", 711, 1 }, { "AMS", "KL", 862, 1 },
	{ "DXB", "EK", 319, 1 }, { "IST", "TK", 53, 1 }, { "SPK", "GK", 101, 2 },
	{ "OSA", "GK", 201, 2 }, { "FUK", "GK", 501, 1 }, { "OKA", "MM", 507, 1 },
};

static const Route kHeathrow[] = {
	{ "PAR", "AF", 1381, 3 }, { "PAR", "BA", 304, 3 }, { "MIL", "BA", 576, 2 },
	{ "ROM", "BA", 548, 2 }, { "VCE", "BA", 2584, 1 }, { "FRA", "LH", 921, 3 },
	{ "MUC", "LH", 2481, 2 },
	{ "AMS", "KL", 1000, 3 }, { "MAD", "IB", 3171, 2 }, { "BCN", "BA", 474, 2 },
	{ "LIS", "TP", 1351, 2 }, { "DUB", "EI", 155, 3 }, { "ATH", "BA", 640, 1 },
	{ "IST", "TK", 1980, 2 }, { "ZRH", "LX", 317, 2 }, { "VIE", "OS", 452, 1 },
	{ "BER", "BA", 982, 2 }, { "EDI", "BA", 1434, 3 }, { "CPH", "SK", 504, 1 },
	{ "NYC", "BA", 117, 2 }, { "NYC", "VS", 3, 1 }, { "LAX", "BA", 283, 1 },
	{ "SFO", "UA", 901, 1 }, { "YYZ", "AC", 857, 1 }, { "DXB", "EK", 2, 2 },
	{ "DOH", "QR", 8, 2 }, { "SIN", "SQ", 317, 1 }, { "HKG", "CX", 254, 1 },
	{ "TYO", "JL", 44, 1 }, { "TYO", "NH", 212, 1 }, { "SEL", "KE", 908, 1 },
	{ "BJS", "CA", 938, 1 }, { "MIA", "BA", 209, 1 },
};

static const Route kCharlesDeGaulle[] = {
	{ "LON", "AF", 1680, 3 }, { "MIL", "AF", 1612, 2 }, { "ROM", "AF", 1104, 2 },
	{ "VCE", "AF", 1526, 2 },
	{ "FRA", "LH", 1029, 2 }, { "MUC", "LH", 2229, 1 }, { "AMS", "KL", 1224, 3 },
	{ "MAD", "AF", 1300, 2 }, { "BCN", "AF", 1148, 2 }, { "LIS", "TP", 433, 2 },
	{ "ATH", "AF", 1832, 1 }, { "IST", "TK", 1824, 2 }, { "NCE", "AF", 7700, 3 },
	{ "NCE", "U2", 4013, 1 }, { "MRS", "AF", 7660, 2 }, { "TLS", "AF", 6120, 2 },
	{ "ZRH", "LX", 633, 1 }, { "CPH", "AF", 1350, 1 }, { "YUL", "AF", 346, 1 },
	{ "NYC", "AF", 6, 2 }, { "NYC", "DL", 265, 1 }, { "LAX", "AF", 22, 1 },
	{ "SFO", "AF", 84, 1 }, { "MEX", "AF", 178, 1 }, { "GRU", "AF", 456, 1 },
	{ "DXB", "EK", 76, 1 }, { "DOH", "QR", 42, 1 }, { "SIN", "AF", 256, 1 },
	{ "HKG", "CX", 260, 1 }, { "TYO", "AF", 274, 1 }, { "TYO", "JL", 46, 1 },
	{ "SEL", "KE", 902, 1 }, { "BJS", "AF", 128, 1 }, { "SHA", "MU", 554, 1 },
};

static const Route kMalpensa[] = {
	{ "ROM", "AZ", 2071, 2 }, { "NAP", "U2", 2853, 2 }, { "PMO", "U2", 2903, 2 },
	{ "CTA", "U2", 2869, 2 }, { "PAR", "AF", 1531, 2 }, { "PAR", "U2", 3871, 1 },
	{ "LON", "BA", 571, 2 }, { "LON", "U2", 8022, 1 }, { "FRA", "LH", 251, 2 },
	{ "MUC", "LH", 1863, 1 }, { "AMS", "KL", 1622, 2 }, { "MAD", "IB", 3251, 1 },
	{ "BCN", "VY", 6313, 2 }, { "LIS", "TP", 827, 1 }, { "ATH", "A3", 665, 1 },
	{ "IST", "TK", 1874, 1 }, { "DXB", "EK", 206, 1 }, { "DOH", "QR", 128, 1 },
	{ "NYC", "DL", 185, 1 }, { "NYC", "AA", 199, 1 }, { "NYC", "EK", 205, 1 },
	{ "SEL", "KE", 928, 1 }, { "SIN", "SQ", 377, 1 }, { "SHA", "MU", 784, 1 },
	{ "BER", "U2", 4572, 1 }, { "CPH", "SK", 688, 1 },
};

static const Route kMarcoPolo[] = {
	{ "ROM", "AZ", 1462, 3 }, { "NAP", "U2", 2721, 2 }, { "PMO", "U2", 2769, 1 },
	{ "CTA", "U2", 2765, 1 }, { "PAR", "AF", 1427, 2 }, { "PAR", "U2", 4642, 1 },
	{ "LON", "BA", 2585, 2 }, { "LON", "U2", 8642, 1 }, { "FRA", "LH", 327, 2 },
	{ "MUC", "LH", 1975, 2 }, { "AMS", "KL", 1660, 2 }, { "MAD", "IB", 3237, 1 },
	{ "BCN", "VY", 6409, 1 }, { "LIS", "TP", 841, 1 }, { "ATH", "A3", 661, 1 },
	{ "IST", "TK", 1868, 1 }, { "ZRH", "LX", 1671, 1 }, { "VIE", "OS", 534, 1 },
	{ "CPH", "SK", 1690, 1 }, { "BER", "U2", 5016, 1 }, { "DXB", "EK", 136, 1 },
	{ "DOH", "QR", 132, 1 }, { "NYC", "DL", 205, 1 }, { "NYC", "UA", 169, 1 },
};

static const Route kKennedy[] = {
	{ "LON", "BA", 178, 3 }, { "LON", "VS", 4, 2 }, { "PAR", "AF", 7, 2 },
	{ "PAR", "DL", 264, 1 }, { "MIL", "AZ", 609, 1 }, { "ROM", "AZ", 611, 1 },
	{ "VCE", "DL", 221, 1 },
	{ "FRA", "LH", 401, 1 }, { "MUC", "LH", 411, 1 }, { "AMS", "KL", 642, 1 },
	{ "MAD", "IB", 6250, 1 }, { "BCN", "DL", 168, 1 }, { "LIS", "TP", 210, 1 },
	{ "DUB", "EI", 106, 1 }, { "ATH", "DL", 200, 1 }, { "IST", "TK", 2, 1 },
	{ "ZRH", "LX", 15, 1 }, { "TYO", "JL", 5, 1 }, { "TYO", "NH", 9, 1 },
	{ "SEL", "KE", 82, 1 }, { "HKG", "CX", 845, 1 }, { "TPE", "BR", 31, 1 },
	{ "DXB", "EK", 202, 1 }, { "DOH", "QR", 702, 1 }, { "LAX", "B6", 23, 3 },
	{ "LAX", "AA", 1, 2 }, { "SFO", "B6", 15, 2 }, { "SFO", "UA", 2215, 1 },
	{ "MIA", "AA", 1001, 2 }, { "BOS", "B6", 117, 2 }, { "LAS", "B6", 1311, 1 },
	{ "MEX", "AM", 409, 1 }, { "CUN", "B6", 1155, 1 }, { "SEA", "AS", 9, 1 },
	{ "YYZ", "AC", 711, 1 },
};

static const Route kSanFrancisco[] = {
	{ "NYC", "UA", 2286, 2 }, { "NYC", "B6", 916, 2 }, { "NYC", "AA", 178, 1 },
	{ "LAX", "UA", 1112, 3 }, { "LAX", "AS", 1946, 2 }, { "SEA", "AS", 1371, 2 },
	{ "LAS", "WN", 1500, 2 }, { "DEN", "UA", 401, 2 }, { "CHI", "UA", 2240, 2 },
	{ "BOS", "B6", 434, 1 }, { "HNL", "UA", 1158, 2 }, { "YVR", "AC", 548, 1 },
	{ "MEX", "AM", 669, 1 }, { "LON", "BA", 286, 1 }, { "LON", "UA", 900, 1 },
	{ "PAR", "AF", 83, 1 }, { "FRA", "LH", 455, 1 }, { "MUC", "LH", 459, 1 },
	{ "AMS", "KL", 606, 1 }, { "ZRH", "LX", 39, 1 }, { "DUB", "EI", 60, 1 },
	{ "TYO", "JL", 1, 1 }, { "TYO", "NH", 7, 1 }, { "TYO", "UA", 837, 1 },
	{ "SEL", "KE", 26, 1 }, { "SEL", "OZ", 211, 1 }, { "TPE", "BR", 27, 1 },
	{ "TPE", "CI", 3, 1 }, { "HKG", "CX", 873, 1 }, { "SIN", "SQ", 33, 1 },
	{ "MNL", "PR", 105, 1 }, { "SYD", "QF", 74, 1 }, { "AKL", "NZ", 7, 1 },
	{ "DXB", "EK", 226, 1 }, { "DOH", "QR", 738, 1 }, { "IST", "TK", 80, 1 },
};

static const Route kHongKong[] = {
	{ "TYO", "CX", 524, 2 }, { "TYO", "UO", 848, 1 }, { "OSA", "CX", 594, 1 },
	{ "OSA", "UO", 686, 1 }, { "FUK", "UO", 652, 1 }, { "SEL", "CX", 410, 2 },
	{ "SEL", "KE", 608, 1 }, { "TPE", "CX", 450, 3 }, { "TPE", "BR", 858, 1 },
	{ "BJS", "CA", 112, 2 }, { "SHA", "MU", 502, 2 }, { "SIN", "SQ", 893, 2 },
	{ "BKK", "TG", 601, 2 }, { "MNL", "PR", 307, 1 }, { "SGN", "VN", 595, 1 },
	{ "HAN", "CX", 743, 1 }, { "KUL", "CX", 721, 1 }, { "DPS", "CX", 785, 1 },
	{ "SYD", "CX", 101, 1 }, { "AKL", "NZ", 80, 1 }, { "LON", "CX", 251, 2 },
	{ "LON", "BA", 32, 1 }, { "PAR", "CX", 261, 1 }, { "FRA", "LH", 797, 1 },
	{ "MIL", "CX", 293, 1 }, { "ZRH", "LX", 139, 1 }, { "AMS", "KL", 888, 1 },
	{ "IST", "TK", 71, 1 }, { "DXB", "EK", 381, 1 }, { "DOH", "QR", 815, 1 },
	{ "LAX", "CX", 880, 1 }, { "SFO", "UA", 862, 1 }, { "NYC", "CX", 840, 1 },
	{ "YVR", "AC", 8, 1 },
};

#define ROUTES(r) r, (int)(sizeof(r) / sizeof(r[0]))

const Airport kAirports[] = {
	{ "ICN", LANG_KO, "인천국제공항", "INCHEON INTERNATIONAL AIRPORT",
		9 * 60, DST_NONE, "", 10, 132, true, ROUTES(kIncheon),
		{ LANG_KO, LANG_EN, LANG_DEST }, 3 },
	{ "NRT", LANG_JA, "成田国際空港", "NARITA INTERNATIONAL AIRPORT",
		9 * 60, DST_NONE, "", 11, 99, true, ROUTES(kNarita),
		{ LANG_JA, LANG_EN, LANG_DEST }, 3 },
	{ "HKG", LANG_ZHT, "香港國際機場", "HONG KONG INTERNATIONAL AIRPORT",
		8 * 60, DST_NONE, "", 1, 80, true, ROUTES(kHongKong),
		{ LANG_ZHT, LANG_EN, LANG_DEST }, 3 },
	{ "LHR", LANG_EN, "LONDON HEATHROW", "",
		0, DST_EU, "ABC", 1, 60, false, ROUTES(kHeathrow),
		{ LANG_EN, LANG_DEST, 0 }, 2 },
	{ "CDG", LANG_FR, "PARIS-CHARLES DE GAULLE", "PARIS CHARLES DE GAULLE AIRPORT",
		60, DST_EU, "KLMFE", 20, 50, false, ROUTES(kCharlesDeGaulle),
		{ LANG_FR, LANG_EN, LANG_DEST }, 3 },
	{ "MXP", LANG_IT, "MILANO MALPENSA", "MILAN MALPENSA AIRPORT",
		60, DST_EU, "AB", 1, 60, false, ROUTES(kMalpensa),
		{ LANG_IT, LANG_EN, LANG_DEST }, 3 },
	{ "VCE", LANG_IT, "VENEZIA MARCO POLO", "VENICE MARCO POLO AIRPORT",
		60, DST_EU, "ABC", 1, 40, false, ROUTES(kMarcoPolo),
		60, DST_EU, "", 1, 58, false, ROUTES(kVenezia),
		{ LANG_IT, LANG_EN, LANG_DEST }, 3 },
	{ "JFK", LANG_EN, "NEW YORK JFK", "",
		-5 * 60, DST_US, "B", 20, 55, false, ROUTES(kKennedy),
		{ LANG_EN, LANG_DEST, 0 }, 2 },
	{ "SFO", LANG_EN, "SAN FRANCISCO INTERNATIONAL", "",
		-8 * 60, DST_US, "GABF", 1, 99, false, ROUTES(kSanFrancisco),
		{ LANG_EN, LANG_DEST, 0 }, 2 },
};
const int kAirportCount = sizeof(kAirports) / sizeof(kAirports[0]);


// #pragma mark - lookups


const City*
find_city(const char* code)
{
	for (int i = 0; i < kCityCount; i++) {
		if (strcmp(kCities[i].code, code) == 0)
			return &kCities[i];
	}
	return &kCities[0];
}


const Airline*
find_airline(const char* code)
{
	for (int i = 0; i < kAirlineCount; i++) {
		if (strcmp(kAirlines[i].code, code) == 0)
			return &kAirlines[i];
	}
	return &kAirlines[0];
}


int
airline_count()
{
	return kAirlineCount;
}


const Airline*
airline_at(int index)
{
	return &kAirlines[index % kAirlineCount];
}


const char*
city_name(const City* city, int lang)
{
	switch (lang) {
		case LANG_KO: return city->name[1];
		case LANG_JA: return city->name[2];
		case LANG_FR: return city->name[3];
		case LANG_IT: return city->name[4];
		case LANG_ZHT: return city->name[5];
		case LANG_DEST: return city->native;
		default: return city->name[0];
	}
}


// #pragma mark - text


// The languages there are words for. A destination phase row in any other
// language gets English.
int
remarks_lang(int lang)
{
	return lang >= LANG_EN && lang < LANG_OTHER ? lang : LANG_EN;
}


static const char* kStatus[LANG_OTHER][STATUS_COUNT] = {
	{ "ON TIME", "CHECK-IN", "GATE OPEN", "BOARDING", "FINAL CALL",
		"GATE CLOSED", "DEPARTED", "DELAYED", "CANCELLED" },
	{ "정시", "수속중", "탑승구 열림", "탑승중", "마감 임박",
		"탑승 마감", "출발", "지연", "결항" },
	{ "定刻", "搭乗手続中", "ゲートオープン", "搭乗中", "最終案内",
		"搭乗締切", "出発済", "遅延", "欠航" },
	{ "À L'HEURE", "ENREGISTREMENT", "PORTE OUVERTE", "EMBARQUEMENT",
		"DERNIER APPEL", "PORTE FERMÉE", "PARTI", "RETARDÉ", "ANNULÉ" },
	{ "IN ORARIO", "CHECK-IN", "GATE APERTO", "IMBARCO", "ULTIMA CHIAMATA",
		"GATE CHIUSO", "PARTITO", "IN RITARDO", "CANCELLATO" },
	{ "正点", "值机", "登机口开放", "正在登机", "最后召集",
		"登机结束", "已起飞", "延误", "取消" },
	{ "PÜNKTLICH", "CHECK-IN", "GATE OFFEN", "BOARDING", "LETZTER AUFRUF",
		"GATE GESCHLOSSEN", "GESTARTET", "VERSPÄTET", "ANNULLIERT" },
	{ "EN HORA", "FACTURACIÓN", "PUERTA ABIERTA", "EMBARCANDO",
		"ÚLTIMA LLAMADA", "PUERTA CERRADA", "DESPEGADO", "RETRASADO",
		"CANCELADO" },
	{ "準時", "辦理登機", "閘口開放", "登機中", "最後召集",
		"閘口已關", "已起飛", "延遲", "取消" },
};


const char*
status_text(int status, int lang)
{
	return kStatus[remarks_lang(lang)][status];
}


// The languages the board itself speaks (labels, title, footer): one per
// airport.
static int
ui_index(int lang)
{
	switch (lang) {
		case LANG_KO: return 1;
		case LANG_JA: return 2;
		case LANG_FR: return 3;
		case LANG_IT: return 4;
		case LANG_ZHT: return 5;
		default: return 0;
	}
}


static const char* kLabels[6][LABEL_COUNT] = {
	{ "TIME", "EXPECTED", "DESTINATION", "AIRLINE", "FLIGHT", "GATE",
		"REMARKS" },
	{ "시각", "변경", "목적지", "항공사", "편명", "탑승구", "비고" },
	{ "定刻", "変更時刻", "行先", "航空会社", "便名", "ゲート", "備考" },
	{ "HEURE", "PRÉVU", "DESTINATION", "COMPAGNIE", "VOL", "PORTE",
		"REMARQUES" },
	{ "ORA", "PREVISTO", "DESTINAZIONE", "COMPAGNIA", "VOLO", "GATE",
		"NOTE" },
	{ "時間", "更改時間", "目的地", "航空公司", "航班", "閘口", "備註" },
};


const char*
label_text(int label, int lang)
{
	return kLabels[ui_index(lang)][label];
}


const char*
title_text(int lang)
{
	switch (lang) {
		case LANG_KO: return "출발";
		case LANG_JA: return "出発";
		case LANG_FR: return "DÉPARTS";
		case LANG_IT: return "PARTENZE";
		case LANG_ZHT: return "出發";
		default: return "DEPARTURES";
	}
}


static const char* kFooters[][6] = {
	{ "PLEASE HAVE YOUR BOARDING PASS AND PASSPORT READY",
		"탑승권과 여권을 미리 준비해 주십시오",
		"搭乗券とパスポートをご用意ください",
		"MERCI DE PRÉPARER CARTE D'EMBARQUEMENT ET PASSEPORT",
		"TENERE PRONTI CARTA D'IMBARCO E PASSAPORTO",
		"請準備好登機證及護照" },
	{ "PLEASE PROCEED TO YOUR GATE",
		"탑승구로 이동해 주십시오",
		"搭乗ゲートへお進みください",
		"VEUILLEZ VOUS RENDRE À VOTRE PORTE",
		"SI PREGA DI RECARSI AL GATE",
		"請前往登機閘口" },
	{ "DO NOT LEAVE YOUR BAGGAGE UNATTENDED",
		"수하물을 방치하지 마십시오",
		"お手荷物から目を離さないでください",
		"NE LAISSEZ PAS VOS BAGAGES SANS SURVEILLANCE",
		"NON LASCIARE I BAGAGLI INCUSTODITI",
		"請勿將行李無人看管" },
};


int
footer_count()
{
	return sizeof(kFooters) / sizeof(kFooters[0]);
}


const char*
footer_text(int index, int lang)
{
	return kFooters[index % footer_count()][ui_index(lang)];
}


// #pragma mark - time


// Days since 1970-01-01 for a civil date (Howard Hinnant's algorithm).
static int64
days_from_civil(int y, int m, int d)
{
	y -= m <= 2;
	int64 era = (y >= 0 ? y : y - 399) / 400;
	int64 yoe = y - era * 400;
	int64 doy = (153 * (m + (m > 2 ? -3 : 9)) + 2) / 5 + d - 1;
	int64 doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
	return era * 146097 + doe - 719468;
}


static void
civil_from_days(int64 z, int& y, int& m, int& d)
{
	z += 719468;
	int64 era = (z >= 0 ? z : z - 146096) / 146097;
	int64 doe = z - era * 146097;
	int64 yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;
	int64 doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
	int64 mp = (5 * doy + 2) / 153;
	d = (int)(doy - (153 * mp + 2) / 5 + 1);
	m = (int)(mp < 10 ? mp + 3 : mp - 9);
	y = (int)(yoe + era * 400 + (m <= 2));
}


// The day of month of the n-th (1-based) given weekday, or the last one
// when n is 0. Weekday 0 is Sunday.
static int
nth_weekday(int y, int m, int weekday, int n)
{
	if (n == 0) {
		int nm = m == 12 ? 1 : m + 1;
		int ny = m == 12 ? y + 1 : y;
		int64 last = days_from_civil(ny, nm, 1) - 1;
		int wd = (int)((last + 4) % 7);
		int lastDay;
		int yy, mm;
		civil_from_days(last, yy, mm, lastDay);
		return lastDay - ((wd - weekday + 7) % 7);
	}
	int64 first = days_from_civil(y, m, 1);
	int wd = (int)((first + 4) % 7);
	return 1 + (weekday - wd + 7) % 7 + (n - 1) * 7;
}


int64
local_minutes(int utcOffset, int dstRule, time_t utc)
{
	int64 utcMin = (int64)utc / 60;
	int y, m, d;
	civil_from_days(utcMin / 1440, y, m, d);

	bool summer = false;
	if (dstRule == DST_EU) {
		// Last Sunday of March to last Sunday of October, 01:00 UTC.
		int64 start = days_from_civil(y, 3, nth_weekday(y, 3, 0, 0)) * 1440 + 60;
		int64 end = days_from_civil(y, 10, nth_weekday(y, 10, 0, 0)) * 1440 + 60;
		summer = utcMin >= start && utcMin < end;
	} else if (dstRule == DST_US) {
		// Second Sunday of March to first Sunday of November, 02:00 local.
		int64 start = days_from_civil(y, 3, nth_weekday(y, 3, 0, 2)) * 1440
			+ 120 - utcOffset;
		int64 end = days_from_civil(y, 11, nth_weekday(y, 11, 0, 1)) * 1440
			+ 120 - utcOffset - 60;
		summer = utcMin >= start && utcMin < end;
	} else if (dstRule == DST_AU) {
		// Southern summer: from the first Sunday of October, 02:00 standard,
		// to the first Sunday of April, 03:00 daylight (02:00 standard).
		int64 end = days_from_civil(y, 4, nth_weekday(y, 4, 0, 1)) * 1440
			+ 120 - utcOffset;
		int64 start = days_from_civil(y, 10, nth_weekday(y, 10, 0, 1)) * 1440
			+ 120 - utcOffset;
		summer = utcMin < end || utcMin >= start;
	}
	return utcMin + utcOffset + (summer ? 60 : 0);
}


int64
airport_local_minutes(const Airport& airport, time_t utc)
{
	return local_minutes(airport.utcOffset, airport.dstRule, utc);
}


void
format_date(char* out, int size, int64 localMinutes, int lang)
{
	int y, m, d;
	civil_from_days(localMinutes / 1440, y, m, d);
	static const char* kEn[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
		"JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
	static const char* kFr[] = { "JANV", "FÉVR", "MARS", "AVR", "MAI", "JUIN",
		"JUIL", "AOÛT", "SEPT", "OCT", "NOV", "DÉC" };
	static const char* kIt[] = { "GEN", "FEB", "MAR", "APR", "MAG", "GIU",
		"LUG", "AGO", "SET", "OTT", "NOV", "DIC" };
	switch (lang) {
		case LANG_KO: snprintf(out, size, "%d월%d일", m, d); break;
		case LANG_JA:
		case LANG_ZHT: snprintf(out, size, "%d月%d日", m, d); break;
		case LANG_FR: snprintf(out, size, "%d %s", d, kFr[m - 1]); break;
		case LANG_IT: snprintf(out, size, "%d %s", d, kIt[m - 1]); break;
		default: snprintf(out, size, "%d %s", d, kEn[m - 1]); break;
	}
}


// #pragma mark - timetable


static uint32
mix(uint32 h)
{
	h ^= h >> 16;
	h *= 0x7feb352d;
	h ^= h >> 15;
	h *= 0x846ca68b;
	h ^= h >> 16;
	return h;
}


static uint32
hash4(uint32 a, uint32 b, uint32 c, uint32 d)
{
	return mix(a * 0x9e3779b1 ^ mix(b * 0x85ebca77 ^ mix(c * 0xc2b2ae3d
		^ mix(d + 0x27d4eb2f))));
}


static void
add_day(const Airport& airport, int airportIndex, int64 day, Flight* out,
	int& count, int max)
{
	// Departures between 06:20 and 23:50, spread evenly per route and
	// offset by a hash of it so that routes do not all leave together.
	const int kSpan = 1050;
	for (int r = 0; r < airport.routeCount; r++) {
		const Route& route = airport.routes[r];
		int base = (int)(hash4(airportIndex, r, route.number, 0) % kSpan);
		for (int k = 0; k < route.perDay && count < max; k++) {
			int minute = 380 + (base + k * kSpan / route.perDay) % kSpan;
			minute -= minute % 5;
			Flight& f = out[count++];
			f.route = r;
			f.number = route.number + k * 2;
			f.scheduled = day * 1440 + minute;
			uint32 h = hash4(airportIndex, r, k, (uint32)day);
			f.cancelled = h % 100 < 2;
			f.delay = h % 100 >= 2 && h % 100 < 14
				? 15 + (int)((h >> 8) % 22) * 5 : 0;
			uint32 g = (h >> 16) % (airport.gateMax - airport.gateMin + 1);
			int letters = strlen(airport.gateLetters);
			if (letters > 0) {
				snprintf(f.gate, sizeof(f.gate), "%c%d",
					airport.gateLetters[(h >> 24) % letters],
					airport.gateMin + (int)g);
			} else
				snprintf(f.gate, sizeof(f.gate), "%d", airport.gateMin + (int)g);
		}
	}
}


int
build_departures(const Airport& airport, int64 now, Flight* out, int max)
{
	int airportIndex = (int)(&airport - kAirports);
	int64 today = now / 1440;
	const int kPool = 512;
	Flight pool[kPool];
	int count = 0;
	add_day(airport, airportIndex, today - 1, pool, count, kPool);
	add_day(airport, airportIndex, today, pool, count, kPool);
	add_day(airport, airportIndex, today + 1, pool, count, kPool);

	// What a board shows: what has not left yet, and what left in the last
	// ten minutes; ordered by scheduled time.
	int shown = 0;
	for (int i = 0; i < count; i++) {
		const Flight& f = pool[i];
		int64 leaves = f.scheduled + (f.cancelled ? 0 : f.delay);
		if (leaves < now - 10)
			continue;
		if (shown < max)
			out[shown++] = f;
		else {
			int latest = 0;
			for (int j = 1; j < shown; j++) {
				if (out[j].scheduled > out[latest].scheduled)
					latest = j;
			}
			if (f.scheduled < out[latest].scheduled)
				out[latest] = f;
		}
	}
	for (int i = 1; i < shown; i++) {
		Flight f = out[i];
		int j = i - 1;
		while (j >= 0 && (out[j].scheduled > f.scheduled
				|| (out[j].scheduled == f.scheduled
					&& out[j].number > f.number))) {
			out[j + 1] = out[j];
			j--;
		}
		out[j + 1] = f;
	}
	return shown;
}


int
flight_status(const Flight& flight, int64 now)
{
	if (flight.cancelled)
		return STATUS_CANCELLED;
	int64 left = flight.scheduled + flight.delay - now;
	if (left < 0)
		return STATUS_DEPARTED;
	if (left < 5)
		return STATUS_GATE_CLOSED;
	if (left < 15)
		return STATUS_FINAL_CALL;
	if (left < 35)
		return STATUS_BOARDING;
	if (left < 60)
		return STATUS_GATE_OPEN;
	if (flight.delay > 0)
		return STATUS_DELAYED;
	if (left < 150)
		return STATUS_CHECK_IN;
	return STATUS_ON_TIME;
}


void
format_flight_number(char* out, int size, const Airport& airport,
	const Flight& flight)
{
	const char* code = airport.routes[flight.route].airline;
	if (airport.padNumbers)
		snprintf(out, size, "%s%03d", code, flight.number);
	else
		snprintf(out, size, "%s%d", code, flight.number);
}
