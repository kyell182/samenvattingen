# Oefeningen - Ch10: Scripting en automatisatie

Deze opdrachten laten je scripts schrijven die nuttig zijn voor systeembeheer.

## 1. Welkomstbericht tonen
**Opdracht**: Schrijf een script `welkom.sh` dat een welkomstbericht toont met je gebruikersnaam.

**Voorbeeldoutput**:
```
Welkom, student!
```

**Oplossing**:
```bash
#!/bin/bash
echo "Welkom, $USER!"
```

---

## 2. Controleer of een bestand bestaat
**Opdracht**: Schrijf een script `bestandscheck.sh` dat controleert of `/etc/passwd` bestaat en een gepaste boodschap toont.

**Oplossing**:
```bash
#!/bin/bash
if [ -f /etc/passwd ]; then
  echo "Bestand bestaat."
else
  echo "Bestand niet gevonden."
fi
```

---

## 3. Toon huidige schijfruimte
**Opdracht**: Schrijf een script `ruimte.sh` dat `df -h` uitvoert en enkel de lijnen toont met `/dev`.

**Oplossing**:
```bash
#!/bin/bash
df -h | grep /dev
```

---

## 4. Backupscript met `tar`
**Opdracht**: Schrijf een script `backup.sh` dat de map `/etc` archiveert naar `~/backups/etc_YYYYMMDD.tar.gz`.

**Oplossing**:
```bash
#!/bin/bash
datum=$(date +%Y%m%d)
mkdir -p ~/backups
sudo tar -czf ~/backups/etc_$datum.tar.gz /etc
```

---

## 5. Log recente sudo-acties
**Opdracht**: Maak een script `sudo_log.sh` dat alle recente sudo-acties toont.

**Oplossing**:
```bash
#!/bin/bash
grep sudo /var/log/auth.log
```

---

## 6. Automatisch update-script
**Opdracht**: Schrijf een script `update.sh` dat je systeem automatisch bijwerkt en logt naar `~/update.log`.

**Oplossing**:
```bash
#!/bin/bash
sudo apt update && sudo apt upgrade -y > ~/update.log
```

---

## 7. Controle op netwerkconnectie
**Opdracht**: Schrijf een script `nettest.sh` dat controleert of google.com bereikbaar is. Indien niet, toon "Geen internet".

**Oplossing**:
```bash
#!/bin/bash
# > /dev/null: verstuurt de normale uitvoer (stdout) naar /dev/null, een soort "prullenbak" in Linux. Je ziet dus geen output meer op het scherm.
# 2>&1: verstuurt de foutmeldingen (stderr) ook naar dezelfde plaats als stdout, dus ook naar /dev/null

ping -c 1 google.com > /dev/null 2>&1

#$? is een speciale variabele in Bash die de exitstatus van het vorige commando bevat.
#Een exitstatus van 0 betekent: het vorige commando is geslaagd.
#Elke andere waarde betekent: er is iets foutgelopen.
if [ $? -eq 0 ]; then
#-eq betekent is gelijk aan (is de exit code gelijk aan 0 dus is het commando geslaagd)
  echo "Internet OK"
else
  echo "Geen internet"
fi
```

---

## 8. Gebruikers waarschuwen bij volle schijf
**Opdracht**: Schrijf een script `waarschuwing.sh` dat een melding toont als root-partitie meer dan 80% vol is.

**Oplossing**:
```bash
#!/bin/bash
# NR==2: selecteert de tweede regel van de uitvoer (de eerste regel is de kolomtitel).
#{print $5}: toont de vijfde kolom = het percentage gebruikte ruimte, bv. 51%.
# tr -d '%' Verwijdert het %-teken uit de uitvoer.
gebruik=$(df / | awk 'NR==2 {print $5}' | tr -d '%')
# -gt is greater than, dus als gebruik groter is dan 80
if [ $gebruik -gt 80 ]; then
  echo "Waarschuwing: root-partitie bijna vol!"
fi
```

---

## 9. Script om dubbele bestanden te zoeken
**Opdracht**: Maak een script `dubbel.sh` dat via `fdupes` duplicaten toont in een opgegeven map.

**Gebruik**:
```bash
./dubbel.sh /opt/shared
```

**Oplossing**:
```bash
#!/bin/bash
#"$1": het eerste argument dat je meegeeft aan het script.
#-z "$1": test of de inhoud leeg is (is er geen argument meegegeven?)
if [ -z "$1" ]; then
# $0 is de naam van het script zelf, bv. script.sh.
  echo "Gebruik: $0 <map>"
  exit 1
fi
fdupes -rS "$1"
```

---
s