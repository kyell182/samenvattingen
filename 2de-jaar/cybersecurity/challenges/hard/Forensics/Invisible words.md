
# PicoCTF Challenge Rapport : invisible words

---

# 1. Challenge-informatie

**Naam challenge:**  Invisible WORDs
**Categorie:** Forensics
**Difficulty:** Hard
**PicoCTF platform:** picoCTF  
**Datum opgelost:**  
**PicoCTF username:**  kyell182

## Probleemstelling

we krijgen een image bestand, en we moeten de verborgen tekst vinden. We kunnen de afbeelding openen, maar er is geen tekst te zien. We moeten dus een manier vinden om de verborgen tekst te onthullen.

## hints

- Something doesn't quite add up with this image...
- How's the image quality?

---

## 2. Eerste Analyse (Reconnaissance)

via defender geen vlaggen gekregen dus geen virus

na openen van de afbeelding zie je de image met veel ruis pixels erond

![image](../../assets/invisible_words%20image.png)

### Observaties

- Er is veel ruis in de afbeelding, wat kan betekenen dat er iets verborgen is.
- De afbeelding lijkt op het eerste gezicht normaal, maar er is iets mis mee.
- De hints suggereren dat er iets mis is met de kwaliteit van de afbeelding.
- Er is geen zichtbare tekst in de afbeelding, dus we moeten een manier vinden om de verborgen tekst te onthullen.
- De afbeelding heeft een lage resolutie, wat kan betekenen dat er iets verborgen is in de pixels.
- ik vind het ook raar dat de titel vand de opdracht WORD in hoofdletters staat.
- een van de badges van de opdracht is "Steganography", wat suggereert dat er iets verborgen is in de afbeelding.

### Hypothese 1

> ik vermoed dat er een verborgen tekst is in de afbeelding, en dat we een manier moeten vinden om deze te onthullen. Misschien is er een manier om de ruis te verwijderen of te verminderen, zodat we de verborgen tekst kunnen zien. Of misschien is er een manier om de pixels te analyseren om de verborgen tekst te vinden. We moeten dus een manier vinden om de afbeelding te analyseren en de verborgen tekst te onthullen.

> een grote hint volgens mij is ook WORD een word is 2 bytes dus 16 bit en dit zal volgens mij toch belangerijk zijn.

---

## 3. Onderzoek en Stappenplan (Volledig Denkproces)

### Stap 1

ik zal hem eerst eens binnen halen op de webshell van pico ctf en dan eens kijken wat ik er mee kan doen

#### Waarom probeerde ik dit?

de linux mgeving heeft veel tools die ik kan gebruiken om de afbeelding te analyseren, en ik kan ook de pixels analyseren om te zien of er iets verborgen is.

#### Tool

pico ctf webshell

#### comando's

```bash
wget https://artifacts.picoctf.net/c/405/output.bmp
```

### Stap 2

ik zal eens kijken naar de eigenschappen van de afbeelding, zoals de resolutie, het aantal pixels, en de kleurinformatie. Misschien kan ik iets vinden dat me helpt om de verborgen tekst te onthullen.

#### Waarom probeerde ik dit?

door de eigenschappen van de afbeelding te analyseren, kan ik misschien iets vinden dat me helpt om de verborgen tekst te onthullen. Misschien is er iets mis met de resolutie of het aantal pixels, of misschien is er iets mis met de kleurinformatie.

#### Tool

```bash
exiftool output.bmp
```

### resultaat

```bash
ExifTool Version Number         : 12.40
File Name                       : output.bmp
Directory                       : .
File Size                       : 2025 KiB
File Modification Date/Time     : 2023:03:16 03:16:15+00:00
File Access Date/Time           : 2026:04:14 20:06:57+00:00
File Inode Change Date/Time     : 2026:04:14 20:06:40+00:00
File Permissions                : -rw-rw-r--
File Type                       : BMP
File Type Extension             : bmp
MIME Type                       : image/bmp
BMP Version                     : Windows V5
Image Width                     : 960
Image Height                    : 540
Planes                          : 1
Bit Depth                       : 32
Compression                     : Bitfields
Image Length                    : 2073600
Pixels Per Meter X              : 11811
Pixels Per Meter Y              : 11811
Num Colors                      : Use BitDepth
Num Important Colors            : All
Red Mask                        : 0x00007c00
Green Mask                      : 0x000003e0
Blue Mask                       : 0x0000001f
Alpha Mask                      : 0x00000000
Color Space                     : sRGB
Rendering Intent                : Proof (LCS_GM_GRAPHICS)
Image Size                      : 960x540
Megapixels                      : 0.518
```

### Observaties

- De afbeelding heeft een resolutie van 960x540, wat betekent dat er 518.4K pixels zijn.
- De afbeelding heeft een bit depth van 32, wat betekent dat er 4 bytes per pixel zijn.
- De afbeelding heeft een compressie van "Bitfields", wat betekent dat er een specifieke manier is om de kleuren te coderen.
- De afbeelding heeft een kleurenschema van sRGB, wat betekent dat de kleuren worden gecodeerd in rood, groen, en blauw.
- de afbeelding heeft een red mask van 0x00007c00, een green mask van 0x000003e0, en een blue mask van 0x0000001f, wat betekent dat de kleuren worden gecodeerd in specifieke bits van de pixelwaarden.
- de afbeelding heeft een alpha mask van 0x00000000, wat betekent dat er geen transparantie is in de afbeelding.
- de afbeelding heeft een rendering intent van "Proof (LCS_GM_GRAPHICS)", wat betekent dat de kleuren worden gecodeerd op een manier die geschikt is voor grafische weergave.
- de afbeelding heeft een image size van 960x540, wat betekent dat er 518.4K pixels zijn, en een megapixels van 0.518, wat betekent dat de afbeelding relatief klein is.

### denk piste

- gezien de hints en de observaties, denk ik dat er iets mis is met de kwaliteit van de afbeelding, en dat er misschien iets verborgen is in de pixels. Misschien is er een manier om de ruis te verwijderen of te verminderen, zodat we de verborgen tekst kunnen zien. Of misschien is er een manier om de pixels te analyseren om de verborgen tekst te vinden. We moeten dus een manier vinden om de afbeelding te analyseren en de verborgen tekst te onthullen.

- ik zie dat de bit depth van de afbeelding 32 is, wat betekent dat er 4 bytes per pixel zijn.
  - de red mask is `0x00007c00`, wat betekent dat de rode kleur wordt gecodeerd in de bits 10-14 van de pixelwaarden.
  - de green mask is `0x000003e0`, wat betekent dat de groene kleur wordt gecodeerd in de bits 5-9 van de pixelwaarden.
  - de blue mask is `0x0000001f`, wat betekent dat de blauwe kleur wordt gecodeerd in de bits 0-4 van de pixelwaarden.

    - dit is belangerijk omdat aan de hand van dit  mask word gekeken welke bits van de pixelwaarden worden gebruikt om de kleuren te coderen, en dit kan ons helpen om de verborgen tekst te vinden als deze is gecodeerd in de pixels.

    - dit is de `high color ( RGB555)` format waarbij elke kleur wordt gecodeerd in 5 bits, en er is 1 bit over voor de alpha channel (transparantie), maar in dit geval is de alpha mask `0x00000000`, wat betekent dat er geen transparantie is in de afbeelding.
    - hierdoor word duidelijk dat de data wel eens in de top 2 words van de pixelwaarden zal zitten daar deze niet gebruikt worden en door image renders genegeerd worden door het mask en dit is ook een van de hints die we kregen "Something doesn't quite add up with this image..." en "How's the image quality?" wat suggereert dat er iets mis is met de kwaliteit van de afbeelding, en dat er misschien iets verborgen is in de pixels.

### stap 3

ik zal de file nu eens bekijken met een hex editor om te zien of ik iets kan vinden dat me helpt om de verborgen tekst te onthullen.

#### Waarom probeerde ik dit?

ik verwacht dat de data telkens in de 3 en 4 de byte van de pixelwaarden zal zitten, omdat de eerste 2 bytes worden gebruikt om de kleuren te coderen, en de laatste 2 bytes worden genegeerd door het mask.

#### Tool

```bash
xxd output.bmp
```

#### resultaat

```bash
001f6260: ff00 083a ff00 ad39 ff00 f041 ff00 310e  ...:...9...A..1.
001f6270: ff00 ae4a ff00 4e1d ff00 ad49 ff00 5452  ...J..N....I..TR
001f6280: ff00 364a ff00 a844 ff00 3767 ff00 1121  ..6J...D..7g...!
001f6290: ff00 765b ff00 1042 ff00 2510 ff00 f245  ..v[...B..%....E
001f62a0: ff00 ee35 ff00 e848 ff00 5342 ff00 0f3e  ...5...H..SB...>
001f62b0: ff00 314a ff00 d351 ff00 b656 ff00 5877  ..1J...Q...V..Xw
001f62c0: ff00 2410 ff00 1046 ff00 8328 ff00 f245  ..$....F...(...E
001f62d0: ff00 d24a ff00 f114 ff00 ad35 ff00 a114  ...J.......5....
001f62e0: ff00 f249 ff00 8414 ff00 ee39 ff00 2a21  ...I.......9..*!
001f62f0: ff00 0f56 ff00 0c25 ff00 503e ff00 f456  ...V...%..P>...V
001f6300: ff00 8c31 ff00 a609 ff00 8d19 ff00 3246  ...1..........2F
001f6310: ff00 e920 ff00 d656 ff00 2939 ff00 6a2d  ... ...V..)9..j-
001f6320: ff00 0719 ff00 904a ff00 1963 ff00 5746  .......J...c..WF
001f6330: ff00 b456 ff00 a814 ff00 543d ff00 1145  ...V......T=...E
001f6340: ff00 cf39 ff00 1142 ff00 325a ff00 3015  ...9...B..2Z..0.
001f6350: ff00 4645 ff00 113a ff00 4f2e ff00 5139  ..FE...:..O...Q9
001f6360: ff00 d45e ff00 1763 ff00 563e ff00 f431  ...^...c..V>...1
001f6370: ff00 b13d ff00 cc49 ff00 8308 ff00 314a  ...=...I......1J
001f6380: ff00 4d11 ff00 763a ff00 1863 ff00 ec51  ..M...v:...c...Q
001f6390: ff00 f24e ff00 8f31 ff00 4b4d ff00 1146  ...N...1..KM...F
001f63a0: ff00 1542 ff00 693d ff00 ac3d ff00 8d52  ...B..i=...=...R
```

hier worden we niet veel wijzer van ik denk dat dit komt door het feit dat we niet goed groeperen en ik ben ook vergeten om de header van de afbeelding te negeren, dus ik zal eens kijken naar de header van de afbeelding om te zien waar de pixeldata begint.

### stap 4

ik zal de header van de afbeelding bekijken om te zien waar de pixeldata begint, zodat ik de pixeldata kan analyseren en weet waar de data begint.

#### Waarom probeerde ik dit?

ik moet weten waar de echte data begint en waar de header data zit ( de header data is de data die wordt gebruikt om de afbeelding te beschrijven, zoals de resolutie, het aantal pixels, en de kleurinformatie), zodat ik de pixeldata kan analyseren en weet waar de data begint.

#### Tool

```bash
file output.bmp
```

#### resultaat

```bash
output.bmp: PC bitmap, Windows 98/2000 and newer format, 960 x 540 x 32, cbSize 2073738, bits offset 138
```

hier zien we dat de pixeldata begint bij byte 138, dus ik zal de pixeldata analyseren vanaf byte 138 om te zien of ik iets kan vinden dat me helpt om de verborgen tekst te onthullen.

### stap 5

nu ga ik het xxd commando gebruiken om de pixeldata te analyseren vanaf byte 138, en ik zal de data groeperen in 4 bytes per pixel, zodat ik kan zien welke data er in de pixels zit.

#### Waarom probeerde ik dit?

de header info ben ik niets mee ik moet de echte data hebben en die zit in de pixeldata, dus ik zal de pixeldata analyseren vanaf byte 138 om te zien of ik iets kan vinden dat me helpt om de verborgen tekst te onthullen.

#### Tool

```bash
xxd -s 138 -c 4 -g 2 output.bmp | head -n 20
```

