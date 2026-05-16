
# PicoCTF Challenge Rapport : riddle registery

---

# 1. Challenge-informatie

**Naam challenge:**  Riddle Registry
**Categorie:** Forensics
**Difficulty:** Easy
**PicoCTF platform:** picoCTF  
**Datum opgelost:**  28/2/26
**PicoCTF username:**  kyell182

## Probleemstelling

een pdf file met onsamenhangende data.
ergens in die data zit een verborgen flag in de meta data.

Voorbeeld structuur:

- Welke bestanden / service krijg je?
  - Hidden Confidential Document
- hints?
  - Don't Be fooled by the visible text; It’s just a decoy!
  - Look beyond the surface for hidden clues
- Wat is het doel?
  - in de meta data de verborgen vlag vinden
- Wat moet uiteindelijk gevonden worden?
  - de verstopte flag

---

## 2. Eerste Analyse (Reconnaissance)

Beschrijf wat je eerst onderzocht voordat je tools begon te gebruiken.

hoe kan ik meta data bekijken van bestanden ?

- met de windows eigenschap tool kan je niet veel meta data bekijken
- exiftool is een programma die zou werken ( is wel een terminal programma mischien te ingewikkeld voor wat we maar moeten weten )
- https://exiftools.com/nl ( is een web versie hiervan )
is er iets in de pdf file waar ik info kan uithalen
- de redacted stukken kan je kopieren en plakken om te zien wat er staat?
is het veilig om het bestand te openen?

### Observaties

- Wat zie je onmiddellijk?
  - het is een pdf file die 178 kb groot is.
  - de naam van de file is Hidden Confidential Document.pdf wat zeer aanlokkelijk is om te openen.

### Hypothese 1

Wat denk je dat de challenge mogelijk probeert te testen?

> hoe we verborgen data kunnen vinden in bestanden, en hoe we deze kunnen analyseren.

---

## 3. Onderzoek en Stappenplan (Volledig Denkproces)

### Stap 1

- ik hb de file eerst gecopieerd naar de online webshell van picoCTF zodat ik er veilig mee kon werken zonder risico te lopen op malware of virussen.

#### Waarom probeerde ik dit?

het is veiliger om de file te manipuleren in een gecontroleerde omgeving, vooral als het bestand afkomstig is van een onbekende bron. Door het bestand te openen in een webshell van picoCTF, kon ik voorkomen dat eventuele schadelijke code op mijn eigen systeem zou worden uitgevoerd.

#### Tool

pico ctf webshell

#### comando's

```bash
wget https://challenge-files.picoctf.net/c_amiable_citadel/570d726d77600d7540c9a8fe7df9e37f4e8b05fafe16f2b316f4a0603dfa7d2f/confidential.pdf
```

### Stap 2

- nu ga ik kijken naar de metadata van de file om te zien of er iets opvalt.
- ik zie dat het idd een pdf is en dat er geen execute rechten op de file zitten.
- de author heeft een zeer vreemde naam die precies als base64 string is gecodeerd. (`cGljb0NURntwdXp6bDNkX20zdGFkYXRhX2YwdW5kIV9mOTQzMDBjNH0=`)

#### Waarom probeerde ik dit?

aangezien de hints aangaven dat we moesten kijken naar verborgen informatie en dat de zichtbare tekst slechts een afleiding was, leek het logisch om te controleren of er meta data in de pdf file zat. De author naam die ik vond was erg verdacht en leek op een gecodeerde string, wat me deed vermoeden dat er iets verborgen was in de meta data.

#### Tool

exiftool is een krachtige tool die veel verschillende soorten meta data kan uitlezen, en het is een goede keuze voor deze challenge omdat het gemakkelijk te gebruiken is en veel informatie kan geven over het bestand.

#### comando's

```bash
exiftool confidential.pdf
```

### Stap 3

- omdat de author name eindigde op = wat typisch is voor base64 strings, besloot ik om deze string te decoderen van base64 naar ascii om te zien of er iets leesbaars uit kwam.

#### Waarom probeerde ik dit?

meestal omzetten we data naar base64 om het te verbergen of om het in een formaat te gieten dat gemakkelijk kan worden overgedragen. Aangezien de author string er verdacht uitzag en eindigde op een = teken, wat vaak voorkomt bij base64 gecodeerde strings, besloot ik om deze te decoderen om te zien of er iets leesbaars uit kwam.

dit is ook het gebruikte formaat om via http data te versturen, dus het is een veelgebruikte methode om verborgen informatie te verbergen.

#### Tool

ik heb de ingebouwde base64 decoder van linux gebruikt, maar er zijn ook online tools beschikbaar die hetzelfde kunnen doen.

#### comando's

```bash
echo "cGljb0NURntwdXp6bDNkX20zdGF0YXRhX2YwdW5kIV9mOTQzMDBjNH0=" | base64 -d
```

echo = neem de string tussen de aanhalingstekens en stuur deze naar de volgende commando via een pipe (|)
base64 -d = decodeer de input van base64 naar ascii (-d staat voor decode)

### Stap 4

- ik heb de author string gedecodeerd van base64 naar ascii en kreeg toen `picoCTF{puzzl3d_m3tadata_f0und!_f94300c4}` wat er uit ziet als een flag.
- deze ingegeven en bleek inderdaad de juiste flag te zijn.

---

#### technische uitleg

we hebben aan de hand van de meta data een zeer verdachte string in de author gevonden wat er precies uitzag als een base64 string. Door deze te decoderen kregen we een leesbare string die er precies uitzag als een flag. Dit bevestigde onze hypothese dat er verborgen informatie in de meta data zat en dat het decoderen van de author string de sleutel was tot het vinden van de flag.

#### analyse

de flag die ik vond in de meta data van de pdf file was inderdaad de juiste oplossing voor deze challenge. Dit bevestigde mijn hypothese dat er verborgen informatie in de meta data zat en dat het decoderen van de author string de sleutel was tot het vinden van de flag.

men kan zich moeilijk voorstellen dat er een bestand is dat er onschuldig uitziet, maar dat eigenlijk schadelijke code bevat die automatisch wordt uitgevoerd wanneer het bestand wordt geopend. Door de rechten van het bestand te controleren, kan je een indicatie krijgen of het bestand mogelijk gevaarlijk is of niet.

men kan ook alle bestanden standaard enkel read en write rechten geven bij het aanmaken van files en dir om te voorkomen dat er per ongeluk schadelijke code wordt uitgevoerd, en om te zorgen dat je altijd bewust toestemming moet geven om een bestand uit te voeren.

maar men zal vooral de gebruiker moeten opleiden en informeren om niet zomaar bestanden te openen van onbekende bronnen en deze al zeker eerst te laten scannen met een antivirus programma voordat ze worden geopend.

maar 100% waterdicht kun je dit niet maken omdat er altijd een menselijke factor is, en mensen kunnen fouten maken of worden misleid door social engineering technieken. Daarom is het belangrijk om een combinatie van technische maatregelen en gebruikerseducatie te hebben om de risico's te minimaliseren.

![flag](../assets/riddle%20registery.png)
