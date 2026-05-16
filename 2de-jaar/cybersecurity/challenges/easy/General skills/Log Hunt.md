
# PicoCTF Challenge Rapport : Log Hunt

---

# 1. Challenge-informatie

**Naam challenge:**  Log Hunt
**Categorie:** General skills
**Difficulty:** Easy
**PicoCTF platform:** picoCTF  
**Datum opgelost:** 13/04/26
**PicoCTF username:**  kyell182

## Probleemstelling

de server lijkt stukjes ven een geheime flag te loggen.
deze zijn gefragmenteerd en soms worden ze herhaald.
om de flag te vinden moet je alle log entries verzamelen en ze in de juiste volgorde zetten

hints:

- You can use grep to filter only matching lines from the log.
- Some lines are duplicates; ignore extra occurrences.

---

## 2. Eerste Analyse (Reconnaissance)

### Observaties

het bestand ziet er een gewoon log bastand uit.
aan de hand van de uitleg zullen we waarschijnlijk via regexp de verschillende stukjes van de flag moeten verzamelen en in de juiste volgorde zetten.

### Hypothese 1

> men wil ons testen of we regexp goed in de vingers hebben en of we in staat zijn om de juiste stukjes van de flag te verzamelen en in de juiste volgorde te zetten.

---

## 3. Onderzoek en Stappenplan (Volledig Denkproces)

### Stap 1

ik zal eerst de log file in de webshell binnen trekken zodat ik er mee kan werken.

#### Waarom probeerde ik dit?

zodat ik in een veilige en geisoleerde omgeving kan werken met de log file zonder risico te lopen op malware of virussen.

#### Tool

pico ctf webshell

#### comando's

```bash
wget https://challenge-files.picoctf.net/c_amiable_citadel/49cec6157142f24a599f4164d5b63322c2494f801390d6f22eb91b3aa592bc66/server.log
```

### Stap 2

ik al eerst naar de meta data kijken van het log bestand om te zien of er iets opvallends is en of er bepaalde rechten zijn die kunnen aangeven of het bestand mogelijk gevaarlijk is of niet.

#### Waarom probeerde ik dit?

dit is eigenlijk niet zo hard nodig om deze challenge op te lossen, maar het is wel een goede gewoonte om altijd de meta data van bestanden te controleren voordat je ermee gaat werken, vooral als het bestand afkomstig is van een onbekende bron. Door de meta data te bekijken, kan je mogelijk informatie vinden over de herkomst van het bestand, de auteur, of andere details die kunnen helpen bij het oplossen van de challenge.

wat opviel is dat er 2348 lijnen zijn en 13550 woorden in het bestand, wat aangeeft dat er veel informatie in de log file staat en dat we waarschijnlijk een manier moeten vinden om de relevante stukjes eruit te filteren.

#### Tool

exiftool

#### comando's

```bash
exiftool server.log
```

### stap 3

nu ga ik kijken naar de inhoud van de log en kijken wat er efectief inzit en of er bepaalde patronen zijn die me kunnen helpen om de relevante stukjes van de flag te vinden.

#### Waarom probeerde ik dit?

dit is eigenlijk de kern van de challenge, we moeten de log file analyseren om de relevante stukjes van de flag te vinden. Door naar de inhoud van de log te kijken, kunnen we mogelijk patronen ontdekken die ons kunnen helpen om de juiste lijnen te filteren en de stukjes van de flag te verzamelen.

#### Tool

cat = om de inhoud van de log file te bekijken

#### comando's

```bash
cat server.log
```

#### resultaat

we vinden volgende dingen terug in de file :

```log
[1990-08-09 12:18:16] DEBUG System check complete
[1990-08-09 12:18:25] ERROR Connection lost
[1990-08-09 12:18:33] WARN High memory usage detected
[1990-08-09 12:18:38] INFO Service restarted
[1990-08-09 12:18:40] WARN High memory usage detected
[1990-08-09 12:18:50] DEBUG System check complete
[1990-08-09 12:18:56] DEBUG System check complete
[1990-08-09 12:19:04] DEBUG Cache cleared
[1990-08-09 12:19:13] WARN Disk space low
[1990-08-09 12:19:23] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:19:29] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:19:32] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:19:36] ERROR Connection lost
[1990-08-09 12:19:45] WARN Disk space low
[1990-08-09 12:19:50] WARN Disk space low
[1990-08-09 12:19:54] INFO User logged in
[1990-08-09 12:20:01] INFO Scheduled task run
```

er staan dus in de logs een aantal foutmeldingen en waarschuwingen, maar er zijn ook een paar lijnen die beginnen met "INFO FLAGPART:" gevolgd door een stukje van de flag. Deze lijnen lijken erg relevant te zijn voor het oplossen van de challenge, aangezien ze direct verwijzen naar delen van de flag.

### Stap 4

nu ga ik proberen om alle lijnen die beginnen met "INFO FLAGPART:" te filteren uit de log file, zodat ik alleen de relevante stukjes van de flag overhoud.

#### Waarom probeerde ik dit?

om de relevante stukjes van de flag te isoleren en te verzamelen, zodat we ze in de juiste volgorde kunnen zetten om de volledige flag te reconstrueren.

en we niet steeds door de hele log file moeten scrollen om de relevante stukjes te vinden. ( 2348 lijnen is nogal veel om handmatig te doorzoeken )

#### Tool

grep is een krachtige tool die we kunnen gebruiken om specifieke patronen te zoeken in tekstbestanden, en het is perfect voor deze taak omdat we alleen de lijnen willen hebben die beginnen met "INFO FLAGPART:".

#### comando's

```bash
grep "INFO FLAGPART:" server.log
```

#### resultaat

```log
[1990-08-09 10:00:10] INFO FLAGPART: picoCTF{us3_
[1990-08-09 10:02:55] INFO FLAGPART: y0urlinux_
[1990-08-09 10:05:54] INFO FLAGPART: sk1lls_
[1990-08-09 10:05:55] INFO FLAGPART: sk1lls_
[1990-08-09 10:10:54] INFO FLAGPART: cedfa5fb}
[1990-08-09 10:10:58] INFO FLAGPART: cedfa5fb}
[1990-08-09 10:11:06] INFO FLAGPART: cedfa5fb}
[1990-08-09 11:04:27] INFO FLAGPART: picoCTF{us3_
[1990-08-09 11:04:29] INFO FLAGPART: picoCTF{us3_
[1990-08-09 11:04:37] INFO FLAGPART: picoCTF{us3_
[1990-08-09 11:09:16] INFO FLAGPART: y0urlinux_
[1990-08-09 11:09:19] INFO FLAGPART: y0urlinux_
[1990-08-09 11:12:40] INFO FLAGPART: sk1lls_
[1990-08-09 11:12:45] INFO FLAGPART: sk1lls_
[1990-08-09 11:16:58] INFO FLAGPART: cedfa5fb}
[1990-08-09 11:16:59] INFO FLAGPART: cedfa5fb}
[1990-08-09 11:17:00] INFO FLAGPART: cedfa5fb}
[1990-08-09 12:19:23] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:19:29] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:19:32] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:23:43] INFO FLAGPART: y0urlinux_
[1990-08-09 12:23:45] INFO FLAGPART: y0urlinux_
[1990-08-09 12:23:53] INFO FLAGPART: y0urlinux_
[1990-08-09 12:25:32] INFO FLAGPART: sk1lls_
[1990-08-09 12:28:45] INFO FLAGPART: cedfa5fb}
[1990-08-09 12:28:49] INFO FLAGPART: cedfa5fb}
[1990-08-09 12:28:52] INFO FLAGPART: cedfa5fb}
```

nu zien we dat we al veel minder lijnen hebben om door te zoeken, en dat er duidelijk drie verschillende stukjes van de flag zijn die herhaald worden in de logs. We kunnen deze stukjes nu verzamelen en in de juiste volgorde zetten om de volledige flag te reconstrueren.

#### Stap 5

om dit nog fraaier te maken kunnen we ook nog alle duplicaten verwijderen zodat we alleen unieke stukjes van de flag overhouden.

