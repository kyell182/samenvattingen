# Cybersecurity & Nmap Studiegids

## Wat is Nmap (Network Mapper)?

**Nmap** is een gratis, open-source utility voor netwerkdetectie en beveiligingsaudits. Het is ontworpen om snel grote netwerken te scannen, maar werkt ook goed tegen single hosts.

Nmap gebruikt ruwe IP-pakketten op innovatieve manieren om de volgende eigenschappen van een netwerk te bepalen:

* Welke **hosts** beschikbaar zijn op het netwerk.
* Welke **services** (applicatienaam en versie) deze hosts aanbieden.
* Welke **besturingssystemen** (en OS-versies) ze draaien.
* Welk type **pakketfilters/firewalls** in gebruik zijn.
* Tientallen andere netwerkkenmerken.

---

## Cyberaanvallen

Een **cyberaanval** is een poging om schade aan te richten aan een computersysteem, netwerk of digitale informatie.

### Aanvalsvectoren

Aanvallen worden vaak uitgevoerd via of gericht op:

* Mensen
* Computers
* Telefoons
* Applicaties
* Boodschappen (berichten/communicatie)
* Systeemprocessen

### Doelen van aanvallen

* Informatie verzamelen.
* Data en processen versleutelen en losgeld vragen (ransomware).
* Cruciale informatie verwijderen.
* Informatie stelen.
* Informatie publiek maken.
* Systemen onbruikbaar maken.

### Typen aanvallen

| Type Aanval | Omschrijving | Voorbeelden |
| :--- | :--- | :--- |
| **Passieve aanvallen** | Gericht op het verzamelen van informatie of inbreken zonder directe schade of wijzigingen aan te brengen. | *Traffic sniffing*, *port scanning* |
| **Actieve aanvallen** | Gericht op het daadwerkelijk toebrengen van schade, misbruik of het aanpassen van systemen. | Malware, DDoS-aanvallen |

> **Slowloris:** Een specifieke actieve aanval waarbij een verbinding met een server open wordt gehouden zonder data te versturen. Hierdoor blijven de resources van de server bezet, waardoor deze uiteindelijk onbruikbaar wordt voor legitieme gebruikers.

### Rollen en Typen Hackers

| Team / Type | Definitie |
| :--- | :--- |
| **Red team** | De aanvallers (simuleren van echte cybercriminele tactieken). |
| **Blue team** | De verdedigers (beveiligen, detecteren en reageren op incidenten). |
| **White hat hackers** | Ethische hackers die alleen goede dingen doen *met* expliciete toestemming. |
| **Grey hat hackers** | Hackers die vaak goede bedoelingen hebben, maar kwetsbaarheden opsporen *zonder* voorafgaande toestemming. |
| **Black hat hackers** | Kwaadaardige hackers die systemen binnendringen voor eigen gewin of om schade aan te richten. |

---

## Verdedigingsmethoden & Pijlers

### Verdedigingsmethoden

Om netwerken en systemen te beschermen tegen aanvallen, worden de volgende methoden ingezet:

* Firewalls
* Antivirussoftware
* Intrusion Detection Systems (IDS)
* Intrusion Prevention Systems (IPS)
* Regelmatige software-updates
* Gebruik van sterke wachtwoorden
* Educatie en bewustwording van gebruikers (security awareness)
* Netwerksegmentatie
* Encryptie van data (zowel in rust als in transit)
* Back-ups maken van belangrijke data
* Monitoring en logging van netwerkactiviteiten

### Pijlers van Cybersecurity (De CIA-triade & aanvullingen)

De basis van informatiebeveiliging rust op de **CIA-triade**, vaak aangevuld met drie andere cruciale concepten:

| Pijler | Nederlandse term | Definitie |
| :--- | :--- | :--- |
| **Confidentiality** | Vertrouwelijkheid | Zorgen dat informatie alleen toegankelijk is voor degenen die er recht op hebben. |
| **Integrity** | Integriteit | Zorgen dat informatie accuraat en volledig is, en niet ongeautoriseerd wordt gewijzigd. |
| **Availability** | Beschikbaarheid | Zorgen dat informatie en systemen direct beschikbaar zijn wanneer ze nodig zijn. |
| **Non-repudiation** | Onweerlegbaarheid | Zorgen dat een partij niet kan ontkennen dat ze een bepaalde actie (zoals een transactie of bericht) hebben uitgevoerd. |
| **Authentication** | Authenticatie | Het proces van het verifiëren van de identiteit van een gebruiker, apparaat of systeem voordat toegang wordt verleend. |
| **Authorization** | Autorisatie | Het bepalen van de specifieke toegangsrechten en privileges van een reeds geauthenticeerde entiteit. |

