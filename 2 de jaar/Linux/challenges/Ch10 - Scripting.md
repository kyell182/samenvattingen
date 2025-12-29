# Oefeningen - Ch10: Scripting en automatisatie

Deze opdrachten laten je scripts schrijven die nuttig zijn voor systeembeheer.

## 1. Welkomstbericht tonen
**Opdracht**: Schrijf een script `welkom.sh` dat een welkomstbericht toont met je gebruikersnaam.

**Voorbeeldoutput**:
```
Welkom, student!
```

**Oplossing**:


## 2. Controleer of een bestand bestaat
**Opdracht**: Schrijf een script `bestandscheck.sh` dat controleert of `/etc/passwd` bestaat en een gepaste boodschap toont.

**Oplossing**:


## 3. Toon huidige schijfruimte
**Opdracht**: Schrijf een script `ruimte.sh` dat `df -h` uitvoert en enkel de lijnen toont met `/dev`.

**Oplossing**:


## 4. Backupscript met `tar`
**Opdracht**: Schrijf een script `backup.sh` dat de map `/etc` archiveert naar `~/backups/etc_YYYYMMDD.tar.gz`.

**Oplossing**:


## 5. Log recente sudo-acties
**Opdracht**: Maak een script `sudo_log.sh` dat alle recente sudo-acties toont.

**Oplossing**:


## 6. Automatisch update-script
**Opdracht**: Schrijf een script `update.sh` dat je systeem automatisch bijwerkt en logt naar `~/update.log`.

**Oplossing**:


## 7. Controle op netwerkconnectie
**Opdracht**: Schrijf een script `nettest.sh` dat controleert of google.com bereikbaar is. Indien niet, toon "Geen internet".

**Oplossing**:


## 8. Gebruikers waarschuwen bij volle schijf
**Opdracht**: Schrijf een script `waarschuwing.sh` dat een melding toont als root-partitie meer dan 80% vol is.

**Oplossing**:

## 9. Script om dubbele bestanden te zoeken
**Opdracht**: Maak een script `dubbel.sh` dat via `fdupes` duplicaten toont in een opgegeven map.

**Gebruik**:
```bash
./dubbel.sh /opt/shared
```

**Oplossing**:
