
# Oefeningen Linux Storage

## Oefening 1: Nieuwe schijf detecteren
Gebruik het juiste commando om te zien welke schijven aan het systeem gekoppeld zijn.

**Opdracht**  
Welke schijf is recent toegevoegd aan het systeem?
````bash
lsblk
````

## Oefening 2: Schijf partitioneren met fdisk
Initialiseer een nieuwe schijf `/dev/sdb` met een enkele partitie.

**Opdracht**  
Gebruik het `fdisk`-commando om een nieuwe partitie aan te maken.

````bash
fdisk /dev/sdb # start fdisk voor de schijf /dev/sdb
````
Gebruik de volgende stappen in fdisk:
````bash
  n (new partition) # maak een nieuwe partitie
  p (primary) # maak het een primaire partitie
  1 (partition number) # eerste partitie
  <enter> (default first sector) # accepteer standaard
  <enter> (default last sector) # accepteer standaard
  w (write changes) # schrijf de partitietabel en sluit af
````

## Oefening 3: Filesysteem aanmaken
Maak een XFS-filesysteem aan op `/dev/sdb1`.

**Opdracht**  
Welk commando gebruik je?
````bash
mkfs.xfs /dev/sdb1
````
-   `mkfs.xfs` → maakt een XFS-bestandssysteem aan.

-   `/dev/sdb1` → de partitie waarop het bestandssysteem wordt aangemaakt.

⚠️ Alles wat al op die partitie staat, wordt verwijderd.

## Oefening 4: Mount point maken en mounten
Mount `/dev/sdb1` op `/mnt/data`.

**Opdracht**  
Welke commando’s voer je uit?
````bash
mkdir -p /mnt/data          # maak het mount point aan
mount /dev/sdb1 /mnt/data   # mount de partitie op het mount point
````
-   `mkdir -p /mnt/data` → maakt de directory `/mnt/data` aan als mount point. (`-p` zorgt ervoor dat ook eventuele bovenliggende directories worden aangemaakt.)
-   `mount /dev/sdb1 /mnt/data` → mount de partitie op het mount point.

## Oefening 5: Automatisch mounten bij opstart
Zorg dat `/dev/sdb1` automatisch mount op `/mnt/data` bij het opstarten.

**Opdracht**  
Wat moet je aanpassen?
Je moet een regel toevoegen aan het bestand `/etc/fstab`. De regel zou er als volgt uit kunnen zien:
````bash
/dev/sdb1   /mnt/data   xfs   defaults   0   0
````
-   `/dev/sdb1` → de partitie die gemount moet worden.
-   `/mnt/data` → het mount point.
-   `xfs` → het type bestandssysteem.
-   `defaults` → standaard mount opties.
-   `0 0` → dump en fsck opties (meestal op 0 zetten voor niet-root bestanden).
-   dump is een back-up optie, fsck is een controle optie.

⚠️ Wees voorzichtig bij het bewerken van `/etc/fstab`, een fout kan ertoe leiden dat het systeem niet goed opstart.


## Oefening 6: Diskgebruik controleren
Controleer hoeveel ruimte beschikbaar is op het bestandssysteem.

**Opdracht**  
Welke commando’s kan je gebruiken?
````bash
df -h          # toont schijfruimte in een leesbaar formaat
du -sh /mnt/data  # toont de grootte van de directory /mnt/data
````
-   `df -h` → toont de beschikbare en gebruikte schijfruimte van alle gemounte bestandssystemen in een menselijk leesbaar formaat.
-   `du -sh /mnt/data` → toont de totale grootte van de directory `/mnt/data` in een samenvatting.


## Oefening 7: Bestandssysteem permissies instellen
Stel in dat enkel leden van groep `project` toegang hebben tot `/mnt/data`.

**Opdracht**  
Welke stappen zijn nodig?
1. Verander de groep van de directory:
````bash
chgrp project /mnt/data
````

2. Stel de juiste permissies in:
````bash
chmod 770 /mnt/data
````
-   `chgrp project /mnt/data` → verandert de groep van de directory naar `project`.
-   `chmod 770 /mnt/data` → stelt de permissies zo in dat de eigenaar en groep volledige toegang hebben, terwijl anderen geen toegang hebben.


## Oefening 8: Tijdelijke mount uitvoeren
Mount tijdelijk een ISO-bestand `image.iso` op `/mnt/iso`.

**Opdracht**  
Welke commando's gebruik je?
````bash
mkdir -p /mnt/iso                     # maak het mount point aan
mount -o loop image.iso /mnt/iso      # mount het ISO-bestand
````
-  `-o loop` → mount een bestand als een virtuele schijf (loop device).

-   `image.iso` → het ISO-bestand dat je wil mounten.

-   `/mnt/iso` → de map waar de inhoud van de ISO zichtbaar wordt.


## Oefening 9: Bestandssysteem controleren
Controleer of het bestandssysteem op `/dev/sdb1` fouten bevat.

**Opdracht**  
Welke tool gebruik je?
````bash
sudo umount /dev/sdb1           # unmount het bestandssysteem eerst
sudo fsck -n /dev/sdb1          # controleer het bestandssysteem zonder wijzigingen aan te brengen
sudo fsck /dev/sdb1             # voer fsck opnieuw uit om eventuele fouten te herstellen
sudo mount /dev/sdb1 /mnt/data  # mount het bestandssysteem opnieuw
````
-   `fsck` → bestandssysteem controle tool.
-   `-n` → voert een controle uit zonder wijzigingen aan te brengen (alleen lezen).
-   ⚠️ Het is belangrijk om het bestandssysteem te unmounten voordat je `fsck` uitvoert om gegevensverlies te voorkomen.
-   `sudo` → omdat `fsck` meestal root-rechten vereist.anders kan het systeem hem nog gebruiken en leesfouten veroorzaken.
-   `umount` → om het bestandssysteem te unmounten.
-   `/dev/sdb1` → de partitie die gecontroleerd wordt.
-   `fsck` kan verschillende opties hebben afhankelijk van het type bestandssysteem, dus zorg ervoor dat je de juiste gebruikt voor jouw situatie.
-  Na de controle, als er fouten worden gevonden, kan je `fsck` zonder de `-n` optie uitvoeren om de fouten te herstellen.

## Oefening 10: Rechten en eigenaarschap
Je merkt dat een bestand `data.txt` niet door een andere gebruiker kan worden gelezen. Wat doe je?

**Opdracht**  
Geef leesrechten aan anderen.
````bash
chmod o+r data.txt # geef leesrechten aan anderen
chmod 704 data.txt # stel specifieke rechten in
````
-   `chmod o+r data.txt` → geeft leesrechten aan "others" (anderen) voor het bestand `data.txt`.
-   `chmod 704 data.txt` → eigenaar volledige toegang, groep geen toegang, anderen alleen lezen
-   `o+r` → staat voor "others" (anderen) en `+r` betekent "voeg leesrechten toe".

⚠️ Wees voorzichtig met het wijzigen van bestandsrechten, vooral op gevoelige bestanden, om ongeautoriseerde toegang te voorkomen.