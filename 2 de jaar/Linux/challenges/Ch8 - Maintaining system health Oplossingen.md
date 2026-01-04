# Opdrachten – Maintaining System Health in Linux

## Opdracht 1: Wat doet het commando `sar -b`?
**Vraag:** Wat voor soort informatie toont het commando `sar -b`?  
**Antwoord:** Het toont I/O-statistieken zoals reads/s, writes/s en blokken per seconde.

## Opdracht 2: Vind duplicaatbestanden met fdupes
**Vraag:** Hoe zoek je duplicaatbestanden in de map `/home`?  
**Antwoord:** `fdupes -r /home`

## Opdracht 3: Beperk ruimtegebruik in `/tmp`
**Vraag:** Waarom zou je `/tmp` op een aparte partitie plaatsen?  
**Antwoord:** Om te vermijden dat gebruikers de root-partitie vullen via tijdelijke bestanden.

## Opdracht 4: Gebruik van `passwd`
**Vraag:** Wat doet het commando `passwd`?  
**Antwoord:** Het verandert het wachtwoord van de huidige gebruiker (of van een andere gebruiker met rootrechten).

## Opdracht 5: Controleer groepsleden met groupmems
**Vraag:** Hoe lijst je alle leden van de groep `marketing` op?  
**Antwoord:** `sudo groupmems -g marketing -l`

## Opdracht 6: Toon schrijfgebruik per map
**Vraag:** Toon het schijfgebruik van `/var` op een overzichtelijke manier.  
**Antwoord:** `sudo du -sh /var/*`

## Opdracht 7: Verwijder een lege groep
**Vraag:** Hoe verwijder je veilig een lege groep `testgroep`?  
**Antwoord:** Controleer eerst op bestanden (`sudo find / -group testgroep`), wijzig eigenaarschap indien nodig, en gebruik `sudo groupdel testgroep`.

## Opdracht 8: Zoek in logs met grep
**Vraag:** Zoek naar SSH-inlogpogingen in `/var/log/auth.log`.  
**Antwoord:** `grep sshd /var/log/auth.log`

## Opdracht 9: Creëer een gebruikersnaam volgens conventie
**Vraag:** Wat zou een goede gebruikersnaam zijn voor gebruiker Alice Van Dam?  
**Antwoord:** avandam (eerste initiaal + eerste 7 letters van achternaam)

## Opdracht 10: Maak een CSV-bestand van systeemactiviteit
**Vraag:** Hoe sla je sar-gegevens op in CSV-formaat?  
**Antwoord:** `sadf -d`

## Opdracht 11: Bekijk ruimtegebruik op gemonteerde partities
**Vraag:** Welk commando toont ruimtegebruik in een leesbaar formaat?  
**Antwoord:** `df -h`

## Opdracht 12: Kopieer inhoud veilig met cp
**Vraag:** Wat doet `cp -r /home/user/docs /mnt/backup/`?  
**Antwoord:** Kopieert recursief alle bestanden en submappen van `/home/user/docs` naar `/mnt/backup/`.