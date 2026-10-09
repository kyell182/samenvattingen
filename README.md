# Samenvattingen ICT & Elektronica

Studiemateriaal uit mijn opleiding Elektronica-ICT aan VIVES: samenvattingen, cheatsheets, labo-verslagen en uitgewerkte opdrachten, geordend per jaar en per vak.

## Overzicht

### 1ste jaar

| Vak | Inhoud |
| :-- | :-- |
| [Digital technologie](1ste-jaar/digital%20technologie/) | Digitaal rekenen, logische poorten, tellers en flip-flops |
| [Electronica STEM](1ste-jaar/electronica%20stem/) | Weerstanden, dioden, versterkers en oscilloscoop |
| [Electronics](1ste-jaar/electronics/) | Theorie, LTspice-labo en examenvoorbereiding |
| [Introduction to gaming](1ste-jaar/introduction%20to%20gaming/) | Hardwareanalyse van de PlayStation 4 Pro |
| [Microsoft management](1ste-jaar/microsoft%20management/) | Netwerkbeheer met Windows Server 2022 |
| [PCB design](1ste-jaar/pcb%20design/) | Schema's en printplaten (LM555, IO-expander) |
| [Prototyping](1ste-jaar/prototyping/) | 3D-printen, lasersnijden en Arduino |
| [Web essentials](1ste-jaar/web%20essentials/) | HTML, CSS, Bootstrap, JavaScript en Web API's |

### 2de jaar

| Vak | Inhoud |
| :-- | :-- |
| [AI Fundamentals](2de-jaar/AI%20Fundamentals/) | Machine learning, neurale netwerken en zoekalgoritmen |
| [AI Programming](2de-jaar/AI%20Programming/) | Python, NumPy, pandas en PyTorch |
| [AI math](2de-jaar/ai%20math/) | Vectoren, matrices en de wiskunde achter AI |
| [Applied Math](2de-jaar/Applied%20Math/) | Lettervormen, vergelijkingen, afgeleiden en integralen |
| [Computer architectuur](2de-jaar/computer%20architectuur/) | Processoren, geheugen en prestatieverbetering |
| [Cybersecurity](2de-jaar/cybersecurity/) | Nmap, OSINT, Hashcat en picoCTF-challenges |
| [Databases](2de-jaar/Databases/) | Databankontwerp, SQL en security |
| [IoT devices](2de-jaar/IoT%20devices/) | I2C, SPI, WiFi en RTOS op microcontrollers |
| [Linux](2de-jaar/Linux/) | Systeembeheer, rechten, netwerk en containers |

### 3de jaar

Nog niet gestart.

## Structuur

```
samenvattingen/
  1ste-jaar/<vak>/     samenvattingen, cursusmateriaal, labo's en opdrachten
  2de-jaar/<vak>/
  3de-jaar/
  index.md             startpagina van de website
  _config.yml          Jekyll-instellingen
  .github/workflows/   automatische publicatie naar GitHub Pages
```

Elk vak heeft een `index.md` met een overzicht van de beschikbare bestanden. Samenvattingen zijn geschreven in markdown, bijbehorende bronbestanden zijn PDF, Word of Excel.

## Website lokaal bekijken

De repo wordt met Jekyll gepubliceerd op GitHub Pages. Om de site lokaal te testen heb je Ruby en Bundler nodig:

```bash
gem install jekyll bundler
jekyll serve
```

De site is daarna bereikbaar op `http://localhost:4000`.

## Gebruik

Het materiaal is bedoeld als persoonlijke studiehulp en kan fouten bevatten. Controleer belangrijke zaken altijd in de officiële cursus.
