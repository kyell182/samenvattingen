# Studiegids IoT Devices

Welkom bij de studiegids voor het examen **IoT Devices**. Deze gids behandelt de kernconcepten van microcontrollers, IO-transfers, WiFi-communicatie en RTOS, inclusief quizvragen met **inklapbare antwoorden** en voldoende **ruimte voor notities**.

---

## Deel 1: Basisprincipes en IO-Transfers

### 1.1 Inleiding en Doelstellingen

**Quizvraag:**  
Wat is het hoofddoel van de overstap van CMSIS-code naar HAL-bibliotheken, en welke drie methoden voor IO-transfers staan centraal?

<details>
<summary>Antwoord</summary>

Doel: Werken op een hoger abstractieniveau, snellere ontwikkeling en betere portabiliteit.  

**Drie methoden voor IO-transfers:**  
1. **Polling** – Continu controleren of een peripheral data heeft.  
2. **Interrupts** – Hardware laat CPU weten wanneer data beschikbaar is.  
3. **DMA** – CPU ontlasten door een aparte controller de dataoverdracht te laten uitvoeren.  

**Extra doelstellingen:**  
- Beveiligde WiFi-communicatie op ESP32-C3.  
- Werken met een Real-Time Operating System (RTOS).  
- Verdieping in C (pointers, strings).  

</details>

---

### 1.2 C-Taal Concepten: Strings

**Quizvraag:**  
Hoe wordt een string in C voorgesteld in het geheugen en welk speciaal karakter is essentieel?

<details>
<summary>Antwoord</summary>

Strings zijn **char-arrays**.  
Het **nulkarakter** (`\0`) geeft het einde van de string aan. Zonder dit karakter weten functies zoals `printf` niet waar de string stopt.

Praktisch: Bij UART wordt een lus gebruikt om karakters te verzenden tot het nulkarakter.

</details>

---

### 1.3 Methoden voor IO-Transfers

#### Polling

**Quizvraag:**  
Wat is het principe en nadeel van polling?  

<details>
<summary>Antwoord</summary>

**Principe:** CPU vraagt continu of data aanwezig is.  

**Nadeel:** Bij vertragingen kan data gemist worden, omdat de CPU andere taken uitvoert.

</details>

#### Interrupts

**Quizvraag:**  
Hoe lost een interrupt het nadeel van polling op en waar wordt de data verwerkt?

<details>
<summary>Antwoord</summary>

**Principe:** CPU wordt alleen gealarmeerd bij beschikbare data.  

**Mechanisme:** Data wordt verwerkt in de ISR (`HAL_UART_RxCpltCallback`) buiten de hoofdlus.  

**Nadeel:** Context switching kost processortijd.

</details>

#### DMA

**Quizvraag:**  
Wat is het voordeel van DMA t.o.v. polling en interrupts?

<details>
<summary>Antwoord</summary>

**Principe:** CPU wordt volledig vrijgesteld; DMA-controller voert de transfer uit.  

**Voordeel:** CPU kan ondertussen andere taken uitvoeren; zeer efficiënte data-overdracht.

</details>

---

### 1.4 Vergelijking Polling vs DMA

**Quizvraag:**  
Hoeveel efficiënter is DMA dan polling?

<details>
<summary>Antwoord</summary>

- Polling: CPU geblokkeerd 57.25 ms  
- DMA: CPU geblokkeerd 5.61 µs  

DMA is >10.000x efficiënter voor data-overdracht.

</details>

---

## Deel 2: WiFi en Netwerkcommunicatie

### 2.1 ESP32-C3 Basis

**Quizvraag:**  
Welk protocol wordt gebruikt om te communiceren met de ESP32-C3 vanaf de Nucleo-controller?

<details>
<summary>Antwoord</summary>

**Protocol:** AT-commando’s over UART.  
ESP32-C3 heeft 2.4GHz WiFi en Bluetooth 5 (LE).  
AT-firmware laat netwerkoperaties uitvoeren via tekstcommando’s.

</details>

---

### 2.2 Buffering en Web Requests

**Quizvraag:**  
Waarom is een circular buffer essentieel voor WiFi-modules?

<details>
<summary>Antwoord</summary>

