# 📘 IoT Devices – Samenvattingen & Oefenvragen  
**VIVES – ICT & Elektronica**

Deze repository bevat gestructureerde studievragen met uitklapbare antwoorden en een begrippenlijst.  
Ideaal om actief te studeren: eerst nadenken, dan pas controleren.

---

## 📂 Inhoud
- [📘 IoT Devices – Samenvattingen \& Oefenvragen](#-iot-devices--samenvattingen--oefenvragen)
  - [📂 Inhoud](#-inhoud)
  - [📖 Hoofdstuk 1 – Introductie \& C-taal](#-hoofdstuk-1--introductie--c-taal)
  - [📖 Hoofdstuk 3 – Soorten IO-transfers](#-hoofdstuk-3--soorten-io-transfers)
  - [📖 Hoofdstuk 6 – WiFi \& Netwerkcommunicatie](#-hoofdstuk-6--wifi--netwerkcommunicatie)
  - [📖 Hoofdstuk 7 – RTOS deel 1](#-hoofdstuk-7--rtos-deel-1)
  - [📖 Hoofdstuk 8 – RTOS deel 2](#-hoofdstuk-8--rtos-deel-2)
  - [📚 Begrippenlijst](#-begrippenlijst)
  - [📌 Gebruik](#-gebruik)
  - [📄 Licentie](#-licentie)

---

## 📖 Hoofdstuk 1 – Introductie & C-taal

**1. Wat zijn de vijf hoofddoelstellingen van de module “IoT Devices”?**

<details>
<summary>Antwoord tonen</summary>

- IO-transfers inoefenen (polling, interrupts, DMA)  
- Beveiligde WiFi-communicatie via ESP32-C3  
- Bluetooth-communicatie naar een webbrowser  
- Werken met een RTOS  
- Correct gebruik van de C-programmeertaal  

</details>

<br>

**2. Welke bibliotheek wordt gebruikt in plaats van CMSIS-code op registerniveau?**

<details>
<summary>Antwoord tonen</summary>

De Hardware Abstraction Layer (HAL) bibliotheek.

</details>

<br>

**3. Hoe wordt een string opgeslagen in de C-taal?**

<details>
<summary>Antwoord tonen</summary>

Als een array van karakters die eindigt met het nulkarakter (`\0`).

</details>

<br>

**4. Wat is het doel van het nulkarakter (`\0`)?**

<details>
<summary>Antwoord tonen</summary>

Het geeft het einde van de string aan zodat functies weten waar de tekst stopt.

</details>

---

## 📖 Hoofdstuk 3 – Soorten IO-transfers

**1. Welke drie methoden bestaan er voor IO-transfers?**

<details>
<summary>Antwoord tonen</summary>

* Polling
* interrupts  
* Direct Memory Access (DMA).

</details>

<br>

**2. Leg het concept 'polling' uit. Wat is het grootste nadeel?**

<details>
<summary>Antwoord tonen</summary>

De CPU controleert continu de status van een peripheral.  
Grootste nadeel: CPU-tijd wordt verspild en data kan verloren gaan.

</details>

<br>

**3. Hoe werkt communicatie via 'interrupts'? Wat is een nadeel?**

<details>
<summary>Antwoord tonen</summary>

De CPU wordt onderbroken om een gebeurtenis af te handelen.  
Nadeel: de normale programmastructuur wordt onderbroken.

</details>

<br>

**4. Wat is de functie van Direct Memory Access (DMA)?**

<details>
<summary>Antwoord tonen</summary>

DMA laat randapparatuur rechtstreeks data naar geheugen sturen zonder CPU-interventie.

</details>

---

## 📖 Hoofdstuk 6 – WiFi & Netwerkcommunicatie

**1. Welke WiFi-module wordt gebruikt en welke chip bevat deze?**

<details>
<summary>Antwoord tonen</summary>

De LILYGO T-01C3 module met een **ESP32-C3 chip**.

</details>

<br>

**2. Wat is Postman en waarvoor wordt het gebruikt?**

<details>
<summary>Antwoord tonen</summary>

Een tool om HTTP-requests te testen en analyseren (GET, POST).

</details>

<br>

**3. Wat is het verschil tussen HTTP GET en POST?**

<details>
<summary>Antwoord tonen</summary>

- GET: data opvragen van een server  
- POST: data verzenden naar een server

</details>

<br>

**4. Wat is Firebase RTDB en welke requests vereisen authenticatie?**

<details>
<summary>Antwoord tonen</summary>

Realtime NoSQL database.  
PATCH/WRITE requests vereisen authenticatie.

</details>

---

## 📖 Hoofdstuk 7 – RTOS deel 1

**1. Wat is een RTOS en wat betekent "preemptive multitasking"?**

<details>
<summary>Antwoord tonen</summary>

* RTOS = Realtime Operating System, beheert meerdere taken met timing. 

* Preemptive multitasking = een hogere-prioriteit taak kan een lagere taak onderbreken.

</details>

<br>

**2. Wat is een context switch en welk onderdeel wordt opgeslagen?**

<details>
<summary>Antwoord tonen</summary>

Een context switch bewaart de toestand van een thread in een **Thread Control Block (TCB)** om later terug te keren.

</details>

<br>

**3. Welke functie gebruik je voor vertraging in een RTOS in plaats van HAL_Delay()?**

<details>
<summary>Antwoord tonen</summary>

`osDelay()`, omdat dit de CPU vrijlaat terwijl de thread wacht.

</details>

---

## 📖 Hoofdstuk 8 – RTOS deel 2

**1. Wat is een binaire semafoor en waarvoor kan deze gebruikt worden?**

<details>
<summary>Antwoord tonen</summary>

Synchronisatiemechanisme: slechts één thread kan het tegelijk "bezitten". Andere threads worden geblokkeerd.

</details>

<br>

**2. Wat is het verschil tussen een counting semaphore en een binaire semafoor?**

<details>
<summary>Antwoord tonen</summary>

Counting semaphore houdt een teller bij; binaire semafoor slechts 0 of 1.

</details>

<br>

**3. Wat is een Mutex en wat is een belangrijk verschil met een semafoor?**

<details>
<summary>Antwoord tonen</summary>

Mutex = exclusieve toegang voor één thread; implementeert priority inheritance.

</details>

---

## 📚 Begrippenlijst

| Begrip | Uitleg |
|------|-------|
| RTOS | Besturingssysteem voor taken met strikte timing |
| HAL | Bibliotheek die hardware-details verbergt |
| Polling | CPU controleert continu een status |
| Interrupt | Signaal dat de CPU onderbreekt |
| DMA | Data-overdracht zonder CPU-belasting |
| Scheduler | Bepaalt taakvolgorde in een RTOS |
| Mutex | Beschermt gedeelde resources |
| Semaphore | Synchronisatie tussen taken |
| Task | Onafhankelijke uitvoerbare eenheid |
| Thread | Lichte uitvoering binnen een taak |
| Context Switch | Overgang tussen threads, toestand opgeslagen in TCB |
| Watchdog Timer | Reset microcontroller bij vastgelopen software |
| MQTT | Publish/subscribe protocol voor IoT |
| SBUS | Serieel communicatieprotocol voor RC |

---

## 📌 Gebruik
- Klik enkel op “Antwoord tonen” na zelf nadenken  
- Geschikt voor examenvoorbereiding  
- Uitbreidbaar per hoofdstuk  

---

## 📄 Licentie
Vrij te gebruiken voor educatieve doeleinden binnen VIVES.