---

## Malware (Malicious Software)

Malware is een verzamelnaam voor software die specifiek is ontworpen om schade aan te richten aan computersystemen, netwerken of gebruikers.

### Componenten van Malware

1. **Payload:** De daadwerkelijke kwaadaardige code die de schade aanricht of het einddoel bereikt (bijv. data stelen of bestanden versleutelen).
2. **Propagation mechanism:** De methode of het mechanisme waarmee de malware zich verspreidt (bijv. via e-mailbijlagen, netwerkverbindingen of geïnfecteerde websites).
3. **Command and Control (C&C) server:** Een externe server die door de aanvaller wordt beheerd om instructies naar de malware te sturen of gestolen gegevens te ontvangen.

### Soorten Malware

| Type | Definitie en Kenmerken |
| :--- | :--- |
| **Virus** | Kwaadaardige software die zich hecht aan legitieme bestanden of programma's en activeert/verspreidt wanneer deze bestanden worden uitgevoerd. |
| **Worm** | Zelfstandige malware die geen hostbestand nodig heeft en zich autonoom via netwerken kan verspreiden om systemen te overbelasten. |
| **Trojaans paard** | Malware die zich voordoet als legitieme, nuttige software om gebruikers te misleiden en zo toegang te krijgen tot het systeem. |
| **Ransomware** | Gijzelsoftware die vitale bestanden versleutelt en losgeld (ransom) eist van het slachtoffer om de decriptiesleutel te verkrijgen. |
| **Spyware** | Software ontworpen om stiekem informatie over een gebruiker of systeem te verzamelen (zoals wachtwoorden en surfgedrag) zonder toestemming. |
| **Adware** | Software die ongevraagd advertenties weergeeft op een apparaat, vaak gekoppeld aan het verzamelen van gebruikersdata. |
| **Backdoor** | Een verborgen toegangspunt in een systeem of applicatie waarmee aanvallers de normale authenticatie omzeilen voor ongeautoriseerde toegang. |
| **Botnet** | Een netwerk van geïnfecteerde computers ("bots") die centraal worden aangestuurd via een C&C-server voor grootschalige aanvallen zoals DDoS. |

---

## Beperkingsstrategieën (Mitigation Strategies)

Bij het beheren van cyberrisico's worden drie hoofdstrategieën gehanteerd:

* **Preventie:** Maatregelen nemen om te voorkomen dat aanvallen überhaupt kunnen plaatsvinden.
  * *Voorbeelden:* Firewalls, antivirus, patches, sterke wachtwoorden.
* **Detectie:** Het continu monitoren van systemen en netwerken om lopende verdachte activiteiten of inbreuken direct te identificeren.
  * *Voorbeelden:* Intrusion Detection Systems (IDS), loganalyse.
* **Recovery (Herstel):** Het herstellen van systemen, processen en gegevens na een succesvolle aanval om de schade te minimaliseren.
  * *Voorbeelden:* Back-ups terugzetten, incident response plannen activeren, forensisch onderzoek.

---

## Phishing-aanvallen

| Type Phishing | Doelgroep en Kenmerken |
| :--- | :--- |
| **Phishing** | De algemene, brede term voor online oplichting waarbij aanvallers zich voordoen als betrouwbare instanties om gevoelige gegevens (wachtwoorden, creditcards) te stelen via e-mail, sms, social media of telefoon. |
| **Spear phishing** | Een zeer gerichte aanval waarbij de communicatie specifiek is gepersonaliseerd voor één individu of organisatie op basis van verzamelde voorkennis. |
| **Whaling** | Een specifieke vorm van spear phishing die zich exclusief richt op hooggeplaatste personen binnen een organisatie, zoals CEO's of CFO's. |

---

## De Cybersecurity Kill Chain

De Cyber Kill Chain beschrijft de opeenvolgende fasen die een aanvaller moet doorlopen om een succesvolle inbreuk te plegen:

1. **Reconnaissance (Verkenning):** De aanvaller verzamelt informatie over het doelwit (netwerkinfrastructuur, softwareversies, kwetsbaarheden).
2. **Weaponization (Wapening):** De aanvaller koppelt een exploit (misbruikcode) aan een payload (malware) om een digitaal wapen te maken.
3. **Delivery (Aflevering):** Het digitale wapen wordt overgebracht naar het doelwit (bijv. via een phishing-mail, geïnfecteerde usb-stick of website).
4. **Exploitation (Misbruik):** De kwaadaardige code wordt geactiveerd en misbruikt een specifieke kwetsbaarheid in het systeem van het doelwit.
5. **Installation (Installatie):** De malware installeert zich op het systeem om permanente toegang (persistence) te garanderen.
6. **Command and Control (C&C):** De geïnstalleerde malware opent een communicatiekanaal naar de externe server van de aanvaller voor verdere instructies.
7. **Actions on Objectives (Acties op doelen):** De aanvaller voert zijn uiteindelijke doel uit (bijv. data exfiltreren, bestanden vernietigen of ransomware activeren).