Circular buffer voorkomt overflow van de UART-buffer; data kan rustig verwerkt worden uit de buffer.  

**Testsoftware:** Postman voor GET/POST/HTTPS requests.

| Request Type | Gebruik | Voorbeeld | Beveiliging |
|-------------|---------|-----------|------------|
| HTTP GET | Data ophalen | rubu.be | Onbeveiligd |
| HTTP POST | Data versturen | rubu.be | Onbeveiligd |
| HTTPS GET | Data ophalen | Firebase RTDB | Beveiligd |
| HTTPS PATCH | Data schrijven | Firebase RTDB | Beveiligd |

</details>

---

### 2.3 MQTT Protocol

**Quizvraag:**  
Wat zijn de drie hoofdcomponenten van MQTT?

<details>
<summary>Antwoord</summary>

1. **Publisher:** Stuurt berichten naar een topic.  
2. **Subscriber:** Ontvangt berichten van een topic.  
3. **Broker:** Centrale server die berichten distribueert.

</details>

---

## Deel 3: Real-Time Operating System (RTOS)

### 3.1 Wat is een RTOS?

**Quizvraag:**  
Wat is een preemptive multitasking OS en wat is de rol van scheduler en time slice?

<details>
<summary>Antwoord</summary>

- **Preemptive:** OS kan een taak onderbreken voor een hogere prioriteit.  
- **Multitasking:** Meerdere taken schijnbaar tegelijk uitvoeren.  
- **Scheduler:** Beslist welke taak draait en geeft tijdsloten (time slices).  
- **Context switch:** Opslaan/laden van taakstatus in Thread Control Block (TCB).

</details>

---

### 3.2 Delays en thread states

**Quizvraag:**  
Waarom is HAL_Delay() slecht in RTOS? Wat is het alternatief?

<details>
<summary>Antwoord</summary>

- **HAL_Delay():** Blocking, CPU 100% bezet.  
- **Alternatief:** `osDelay()`, thread gaat naar **Blocked** state, CPU vrij voor andere taken.  

**Thread states:** Running, Ready, Blocked, Suspended.

</details>

---

### 3.3 Synchronisatie Primitives

**Quizvraag:**  
Koppel RTOS-primitives aan hun functie:

<details>
<summary>Antwoord</summary>

| Primitive | Functie |
|-----------|---------|
| Message Queue | FIFO-buffer om data veilig door te geven tussen threads |
| Binary Semaphore | Wachten op simpele gebeurtenis (open/dicht) |
| Mutex | Exclusieve toegang tot gedeelde resources (UART) |
| Event Flags | Signalen van complexe gebeurtenissen tussen threads |

**Counting Semaphore:** Houdt een teller bij, handig voor beschikbare bufferplekken.

</details>

---

## Begrippenlijst

| Begrip | Definitie |
|--------|-----------|
| HAL | Hardware Abstraction Layer, maakt code portabel en makkelijker te schrijven |
| Polling | CPU controleert continu status van peripheral |
| Interrupt | CPU wordt gealarmeerd bij gebeurtenis door hardware |
| DMA | Data transfer door speciale controller zonder CPU |
| Bus Matrix | Coördineert toegang van verschillende bus masters |
| Round-robin | Elke deelnemer krijgt om beurt gelijke toegang |
| ESP32-C3 | Microcontroller met WiFi en Bluetooth 5 |
| AT-commando's | Tekstcommando's over UART voor module aansturing |
| Circular Buffer | Datastructuur om data op te slaan in cirkelvorm, voorkomt overflow |
| Firebase RTDB | Realtime NoSQL database in de cloud |
| MQTT | Publish-subscribe netwerkprotocol voor IoT devices |
| RTOS | Real-Time Operating System met preemptive scheduler |
| Scheduler | Bepaalt welke taak wanneer draait |
| Context Switch | Opslaan/laden van thread status |
| TCB | Thread Control Block, opslaan van threadcontext |
| Message Queue | FIFO-buffer tussen threads |
| Semaphore | Synchronisatie primitive (binary of counting) |
| Mutex | Exclusieve toegang tot shared resource |
| Priority Inversion | Lage prioriteit taak blokkeert hoge prioriteit taak |
| Software Timer | Timer beheerd door RTOS kernel, roept callback op |
