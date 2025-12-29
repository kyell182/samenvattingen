# Opdrachten – Maintaining System Health in Linux

## Opdracht 1: Wat doet het commando `sar -b`?
**Vraag:** Wat voor soort informatie toont het commando `sar -b`? 
````bash
Linux 6.12.48+deb13-amd64 (debiandewindt) 	11/17/2025 	_x86_64_	(6 CPU)

03:17:06 PM  LINUX RESTART	(6 CPU)
````

hij toont de volgdende i/o statistieken :
-   het os type 
-   de versie van het os
-   de user
-   de datum
-   de processor instructieset
-   aantal kernen

## Opdracht 2: Vind duplicaatbestanden met fdupes
**Vraag:** Hoe zoek je duplicaatbestanden in de map `/home`? 
````bash
 fdupes -r ./home
 ````

## Opdracht 3: Beperk ruimtegebruik in `/tmp`
**Vraag:** Waarom zou je `/tmp` op een aparte partitie plaatsen? 

omdat als je dit niet doet de users de root folder zouden kunnen vol zetten en zo het systeem onbruikbaar kunnen maken.

## Opdracht 4: Gebruik van `passwd`
**Vraag:** Wat doet het commando `passwd`?  

hiermee kun je de wachtwoorden van gebruikers aanpassen of veranderen.

## Opdracht 5: Controleer groepsleden met groupmems
**Vraag:** Hoe lijst je alle leden van de groep `marketing` op?
````bash
getent group marketing # toont de groepsinformatie inclusief leden
````  

## Opdracht 6: Toon schrijfgebruik per map
**Vraag:** Toon het schijfgebruik van `/var` op een overzichtelijke manier.
````bash
du -sh /var
````
- `du` → disk usage
- `-s` → samenvatting
- `-h` → human readable (leesbaar formaat)

## Opdracht 7: Verwijder een lege groep
**Vraag:** Hoe verwijder je veilig een lege groep `testgroep`? 
````bash
groupdel testgroep
```` 
-   `groupdel` → commando om een groep te verwijderen
-   `testgroep` → de naam van de groep die je wilt verwijderen
-   Zorg ervoor dat de groep geen leden heeft voordat je deze verwijdert, anders krijg je een foutmelding.

⚠️ Wees voorzichtig bij het verwijderen van groepen, vooral als ze nog leden hebben, om systeemproblemen te voorkomen.

## Opdracht 8: Zoek in logs met grep
**Vraag:** Zoek naar SSH-inlogpogingen in `/var/log/auth.log`.
````bash
grep "sshd" /var/log/auth.log
````
-   `grep` → commando om te zoeken naar specifieke tekst in bestanden
-   `"sshd"` → de zoekterm die je wilt vinden (in dit geval SSH-gerelateerde vermeldingen)
-   `/var/log/auth.log` → het logbestand waarin je wilt zoeken  

## Opdracht 9: Creëer een gebruikersnaam volgens conventie
**Vraag:** Wat zou een goede gebruikersnaam zijn voor gebruiker Alice Van Dam? 

Een goede gebruikersnaam zou kunnen zijn `avadam` of `alicevd`, afhankelijk van de conventies die in jouw organisatie worden gebruikt. Meestal wordt de eerste letter van de voornaam gecombineerd met de achternaam, of een combinatie van voornaam en achternaam zonder spaties.

## Opdracht 10: Maak een CSV-bestand van systeemactiviteit
**Vraag:** Hoe sla je sar-gegevens op in CSV-formaat?
````bash
sar -o outputfile 1 10 # verzamel systeemprestatistieken elke seconde voor 10 seconden
sadf -c outputfile -- -A > outputfile.csv # converteer naar CSV-formaat
````
-   `sar -o outputfile 1 10` → verzamelt systeemprestatistieken elke seconde voor 10 seconden en slaat ze op in een binaire bestand `outputfile`.
-   `sadf -c outputfile -- -A > outputfile.csv` → converteert de binaire sar-gegevens naar CSV-formaat en slaat ze op in `outputfile.csv`.
-   `-c` → geeft aan dat de uitvoer in CSV-formaat moet zijn.
-   `-- -A` → geeft aan dat alle beschikbare statistieken moeten worden opgenomen.  

## Opdracht 11: Bekijk ruimtegebruik op gemonteerde partities
**Vraag:** Welk commando toont ruimtegebruik in een leesbaar formaat? 
````bash
df -h # toont schijfruimte in een leesbaar formaat
````
-   `df` → disk free, toont de beschikbare en gebruikte schijfruimte
-   `-h` → human readable, toont de informatie in een formaat dat gemakkelijk te lezen is (bijv. MB, GB) 

## Opdracht 12: Kopieer inhoud veilig met cp
**Vraag:** Wat doet `cp -r /home/user/docs /mnt/backup/`?  

Het commando kopieert de gehele inhoud van de map `/home/user/docs` naar de map `/mnt/backup/`, inclusief alle submappen en bestanden binnen `docs`.

-   `cp` → copy, het commando om bestanden en mappen te kopiëren
-   `-r` → recursive, zorgt ervoor dat alle submappen en hun inhoud ook worden gekopieerd
-   `/home/user/docs` → de bronmap die je wilt kopiëren
-   `/mnt/backup/` → de doelmap waar de inhoud naartoe gekopieerd wordt
