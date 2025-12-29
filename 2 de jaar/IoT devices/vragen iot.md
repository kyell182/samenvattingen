# 📡 Studiegids – IoT Devices

Deze studiegids is bedoeld als **voorbereiding op het examen IoT Devices**.  
Lees **eerst de vraag**, denk zelf na en **klik daarna** om het antwoord te bekijken.

---

## 📘 Hoofdstuk 1 – Introductie en C-taal

**1. Wat zijn de vijf hoofddoelstellingen van de module "IoT Devices"?**

<details>
<summary>Toon antwoord</summary>

- IO-transfers inoefenen (polling, interrupts, DMA)
- Beveiligde WiFi-communicatie via ESP32-C3
- Bluetooth-communicatie naar een webbrowser
- Werken met een Realtime Operating System (RTOS)
- Correct en efficiënt gebruik van de C-taal

</details>

---

**2. Welke bibliotheek wordt gebruikt in plaats van CMSIS-code op registerniveau?**

<details>
<summary>Toon antwoord</summary>

De **Hardware Abstraction Layer (HAL)** bibliotheek.

</details>

---

**3. Hoe wordt een string of tekst opgeslagen in de C-taal?**

<details>
<summary>Toon antwoord</summary>

Als een **array van karakters** (`char[]`).

</details>

---

**4. Wat is het doel van het nulkarakter (`\0`)?**

<details>
<summary>Toon antwoord</summary>

Het nulkarakter geeft het **einde van de string** aan.

</details>

---

## 📘 Hoofdstuk 3 – Soorten IO-transfers

**1. Welke drie methoden bestaan er voor IO-transfers?**

<details>
<summary>Toon antwoord</summary>

Polling, interrupts en Direct Memory Access (DMA).

</details>

---

**2. Wat is polling en wat is het grootste nadeel?**

<details>
<summary>Toon antwoord</summary>

Polling betekent dat de CPU constant de status van een peripheral controleert.  
Het nadeel is **tijdverlies** en mogelijk **dataverlies**.

</details>

---

**3. Hoe werken interrupts en wat is een nadeel?**

<details>
<summary>Toon antwoord</summary>

De CPU wordt onderbroken om een interrupt af te handelen.  
Dit onderbreekt de normale program flow.

</details>

---

**4. Wat is DMA en hoe ontlast het de CPU?**

<details>
<summary>Toon antwoord</summary>

DMA verplaatst data tussen peripherals en geheugen zonder CPU-interventie.

</details>

---

**5. Welk planningsmechanisme gebruikt de Bus Matrix?**

<details>
<summary>Toon antwoord</summary>

Een **round-robin** schema.

</details>

---

**6. Wat was het prestatieverschil tussen UART via polling en via DMA?**

<details>
<summary>Toon antwoord</summary>

- Polling: ~57 ms CPU-tijdverlies  
- DMA: ~5,61 µs  

DMA is **meer dan 10.000× efficiënter**.

</details>

---

**7. Wat is SBUS en wat zijn de seriële eigenschappen?**

<details>
<summary>Toon antwoord</summary>

SBUS is een RC-protocol met:
- 100k baud  
- 2 stopbits  
- even parity  
- inverted RX

</details>

---

**8. Welke technieken werden gebruikt in de automatisch kofferdeksel demo?**

<details>
<summary>Toon antwoord</summary>

- Timer Input Capture (ultrasone sensor)
- Timer PWM (servo)

</details>

---

## 📘 Hoofdstuk 6 – WiFi en Netwerkcommunicatie

**1. Welke WiFi-module en chip worden gebruikt?**

<details>
<summary>Toon antwoord</summary>

De **LILYGO T-01C3** met **ESP32-C3**.

</details>

---

**2. Wat is Postman en waarvoor wordt het gebruikt?**

<details>
<summary>Toon antwoord</summary>

Een tool om **HTTP GET en POST requests** te testen.

</details>

---

**3. Wat is het verschil tussen HTTP GET en POST?**

<details>
<summary>Toon antwoord</summary>

GET vraagt data op.  
POST stuurt data naar de server.

</details>

---

**4. Wat is Firebase RTDB en welk request vereist authenticatie?**

<details>
<summary>Toon antwoord</summary>

Een realtime NoSQL database.  
**PATCH** vereist authenticatie.

</details>

---

**5. Wat zijn AT-commando’s en hun structuur?**

<details>
<summary>Toon antwoord</summary>

Tekstcommando’s via UART:  
`AT+COMMAND\r\n`

</details>

---

**6. Waarom is een circulaire buffer nuttig?**

<details>
<summary>Toon antwoord</summary>

Om snelle inkomende data op te vangen zonder verlies.

</details>

---

**7. Wat doet de watchdog timer in de ESP32-C3 demo?**

<details>
<summary>Toon antwoord</summary>

Reset de microcontroller bij vastlopen (>6 s).

</details>

---

**8. Leg het MQTT publisher/subscriber model uit.**

<details>
<summary>Toon antwoord</summary>

Publishers sturen data naar een broker.  
Subscribers ontvangen data via topics.

</details>

---

## 📘 Hoofdstuk 7 – RTOS deel 1

**1. Wat is een RTOS en wat is preemptive multitasking?**

<details>
<summary>Toon antwoord</summary>

Een RTOS beheert taken met prioriteiten.  
Taken kunnen worden onderbroken.

</details>

---

**2. Wat is een context switch en wat wordt opgeslagen?**

<details>
<summary>Toon antwoord</summary>

De toestand van een thread wordt opgeslagen in een **TCB**.

</details>

---

**3. Waarom osDelay() gebruiken i.p.v. HAL_Delay()?**

<details>
<summary>Toon antwoord</summary>

osDelay() blokkeert de thread zonder CPU-tijd te verspillen.

</details>

---

## 📘 Hoofdstuk 8 – RTOS deel 2

**1. Wat is priority inversion?**

<details>
<summary>Toon antwoord</summary>

Een lage-prioriteit thread blokkeert een hoge-prioriteit thread.

</details>

---

## 📚 Begrippenlijst

| Begrip | Definitie |
|------|----------|
| AT-Commando | Tekstcommando via UART (`AT+COMMAND\r\n`) |
| Binary Semaphore | Synchronisatie met 0/1 toestand |
| Bus Matrix | Regelt bus-toegang via round-robin |
| C-String | Char-array eindigend op `\0` |
| Circulair Buffer | Buffer met ronddraaiende pointers |
| CMSIS | ARM hardware-abstractiestandaard |
| Context Switch | Wissel van thread via TCB |
| Counting Semaphore | Semaphore met teller |
| DMA | Data-overdracht zonder CPU |
| Event Flags | Bit-gebaseerde thread-signalen |
| Firebase RTDB | Google realtime NoSQL database |
| HAL | Hardware Abstraction Layer |
| Interrupt | Onmiddellijke CPU-onderbreking |
| Message Queue | FIFO voor thread-communicatie |
| MQTT | Publish/subscribe IoT-protocol |
| Mutex | Exclusieve toegang met priority inheritance |
| NVIC | ARM interrupt controller |
| Polling | Actief status controleren |
| RTOS | Realtime Operating System |
| SBUS | Serieel RC-protocol |
| Software Timer | RTOS-timer met callback |
| TCB | Thread Control Block |
| Watchdog Timer | Reset bij vastlopen |
| WiFi | IEEE 802.11 draadloos netwerk |

