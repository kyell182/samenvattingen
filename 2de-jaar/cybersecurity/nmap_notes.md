- nmap = network mapper

nmap is a free and open source utility for network discovery and security auditing. It was designed to rapidly scan large networks, but it also works well against single hosts. Nmap uses raw IP packets in novel ways to determine what hosts are available on the network, what services (application name and version) those hosts are offering, what operating systems (and OS versions) they are running, what type of packet filters/firewalls are in use, and dozens of other characteristics.

- wat is een cyberaanval?

gedaan via

- Mensen
- computer
- Telefoons
- Applicaties
- Boodschappen
- Systeemprocessen

doelen van aanvallen

informatie verzamelen

- date en processene versleutelen en losgeld vragen
- cruciale info verwijderen
- informatie stelen
- informatie publiek maken
- systeem onbruikbaar maken

types aanvalen

passive aanvallen:

schade / wijzigingen toebrengen inbreken in systemen

- sniffeing traffic
- port scanning

active aanvallen:

- malware
- DDOS (Distributed Denial of Service)

red team = aanvallers
blue team = verdedigers

grey hat hackers = hackers die zowel goede bedoelingen maar zonder toestemming
white hat hackers = hackers die alleen goede dingen doen met toestemming
black hat hackers = hackers die alleen slechte dingen doen

 slow lorris = aanval waarbij een verbinding open blijft zonder data te versturen, waardoor de server resources bezet houdt en uiteindelijk onbruikbaar wordt

 verdedigingsmethoden
- firewalls
- antivirus software
- intrusion detection systems (IDS)
- intrusion prevention systems (IPS)
- regelmatige software updates
- gebruik van sterke wachtwoorden
- educatie en bewustwording van gebruikers
- netwerksegmentatie
- encryptie van data
- backups maken van belangrijke data
- monitoring en logging van netwerkactiviteiten

3 pijlers van cybersecurity:

- Confidentiality (vertrouwelijkheid): zorgen dat informatie alleen toegankelijk is voor degenen die er recht op hebben.
- Integrity (integriteit): zorgen dat informatie accuraat en volledig is, en niet ongeautoriseerd wordt gewijzigd.
- Availability (beschikbaarheid): zorgen dat informatie en systemen beschikbaar zijn wanneer ze nodig zijn.
- non repudiation (niet-afdwingbaarheid): zorgen dat een partij niet kan ontkennen dat ze een bepaalde actie hebben uitgevoerd, zoals het verzenden van een bericht of het uitvoeren van een transactie.
- authentication (authenticatie): het proces van het verifiëren van de identiteit van een gebruiker, apparaat of systeem voordat toegang wordt verleend tot bronnen of informatie.
- authorization (autorisatie): het proces van het bepalen van de toegangsrechten en -privileges van een geauthenticeerde gebruiker, apparaat of systeem, om te bepalen welke bronnen of informatie ze mogen benaderen of gebruiken.

CIA triade = Confidentiality, Integrity, Availability

Wat is malware?

- Malicious software, oftewel kwaadaardige software, is een verzamelnaam voor software die is ontworpen om schade aan te richten aan computersystemen, netwerken of gebruikers. Malware kan verschillende vormen aannemen, zoals virussen, wormen, Trojaanse paarden, ransomware, spyware en adware. Het doel van malware kan variëren van het stelen van persoonlijke informatie tot het vernietigen van gegevens of het overnemen van systemen voor kwaadaardige doeleinden. Het is belangrijk om goede beveiligingsmaatregelen te nemen om jezelf te beschermen tegen malware-aanvallen.

componeten malware
- Payload: de kwaadaardige code die schade aanricht of een bepaald doel bereikt, zoals het stelen van gegevens, het versleutelen van bestanden of het overnemen van een systeem.
- Propagation mechanism: de methode waarmee malware zich verspreidt, zoals via e-mailbijlagen, geïnfecteerde websites, sociale media of netwerkverbindingen.
- Command and Control (C&C) server: een externe server waarmee de aanvaller communiceeert om instructies te geven aan de malware of om gestolen gegevens te ontvangen.

virussen = kwaadaardige software die zich hecht aan legitieme bestanden of programma's en zich verspreidt wanneer deze worden uitgevoerd of gedeeld. Virussen kunnen verschillende soorten schade aanrichten, zoals het verwijderen van bestanden, het stelen van persoonlijke informatie of het overnemen van systemen.

wormen = kwaadaardige software die zich zelfstandig kan verspreiden zonder dat er een hostbestand nodig is. Wormen kunnen zich via netwerken verspreiden en kunnen grote hoeveelheden schade aanrichten door systemen te overbelasten of gegevens te stelen.

Trojaanse paarden = kwaadaardige software die zich voordoet als legitieme software om gebruikers te misleiden en toegang te krijgen tot systemen. Trojaanse paarden kunnen worden gebruikt om gegevens te stelen, systemen over te nemen of andere kwaadaardige activiteiten uit te voeren.

ransomware = kwaadaardige software die bestanden versleutelt en losgeld eist van slachtoffers om de bestanden te ontgrendelen. Ransomware kan ernstige schade aanrichten door belangrijke gegevens ontoegankelijk te maken.

spyware = kwaadaardige software die is ontworpen om informatie over een gebruiker of systeem te verzamelen zonder hun medeweten of toestemming. Spyware kan worden gebruikt om persoonlijke informatie te stelen, zoals wachtwoorden, creditcardgegevens of surfgedrag, en kan ook worden gebruikt om advertenties weer te geven of andere ongewenste activiteiten uit te voeren.