`xxd` is een commando dat wordt gebruikt om een bestand te bekijken in hexadecimale en ASCII notatie.  
`-s 138` geeft aan dat we willen beginnen bij byte 138, wat het begin van de pixeldata is.  
`-c 4` geeft aan dat we de data willen groeperen in 4 bytes per pixel.  
`-g 2` geeft aan dat we de data willen groeperen in 2 bytes per groep, wat betekent dat we de data zullen groeperen in words van 2 bytes.  
`output.bmp` is het bestand dat we willen analyseren.  
`| head -n 20` geeft aan dat we alleen de eerste 20 regels van de output willen zien, zodat we een overzicht krijgen van de eerste paar pixels.

#### resultaat

```bash
0000008a: 3867 504b  8gPK
0000008e: 9552 0304  .R..
00000092: c618 1400  ....
00000096: ce3d 0000  .=..
0000009a: 104a 0800  .J..
0000009e: 6f56 6f13  oVo.
000000a2: 1016 7056  ..pV
000000a6: 723e 229b  r>".
000000aa: 0e3a 64e7  .:d.
000000ae: d55a b095  .Z..
000000b2: ab39 0200  .9..
000000b6: 2d4e 82d8  -N..
000000ba: 693d 0600  i=..
000000be: ef41 1c00  .A..
000000c2: 4e49 1c00  NI..
000000c6: 314a 5a6e  1JZn
000000ca: af1d 4a68  ..Jh
000000ce: b452 626d  .Rbm
000000d2: 1146 746c  .Ftl
000000d6: 0909 626e  ..bn
```

wat hier opvalt is dat de eerste pixelwaarde op byte 3 en 4 een waarde van `504b` heeft wat het magic number is voor een zip bestand en dat er dus een zip file verborgen zit in de pixel data.

### stap 6

nu dat we weten dat er een zip file verborgen zit in de pixel data, ga ik proberen om deze zip file te extraheren en te bekijken wat erin zit.

#### Waarom probeerde ik dit?

nu dat we weten dat er een zip file verborgen zit in de pixel data, ga ik proberen om deze zip file te extraheren en te bekijken wat erin zit, omdat dit waarschijnlijk de verborgen tekst bevat die we moeten vinden.

#### Tool

```bash
xxd -s 138 -c 4 -g 2 output.bmp | head -n 20 | awk '{print $2$3}' | xxd -r -p > hidden.zip
```

`awk '{print $2$3}'` wordt gebruikt om de tweede en derde kolom van de output van `xxd` te combineren, wat de hexadecimale waarden van de pixels bevat.  
`xxd -r -p` wordt gebruikt om de hexadecimale waarden terug te converteren naar binaire data, wat de zip file zal zijn.  
`> hidden.zip` wordt gebruikt om de output van het commando op te slaan in een bestand genaamd `hidden.zip`.

#### resultaat

na het uitvoeren van het commando hebben we een bestand genaamd `hidden.zip` dat de verborgen zip file bevat. We kunnen deze zip file nu extraheren om te zien wat erin zit.

```bash
unzip hidden.zip
```

```bash
Archive:  hidden.zip

  End-of-central-directory signature not found.  Either this file is not

  a zipfile, or it constitutes one disk of a multi-part archive.  In the

  latter case the central directory and zipfile comment will be found on

  the last disk(s) of this archive.

unzip:  cannot find zipfile directory in one of hidden.zip or

        hidden.zip.zip, and cannot find hidden.zip.ZIP, period.
```

deze foutmelding geeft aan dat de zip file die we hebben geëxtraheerd niet geldig is, wat kan betekenen dat er iets mis is met de manier waarop we de zip file hebben geëxtraheerd, of dat er iets mis is met de zip file zelf. We moeten dus een andere manier vinden om de zip file te extraheren, of we moeten proberen om de zip file te repareren.

mischien dat ik dit via een python programma kan doen om de zip file te extraheren, omdat er misschien iets mis is met de manier waarop we de zip file hebben geëxtraheerd, of dat er iets mis is met de zip file zelf.

### stap 7

ik zal nu met een python programma proberen om de zip file te extraheren vermoedelijk komt er nog teveel of foutieve data mee

#### Waarom probeerde ik dit?

de zip file is niet geldig 

