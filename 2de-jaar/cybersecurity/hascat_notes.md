# Handige uitleg — Hashcat & cryptografie (uitgebreid)

Dit document legt kort en toch iets uitgebreider uit wat je echt moet begrijpen voor studie: waarom methodes werken, wanneer je ze gebruikt en concrete voorbeelden.

> Waarschuwing: gebruik Hashcat of wachtwoordkraaktools alleen op systemen waarvoor je toestemming hebt. Het ongevraagd kraken van wachtwoorden is illegaal.

## 1. Wat is cryptografie?

Cryptografie is de wetenschap van het veilig maken van informatie. Praktisch betekent dat:

- Vertrouwelijkheid: alleen bevoegden lezen de data (encryptie).
- Integriteit: je kunt controleren of data niet gewijzigd is (hashes, MACs).
- Authenticatie: je kunt bewijzen wie iets heeft verstuurd (digitale handtekeningen).

Kort voorbeeld:

bij e-mail wil je dat alleen de ontvanger kan lezen (vertrouwelijkheid), dat het bericht niet gewijzigd is (integriteit) en dat je zeker weet wie het stuurde (authenticatie).

## 2. Basis: substitutie (Caesar)

Substitutie is het simpelste voorbeeld:

elke letter wordt vervangen of verschoven. Caesar-cijfer verschuift het alfabet (shift 3: A→D). Dit illustreert het idee van een sleutel (de shift), maar is makkelijk te kraken (frequentieanalyse).

## 3. Encryptie: symmetrisch vs asymmetrisch

- Symmetrisch:
  - Zelfde sleutel voor encryptie en decryptie.
  - Snel en geschikt voor grote data (bv. AES voor bestanden/verbindingen).
  - Nadeel: sleuteluitwisseling (hoe deel je de geheime sleutel veilig?).
  - Voorbeeld: twee partijen delen tevoren een AES-sleutel en gebruiken die om bestanden te versleutelen.

- Asymmetrisch:
  - Publieke en private sleutel. Publieke sleutel kan iedereen gebruiken om te versleutelen; alleen eigenaar met private sleutel kan ontsleutelen.
  - Handig voor sleuteluitwisseling en digitale handtekeningen (bv. RSA, ECC).
  - Voorbeeld: verzender gebruikt jouw publieke sleutel om een bericht te versleutelen; alleen jij kunt het ontcijferen met je private sleutel.

Praktisch:

moderne systemen combineren beide (hybride): asymmetrisch om een symmetrische sessiesleutel veilig te delen, symmetrisch voor de datastroom.

## 4. Hashfuncties — wat en waarom

Een hashfunctie neemt willekeurige input en geeft een vaste-lengte output (digest). Kenmerken:

- Deterministisch: dezelfde input → dezelfde hash.
- Eénrichtingsfunctie: van hash terug naar input is praktisch onmogelijk.
- Botsingsresistent: moeilijk twee verschillende inputs te vinden met dezelfde hash.

Gebruik:

- Wachtwoordopslag (hash + salt).
- Integriteitscontrole (bestandshashes).

Voorbeeld: SHA‑256 geeft een 256‑bit (32 byte) hex-string zoals:

$$
    \text{SHA256}('wachtwoord') = \text{e3b0c44298fc1c149...}  \quad(verkort)
$$

MD5 produceert kortere hashes maar is kwetsbaar voor botsingen; gebruik SHA‑2/3 of een KDF (bcrypt, scrypt) voor wachtwoorden.

## 5. Digitale handtekeningen (kort)

Proces:

1. Hash het bericht.
2. Onderteken die hash met je private sleutel (sign).
3. Ontvanger verifieert met je publieke sleutel.

Zo garandeer je zowel authenticatie (wie het stuurde) als integriteit (niet gewijzigd).

## 6. Hash -> username koppelen (praktisch overzicht)

- Een hash bevat meestal geen username; koppelen gebeurt als je een dataset hebt met `username:hash`.
- Methoden om wachtwoorden te achterhalen (voor herstel/legale tests):

  - Brute force: alle combinaties proberen (tijdrovend).
  - Dictionary: woordlijsten zoals `rockyou.txt` gebruiken.
  - Mask / mask attack: gerichte brute force (bv. `?d?d?d?d` voor 4 cijfers).
  - Rules: transformaties op woordenlijsten (bv. hoofdletters, cijfers toevoegen).

Bescherming: gebruik altijd `salt` + KDF (bcrypt/scrypt/PBKDF2) en voldoende iteraties.

## 7. Hashcat: uitleg en voorbeelden

Hashcat is een krachtige tool om hashes te testen/kraken bij security-audits. Belangrijkste opties:

- `-m <mode>`: hash type (0 = MD5, 100 = SHA1, 1400 = SHA256, etc.).
- `-a <attack>`: aanvalstype (0=dictionary, 3=mask, 6=hybrid word+mask, 7=mask+word).
- `-r <rules>`: pas rules toe op woordenlijst (bv. capitalize, append digits).
- `-O`: optimized kernel (sneller, minder flexibel).
- `-i`: increment (voor mask attacks; groeit lengte tussen min/max).

Voorbeelden met uitleg (Windows-commando's):

```bash
# Mask: 4 cijfers (bv. PIN 0000-9999)
.\hashcat.exe -m 0 -a 3 .\example0.hash ?d?d?d?d

# Mask: 5 kleine letters (alle combinaties van a-z length 5)
.\hashcat.exe -m 0 -a 3 .\example0.hash ?l?l?l?l?l

# Increment: probeer alle mask-lengtes tussen min en max
.\hashcat.exe -m 0 -a 3 .\example0.hash ?l?l?l? -i

# Dictionary (rockyou) tegen MD5-hashes, geoptimaliseerd
.\hashcat.exe -m 0 -a 0 .\example0.hash .\rockyou.txt -O

# Dictionary + suffix (append 4 digits) — hybrid attack
.\hashcat.exe -m 0 -a 6 .\example0.hash .\rockyou.txt ?d?d?d?d -i

# Rules: pas dive.rule toe op rockyou
.\hashcat.exe -m 0 -a 0 -r .\rules\dive.rule .\example0.hash .\rockyou.txt -O

# Custom charset voorbeeld: -1 definieert set 1 als letters+digits
.\hashcat.exe -m 0 -a 3 -1 ?l?d .\example0.hash ?1?1?1?1?1?1?1 -i
```

Legenda korte samenvatting:

- `?l` = lowercase letters
- `?u` = uppercase
- `?d` = digits
- `?s` = special characters
- `-i` = increment (groepeer mask lengte)
- `-O` = gebruik snelle kernel (minder compatibel op sommige hardware)

Belangrijk: kies altijd de juiste `-m` (hashtype). Foute modus geeft geen resultaten en kost tijd.

### hashcat.potfile

Het `hashcat.potfile` bevat `hash:plaintext` regels voor elk succesvol gekraakt item — handig om resultaten te bewaren en later te raadplegen.

## 8. Kort: NT AUTHORITY, Hak5, CA

- `NT AUTHORITY`: Windows systeempseudo-account voor services (bv. `SYSTEM`). Niet te verwijderen.
- `Hak5`: community en bedrijf dat hardware en tutorials maakt voor pentesting (educatief).
- `CA` (Certificate Authority): instantie die digitale certificaten uitgeeft voor SSL/TLS; vertrouwen van browsers hangt hiervan af.

---
