# Network Security — Samenvatting voor studie

Doel: compacte, studeerbare uitleg van kernbegrippen, aanvallen, verdedigingen en veelgebruikte commando's. Bevat de originele onderwerpen, herschikt en kort toegelicht.

## Intro

- Netwerkbeveiliging beschermt beschikbaarheid, integriteit en vertrouwelijkheid van netwerkdiensten en data.
- Onderwerpen: discovery (Shodan), kwetsbaarheidsbeheer (CVE/CVSS), aanvallen (MITM, DDoS, DNS), draadloze risico's, verdedigingen (firewalls, IPS/IDS, VPN), en operationele tools.

## Belangrijke concepten

- Shodan: search engine voor internet-exposed apparaten; nuttig voor asset discovery en het vinden van potentieel kwetsbare services.
- NAT: vertaalt private IP-adressen naar één of meer publieke adressen; verbergt interne structuur maar is geen beveiliging op applicatieniveau.
- CVE: gestandaardiseerde ID voor bekend gemaakte kwetsbaarheden. Raadpleeg cvedetails.com voor overzicht en referenties.
- CVSS: score (0.0–10.0) die de ernst van een kwetsbaarheid kwantificeert (base, temporal, environmental metrics).

## Aanvalstypes (kort)

- Man-in-the-Middle (MITM): aanvaller onderschept of wijzigt verkeer tussen twee partijen (bijv. ARP spoofing, rogue AP).
- DNS poisoning / spoofing: manipulatie of vervuiling van DNS-resultaten, leidt gebruikers naar kwaadaardige sites; mitigatie: DNSSEC, DoH (met aandacht voor beheer).
- DDoS: gedistribueerde aanvallen die beschikbaarheid verstoren (volumetrisch, protocol, applicatielaag).
- Wi‑Fi gerelateerde: wardriving (netwerken scannen), rogue/evil‑twin hotspots (spoofed AP), WPA/WPA2/WPA3 beveiligingsverschillen.
- Bluetooth: bluejacking is ongevraagd berichten sturen; vaak hinderlijk maar kan wijzen op slechte instellingen.
- Botnets / ‘derp servers’: gecompromitteerde servers die worden gebruikt voor coördinatie van aanvallen (DDoS, C2).

## Netwerkdiensten & protocollen

- SMB/Samba: file‑sharing protocol; vaak doelwit voor credential‑replay en RCE. Let op permissies en patchniveau.
- mDNS: lokaal discovery-protocol (Multicast DNS); handig maar kan informatie lekken binnen LAN.

## Verdediging en controls

- Firewalls:
  - Stateless: controleert losse pakketten op rules (sneller, minder context).
  - Stateful: houdt verbindingstoestand bij en kan context gebruiken (veiliger voor TCP‑flows).
  - Host‑based: draait op endpoints om lokaal verkeer te filteren.
- IDS/IPS: detectie (IDS) en preventie (IPS) van kwaadaardige patronen; combineer met logging en response playbooks.
- Deep Packet Inspection (DPI): inspecteert payloads voor geavanceerde detectie/controle (privacy en performance trade‑offs).
- Segmentatie: VLANs / subnetten om blast‑radius te beperken en laterale beweging tegen te gaan.
- RADIUS / 802.1x: centraal AAA voor netwerktoegang (veel gebruikt bij bedrijfs‑wifi en 802.1x authenticatie).
- VPN: versleutelde tunnels voor veilige toegang; let op endpoint security en split‑tunneling risico's.
- Wi‑Fi encryptie: vermijd WEP; kies WPA3 of goed geconfigureerde WPA2‑Enterprise (802.1x) waar mogelijk.

## Antivirus & detectie

- Detectiemethoden: handtekeningen, heuristiek, gedragsanalyse, sandboxing, hash‑vergelijking.
- Houd definities up‑to‑date en combineer endpoint detection met netwerkanalyse voor betere zichtbaarheid.

## Tools & commando‑legenda (kort per commando)

- `ipconfig /all` (Windows): tonen van interfaces, IP, DNS‑servers, MAC. Gebruik als eerste stap bij host‑info.
- `nslookup <host>` / `dig <host>`: DNS‑resolutie en nameserver troubleshooting; test A/AAAA/CNAME records.
- `nmap -p- -sV -sC -Pn <target>`: poortscan (alle poorten), versie‑detectie, standaard scripts; veel gebruikt bij recon.
- `shodan search <query>`: zoek exposeerde apparaten en services; nuttig om publieke attack surface te vinden.
- `tcpdump -i <iface> -w capture.pcap`: paketten vastleggen; analyseer later in Wireshark.
- `wireshark`: GUI netwerktraffic analyser; gebruik filters voor efficiënte triage.

Voorbeeld DNS‑onderzoek

```bash
ipconfig /all
nslookup verpleegkunde.voltlab.net
```

Praktische notities

- Gebruik Shodan om te controleren welke services publiek zichtbaar zijn voordat je perimeter hardening uitvoert.
- Bij CVE‑beheer: prioriteer op CVSS en exposure (is de service publiek bereikbaar?) en of er werkende exploit‑code beschikbaar is.
- Segmentatie en least‑privilege beperken verspreiding bij een succesvolle breach.

Bronnen

- <https://www.shodan.io>
- <https://cvedetails.com>
- CVSS informatie: <https://www.first.org/cvss/>

Ethisch en praktisch

- Gebruik discovery/tools alleen op systemen waar je toestemming voor hebt (eigen lab of expliciete toestemming). Misbruik is strafbaar.

---