#### Tool

```python
python3 -c "f=open('output.bmp','rb').read(); open('vlag_herstel.zip','wb').write(b''.join(f[i:i+2] for i in range(138+2, len(f), 4)))"
```

`pyton3 -c` wordt gebruikt om een python commando uit te voeren vanuit de command line.  
`f=open('output.bmp','rb').read()` wordt gebruikt om het bestand `output.bmp` te openen in binaire modus en de inhoud ervan te lezen.  
`open('vlag_herstel.zip','wb').write(...)` wordt gebruikt om een nieuw bestand genaamd `vlag_herstel.zip` te openen in binaire modus en de data die we willen schrijven naar dit bestand te schrijven.  
`b''.join(f[i:i+2] for i in range(138+2, len(f), 4))` wordt gebruikt om de data te extraheren uit de pixeldata van de afbeelding, door elke 4 bytes te nemen en alleen de derde en vierde byte te gebruiken (omdat de eerste en tweede byte worden gebruikt om de kleuren te coderen), en deze bytes te combineren tot een binaire string die de zip file zal zijn.

#### resultaat

ik heb nu een bestand genaamd `vlag_herstel.zip` dat de zip file bevat die we eerder hebben geëxtraheerd, maar deze keer hebben we alleen de relevante data uit de pixeldata gebruikt, dus de zip file zou nu geldig moeten zijn. We kunnen deze zip file nu extraheren om te zien wat erin zit.

```bash
unzip vlag_herstel.zip
```

### stap 8

nu dat we de zip file hebben geëxtraheerd, kunnen we kijken wat erin zit en of we de verborgen tekst kunnen vinden.

#### comando's

```bash
unzip vlag_herstel.zip
```

#### resultaat

dit geeft nog steeds een error

#### stap 9

ik zal dit nnu met een andere tool proberen te extraheren, omdat er misschien iets mis is met de manier waarop we de zip file hebben geëxtraheerd, of dat er iets mis is met de zip file zelf.

#### Tool

```bash
binwalk -e vlag_herstel.zip
```

`binwalk` is een tool die wordt gebruikt om bestanden te analyseren en te extraheren, vooral in het geval van bestanden die zijn verpakt in andere bestanden, zoals zip files die zijn verborgen in afbeeldingen.  
`-e` geeft aan dat we willen proberen om de inhoud van de zip file te extraheren.

#### resultaat

na het uitvoeren van het commando hebben we een nieuwe map genaamd `_vlag_herstel.zip.extracted` die de inhoud van de zip file bevat. We kunnen deze map nu bekijken om te zien wat erin zit.

```bash
ls _vlag_herstel.zip.extracted
```

```bash
0.zip  ZnJhbmtlbnN0ZWluLXRlc3QudHh0
```

#### stap 10

nu dat we de files gevonden hebben zal de juiste file `ZnJhbmtlbnN0ZWluLXRlc3QudHh0` zijn omdat deze een txt file is en de andere file een zip file is die waarschijnlijk niet geldig is, dus ik zal deze txt file openen om te zien wat erin zit.

#### Tool

```bash
cat _vlag_herstel.zip.extracted/ZnJhbmtlbnN0ZWluLXRlc3QudHh0
```

#### resultaat

we krijgen nu een stuk uit een ebook van frankestein te zien.

ik doe nu nog een grep picoctf om de flag te vinden in de tekst

```bash
grep picoCTF _vlag_herstel.zip.extracted/ZnJhbmtlbnN0ZWluLXRlc3QudHh0
```

At that age I became acquainted with the celebrated `picoCTF{w0rd_d4wg_y0u_f0und_5h3113ys_m4573rp13c3_539ea4a8}`

#### analyse

hier word het enorm duidelijk dat er veel info kan verborgen worden in ogenschijnlijke onschuldige images, en dat het belangrijk is om goed te kijken naar de eigenschappen van de afbeelding en de data die erin zit, omdat er misschien iets verborgen is dat we moeten vinden. In dit geval was er een zip file verborgen in de pixeldata van de afbeelding, en we moesten deze zip file extraheren om de verborgen tekst te vinden. Dit laat zien dat het belangrijk is om creatief te zijn en verschillende tools te gebruiken om de data te analyseren en te extraheren, omdat er misschien iets verborgen is dat we moeten vinden.

