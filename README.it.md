# R Departures

<img src="docs/icon.png" width="64" alt="">

[English](README.md) | [日本語](README.ja.md) | [한국어](README.ko.md) | **Italiano**

Un tabellone delle partenze di un aeroporto per RenkuOS (HaikuOS), a schermo
intero e senza bordo di finestra, e i tabelloni dei treni di Tokyo, Seul, London
Victoria e Sydney Central. Ogni carattere è una paletta: quando qualcosa cambia,
le palette girano attraverso altre lettere e si fermano, una riga dopo l'altra,
e la colonna della compagnia è una paletta sola nei colori della compagnia.

![Venezia](docs/venice.png)

## Installazione con pkgman

| Haiku | Aggiungere il repository |
| --- | --- |
| x86 a 32 bit (x86_gcc2) | `pkgman add-repo https://pkgman.rainygirl.com/x86_gcc2` |
| x86_64 | `pkgman add-repo https://pkgman.rainygirl.com/x86_64` |
| arm64 | `pkgman add-repo http://pkgman.rainygirl.com/arm64` |

```sh
pkgman install rdepartures
```

Poi si avvia **R Departures** da **Deskbar -> Applications**. Il pacchetto
installa anche il carattere delle palette, TeX Gyre Heros Condensed Bold.

