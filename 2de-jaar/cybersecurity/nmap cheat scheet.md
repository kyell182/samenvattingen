# Nmap Cheat Sheet

nmap is een krachtig netwerk scanning tool dat wordt gebruikt voor het ontdekken van hosts en services op een computernetwerk. Hieronder vind je een overzicht van veelgebruikte nmap commando's en hun functies.

## Basis Scans

| Doel           | Commando                       | Wat doet het?             | Uitleg (hoe/waarom)                                                                    |
| -------------- | ------------------------------ | ------------------------- | -------------------------------------------------------------------------------------- |
| Simpele scan   | `nmap 192.168.1.10`            | Scan top 1000 TCP poorten | Nmap gebruikt standaard een TCP SYN scan (als root). Snel overzicht van open services. |
| Meerdere hosts | `nmap 192.168.1.1 192.168.1.2` | Scan meerdere targets     | Handig voor kleine omgevingen of servers apart.                                        |
| Subnet         | `nmap 192.168.1.0/24`          | Scan volledig netwerk     | CIDR-notatie → `/24 = 256 adressen`. Eerst host discovery, dan ports.                  |
| Uit bestand    | `nmap -iL targets.txt`         | Leest targets uit file    | Automatisatie bij grote omgevingen.                                                    |

## flaggen

| Flag | Betekenis |
| ---- | --------- |
| -v   | Verbose modus (meer details) |
| -vv  | Extra verbose (nog meer details) |
| -n   | Geen DNS resolutie (sneller) |
| -R   | Forceer DNS resolutie (langzamer) |
| -sP  | Ping scan (verouderd, gebruik -sn) |
| -sS  | SYN scan (half-open) |
| -sT  | TCP connect scan (volledige handshake) |
| -sU  | UDP scan |
| -sn  | Ping scan (geen port scan) |
| -p   | Poorten specificeren |
| -sV  | Service versie detectie |
| -O   | OS detectie |
| -A   | Aggressieve scan (alles in één) |
| -sC  | Standaard scripts uitvoeren |
| --script | Specifieke NSE scripts draaien |
| -T   | Timing template (T0-T5) |
| -f   | Fragmentatie (splitst pakketten) |
| -D   | Decoy scan (fake IP’s) |
| -S   | Spoofing (vals IP-adres) |
| -oN  | Output in normaal formaat |
| -oX  | Output in XML formaat |
| -oA  | Output in alle formaten (.nmap, .xml, .gnmap) |
| tnet | Target netwerk (bijvoorbeeld 192.168.1.0/24) |
| -PE  | ICMP echo request (ping) |
| --packet-trace | Toont details van verzonden en ontvangen pakketten |

## Scan Types

| Scan         | Commando | Wat doet het?           | Uitleg (technisch)                                                                     |
| ------------ | -------- | ----------------------- | -------------------------------------------------------------------------------------- |
| SYN scan     | `-sS`    | Half-open scan          | Stuurt SYN → krijgt SYN/ACK → stuurt RST. Geen volledige handshake. Sneller & stealth. |
| TCP connect  | `-sT`    | Volledige connectie     | Gebruikt OS connect(). Volledige 3-way handshake. Minder stealth.                      |
| UDP scan     | `-sU`    | UDP poorten scannen     | Geen handshake bij UDP → wacht op ICMP unreachable. Traag.                             |
| Ping scan    | `-sn`    | Alleen hosts detecteren | Geen port scan. Checkt wie online is via ICMP/ARP.                                     |
| Alle poorten | `-p-`    | Scan 1–65535            | Normaal 1000 poorten, hiermee alles.                                                   |
| Stealth scan  | `-sN`    | Null scan               | Stuurt geen flags. Sommige firewalls laten dit door.                                      |
| Xmas scan   | `-sX`    | Stuurt FIN, PSH, URG  | Sommige systemen reageren alleen op deze combinatie.                                        |
| FIN scan    | `-sF`    | Stuurt alleen FIN       | Sommige systemen reageren alleen op deze combinatie.                                        |
| ACK scan    | `-sA`    | Stuurt alleen ACK       | Gebruikt om firewall regels te detecteren.                                                   |

## Poorten specificeren

| Doel        | Commando          | Wat doet het?       | Uitleg                       |
| ----------- | ----------------- | ------------------- | ---------------------------- |
| 1 poort     | `-p 80`           | Scan poort 80       | Handig bij webserver testing |
| Meerdere    | `-p 22,80,443`    | Specifieke lijst    | Comma gescheiden             |
| Range       | `-p 1-1000`       | Poort range         | Vaak bij interne audits      |
| Top poorten | `--top-ports 100` | 100 meest gebruikte | Snelle scan                  |

