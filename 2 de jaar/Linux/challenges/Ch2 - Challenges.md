* # Challenges: Bestandsrechten in Linux

## 🔐 Challenge 1: Basisrechten verkennen

1. Maak een nieuw bestand `oefenbestand.txt` aan in je thuismap.
2. Gebruik `ls -l` om de rechten van dit bestand te bekijken.
3. Leg in je eigen woorden uit wat elk deel van de uitvoer betekent.

```bash
[-][rw-rw-r--] [1] [student] [student] [0] [Oct 29 22:26] [oefenbestand.txt]
```

**1.** 
```bash
[-]
```

* Eerste teken: type bestand. - = regulier bestand. (Bij een map zie je d, bij een symlink l.)

**2.**
```bash
[rw-rw-r--]
```
* Bestandsrechten, in drie groepen van drie tekens:

  * rw- (owner / eigenaar): lezen (r) + schrijven (w), geen uitvoeren ( - ).

  * rw- (group / groep): lezen + schrijven, geen uitvoeren.

  * r-- (others / anderen): alleen lezen.

* In octale vorm: 664 (owner=6, group=6, others=4).

**3.** 
```bash
[1]
```
* Aantal harde links naar het bestand. Voor gewone bestanden meestal `1`. Voor mappen hoger door `.` en `..` en bijkomende links.

**4.**
````bash
[student]
````

* Eigenaar (user) van het bestand.

**5.**
````bash
[student]
````

* Groepseigenaar van het bestand.

**6.**
````bash
[0]
````

* Bestandsgrootte in bytes. Hier: 0 bytes (lege file).

**7.**
````bash
[Oct 29 22:26]
````

* Laatste wijzigingsdatum en -tijd van het bestand (maand dag tijd).

**8.**
````bash
[oefenbestand.txt]
````

* Bestandsnaam.
---

## 🔄 Challenge 2: Rechten wijzigen met symbolische notatie

1. Verwijder het leesrecht voor "others" van `oefenbestand.txt`.
2. Voeg uitvoerrechten toe voor de gebruiker (user).
3. Zet de rechten terug naar de oorspronkelijke toestand.

````bash
chmod o-r oefenbestand.txt && chmod u+x oefenbestand.txt && chmod u=rw,g=rw,o=r oefenbestand.txt
````
## 🔢 Challenge 3: Rechten instellen met numerieke notatie

1. Stel de rechten van `oefenbestand.txt` in op `rw-r--r--` via `chmod`.
2. Zet de rechten vervolgens op `rwxr-xr--`.
3. Leg uit wat elke cijfercombinatie betekent en welke acties wel/niet mogelijk zijn.

**Stap 1: Rechten instellen op rw-r--r-- via numerieke notatie**

````bash
chmod 644 oefenbestand.txt
````

**Uitleg van 644**

* `6` (user / eigenaar) → rw- → lezen + schrijven

* `4` (group / groep) → r-- → alleen lezen

* `4` (others / anderen) → r-- → alleen lezen

**Acties mogelijk:**

* Eigenaar kan lezen en schrijven

* Groep en anderen kunnen alleen lezen

* Niemand kan uitvoeren

**Stap 2: Rechten instellen op rwxr-xr--**

````bash
chmod 754 oefenbestand.txt
````

**Uitleg van 754**

* `7` (user) → rwx → lezen + schrijven + uitvoeren

* `5` (group) → r-x → lezen + uitvoeren, niet schrijven

* `4` (others) → r-- → alleen lezen

**Acties mogelijk:**

* Eigenaar kan alles: lezen, schrijven, uitvoeren

* Groep kan lezen en uitvoeren, maar niet schrijven

* Anderen kunnen alleen lezen

* Uitvoerrechten (x) zijn belangrijk voor scripts of programma’s

💡 Tip:
Numerieke notatie:

* `4` → lezen (r)

* `2` → schrijven (w)

* `1` → uitvoeren (x)

Tellen op om combinaties te maken (`4+2=6`, `4+1=5`, `4+2+1=7`)

## 🧪 Challenge 4: Script uitvoeren

1. Maak een shellscript `hallo.sh` dat de tekst "Hallo Linux!" toont.
2. Probeer het uit te voeren met `./hallo.sh` en leg uit waarom het (niet) lukt.
3. Los het probleem op en voer het script opnieuw uit.

````bash
nano hallo.sh
````

* in nano
````bash
#!/bin/bash
echo "Hallo Linux!"
````
* dan Control + X om op te slaan

````bash
student@debiandewindt:~$ ./hallo.sh
bash: ./hallo.sh: Permission denied
````

* **kan niet uitvoeren omdat er geen x rechten op user zijn** 
````bash
ls -l
-rw-rw-r-- 1 student student   14 Oct 30 00:08 hallo.sh
````
wijzig rechten met chmod

````bash
chmod 764 hallo.sh
````

````bash
student@debiandewindt:~$ ./hallo.sh
Hallo Linux!
````
## ⚠️ Challenge 5: Umask begrijpen

**1. Geef je huidige umask weer met het `umask`-commando.**

````bash
0002
````

`umask 0002` betekent dat **bij het aanmaken** van nieuwe **bestanden en mappen** bepaalde **rechten automatisch worden weggelaten:**

**Bestanden:** standaard ``rw-rw-rw-`` **(666)**

**Mappen:** standaard ``rwxrwxrwx`` **(777)**

De ``“2”`` zorgt ervoor dat anderen (others) geen schrijfrecht krijgen.
Kort gezegd: eigenaar en groep mogen lezen en schrijven, anderen alleen lezen.

💡 de eerste nul slaat op speciale bits maar deze worden nooit gebruikt.
je kan ze weglaten dus ``002`` maar dit word bijna nooit gedaan dit voor de duidelijkheid.

| **umask** | **Bestanden (666 - umask)** | **Mappen (777 - umask)** |        **Rechten (symbolisch)**             |                              **Beschrijving**                                    |
| :-------: | :-------------------------: | :----------------------: | :-----------------------------------------: | :------------------------------------------------------------------------------: |
|   `0000`  |            `666`            |           `777`          | Bestand: `rw-rw-rw-`  <br> Map: `rwxrwxrwx` | Iedereen mag alles doen onveilig)                                                |
|   `0002`  |            `664`            |           `775`          | Bestand: `rw-rw-r--`  <br> Map: `rwxrwxr-x` | Gebruikelijk op **gedeelde systemen**: groep mag schrijven, anderen alleen lezen |
|   `0022`  |            `644`            |           `755`          | Bestand: `rw-r--r--`  <br> Map: `rwxr-xr-x` | **Standaard op de meeste systemen** (andere gebruikers kunnen niet schrijven)    |
|   `0077`  |            `600`            |           `700`          | Bestand: `rw-------`  <br> Map: `rwx------` | **Privé**: enkel eigenaar heeft toegang                                          |
|   `0027`  |            `640`            |           `750`          | Bestand: `rw-r-----`  <br> Map: `rwxr-x---` | Alleen groep kan lezen/uitvoeren, anderen hebben geen toegang                    |
|   `0037`  |            `630`            |           `740`          | Bestand: `rw--wx---`  <br> Map: `rwxr-----` | Minder voorkomend; beperkte groepsrechten                                        |


**2. Maak een nieuw bestand aan en bekijk de rechten.**

````bash
-rw-rw-r-- 1 student student    0 Oct 30 00:37 newfile.txt (664)
````
