
# Oefeningen: Werken met APT en repositories

## Oefening 1: Informatie opvragen over een pakket

**Opdracht:**  
Zoek op welke versie van het pakket `curl` beschikbaar is via APT en geef een korte beschrijving van wat het pakket doet.
````bash
apt show curl
version : 8.14.1-2
Description: command line tool for transferring data with URL syntax

````


---

## Oefening 2: Software installeren en verwijderen met APT

**Opdracht:**  
Installeer het pakket `htop`, verwijder het vervolgens met behoud van configuratiebestanden, en daarna volledig inclusief configuratie.

````bash
sudo apt update # Update de pakketlijsten
sudo apt install htop # Installeer htop
sudo apt remove htop # Verwijder htop, behoud configuratiebestanden
sudo apt purge htop # Verwijder htop volledig, inclusief configuratiebestanden
````

---

## Oefening 3: Overbodige pakketten opruimen

**Opdracht:**  
Na het verwijderen van een pakket blijven afhankelijkheden soms staan. Hoe verwijder je automatisch ongebruikte afhankelijkheden?

````bash
sudo apt autoremove
````

---

## Oefening 4: Een .deb-bestand lokaal installeren

**Opdracht:**  
Je hebt het bestand `example.deb` gedownload. Installeer dit pakket en los eventuele afhankelijkheden op.

````bash
sudo dpkg -i example.deb # Installeer het .deb-bestand
````
-   dpkg -i probeert het pakket te installeren.

-   Mogelijk krijg je een foutmelding als er ontbrekende afhankelijkheden zijn.

Gebruik dan de volgende opdracht om de afhankelijkheden op te lossen:
````bash
sudo apt-get install -f # Los eventuele afhankelijkheden op
````
-   De optie **-f** staat voor **“fix broken”** en installeert de ontbrekende pakketten die het .deb-bestand nodig heeft.

-   Daarna is example.deb correct geïnstalleerd.

---

## Oefening 5: Andere repository toevoegen (Visual Studio Code)

**Opdracht:**  
Voeg de officiële Microsoft Visual Studio Code repository toe, inclusief sleutel via keyring.

````bash
# Download en installeer de Microsoft GPG-sleutel
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor | sudo tee /usr/share/keyrings/packages.microsoft.gpg > /dev/null
# Voeg de Visual Studio Code repository toe aan de APT-bronlijst
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" | sudo tee /etc/apt/sources.list.d/vscode.list
````

---

## Oefening 6: Alleen beveiligingsupdates weergeven

**Opdracht:**  
Hoe kun je op een Debian/Ubuntu-systeem enkel beveiligingsupdates tonen?
````bash
apt list --upgradable | grep -i security # i staat voor case insensitive
````
---

## Oefening 7: Een lijst tonen van alle geïnstalleerde pakketten

**Opdracht:**  
Welke opdracht toont een lijst van alle geïnstalleerde pakketten?
````bashbash
apt list --installed
````
---

## Oefening 8: Zoek een pakket in de repositories

**Opdracht:**  
Je wil weten of het pakket `git` beschikbaar is in de repository. Hoe zoek je dit op?
````bash
apt search git
````

---

## Oefening 9: Meer details over een repositorybestand

**Opdracht:**  
Waar worden APT-repositorydefinities opgeslagen?
````bash
In het bestand
/etc/apt/sources.list # is de hoofdbronlijst
en in de map    
/etc/apt/sources.list.d/ # voor extra bronlijsten
````    
---

## Oefening 10: Wat doet `apt upgrade`?

**Opdracht:**  
Wat is het verschil tussen `apt update` en `apt upgrade`?
| Commando      | Doel                                      | Wat het doet                                                                 | Opmerking                                         |
|---------------|------------------------------------------|-----------------------------------------------------------------------------|--------------------------------------------------|
| `apt update`  | Pakketlijst bijwerken                     | Downloadt nieuwste informatie van alle repositories; installeert niets      | Alleen informatie ophalen, geen installatie     |
| `apt upgrade` | Geïnstalleerde pakketten updaten         | Installeert updates voor alle geïnstalleerde pakketten met nieuwe versies   | Verwijdert geen pakketten en installeert geen nieuwe afhankelijkheden |

`

---

## Oefening 11: Pakketversie forceren

**Opdracht:**  
Je wil een specifieke versie van `nginx` installeren (1.22.1-9+deb12u2). Hoe doe je dat?
````bash
sudo apt install nginx=1.22.1-9+deb12u2
````
---

## Oefening 12: Pakket blokkeren tegen updates

**Opdracht:**  
Hoe voorkom je dat `nginx` automatisch geüpdatet wordt?
````bashbash
sudo apt-mark hold nginx
````

---

## Oefening 13: Cache van APT bekijken

**Opdracht:**  
Waar worden gedownloade pakketten opgeslagen door APT?
````bash
De gedownloade pakketten worden opgeslagen in de map:
/var/cache/apt/archives/
````

---

## Oefening 14: Cache leegmaken

**Opdracht:**  
Hoe verwijder je alle gedownloade pakketten in de cache?
````bash
sudo apt clean # Verwijdert alle bestanden in de cache
````


| Commando                  | Wat het doet                                                       | Opmerking                                           |
|----------------------------|-------------------------------------------------------------------|---------------------------------------------------|
| `sudo apt clean`           | Verwijdert **alle gedownloade .deb-bestanden** uit de cache       | Maakt schijfruimte vrij, pakketten moeten opnieuw gedownload worden als je ze installeert |
| `sudo apt autoclean`       | Verwijdert alleen **verouderde .deb-bestanden** die niet meer beschikbaar zijn in de repository | Minder agressief dan `clean`                     |
| `sudo apt autoremove`      | Verwijdert automatisch **overbodige afhankelijkheden** van niet meer gebruikte pakketten | Handig om systeem schoon te houden              |

💡 tip : een goede volgorde voor ondrhoud is meestal:
````bash
sudo apt update
sudo apt upgrade
sudo apt autoremove
sudo apt clean
````