> **Incident Response:** Dit is het verdedigingsproces dat parallel loopt aan de Kill Chain. Het omvat het detecteren, analyseren, isoleren (containment), herstellen en evalueren van een beveiligingsincident om de impact te minimaliseren en herhaling te voorkomen.

---

## Nmap in de Praktijk

### Poortstatussen binnen Nmap

Wanneer Nmap een poort scant, kan deze drie primaire statussen teruggeven:

* **Open:** Er draait een applicatie op de poort die actief luistert naar verbindingen.
* **Closed:** De poort is bereikbaar, maar er luistert momenteel geen applicatie op.
* **Filtered:** Nmap kan niet bepalen of de poort open of gesloten is omdat een firewall of pakketfilter de scansignalen blokkeert.

Nmap kan naast poortscans ook ingezet worden voor:

* **Service detectie:** Achterhalen welke applicatieversie er op een poort draait.
* **OS fingerprinting:** Het identificeren van het besturingssysteem van de target.
* **Scripting:** Automatiseren van geavanceerde scans middels de Nmap Scripting Engine (NSE).

### Veelgebruikte Commando's en Syntax

```bash
# Scan een subnetwerk zonder DNS-resolutie uit te voeren (-n)
nmap 192.168.189.2/24 -n

# Ping scan (-sn) op het targetnetwerk met extra details (-v) en sla de output op in alle 3 de formaten (-oA tnet) zonder DNS-resolutie (-n)
nmap -sn -oA tnet -v 192.168.189.0/24 -n

# Ping scan (-sn) op een netwerk met expliciete ICMP Echo Requests (-PE) inclusief een packet trace (--packet-trace)
sudo nmap 192.168.189.0/24 -sn -PE --packet-trace

# Ping scan (-sn) op een netwerk waarbij de standaard ARP-pings worden uitgeschakeld (--disable-arp-ping)
sudo nmap 192.168.189.0/24 -sn --disable-arp-ping 

# Scan een specifieke host op de top 10 meest voorkomende poorten (--top-ports=10)
nmap 192.168.189.4 --top-ports=10

# Scan een host op specifiek gedefinieerde poorten (-p)
nmap 192.168.189.4 -p 22,25,80,139,445

# Scan een host op een specifieke poortrange (-p)
nmap 192.168.189.4 -p 22-445

# Scan een host op ALLE (65535) mogelijke TCP-poorten (-p-)
nmap 192.168.189.4 -p- 

# Scan specifiek poort 443 met packet trace, zonder voorafgaande ping/host-discovery (-Pn) en zonder DNS-resolutie (-n)
nmap 192.168.189.4 -p 443 --packet-trace -Pn -n 

# Voer een TCP Connect scan uit (-sT) (maakt de volledige 3-way handshake af)
nmap 192.168.189.4 -sT

# Voer een TCP SYN / Stealth scan uit (-sS) met een maximum van 1 herlooppoging (--max-retries 1)
nmap 192.168.189.4 -sS --max-retries 1

# Voer een snelle (-F) UDP-scan (-sU) uit op de meest voorkomende UDP-poorten
nmap -sU -F 

# Voer een UDP-scan (-sU) uit op de top 100 belangrijkste UDP-poorten
nmap 192.168.189.4 -sU --top-ports=100

# Scan de top 10 poorten zonder DNS-resolutie (-n)
nmap 192.168.189.4 --top 10 -n

# Scan de top 10 poorten inclusief service- en versiedetectie (-sV) zonder DNS-resolutie (-n)
nmap 192.168.189.4 --top 10 -n -sV

# Scan poort 80 met versiedetectie (-sV), zonder DNS-resolutie (-n), negeer host discovery (-Pn) met packet-trace
nmap 192.168.189.4 -p 80 -sV -n -Pn --packet-trace

# Zet handmatig een Netcat-verbinding op naar poort 25 (verbose en numeriek zonder DNS)
nc -nv 192.168.189.4 25
```

### Besturingssysteemindicatie via TTL (Time To Live)

Tijdens het scannen of pingen kan de standaard TTL-waarde in de IP-header een sterke indicatie geven van het achterliggende OS:

* **Windows systemen:** Standaard TTL = `128`
* **Linux/Unix systemen:** Standaard TTL = `64`
* **Cisco routers:** Standaard TTL = `255`
