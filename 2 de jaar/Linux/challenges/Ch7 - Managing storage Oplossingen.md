
# Oefeningen Linux Storage

## Oefening 1: Nieuwe schijf detecteren
Gebruik het juiste commando om te zien welke schijven aan het systeem gekoppeld zijn.

**Opdracht**  
Welke schijf is recent toegevoegd aan het systeem?

**Antwoord**  
Gebruik `lsblk` of `sudo fdisk -l`. De nieuwe schijf verschijnt als `/dev/sdb`, `/dev/sdc`, ...

---

## Oefening 2: Schijf partitioneren met fdisk
Initialiseer een nieuwe schijf `/dev/sdb` met een enkele partitie.

**Opdracht**  
Gebruik het `fdisk`-commando om een nieuwe partitie aan te maken.

**Antwoord**  
`sudo fdisk /dev/sdb`  
Volg de instructies: `n` + `Enter` vier keer + `w` om te schrijven.

---

## Oefening 3: Filesysteem aanmaken
Maak een XFS-filesysteem aan op `/dev/sdb1`.

**Opdracht**  
Welk commando gebruik je?

**Antwoord**  
`sudo mkfs.xfs /dev/sdb1`

---

## Oefening 4: Mount point maken en mounten
Mount `/dev/sdb1` op `/mnt/data`.

**Opdracht**  
Welke commando’s voer je uit?

**Antwoord**  
`sudo mkdir /mnt/data`  
`sudo mount /dev/sdb1 /mnt/data`

---

## Oefening 5: Automatisch mounten bij opstart
Zorg dat `/dev/sdb1` automatisch mount op `/mnt/data` bij het opstarten.

**Opdracht**  
Wat moet je aanpassen?

**Antwoord**  
Voeg een regel toe aan `/etc/fstab` met UUID en mountopties.  
Bijvoorbeeld:  
`UUID=xxx-xxx /mnt/data xfs defaults 0 0`

---

## Oefening 6: Diskgebruik controleren
Controleer hoeveel ruimte beschikbaar is op het bestandssysteem.

**Opdracht**  
Welke commando’s kan je gebruiken?

**Antwoord**  
`df -h` toont ruimte per gemount bestandssysteem  
`du -sh /pad/naar/map` toont gebruik van een specifieke map

---

## Oefening 7: Bestandssysteem permissies instellen
Stel in dat enkel leden van groep `project` toegang hebben tot `/mnt/data`.

**Opdracht**  
Welke stappen zijn nodig?

**Antwoord**  
`sudo chgrp project /mnt/data`  
`sudo chmod 770 /mnt/data`

---

## Oefening 8: Tijdelijke mount uitvoeren
Mount tijdelijk een ISO-bestand `image.iso` op `/mnt/iso`.

**Opdracht**  
Welke commando's gebruik je?

**Antwoord**  
`sudo mkdir /mnt/iso`  
`sudo mount -o loop image.iso /mnt/iso`

---

## Oefening 9: Bestandssysteem controleren
Controleer of het bestandssysteem op `/dev/sdb1` fouten bevat.

**Opdracht**  
Welke tool gebruik je?

**Antwoord**  
`sudo xfs_repair /dev/sdb1` (voor XFS)  
of  
`sudo fsck /dev/sdb1` (voor ext4)

---

## Oefening 10: Rechten en eigenaarschap
Je merkt dat een bestand `data.txt` niet door een andere gebruiker kan worden gelezen. Wat doe je?

**Opdracht**  
Geef leesrechten aan anderen.

**Antwoord**  
`chmod o+r data.txt`

