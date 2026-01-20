# 🐧 Linux Command Cheatsheet

Een overzicht van de meest gebruikte Linux-commando’s en hun opties.  
Gebruik `man <command>` of `<command> --help` voor meer details.

---

## 📁 Navigatie & Bestanden

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `ls` | Lijst bestanden/directories | `-l` (lange lijst), `-a` (alle, incl. verborgen), `-h` (leesbare grootte) |
| `cd <dir>` | Ga naar directory | `..` (één map omhoog), `~` (home directory) |
| `pwd` | Toon huidige directory | — |
| `tree` | Toon mappenstructuur in boomvorm | `-L <n>` (diepte), `-a` (alles tonen) |
| `find <dir> -name <naam>` | Zoek bestanden | `-type f/d` (bestand/map), `-size +10M` (groter dan 10 MB) |

---

## 📄 Bestanden bekijken & bewerken

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `cat` | Toon bestand | `-n` (regelnummering) |
| `less` | Scrollend bestand bekijken | `q` (quit), `/zoekterm` (zoeken) |
| `head` | Toon eerste regels | `-n <aantal>` |
| `tail` | Toon laatste regels | `-f` (volg live, handig voor logs) |
| `nano <bestand>` | Tekstbestand bewerken | `Ctrl+O` (opslaan), `Ctrl+X` (afsluiten) |
| `vim <bestand>` | Geavanceerde editor | `i` (insert), `:wq` (opslaan + sluiten) |

---

## 📦 Bestandsbeheer

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `cp <bron> <doel>` | Kopieer bestand of map | `-r` (recursief), `-v` (verbose) |
| `mv <bron> <doel>` | Verplaats of hernoem | — |
| `rm <bestand>` | Verwijder bestand | `-r` (recursief), `-f` (force) |
| `mkdir <dir>` | Maak nieuwe map | `-p` (maak tussenliggende mappen) |
| `rmdir <dir>` | Verwijder lege map | — |
| `touch <bestand>` | Maak leeg bestand / update timestamp | — |

---

## 🔍 Zoeken & Tekstverwerking

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `grep <term> <bestand>` | Zoek tekst in bestand | `-i` (case-insensitive), `-r` (recursief), `-n` (regelnummer) |
| `sort` | Sorteer tekstregels | `-r` (omgekeerd), `-n` (numeriek) |
| `uniq` | Verwijder dubbele regels | `-c` (tellen), `-d` (alleen dubbels) |
| `wc` | Tel regels, woorden, bytes | `-l` (regels), `-w` (woorden), `-c` (bytes) |
| `cut` | Selecteer kolommen uit tekst | `-d` (scheidingsteken), `-f` (velden) |

---

## ⚙️ Systeeminformatie

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `uname` | Toon systeeminfo | `-a` (alles) |
| `df` | Toon schijfruimte | `-h` (leesbare eenheden) |
| `du` | Toon mapgroottes | `-h` (leesbare eenheden), `-s` (samenvatting) |
| `top` | Toon processen live | `q` (quit), `k` (kill) |
| `ps` | Lijst actieve processen | `-e` (alle), `-f` (volledig) |
| `free` | Toon geheugenstatus | `-h` (leesbaar formaat) |
| `uptime` | Toon systeem runtime | — |

---

## 🌐 Netwerk

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `ping <host>` | Controleer netwerkverbinding | `-c <n>` (Linux) / `-n <n>` (Windows) |
| `ifconfig` | Toon netwerkinterfaces (oude Linux-tool; niet standaard op Windows) | Windows alternatief: `ipconfig` |
| `ip addr` | Toon IP-configuratie (moderne Linux iproute2) | Linux-only (gebruik `ip addr`); Windows: `ipconfig` |
| `netstat` | Toon netwerkverbindingen | `-tuln` (Linux) / `-ano` (Windows; toont PID) |
| `curl <url>` | HTTP-request uitvoeren | `-O`, `-I` (Linux/Unix). Windows 10+ bevat curl; PowerShell alternatief: `Invoke-WebRequest` (`iwr`) |
| `wget <url>` | Download bestand | `-r`, `-q` (Linux). Windows: installeerbare build of gebruik PowerShell `Invoke-WebRequest -OutFile` |

---

## 👥 Gebruikers & Rechten

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `whoami` | Toon huidige gebruiker | — |
| `id` | Toon UID, GID en groepen | — |
| `chmod` | Wijzig rechten | `+x`, `-r`, `777`, etc. |
| `chown` | Wijzig eigenaar | `user:group <bestand>` |
| `sudo <commando>` | Voer commando uit als root | — |
| `passwd` | Wijzig wachtwoord | — |

---

## 💣 Archiveren & Compressie

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `tar -cf archive.tar <dir>` | Maak archief | `-x` (uitpakken), `-v` (verbose), `-z` (gzip) |
| `gzip <bestand>` | Comprimeer bestand | `-d` (decomprimeer) |
| `zip -r archive.zip <dir>` | Maak ZIP-bestand | `-r` (recursief) |
| `unzip <bestand.zip>` | Pak ZIP uit | — |

---

## 🔑 Overige nuttige tools

| Commando | Beschrijving | Belangrijkste opties |
|-----------|---------------|----------------------|
| `history` | Toon commandogeschiedenis | `!n` (herhaal commando n) |
| `alias` | Maak snelkoppeling | `alias ll='ls -lh'` |
| `date` | Toon datum en tijd | `+%Y-%m-%d` (formaat) |
| `clear` | Maak terminal schoon | — |
| `exit` | Sluit terminalsessie | — |

---

> 💡 **Tip:** Combineer commando’s met `|` (piping)  
> Voorbeeld:  
>
> ```bash
> ps -e | grep ssh
> ```
>
> Zo vind je alle actieve SSH-processen.

---