en dat we steeds moeten allert zijn op de meest onbeduidende info omdat deze misschien wel eens de sleutel kan zijn tot het vinden van de verborgen tekst, zoals in dit geval de bit masks die werden gebruikt om de kleuren te coderen, wat ons hielp om te begrijpen hoe de data was gecodeerd in de pixels, en dat we alleen de derde en vierde byte van elke pixel moesten gebruiken om de zip file te extraheren.

dit is al zeer high level data hiding en dat dit door 99% van de mensen niet zal gevonden worden en dus zeer gevaarlijk kan zijn.

voor beveiliging is dit een grote nachtmerrie omdat een aanvaller volgende technieken kan toepassen

1. Data Exfiltratie (Datalekken)

  Dit is het grootste risico binnen bedrijven. Moderne beveiligingssystemen (DLP - Data Loss Prevention) scannen emails en uploads op gevoelige woorden of bekende bestandstypen zoals PDF of Excel.

Het gevaar: Een insider kan gevoelige informatie (zoals klantgegevens of broncode) verstoppen in een gewone profielfoto of een bedrijfslogo.

Waarom het werkt: De afbeelding ziet er op het oog normaal uit en de "file signature" blijft die van een BMP of PNG. De scanner ziet alleen een afbeelding die wordt geüpload naar bijvoorbeeld social media, terwijl er in werkelijkheid een versleuteld archief naar buiten gaat.

2. Malware Verspreiding (C2 Communication)

  Hackers gebruiken steganografie om instructies te sturen naar computers die ze al besmet hebben (Command & Control).

  In plaats van een verdacht tekstbestand met commando's te sturen, downloadt de malware een "meme" van een publieke website zoals Imgur of Pinterest.

  De malware op de computer weet precies welke bytes (zoals de 3e en 4e byte van elke pixel) hij moet uitlezen om de volgende aanvalsfase te starten. Dit is extreem lastig te detecteren voor antivirussoftware.

3. Bypass van Sandboxing

  Veel security-tools "draaien" een bestand eerst in een veilige omgeving (sandbox) om te zien wat het doet.

  Als een afbeelding alleen maar pixeldata bevat, doet de sandbox niets; het is immers geen uitvoerbaar programma.

  De schadelijke code wordt pas "gebouwd" zodra de afbeelding op de lokale machine is en door een ander (ogenschijnlijk veilig) script wordt uitgelezen, precies zoals we met het Python-commando deed.

4. De uitdaging voor de verdediging: "Steganalysis"

  Beveiligers moeten nu gebruikmaken van Steganalysis. Dit is de kunst van het ontdekken van verborgen data.

  Statistische afwijkingen: Een normale foto heeft een bepaalde natuurlijke variatie in kleuren. Als 25% van de bits wordt vervangen door een ZIP-bestand, verandert de statistische vingerafdruk van de pixels (bijvoorbeeld een onnatuurlijke verdeling van kleuren in de LSB - Least Significant Bits).

  Bestandsgrootte: Een BMP-bestand dat veel groter is dan je op basis van de resolutie zou verwachten, is een enorme rode vlag.

#### wat kan er tegen gedaan worden?

- Educatie: Medewerkers bewust maken van de gevaren van steganografie en hoe ze verdachte bestanden kunnen herkennen.
- Geavanceerde Scanning: Gebruik maken van tools die specifiek zijn ontworpen voor steganalysis, zoals StegDetect of StegExpose, om verdachte afbeeldingen te analyseren.
- Beperkingen op Bestandsformaten: Alleen bepaalde bestandstypen toestaan voor uploads en communicatie, en afbeeldingen die groter zijn dan een bepaalde drempel weigeren.
- Monitoring: Continu monitoren van netwerkverkeer en bestandsactiviteiten om ongebruikelijke patronen te detecteren die kunnen wijzen op data-exfiltratie of C2-communicatie.

- Hashes vergelijken om te zien of er iets mis is met de afbeelding, zoals een hash mismatch die kan wijzen op een gewijzigde afbeelding.

---

![image](../assets/invisible%20word%20clear.png)