## Service en OS detectie

| Doel        | Commando          | Wat doet het?       | Uitleg                       |
| ----------- | ----------------- | ------------------- | ---------------------------- |
| 1 poort     | `-p 80`           | Scan poort 80       | Handig bij webserver testing |
| Meerdere    | `-p 22,80,443`    | Specifieke lijst    | Comma gescheiden             |
| Range       | `-p 1-1000`       | Poort range         | Vaak bij interne audits      |
| Top poorten | `--top-ports 100` | 100 meest gebruikte | Snelle scan                  |

## Service & OS detectie

| Functie          | Commando | Wat doet het?                | Uitleg (hoe werkt het)                                          |
| ---------------- | -------- | ---------------------------- | --------------------------------------------------------------- |
| Service detectie | `-sV`    | Detecteert software versie   | Stuurt specifieke probes → vergelijkt met database fingerprints |
| OS detectie      | `-O`     | Detecteert besturingssysteem | Analyseert TCP stack gedrag (TTL, window size, flags)           |
| Aggressief       | `-A`     | Alles combineren             | = `-sV + -O + -sC + traceroute`                                 |

## NSE (Nmap Scripting Engine)

| Doel             | Commando              | Wat doet het?         | Uitleg                               |
| ---------------- | --------------------- | --------------------- | ------------------------------------ |
| Default scripts  | `-sC`                 | Basis scripts         | Checkt bv. SSL, SMB info, HTTP title |
| Specifiek script | `--script http-title` | Draait 1 script       | Geeft webpagina titel terug          |
| Vulnerability    | `--script vuln`       | Kwetsbaarheden zoeken | Gebaseerd op bekende CVE patterns    |
| Script args      | `--script-args`       | Parameters meegeven   | Bijvoorbeeld user/password lists     |
| opzoeken scripts | `--script-help=[script]`       | Lijst beschikbare scripts | Handig om te zien wat er allemaal is |

| soorten scripts | uitleg |
| --------------- | ------ |
| default | basis scripts die vaak nuttige informatie opleveren zonder extra configuratie. |
| safe | scripts die als veilig worden beschouwd en geen schade aan systemen veroorzaken. |
| intrusive | scripts die mogelijk schadelijk kunnen zijn of een systeem kunnen verstoren. |
| vuln | scripts die specifiek gericht zijn op het identificeren van kwetsbaarheden in systemen. |
| auth | scripts die gericht zijn op authenticatie, zoals het testen van zwakke wachtwoorden of het uitvoeren van brute-force aanvallen. |
| brute | scripts die gericht zijn op het uitvoeren van brute-force aanvallen op verschillende protocollen en services. |
| discovery | scripts die gericht zijn op het ontdekken van informatie over het netwerk, zoals het identificeren van hosts, services en netwerktopologie. |
| exploit | scripts die gericht zijn op het uitvoeren van exploits tegen bekende kwetsbaarheden in systemen. |
| dos | scripts die gericht zijn op het uitvoeren van denial-of-service aanvallen tegen systemen. |

## Timing en stealth

| Optie        | Commando   | Wat doet het?     | Uitleg                                 |
| ------------ | ---------- | ----------------- | -------------------------------------- |
| T1           | `-T1`      | Traag             | Minder detecteerbaar                   |
| T4           | `-T4`      | Snel              | Meest gebruikt intern                  |
| Fragmentatie | `-f`       | Splitst pakketten | Probeert firewall detectie te omzeilen |
| Decoys       | `-D RND:5` | Fake IP’s         | IDS ziet meerdere bronnen              |
| Spoofing     | `-S <IP>`  | Vals IP-adres     | Verbergt echte bron                    |

## Output opties

| Formaat | Commando       | Wat doet het?         | Waarom handig               |
| ------- | -------------- | --------------------- | --------------------------- |
| Normaal | `-oN scan.txt` | Tekst output          | Simpel leesbaar             |
| XML     | `-oX scan.xml` | XML bestand           | Voor tools zoals Metasploit |
| Alles   | `-oA scan`     | .nmap + .xml + .gnmap | Complete logging            |

## TCP Logica

**3-way handshake: SYN → SYN/ACK → ACK**

| Stap | Pakket  | Betekenis              |
| ---- | ------- | ---------------------- |
| 1    | SYN     | "Mag ik verbinden?"    |
| 2    | SYN/ACK | "Ja, kom binnen."      |
| 3    | ACK     | "Connectie bevestigd." |