Gli stessi tabelloni sono anche un salvaschermo:
[R Departures screen saver](https://github.com/rainygirl/rdepartures-screensaver)
(`pkgman install rdepartures_screensaver`).

Se `pkgman add-repo` fallisce con `Operation not supported`, il network kit di
quell'immagine non ha TLS: usare `http://` al posto di `https://`.

## Aeroporti

Seul Incheon (ICN), Tokyo Narita (NRT), Hong Kong (HKG), Londra Heathrow (LHR),
Parigi Charles de Gaulle (CDG), Milano Malpensa (MXP), Venezia Marco Polo (VCE),
New York JFK (JFK) e San Francisco (SFO). Si sceglie con l'ingranaggio in alto
a destra; il tabellone lo ricorda all'avvio successivo.

Ogni tabellone segue l'ora locale del suo aeroporto, ora legale compresa, e
cambia lingua ogni otto secondi:

1. la lingua del paese dell'aeroporto,
2. l'inglese, se quella lingua non è già l'inglese,
3. ogni destinazione nella sua lingua -- Seul come 서울, Taipei come 臺北,
   Atene come ΑΘΗΝΑ -- con le note in quella lingua, se il tabellone ha le
   parole.

![Narita, ogni destinazione nella sua lingua](docs/narita-destinations.png)
![Hong Kong](docs/hongkong.png)
![Parigi](docs/paris.png)

I voli sono rotte reali con numeri di volo, gate e orari verosimili; l'orario
è generato, uguale ogni giorno, con qualche ritardo e cancellazione decisi
dalla data. Non sono dati in tempo reale. Le note seguono l'orologio:
check-in, gate aperto, imbarco, ultima chiamata, gate chiuso, partito.

![Palette che cambiano](docs/flipping.png)

## Stazioni ferroviarie

Le ultime quattro voci del menu dell'ingranaggio sono stazioni ferroviarie.
Non sono tabelloni a palette: ognuna somiglia agli schermi delle partenze di
quella stazione.

### Stazione di Tokyo

Un tabellone delle stazioni JR, come gli schermi LED e LCD sopra i binari:
orario di partenza, destinazione, binario nel colore della linea, il treno, e
per ogni treno le stazioni principali dove ferma (○) o che salta (─). Quattro
tabelloni si alternano ogni dodici secondi, ciascuno in giapponese e poi in
inglese:

- Tokaido Shinkansen: Nozomi, Hikari, Kodama, con le carrozze non riservate
- Tohoku, Yamagata, Akita, Joetsu e Hokuriku Shinkansen: Hayabusa, Komachi,
  Yamabiko, Nasuno, Tsubasa, Toki, Tanigawa, Kagayaki, Hakutaka, Asama
- Linea Tokaido, linea Ueno-Tokyo, linea Yokosuka (i binari sotterranei) e il
  limited express Odoriko
- Linea Chuo: Rapid, Chuo e Ome Special Rapid, Azusa e Kaiji

Come i voli, i treni di ogni stazione sono un orario generato dei servizi
reali, non dati in tempo reale.

![Tokaido Shinkansen](docs/tokyo-shinkansen.png)
![Gli Shinkansen verso nord](docs/tokyo-north.png)
![Linee Tokaido, Ueno-Tokyo e Yokosuka, in inglese](docs/tokyo-tokaido-line.png)

### Stazione di Seul

Lo schermo delle partenze di Korail: il tipo di treno nel suo colore (KTX,
KTX-Cheongryong, KTX-Sancheon, ITX-Saemaeul, Mugunghwa), numero del treno,
destinazione, orario, binario e note (in orario, imbarco, chiusura, ritardo),
in coreano, inglese, giapponese e cinese a turno. Dopo ogni destinazione, in
piccolo, le stazioni dove il treno ferma; un elenco troppo lungo per il suo
spazio scorre fino alla fine e torna indietro.

![Stazione di Seul](docs/seoul.png)
![Stazione di Seul, in inglese](docs/seoul-english.png)

### London Victoria

Una colonna per treno, come sugli schermi sopra i binari di Victoria: orario,
destinazione e percorso, poi *Wait* con una mano alzata finché il binario non
viene annunciato, *Platform* con una persona che cammina quando lo è,
*Cancelled* con una croce, o l'orario previsto se in ritardo. Sotto, le
fermate con i loro orari, una pagina alla volta quando non ci stanno, e la
lunghezza del treno.

![London Victoria](docs/victoria.png)

### Sydney Central

La parete di schermi verticali nell'atrio, sotto le schede arancioni Sydney
services, Intercity & Events e Regional services e quella verde acqua Metro:
uno schermo per linea o binario con la linea (T1, T2, T4, T8, T9, M1),
destinazione e percorso, le stazioni, il binario, le carrozze e il tipo di
fermate e i minuti al prossimo treno, poi i treni successivi. Gli schermi del
City Circle elencano sei treni; quelli intercity e regionali mettono prima
l'orario e segnano i treni a soli posti prenotati; uno schermo è un avviso.
Le stazioni che non ci stanno salgono, in un solo senso, finché non si vede
l'ultima, e ricominciano dall'inizio. Su uno schermo più largo di 16:9 la
parete è una sola fila di schermi più alti, quattro per Sydney services.

![Sydney Central](docs/sydney-central-concourse.png)

Ogni stazione segue la sua ora locale, ora legale compresa.

## Tasti

| Tasto | |
| --- | --- |
| Esc, Q | esci |
| Freccia destra, spazio | aeroporto successivo (le stazioni dopo San Francisco) |
| Freccia sinistra | aeroporto precedente |

Il puntatore del mouse si nasconde dopo tre secondi.

## Compilare dai sorgenti

Su Haiku:

```sh
make install
```

compila `RDepartures` e lo copia in `~/config/non-packaged/apps/R Departures`,
con il carattere del tabellone (TeX Gyre Heros Condensed Bold) in
`~/config/non-packaged/data/fonts/otfonts`; il carattere viene caricato al
riavvio successivo. Il codice è C++98, quindi il `g++` predefinito lo compila
anche su un ibrido x86 a 32 bit (gcc2).

Su una macchina con Docker, `tools/cross-build.sh all` compila in modo
incrociato `dist/x86/` (con il compilatore x86 secondario dell'ibrido, non gcc2),
`dist/x86_64/` e `dist/arm64/`.

`RDepartures --snapshot board.png --size 1600x768 --airport VCE` disegna il
tabellone fuori schermo e lo salva, per controllarlo senza uno schermo. Prima
chiudere un tabellone in esecuzione: un secondo avvio viene passato a quello.

## Nessuna affiliazione

I nomi e i colori delle compagnie aeree servono a far sembrare vero il
tabellone; non ci sono loghi, e nulla qui è approvato da compagnie aeree,
aeroporti o ferrovie.

## Uso dell'IA

R Departures è stato sviluppato con l'aiuto di strumenti di programmazione con
IA (Claude di Anthropic).

## Licenza

MIT per il codice. `fonts/texgyreheroscn-bold.otf` (TeX Gyre Heros, di
B. Jackowski e J. M. Nowacki) è sotto la GUST Font License
(`fonts/GUST-FONT-LICENSE.txt`).