#### Waarom probeerde ik dit?

om de relevante stukjes van de flag te isoleren en te verzamelen, zodat we ze in de juiste volgorde kunnen zetten om de volledige flag te reconstrueren, zonder dat we steeds dezelfde stukjes tegenkomen.

#### Tool

uniq is een handige tool die we kunnen gebruiken om dubbele lijnen te verwijderen uit de output van grep, zodat we alleen unieke stukjes van de flag overhouden.

#### comando's

```bash
grep "INFO FLAGPART:" server.log | uniq
```

#### resultaat

```log
[1990-08-09 10:00:10] INFO FLAGPART: picoCTF{us3_
[1990-08-09 10:02:55] INFO FLAGPART: y0urlinux_
[1990-08-09 10:05:54] INFO FLAGPART: sk1lls_
[1990-08-09 10:05:55] INFO FLAGPART: sk1lls_
[1990-08-09 10:10:54] INFO FLAGPART: cedfa5fb}
[1990-08-09 10:10:58] INFO FLAGPART: cedfa5fb}
[1990-08-09 10:11:06] INFO FLAGPART: cedfa5fb}
[1990-08-09 11:04:27] INFO FLAGPART: picoCTF{us3_
[1990-08-09 11:04:29] INFO FLAGPART: picoCTF{us3_
[1990-08-09 11:04:37] INFO FLAGPART: picoCTF{us3_
[1990-08-09 11:09:16] INFO FLAGPART: y0urlinux_
[1990-08-09 11:09:19] INFO FLAGPART: y0urlinux_
[1990-08-09 11:12:40] INFO FLAGPART: sk1lls_
[1990-08-09 11:12:45] INFO FLAGPART: sk1lls_
[1990-08-09 11:16:58] INFO FLAGPART: cedfa5fb}
[1990-08-09 11:16:59] INFO FLAGPART: cedfa5fb}
[1990-08-09 11:17:00] INFO FLAGPART: cedfa5fb}
[1990-08-09 12:19:23] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:19:29] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:19:32] INFO FLAGPART: picoCTF{us3_
[1990-08-09 12:23:43] INFO FLAGPART: y0urlinux_
[1990-08-09 12:23:45] INFO FLAGPART: y0urlinux_
[1990-08-09 12:23:53] INFO FLAGPART: y0urlinux_
[1990-08-09 12:25:32] INFO FLAGPART: sk1lls_
[1990-08-09 12:28:45] INFO FLAGPART: cedfa5fb}
[1990-08-09 12:28:49] INFO FLAGPART: cedfa5fb}
[1990-08-09 12:28:52] INFO FLAGPART: cedfa5fb}
```

we zien dat we dezelfde ouput hebben als de vorige stap.

#### oorzaak

dit komt omdat de timestamps in de log file verschillen voor elke lijn, waardoor uniq deze lijnen niet als duplicaten beschouwt, zelfs als de inhoud van de flagpart hetzelfde is. Om dit op te lossen, zouden we eerst de timestamps moeten verwijderen of negeren voordat we uniq toepassen, zodat we alleen naar de inhoud van de flagpart kijken.

#### Stap 6

om dit op te lossen kunnen we eerst de timestamps verwijderen uit de output van grep, zodat we alleen de inhoud van de flagpart overhouden, en daarna kunnen we uniq toepassen om de duplicaten te verwijderen.

#### Waarom probeerde ik dit?

dit om te vermijden dat de timestamps ervoor zorgen dat uniq de lijnen niet als duplicaten beschouwt, en om ervoor te zorgen dat we alleen naar de inhoud van de flagpart kijken bij het verwijderen van duplicaten.

#### Tool

awk is een krachtige tool die we kunnen gebruiken om specifieke delen van de tekst te extraheren, en we kunnen het gebruiken om de timestamps te verwijderen uit de output van grep.

#### comando's

```bash
grep "INFO FLAGPART:" server.log | awk -F "INFO FLAGPART: " '{print $2}' | uniq
```

`grep` = filtert de lijnen die beginnen met "INFO FLAGPART:"
 `awk -F "INFO FLAGPART: " '{print $2}'` = splitst de lijn op basis van "INFO FLAGPART: " en print het tweede deel, wat de inhoud van de flagpart is

- F staat voor field, en -F geeft aan dat we willen splitsen op "INFO FLAGPART: "
- {print $2} geeft aan dat we het tweede veld willen printen, wat de inhoud van de flagpart is
  
`uniq` = verwijdert de duplicaten uit de output

#### resultaat

```log
picoCTF{us3_
y0urlinux_
sk1lls_
cedfa5fb}
picoCTF{us3_
y0urlinux_
sk1lls_
cedfa5fb}
picoCTF{us3_
y0urlinux_
sk1lls_
cedfa5fb}
```

we zien nu dat we alleen de relevante stukjes van de flag overhouden, zonder de timestamps, en dat we nog steeds duplicaten hebben. We kunnen nu deze stukjes in de juiste volgorde zetten om de volledige flag te reconstrueren.

#### oorzaak

dit komt omdat uniq enkel de opeenvolgende lijnen vergelijkt op duplicaten en in dit geval hebben we meerdere groepen van dezelfde stukjes van de flag die niet opeenvolgend zijn, waardoor uniq ze niet als duplicaten beschouwt. Om dit op te lossen, zouden we eerst de output moeten sorteren voordat we uniq toepassen, zodat alle dezelfde stukjes van de flag bij elkaar komen te staan en uniq ze als duplicaten kan herkennen.

#### Stap 7

om dit op te lossen kunnen we eerst de output sorteren voordat we uniq toepassen, zodat alle dezelfde stukjes van de flag bij elkaar komen te staan en uniq ze als duplicaten kan herkennen.

#### Waarom probeerde ik dit?

dit om ervoor te zorgen dat alle dezelfde stukjes van de flag bij elkaar komen te staan, zodat uniq ze als duplicaten kan herkennen en verwijderen.

#### Tool

sort is een handige tool die we kunnen gebruiken om de output te sorteren, zodat alle dezelfde stukjes van de flag bij elkaar komen te staan.

#### comando's

```bash
grep "INFO FLAGPART:" server.log | awk -F "INFO FLAGPART: " '{print $2}' | sort | uniq
of
grep "INFO FLAGPART:" server.log | awk -F "INFO FLAGPART: " '{print $2}' | sort -u
```

#### resultaat

```log
cedfa5fb}
picoCTF{us3_
sk1lls_
y0urlinux_
```

we zien nu dat we alleen de unieke stukjes van de flag overhouden, zonder de timestamps, en dat we ze in een gesorteerde volgorde hebben. We kunnen nu deze stukjes in de juiste volgorde zetten om de volledige flag te reconstrueren.

we zien in de vorige stap hoe ze moeten staan in de flag, namelijk `picoCTF{us3_y0urlinux_sk1lls_cedfa5fb}` en dit is ook de volledige flag die we kunnen indienen om deze challenge op te lossen.

#### technische uitleg

men wil hier vooral aantonen dat als men goed met regexp en command line tools kan werken,
men in staat is om relevante informatie te filteren uit grote hoeveelheden data, en dat men in staat is om deze informatie te verzamelen en in de juiste volgorde te zetten om een flag te reconstrueren. Dit is een belangrijke vaardigheid in cybersecurity, omdat het vaak nodig is om grote hoeveelheden data te analyseren en relevante informatie te extraheren om kwetsbaarheden te identificeren of aanvallen te detecteren.

#### analyse

hier word duidelijk dat men zeer goed moet opletten naar wat de machine verteld en dat gefragmenteerde data toch iets kan vertellen.

dat het fragmenteren van info of dergelijke niet perse een oplossing is maar wel voor extra stappen kan zorgen waar mensen met slechte bedoelingen kunnen struikelen, maar dat het ook een manier kan zijn om mensen te testen op hun vaardigheden in het analyseren van data en het vinden van relevante informatie.

![screenshot](../assets/log%20hunt.png)
