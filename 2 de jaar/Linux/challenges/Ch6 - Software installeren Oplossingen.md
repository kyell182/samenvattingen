
# Oefeningen: Werken met APT en repositories

## Oefening 1: Informatie opvragen over een pakket

**Opdracht:**  
Zoek op welke versie van het pakket `curl` beschikbaar is via APT en geef een korte beschrijving van wat het pakket doet.

**Oplossing:**  
Voer het volgende commando uit:  
`apt show curl`

Uit de output kun je aflezen:  
- Versie (bijv. Version: 7.81.0-1ubuntu1.13)  
- Beschrijving: command-line tool for transferring data with URL syntax

---

## Oefening 2: Software installeren en verwijderen met APT

**Opdracht:**  
Installeer het pakket `htop`, verwijder het vervolgens met behoud van configuratiebestanden, en daarna volledig inclusief configuratie.

**Oplossing:**

- Installeren:  
  `sudo apt install htop`

- Verwijderen zonder configuratiebestanden te wissen:  
  `sudo apt remove htop`

- Verwijderen inclusief configuratiebestanden:  
  `sudo apt purge htop`

---

## Oefening 3: Overbodige pakketten opruimen

**Opdracht:**  
Na het verwijderen van een pakket blijven afhankelijkheden soms staan. Hoe verwijder je automatisch ongebruikte afhankelijkheden?

**Oplossing:**  
`sudo apt autoremove`

---

## Oefening 4: Een .deb-bestand lokaal installeren

**Opdracht:**  
Je hebt het bestand `example.deb` gedownload. Installeer dit pakket en los eventuele afhankelijkheden op.

**Oplossing:**

1. Installeer het `.deb`-bestand:  
   `sudo dpkg -i example.deb`

2. Herstel ontbrekende afhankelijkheden:  
   `sudo apt-get install -f`


---

## Oefening 5: Andere repository toevoegen (Visual Studio Code)

**Opdracht:**  
Voeg de officiële Microsoft Visual Studio Code repository toe, inclusief sleutel via keyring.

**Oplossing:**

1. Download en importeer de GPG-sleutel:  
   `wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > /tmp/microsoft.gpg`  
   `sudo install -D -o root -g root -m 644 /tmp/microsoft.gpg /etc/apt/keyrings/microsoft.gpg`

2. Voeg de repository toe:  
   `echo "deb [arch=amd64 signed-by=/etc/apt/keyrings/microsoft.gpg] https://packages.microsoft.com/repos/code stable main" | sudo tee /etc/apt/sources.list.d/vscode.list`

3. Update de pakketlijst:  
   `sudo apt update`

---

## Oefening 6: Alleen beveiligingsupdates weergeven

**Opdracht:**  
Hoe kun je op een Debian/Ubuntu-systeem enkel beveiligingsupdates tonen?

**Oplossing:**  
`apt list --upgradable | grep security`

---

## Oefening 7: Een lijst tonen van alle geïnstalleerde pakketten

**Opdracht:**  
Welke opdracht toont een lijst van alle geïnstalleerde pakketten?

**Oplossing:**  
`apt list --installed`

---

## Oefening 8: Zoek een pakket in de repositories

**Opdracht:**  
Je wil weten of het pakket `git` beschikbaar is in de repository. Hoe zoek je dit op?

**Oplossing:**  
`apt search git`

---

## Oefening 9: Meer details over een repositorybestand

**Opdracht:**  
Waar worden APT-repositorydefinities opgeslagen?

**Oplossing:**  
In `/etc/apt/sources.list` en bestanden in `/etc/apt/sources.list.d/`

---

## Oefening 10: Wat doet `apt upgrade`?

**Opdracht:**  
Wat is het verschil tussen `apt update` en `apt upgrade`?

**Oplossing:**  
- `apt update`: ververst de lijst van beschikbare pakketten  
- `apt upgrade`: installeert de nieuwste versies van reeds geïnstalleerde pakketten

---

## Oefening 11: Pakketversie forceren

**Opdracht:**  
Je wil een specifieke versie van `nginx` installeren (1.22.1-9+deb12u2). Hoe doe je dat?

**Oplossing:**  
`sudo apt install nginx=1.22.1-9+deb12u2`

---

## Oefening 12: Pakket blokkeren tegen updates

**Opdracht:**  
Hoe voorkom je dat `nginx` automatisch geüpdatet wordt?

**Oplossing:**  
`sudo apt-mark hold nginx`  
(Om de blokkering op te heffen: `sudo apt-mark unhold nginx`)

---

## Oefening 13: Cache van APT bekijken

**Opdracht:**  
Waar worden gedownloade pakketten opgeslagen door APT?

**Oplossing:**  
In `/var/cache/apt/archives/`

---

## Oefening 14: Cache leegmaken

**Opdracht:**  
Hoe verwijder je alle gedownloade pakketten in de cache?

**Oplossing:**  
`sudo apt clean`