**Verschil**

| Scan | Wat gebeurt er?              |
| ---- | ---------------------------- |
| -sS  | Stopt na stap 2 → stuurt RST |
| -sT  | Voert alle 3 stappen uit     |

## Poort Status Logica

| Status   | Wat betekent het?  | Netwerk gedrag        |
| -------- | ------------------ | --------------------- |
| Open     | Service luistert   | SYN → SYN/ACK         |
| Closed   | Geen service       | SYN → RST             |
| Filtered | Firewall blokkeert | Geen antwoord of ICMP |

## Nmap Tips

- Gebruik `-v` voor meer details tijdens het scannen.
- Combineer opties voor diepgaande scans (bv. `nmap -A -p 80,443`)
- Wees voorzichtig met scans op netwerken die je niet bezit of toestemming hebt, dit kan als illegaal worden beschouwd.
- Gebruik `--reason` om te zien waarom nmap een poort als open/closed/filtered markeert.
- Experimenteer met verschillende timing opties om een balans te vinden tussen snelheid en stealth.
- Gebruik `nmap --script-help` om beschikbare scripts te bekijken en hun functies te begrijpen.
- Voor grote netwerken, overweeg om scans te verdelen in kleinere subnetten of gebruik te maken van `-iL` met een lijst van targets.
- Gebruik `-oA` om alle output formats tegelijk te genereren voor latere analyse.
- Combineer nmap met andere tools zoals Wireshark voor diepgaande netwerk analyse.
- Blijf up-to-date met de nieuwste nmap versies en scripts, aangezien deze regelmatig worden bijgewerkt met nieuwe functies en verbeteringen.
- Gebruik `--exclude` om specifieke IP's of subnetten uit te sluiten van je scan, handig bij grote netwerken of wanneer je bepaalde hosts wilt vermijden.
- Experimenteer met verschillende scan types en opties om te zien welke het beste werkt voor jouw specifieke situatie en netwerkconfiguratie.
- Gebruik `--randomize_hosts` om de volgorde van gescande hosts te randomiseren, wat kan helpen bij het vermijden van detectie door IDS/IPS systemen.
- Gebruik `--traceroute` om de netwerkroute naar de doelhost te achterhalen, wat nuttig kan zijn voor het identificeren van netwerkapparaten en mogelijke zwakke punten in de route.
- Gebruik `--script-args` om specifieke parameters aan nmap scripts door te geven, zoals gebruikersnamen of wachtwoorden voor brute-force scripts, of aangepaste poorten voor service detectie.
- Gebruik `--data-length` om de grootte van de verzonden pakketten aan te passen, wat kan helpen bij het omzeilen van bepaalde firewall regels of IDS detectie.
- Gebruik `--badsum` om pakketten met een ongeldige checksum te verzenden, wat kan helpen bij het testen van firewall regels of IDS detectie.
- Gebruik `--source-port` om een specifiek bronpoortnummer te gebruiken voor je scan, wat kan helpen bij het omzeilen van bepaalde firewall regels die verkeer op specifieke poorten toestaan.
- Gebruik `--ttl` om de Time To Live waarde van de verzonden pakketten aan te passen, wat kan helpen bij het identificeren van het besturingssysteem van de doelhost of het omzeilen van bepaalde firewall regels.
- Gebruik `--spoof-mac` om een vals MAC-adres te gebruiken voor je scan, wat kan helpen bij het verbergen van je echte identiteit en het omzeilen van bepaalde netwerkbeveiligingsmaatregelen.
- Gebruik `--defeat-rst-ratelimit` om te voorkomen dat nmap wordt geblokkeerd door RST rate limiting, wat kan gebeuren bij agressieve scans of wanneer een firewall probeert te voorkomen dat nmap te veel verbindingen maakt.
- Gebruik `--script-trace` om de details van de uitgevoerde scripts te bekijken, wat nuttig kan zijn voor het debuggen van scripts of het begrijpen van hun werking.
- Gebruik `--script-updatedb` om de nmap script database bij te werken, zodat je altijd toegang hebt tot de nieuwste scripts en functies.
- Gebruik `--script-help <script>` om gedetailleerde informatie over een specifiek script te krijgen, inclusief de beschikbare opties en voorbeeldgebruik.
- Gebruik `--script-args-file <file>` om script argumenten uit een bestand te lezen, wat handig kan zijn voor het beheren van complexe scans met veel parameters.