adware = kwaadaardige software die is ontworpen om advertenties weer te geven op een computer of apparaat, vaak zonder de toestemming van de gebruiker. Adware kan ook worden gebruikt om persoonlijke informatie te verzamelen of om andere ongewenste activiteiten uit te voeren.

backdoor = een verborgen toegangspunt in een systeem of software dat door aanvallers kan worden gebruikt om ongeautoriseerde toegang te krijgen tot het systeem, vaak zonder dat de gebruiker of beheerder hiervan op de hoogte is. Backdoors kunnen worden geïnstalleerd door malware, hackers of zelfs door legitieme ontwikkelaars voor onderhoudsdoeleinden, maar ze vormen een groot beveiligingsrisico als ze in verkeerde handen vallen.

botnet = een netwerk van geïnfecteerde computers die worden gecontroleerd door een aanvaller, vaak via een Command and Control (C&C) server. Botnets kunnen worden gebruikt voor verschillende kwaadaardige doeleinden, zoals het uitvoeren van Distributed Denial of Service (DDoS) aanvallen, het verspreiden van malware, het stelen van gegevens of het verzenden van spam.

3 mitigation strategies

- Preventie: maatregelen nemen om te voorkomen dat aanvallen plaatsvinden, zoals het implementeren van firewalls, antivirussoftware, regelmatige software-updates en het gebruik van sterke wachtwoorden.

- Detectie: het monitoren van systemen en netwerken om verdachte activiteiten te identificeren, zoals het gebruik van intrusion detection systems (IDS) en het analyseren van logbestanden.

- Recovery: het herstellen van systemen en gegevens na een aanval, zoals het maken van backups, het implementeren van incident response plannen en het uitvoeren van forensisch onderzoek om de oorzaak van de aanval te achterhalen en toekomstige aanvallen te voorkomen.

3 soorten phissing-aanvallen

- Spear phishing: een gerichte aanval waarbij de aanvaller zich richt op een specifieke persoon of organisatie, vaak door het gebruik van gepersonaliseerde e-mails of berichten die lijken te komen van een vertrouwde bron.

- Whaling: een vorm van spear phishing die zich richt op hooggeplaatste individuen binnen een organisatie, zoals CEO's of CFO's, met als doel gevoelige informatie te stelen of financiële fraude te plegen.

- phishing een bredere term die verwijst naar elke vorm van online oplichting waarbij aanvallers zich voordoen als legitieme entiteiten om slachtoffers te misleiden en persoonlijke informatie te stelen, zoals wachtwoorden, creditcardgegevens of andere gevoelige informatie. Phishing-aanvallen kunnen plaatsvinden via e-mail, sociale media, sms-berichten of zelfs telefoonoproepen.

1 cybersecurity killchain
- Reconnaissance: de aanvaller verzamelt informatie over het doelwit, zoals netwerkinfrastructuur, gebruikte software en kwetsbaarheden.
- Weaponization: de aanvaller ontwikkelt of verkrijgt malware of exploits die kunnen worden gebruikt om het doelwit aan te vallen.
- Delivery: de aanvaller levert de malware of exploit aan het doelwit, bijvoorbeeld via e-mail, geïnfecteerde websites of fysieke media.
- Exploitation: de malware of exploit wordt geactiveerd en maakt gebruik van een kwetsbaarheid in het doelwit om toegang te krijgen tot het systeem.
- Installation: de malware installeert zich op het systeem van het doelwit, waardoor de aanvaller permanente toegang krijgt.
- Command and Control (C&C): de aanvaller communiceert met de malware op het systeem van het doelwit om instructies te geven of gestolen gegevens te ontvangen.
- Actions on Objectives: de aanvaller voert acties uit op het systeem van het doelwit om zijn doelen te bereiken, zoals het stelen van gegevens, het vernietigen van bestanden of het overnemen van systemen.
- Incident Response: het proces van het detecteren, analyseren en reageren op een beveiligingsincident, zoals een cyberaanval, om de schade te beperken en toekomstige aanvallen te voorkomen. Incident response omvat vaak het identificeren van de aanval, het isoleren van getroffen systemen, het herstellen van gegevens en het implementeren van maatregelen om herhaling te voorkomen.


nmap

- open
- closed
- filtered

service detectie
os fingerprinting
scripting

```bash
nmap -192.168.189.2/24 -n
nmap -sn -oA tnet -v 192.168.189.0/24 -n
sudo nmap 192.168.189.0/24 -sn -PE --packet-trace
sudo nmap 192.168.189.0/24 -sn --disable-arp-ping 
nmap 192.168.189.4 --top-ports=10
nmap 192.168.189.4 -p 22,25,80,139,445
nmap 192.168.189.4 -p 22-445
nmap 192.168.189.4 -p- 
nmap 192.168.189.4 -p 443 --packet-trace -Pn -n 
nmap 192.168.189.4 -sT
nmap 192.168.189.4 -sS --max-retries 1
nmap -sU -F 
nmap 192.168.189.4 -sU --top-ports=100
nmap 192.168.189.4 --top 10 -n
nmap 192.168.189.4 --top 10 -n -sV
nmap 192.168.189.4 -p 80-sV -n -Pn --packet-trace
nc -nv 192.168.189.4 25
```
ttl windows = 128
ttl linux = 64