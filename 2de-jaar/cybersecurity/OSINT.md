# Internet of Things (IoT) & Social Engineering Studiegids

## 1. Slimme Toestellen (IoT) en Netwerken

### Veelvoorkomende slimme toestellen thuis

* Wasmachines & koelkasten (frigo's)
* Slimme verlichting (lampen)
* Zigbee-netwerken (voor domotica)
* Smartwatches
* Smartphones

### Algemene kwetsbaarheden van IoT-apparaten

| Probleem | Gevolg / Risico |
| :--- | :--- |
| **Geen updates** | Bekende kwetsbaarheden (CVE's) worden niet gepatcht en blijven exploiteerbaar. |
| **Zwakke admin-credentials** | Standaard inloggegevens (zoals `admin`/`admin`) worden zelden gewijzigd door de consument. |
| **Firewall-omzeiling** | Zodra een aanvaller toegang heeft tot één lokaal IoT-apparaat, bevindt deze zich ín het netwerk achter de firewall. |
| **Dataverzameling** | Apparaten verzamelen en versturen continu enorme hoeveelheden (gevoelige) gebruikersdata. |

### Case Study: Printer API Call

Bepaalde printermerken stonden API-calls toe **zonder authenticatie**.

* **Incident:** Een aanvaller kon live netwerkscans bekijken en onderschepte zo 300 ingescande Amerikaanse paspoorten.
* **Risico:** Identiteitsfraude. Met het *Social Security Number (SSN)* op deze paspoorten kon men zonder extra authenticatie inloggen op overheidssites of zelfs vastgoed kopen op andermans naam.

---

## 2. Netwerkbeveiliging: Firewall vs. Mesh

* **Nut van een firewall:** Biedt beveiliging op netwerkniveau. Je kunt centraal op de router een specifieke poort (bijv. 4000) blokkeren, in plaats van dit op elk afzonderlijk apparaat in het netwerk te moeten configureren.
* **Beperking van een mesh-netwerk in deze context:** Een mesh-netwerk of -topologie kan dit soort gecentraliseerde netwerkblokkades omzeilen. 
* **Nadelen van een mesh-netwerk:**
  * **Trager:** Data moet langs of door meerdere nodes gerouteerd worden.
  * **Hoge latency:** Meer hops betekent een hogere vertraging.

---

## 3. Alledaagse Apparaten & Specifieke Risico's

| Apparaat | Aanvalsscenario / Risico |
| :--- | :--- |
| **Laptop** | Een gebruiker downloadt een 'hack' of cheat voor een game. Deze werkt ogenschijnlijk niet, maar opent op de achtergrond een *reverse shell* naar een externe (bijv. Russische) server, waardoor de aanvaller volledige netwerktoegang krijgt. |
| **Smartphone** | Jonge/onkundige familieleden installeren apps of bezoeken onveilige websites, met als gevolg dat de telefoon op de achtergrond continu verbinding maakt (pingt) met tientallen malafide servers. |
| **Smart Speakers** *(Google Home, Apple HomePod)* | Bevatten microfoons die afgeluisterd kunnen worden als ze gecompromitteerd zijn. Er kan ook gevoelige informatie aan opgevraagd worden, zoals de huidige locatie of agenda. |

### Web 4.0, IoT & AI

* **AI-communicatie:** AI-modellen kunnen onderling communiceren via talen/protocollen (bijv. "Gibberlink") die onverstaanbaar zijn voor mensen, maar waarmee ze extreem snel enorme hoeveelheden data kunnen uitwisselen.
* **Medische IoT:** Pacemakers en compacte defibrillatoren zijn ook IoT-devices. Er is een casus waarbij een open poort werd ontdekt op een pacemaker, waardoor een externe partij het apparaat op afstand kon in- en uitschakelen.

---

## 4. Grote Historische Cyberincidenten (IT/OT)

| Incident / Doelwit | Beschrijving & Impact |
| :--- | :--- |
| **OT - Oliebedrijf** | Malware infecteerde het Operationele Technologie (OT) netwerk en overschreef de temperatuurregeling. Dit creëerde acuut explosiegevaar, waardoor een grote omtrek geëvacueerd moest worden. |
| **OT - Iraanse Uraniumverrijking** *(Stuxnet)* | Amerikaanse/Israëlische malware manipuleerde de centrifuges voor uraniumverrijking in Iran. De machines draaiden 3x sneller dan normaal en gingen daardoor fysiek kapot, wat het nucleaire programma stopzette. |
| **IT - WannaCry in Ziekenhuizen** | Veel computers draaiden nog op het verouderde Windows XP. Een *worm* (malware die zich automatisch en zonder user-input verspreidt) installeerde ransomware. Systemen werden onbruikbaar en operaties moesten worden geannuleerd. |

---

## 5. Kali Linux Praktijkoefeningen

### 5.1 OSINT (Open Source Intelligence)

OSINT is het verzamelen van publiekelijk beschikbare informatie over een doelwit.

* **Voordeel:** Het is **niet te detecteren** door het doelwit (in tegenstelling tot een actieve *Nmap*-scan), omdat je alleen publieke bronnen raadpleegt.

### 5.2 TheHarvester

**Concept:** Vaak worden online 'persoonlijkheidsquizzen' (bijv. "Welk Disney karakter ben jij?" of "Wat is de naam van je eerste huisdier?") gebruikt om antwoorden te verzamelen op veelvoorkomende *password recovery* vragen.

**Installatie en gebruik:**
> **BELANGRIJK:** Zet de netwerkadapter van je VM op **NAT** voor deze oefening. Zet deze ná het labo direct terug op *Internal Adapter*.

```bash
# Start de tool
theHarvester

# Voer een zoekopdracht uit naar tesla.com via DuckDuckGo, limiet 100 resultaten, exporteer naar bestand
theHarvester -d tesla.com -b duckduckgo -l 100 -f tesla_duckduckgo

# Tor browser installeren en starten (indien nodig voor anonimiteit)
sudo apt install -y tor torbrowser-launcher
torbrowser-launcher
```

### 5.3 Google Dorking

Het gebruik van geavanceerde zoekoperatoren in Google om specifieke (vaak gevoelige) informatie te filteren.

| Dork Operator | Uitleg / Resultaat |
| :--- | :--- |
| `site:vives.be` | Toont uitsluitend resultaten van het domein vives.be. |
| `site:vives.be intitle:login` | Toont pagina's op vives.be waarbij "login" in de paginatitel staat. |
| `site:vives.be filetype:php` | Zoekt uitsluitend naar `.php` bestanden op het domein. |
| `inurl:config` | Zoekt naar URL's waarin het woord "config" voorkomt. |
| `filetype:pdf "confidential"` | Zoekt naar PDF-bestanden die exact het woord "confidential" bevatten. |
| `filetype:env` of `filetype:sql` | Zoekt naar blootgestelde database-dumps of configuratiebestanden. |
| `filetype:log "password" "username"` | Zoekt naar logbestanden waarin letterlijk de woorden password en username staan. |

### 5.4 SET (Social Engineering Toolkit)

Een framework voor het opzetten van social engineering aanvallen (zoals phishing).

* Start het programma via: `sudo setoolkit`

**Oefening A: Credential Harvester (Phishing site)**

1. Kies in het hoofdmenu optie **1** (Social-Engineering Attacks).
2. Kies optie **2** (Website Attack Vectors).
3. Kies optie **3** (Credential Harvester Attack Method).
4. Kies optie **2** (Site Cloner).
5. Druk op `Enter` als je luister-IP (jouw IP) klopt.
6. Open een browser, ga naar een inlogpagina (bijv. de Bpost login) en kopieer de URL.
7. Plak deze URL in de SET-terminal en druk op Enter.
8. Navigeer op je eigen machine naar `http://localhost:80`.
9. Log in met valse gegevens en observeer hoe de inloggegevens plain-text in je terminal verschijnen.

**Oefening B: Malicious QR-code**

1. Kies in het hoofdmenu optie **1**.
2. Kies optie **8** (QRCode Generator Attack Vector).
3. Geef een misleidende URL op (bijv. `bp0st.be`).
4. De tool genereert nu een kwaadaardige QR-code die doorlinkt naar je nagemaakte site.

**Clean-up (SET resetten)**
Als je de gegenereerde website wilt verwijderen en SET wilt herstarten, voer je deze commando's uit:

```bash
sudo rm -rf /root/.set
sudo rm -rf /var/www/html/*
```

### 5.5 Case: Hoe val je VIVES aan via OSINT?

**Scenario:** Je hebt geen fysieke toegang tot het gebouw en je netwerkrechten zijn ingetrokken.
**Aanpak (Reconnaissance):**

1. Ga naar LinkedIn en zoek op "VIVES".
2. Filter op werknemers op de IT-afdeling.
3. Bekijk hun profielen en vaardigheden (bijv. ze vermelden *Proxmox*, *MariaDB*, *Cisco*).
4. Nu weet je welke infrastructuur er hoogstwaarschijnlijk draait, en kun je gericht gaan zoeken naar CVE's en exploits voor deze specifieke technologieën.
