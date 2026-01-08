# Computer Architecture: referentievragen en antwoorden

---

## Chapter 1  Introducing Computer Architecture

### Vragen

<details>
<summary><strong>
Licht enkele technologische problemen toe die Charles Babbage ervoer bij het ontwerp van zijn Analytical Engine.
</strong></summary>

![analytical_engine](./assets/charles%20babbage's%20analytical%20engine.png)
![analytical_engine_diagram](./assets/technical%20diagram%20analytical%20engine.png)

- **mechanische precisie**
  
  - in die tijd was het nog niet mogelijk om tandwielen met voldoende precisie te maken.

- **wrijving**
  
  - door de vele bewegende delen was er veel wrijving, wat leidde tot slijtage en verminderde betrouwbaarheid.

- **tandwielspeling**

  - de speling tussen de tandwielen veroorzaakte onnauwkeurigheden in de berekeningen.

â—dit probleem werd opgelost door locking mechanisms te ontwerpen. deze zorgden ervoor dat de tandwielen werden vergrendeld en in geldige posities werden geforceerd.

- **slijtage**
  
  - de mechanische onderdelen waren onderhevig aan slijtage door continu gebruik, wat de levensduur van de machine beperkte.

- **hoge kosten**
  
  - de bouw van zo'n complex mechanisch apparaat was duur en vereiste gespecialiseerde vakmensen.

- complexiteit carry propagation
  
  - het doorvoeren van carries in berekeningen was ingewikkeld en leidde tot vertragingen en fouten.

</details>

<details>
<summary><strong>
Wat betekent ENIAC en bespreek bondig de Von Neumann architectuur?
</strong></summary>

![eniac](./assets/eniac%20.png)

- **ENIAC** staat voor **Electronic Numerical Integrator And Computer**. Het was een van de eerste elektronische algemene computers, gebouwd in de jaren 1940.

- **Von Neumann architectuur**:
  
  - **Geheugen:** zowel data als programma-instructies worden opgeslagen in hetzelfde geheugen.
  
  - **CPU:** bestaat uit een rekenkundig-logische eenheid (ALU) en een besturingseenheid (CU) die instructies ophalen, decoderen en uitvoeren.
  
  - **Instructiecyclus:** de CPU voert een cyclus uit van ophalen, decoderen en uitvoeren van instructies.
  
  - **Seriele verwerking:** instructies worden sequentieel uitgevoerd, wat kan leiden tot bottlenecks (Von Neumann bottleneck).

![von_neumann_architecture](./assets/neumann%20architectuur.png)

</details>

**De microprocessor van de oorspronkelijke IBM PC is de Intel 8088, die tot de Intel 80x86 microprocessor familie behoort.**

**Deze i80x86 microprocessoren werken met een gesegmenteerd geheugenmodel:**

<details>
<summary><strong>
Wat is een segment?
</strong></summary>

- een segment is een blok geheugen met een eigen basisadres.
  In de i80x86 architectuur wordt geheugen opgedeeld in segmenten van maximaal 64 KB.

</details>

<details>
<summary><strong>
Wat zijn de voordelen van het gesegmenteerd geheugenmodel?
</strong></summary>
  
- ***grotere adresseerbare ruimte:*** door segmentatie kan een programma meer geheugen gebruiken dan de limiet van een enkel 16-bit adres.
  
- ***logische opdeling:*** segmentatie maakt het mogelijk om code, data en stack in aparte segmenten te plaatsen, wat de organisatie van programma's verbetert.
  
- ***hergebruik van code:*** segmenten kunnen worden gedeeld tussen verschillende programma's, wat geheugenbesparing oplevert.

</details>

<details>
<summary><strong>
Ondanks de 16-bits architectuur van de registers, is de adresseerbare geheugenruimte 1 MB. Verklaar.
</strong></summary>

- in de i80x86 architectuur wordt het fysieke adres berekend met behulp van een segment:offset combinatie.
  
- elk segmentregister bevat een 16-bit waarde die wordt vermenigvuldigd met 16 (of verschoven naar links met 4 bits) om het basisadres van het segment te verkrijgen.
  
- het offset is ook een 16-bit waarde die wordt toegevoegd aan het basisadres van het segment om het uiteindelijke fysieke adres te bepalen.
  
- hierdoor kan het fysieke adres worden berekend als: fysieke adres = (segment 0 — 16) + offset.
  
- aangezien zowel het segment als het offset 16 bits zijn, resulteert dit in een maximaal fysiek adres van 20 bits (16 + 4), wat overeenkomt met 2^20 = 1 MB aan adresseerbaar geheugen.

![intel 8088 chip](./assets/intel%208088%20chip.png)

</details>

<details>
<summary><strong>
Omschrijf de Wet Van Moore.

 Bespreek enkele limieten die de linearisatie van deze wet in de toekomst niet meer ondersteunen.

- Verklaar de afkortingen CPU en GPU en verklaar enkele essentiele verschillen tussen de werking van een CPU en een GPU.

</strong></summary>

- **Wet van Moore:**

  - het aantal transistors op een geïntegreerde schakeling verdubbelt ongeveer elke twee jaar, wat leidt tot een exponentiële groei in rekenkracht en een afname van de kosten per transistor.

- **Limieten van de Wet van Moore:**
  
  - **Fysieke limieten:**
    - naarmate transistors kleiner worden, komen ze dichter bij de atomaire schaal, men kan niet kleiner gaan dan atomen.
  - **Warmteontwikkeling:**
    - hogere transistor dichtheden leiden tot meer warmte, wat koelingsproblemen veroorzaakt.
  - **energieverbruik:**
    - kleinere transistors kunnen leiden tot hogere lekstromen, wat het energieverbruik verhoogt. wat leidt tot inefficiÃ«ntie.
  - **Kosten:**
    - de kosten voor het produceren van steeds kleinere transistors stijgen aanzienlijk.
  - **snelheid:**
    - er zijn fysieke en technische beperkingen aan hoe snel transistors kunnen schakelen.

</details>

<details>
<summary><strong>
Verklaar de afkortingen CPU en GPU en verklaar enkele essentiele verschillen tussen de werking van een CPU en een GPU.
</strong></summary>

**CPU (Central Processing Unit):**

- de CPU is het hoofdonderdeel van een computer dat instructies uitvoert en algemene taken verwerkt. Het is ontworpen voor veelzijdigheid en kan een breed scala aan taken aan.

**GPU (Graphics Processing Unit):**

- de GPU is gespecialiseerd in het verwerken van grafische gegevens en is geoptimaliseerd voor parallelle verwerking. Het wordt voornamelijk gebruikt voor rendering van beelden en video, maar ook voor andere parallelle taken zoals machine learning.

**Verschillen tussen CPU en GPU:**

| CPU                 | GPU                            |
| ------------------- | ------------------------------ |
| Weinig sterke cores | Zeer veel simpele cores        |
| Sequentieel werk    | Parallel werk                  |
| Complexe logica     | Simpele herhaalde berekeningen |
| Lage latency        | Hoge throughput                |
| Geschikt voor algemene taken | Geschikt voor grafische en parallelle taken |

</details>

<details>
<summary><strong>
Gegeven: de 6502 microprocessor instructie set

[instructie set 6502](./instructie%20set%206502.md)
</strong></summary>

**Opgave 1:**

schrijf 6502 assembly code om twee 16-bits waarden op te slaan op adressen $00-$01 en $02-$03.

Tel deze twee 16-bits waarden op en bewaar het resultaat op adressen $04-$05.

Houd rekening met de carry.

```asm
CLC         ; Clear carry flag (voor start optelling)
LDA $00     ; Laad laagste byte van eerste waarde
ADC $02     ; Tel laagste byte van tweede waarde met carry
STA $04     ; Sla resultaat laagste byte op
LDA $01     ; Laad hoogste byte van eerste waarde
ADC $03     ; Tel hoogste byte van tweede waarde met carry
STA $05     ; Sla resultaat hoogste byte op
```

---

**Opgave 2:**

schrijf 6502 assembly code om het verschil te berekenen van twee 16-bits waarden opgeslagen op adressen $00-$01 en $02-$03.

Sla het resultaat op in adressen $04-$05.

Houd rekening met de borrow.

```asm
SEC         ; Set carry flag (voor borrow bij aftrekking)
LDA $00     ; Laad laagste byte van eerste waarde
SBC $02     ; Trek laagste byte van tweede waarde af met borrow 
STA $04     ; Sla resultaat laagste byte op
LDA $01     ; Laad hoogste byte van eerste waarde
SBC $03     ; Trek hoogste byte van tweede waarde af met borrow
STA $05     ; Sla resultaat hoogste byte op
```

---

**Opgave 3:**

schrijf 6502 assembly code om twee 32-bits waarden op te slaan op adressen $00-$03 en $04-$07.

Tel de twee 32-bits waarden op via een lus/sprong constructive, die doorheen alle bytes itereert.

Sla het resultaat op in adressen $08-$0B. Houd rekening met de carry.

```asm
LDX #0        ; start bij laagste byte (X = 0)
CLC           ; Clear carry flag (voor start optelling)
loop:
  LDA $00,X   ; Laad byte van eerste waarde (low naar high)
  ADC $04,X   ; Tel byte van tweede waarde (met carry)
  STA $08,X   ; Sla resultaat byte op
  INX         ; Volgende byte
  CPX #4      ; Hebben we alle 4 bytes gedaan?
  BNE loop    ; Zo niet, herhaal de lus
```

</details>

---

## Chapter 3  Processor Elements

### Vragen

<details>
<summary><strong>
Verklaar de afkorting CISC en de afkorting RISC en benoem de verschillen tussen beide computerarchitecturen.
</strong></summary>

- CISC: Complex Instruction Set Computer
  - complexe instructies die meerdere operaties kunnen uitvoeren in één enkele instructie.
  - prograama's kunnen korter zijn omdat minder instructies nodig zijn.
  - vaak langere uitvoeringstijd per instructie vanwege de complexiteit.
  - complexe hardware nodig om de instructies te decoderen en uit te voeren.

- voorbeelden: x86 (Intel, AMD)

- RISC: Reduced Instruction Set Computer
  - eenvoudige instructies die meestal Ã©Ã©n enkele operatie uitvoeren.
  - programma's kunnen langer zijn omdat meer instructies nodig zijn.
  - snellere uitvoeringstijd per instructie vanwege de eenvoud.
  - eenvoudigere hardware, wat kan leiden tot hogere kloksnelheden en betere pipelining.

- voorbeelden: ARM (smartphones, Raspberry Pi, Apple M1/M2)

- belangerijkste verschillen:

| Eigenschap                      | CISC                             | RISC                             |
| ------------------------------- | -------------------------------- | -------------------------------- |
| Betekenis                       | Complex Instruction Set Computer | Reduced Instruction Set Computer |
| Instructies                     | Complex                          | Simpel                           |
| Aantal instructies in programma | Weinig                           | Veel                             |
| Klokcycli per instructie        | Meerdere                         | Meestal 1                        |
| Hardware                        | Complex                          | Simpel                           |
| Energieverbruik                 | Hoger                            | Lager                            |

</details>

<details>
<summary><strong>
Verklaar de werking van de 6502 stapel-instructies PHA en PLA. De werking van de 6502 stapel is volgens het LIFO-principe en wat is de relatie met het S-register en de processorvlaggen?
</strong></summary>

- **PHA (Push Accumulator):**
  - de inhoud van de accumulator (A-register) wordt op de stapel geplaatst.
  - de stack pointer (S-register) wordt verlaagd met 1 om ruimte te maken voor de nieuwe waarde.
  - de waarde van A wordt opgeslagen op het adres dat wordt aangegeven door het S-register.
- **PLA (Pull Accumulator):**
  - de waarde bovenop de stapel wordt van de stapel gehaald en in de accumulator (A-register) geplaatst.
  - de waarde wordt gelezen van het adres dat wordt aangegeven door het S-register.
  - de stack pointer (S-register) wordt verhoogd met 1 om aan te geven dat de waarde is verwijderd van de stapel.

- s-register:
  - het S-register houdt de huidige positie van de stapel bij.
  - het begint meestal bij $FF en groeit naar beneden (afnemend adres).
    - â—dit betekent dat de stack adressen van `$FF` naar `$00` gaan naarmate er meer waarden worden gepusht.
  - bij PHA wordt S verlaagd, bij PLA wordt S verhoogd.

- processor vlaggen:
- de PHA en PLA instructies beÃ¯nvloeden de status van de processorvlaggen niet direct.
  - echter, de waarden die worden gepusht of gepulld kunnen de vlaggen beÃ¯nvloeden als ze later worden gebruikt in berekeningen.
  - bijvoorbeeld:
    - als de waarde in de accumulator na een PLA-instructie wordt gebruikt in een berekening, kunnen de vlaggen (zoals zero, negative) worden bijgewerkt op basis van het resultaat van die berekening.

â€¢ Verklaar het verschil tussen een maskable en non-maskable interrupt. Wat zijn de adressen van de interrupt service routines van beide interrupts en welke interrupt is level- of edge sensitive?

- **Maskable Interrupt (IRQ):**
  - kan worden uitgeschakeld (gemaskeerd) door de CPU.
  - wordt vaak gebruikt voor minder kritieke taken.
  - adres van de interrupt service routine (ISR): $FFFE (laag byte) en $FFFF (hoog byte).
  - meestal level-sensitive: de interrupt activeert als een signaal hoog of laag is.

| Actieve laag | Trigger | Pin rust |
| ------------ | ------- | -------- |
| **High**     | Hoog    | Laag     |
| **Low**      | Laag    | Hoog     |

💡 Ezelsbrug: active = de waarde die het signaal moet hebben om te “activeren”

- **Non-Maskable Interrupt (NMI):**
  - kan niet worden uitgeschakeld door de CPU.
  - wordt gebruikt voor kritieke taken die onmiddellijke aandacht vereisen, zoals hardwarefouten.
  - adres van de interrupt service routine (ISR): $FFFA (laag byte) en $FFFB (hoog byte).
  - meestal edge-sensitive: de interrupt wordt geactiveerd door een overgang van laag naar hoog.

</details>

<details>
<summary><strong>
Licht de 3 manieren van I/O-processing toe en wat zijn de verschillen tussen port-mapped I/O en memory-mapped I/O?
</strong></summary>

- **Polling:**

  - de CPU controleert continu de status van een I/O-apparaat om te zien of het klaar is voor gegevensoverdracht.
  - eenvoudig te implementeren, maar inefficiënt omdat de CPU tijd verspilt aan het controleren van apparaten die mogelijk niet klaar zijn.

- **Interrupts:**
  - het I/O-apparaat stuurt een signaal naar de CPU wanneer het klaar is voor gegevensoverdracht.
  - efficiënter dan polling, omdat de CPU andere taken kan uitvoeren totdat het interrupt signaal wordt ontvangen.
- **Direct Memory Access (DMA):**
  - een speciale hardwarecontroller beheert de gegevensoverdracht tussen I/O-apparaten en het geheugen zonder tussenkomst van de CPU.
  - zeer efficiënt voor grote gegevensoverdrachten, omdat de CPU vrij blijft voor andere taken.

- **Port-mapped I/O:**
  - I/O-apparaten hebben een aparte adresruimte, gescheiden van het hoofdgeheugen.
  - speciale instructies worden gebruikt om te communiceren met I/O-apparaten.

- **Memory-mapped I/O:**
  - I/O-apparaten delen dezelfde adresruimte als het hoofdgeheugen.
  - dezelfde instructies worden gebruikt voor zowel geheugen- als I/O-toegang.

</details>

#### Oefening 4 checksum

- Bij het overdragen van gegevensblokken over een foutgevoelig transmissiemedium is het gebruikelijk om een checksum
te gebruiken om vast te stellen of gegevensbits verloren zijn gegaan of beschadigd zijn tijdens de verzending.

- De checksum wordt meestal aan het transferred data record toegevoegd.

  - Een checksumalgoritme gebruikt deze stappen:

    - Tel alle bytes in het transferred data record bij elkaar op, behoudens alleen de laagste 8 bits van de som.
    - De checksum is het twee's complement van de 8-bits som.
    - Voeg de checksumbyte toe aan het transferred data record.
    - Na ontvangst van een gegevensblok met de bijgevoegde checksum kan de processor bepalen of de
    checksum geldig is door eenvoudigweg alle bytes in het record, inclusief de checksum, bij elkaar op te tellen.
    - De checksum is geldig als de laagste 8 bits van de som nul zijn.
  - Implementeer dit checksumalgoritme met behulp van 6502-assemblagetaal.
  - De gegevensbytes beginnen op de geheugenlocatie opgeslagen op adres $10-$11 en het aantal bytes (inclusief
de checksumbyte) wordt gegeven als invoer in het X-register.
  - Zet het A-register op 1 als de checksum geldig is, en op 0 als deze ongeldig is.

  <details>
  <summary><strong>Antwoord:</strong></summary>

  ```asm
  ; Input:
  ; $10 = low byte van pointer
  ; $11 = high byte van pointer
  ; X = aantal bytes inclusief checksum

          LDY #0          ; Y = offset 0
          LDA #0          ; A = accumulator voor som

  checksum_loop:
          CLC             ; clear carry voor ADC
          LDA ($10),Y     ; laad byte van data
          ADC sum         ; tel bij huidige som
          STA sum         ; sla op
          INY             ; volgende byte
          DEX             ; verminder teller
          BNE checksum_loop ; zolang X != 0, herhaal

          LDA sum         ; laad totale som
          CMP #0          ; vergelijk met 0
          BEQ checksum_ok ; als som = 0 → checksum correct
          LDA #0          ; anders, A = 0
          JMP checksum_done ; jump naar checksum_done

  checksum_ok:
          LDA #1         ; A = 1 (checksum correct)

  checksum_done:
          RTS              ; A = 1 of 0


  sum:
          .byte 0       ; tijdelijke opslag voor som
  ```

  Uitleg

  $10/$11 → startadres van de data

  X → loopt door alle bytes inclusief checksum

  Som = lage 8 bits → als totaal = 0 → checksum correct

  Output in A = 1 (valid) of 0 (invalid)

  </details>

---

## Chapter 5 Hardware-Software Interface

### Vragen

<details>
<summary><strong>
Wat betekenen de afkortingen PCI en PCIe?
</strong></summary>

![pci_express](./assets/pcie%20infographic.png)

- **PCI:** Peripheral Component Interconnect
  - een standaard voor het aansluiten van randapparatuur op een computer via een busarchitectuur.
  - ondersteunt meerdere apparaten en biedt een gedeelde communicatie-interface.
  - uitsparing zit rechts op slot ➡️

- **PCIe:** PCI Express
  - een snellere en meer geavanceerde versie van PCI, die seriële communicatie gebruikt.
  - biedt hogere bandbreedte en lagere latentie, waardoor het geschikt is voor moderne randapparatuur zoals grafische kaarten en SSD's.
  - uitsparing zit links op slot ⬅️

</details>

<details>
<summary><strong>
Licht bondig volgende kenmerken toe, die van toepassing zijn bij PCI/PCIe:

- Hot plugging
- Automated configuration
- Bulk DMA transfer
- Multi-lane serial connections
- Root Complex
- End Point

</strong></summary>

| Kenmerk                  | Toelichting                                                                 |
|---------------------------|----------------------------------------------------------------------------|
| Hot plugging              | Kaart in- of uitpluggen terwijl de computer aanstaat (alleen PCIe).       |
| Automated configuration   | Systeem wijst automatisch resources toe (adresruimte, IRQ, etc.).         |
| Bulk DMA transfer         | Data rechtstreeks naar/van geheugen sturen zonder CPU-interventie.        |
| Multi-lane serial connections | Meerdere seriële datapaden parallel voor hogere bandbreedte (x1, x4, x16). |
| Root Complex              | Verbindingspunt tussen CPU/geheugen en PCIe-bus, startpunt van communicatie. |
| End Point                 | Eindapparaat op de PCIe-bus (bv. GPU, SSD) dat data verzendt/ontvangt.   |

</details>

<details>
<summary><strong>
Over welke functies moet een Linux device driver minimaal beschikken?

Eén concreet voorbeeld is de mydevice_init() functie.

Vul de functies verder aan en verklaar het doel van elk van deze functies
</strong></summary>

| Functie                                            | Doel / Verklaring                                                                                                                   |
| -------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| **mydevice_init()**                                | Wordt uitgevoerd bij het laden van de driver (module). Registreert het apparaat bij het systeem en initialiseert hardware/software. |
| **mydevice_exit()**                                | Wordt uitgevoerd bij het verwijderen van de driver (module unload). Ruimt resources op, deregistreert het apparaat.                 |
| **open()**                                         | Wordt aangeroepen wanneer een programma het apparaat opent (bv. via `/dev/mydevice`). Controleert of het apparaat beschikbaar is.   |
| **release() / close()**                            | Wordt aangeroepen bij het sluiten van het apparaat. Sluit het apparaat netjes af en maakt resources vrij.                           |
| **read()**                                         | Wordt gebruikt om data van het apparaat te lezen. Plaatst gegevens van de hardware in het gebruikersgeheugen.                       |
| **write()**                                        | Wordt gebruikt om data naar het apparaat te schrijven. Verstuurt gegevens van de gebruiker naar de hardware.                        |
| **ioctl()**                                        | Gebruikt voor speciale commando’s of configuraties die niet met gewone read/write kunnen.                                           |
| **probe()** (optioneel voor platform/PCI devices)  | Detecteert of de hardware aanwezig is en kan gebruikt worden door deze driver.                                                      |
| **remove()** (optioneel voor platform/PCI devices) | Wordt uitgevoerd bij het loskoppelen van de hardware.                                                                               |

</details>

<details>
<summary><strong>
Verklaar volgende afkortingen en licht de begrippen toe:

- BIOS
- POST
- UEFI

</strong></summary>

- **BIOS (Basic Input Output System):**
  - firmware die wordt uitgevoerd bij het opstarten van een computer.
  - initialiseert hardwarecomponenten en laadt het besturingssysteem vanaf de opslagmedia.
- **POST (Power On Self Test):**
  - diagnostische test die wordt uitgevoerd door de BIOS bij het opstarten.
  - controleert of hardwarecomponenten correct functioneren voordat het besturingssysteem wordt geladen.
- **UEFI (Unified Extensible Firmware Interface):**
  - moderne vervanger van BIOS.
  - biedt een uitgebreidere interface tussen besturingssysteem en firmware, ondersteunt grotere schijven, snellere opstarttijden en meer beveiligingsfuncties.

</details>

<details>
<summary><strong>
Wat zijn de beperkingen van MBR partities en verklaar hoe UEFI partities deze beperkingen oplossen?
</strong></summary>

- **Beperkingen van MBR (Master Boot Record) partities:**
  - ondersteunt maximaal 4 primaire partities per schijf.
  - ondersteunt schijven tot een maximale grootte van 2 TB.
  - beperkte ondersteuning voor moderne hardware en besturingssystemen.

- **Oplossingen met UEFI/GPT (GUID Partition Table):**
  - ondersteunt tot 128 partities per schijf zonder de noodzaak voor uitgebreide partities
  - ondersteunt schijven groter dan 2 TB, tot wel 9.4 ZB (zettabytes).
  - biedt verbeterde gegevensintegriteit en fouttolerantie door het gebruik van redundante partitiegegevens.
  - beter compatibel met moderne hardware en besturingssystemen.

💡 wist je datje

- 9,4 zetabyte is ongeveer 9,4 miljard terabyte of 9,4 miljoen petabyte – kortom, extreem veel data, genoeg om honderden miljoenen full HD-films op te slaan.

| Grootte        |     naam     | Bytes                     |  Vergelijking                               |
|----------------|--------------|-------------------------- |---------------------------------------------|
|1 bit           |bit           | 0.125 B                   | stelt 1 of 0 voor                           |
|4 bits          |nibble        | 0.5 B                     | halve byte                                  |
| 1 byte         |byte          | 8 bits                    | 1 karakter in ASCII                         |
| 1 KB           |kilobyte      | 1.024 B                   | Kleine tekstbestanden                       |
| 1 MB           |megabyte      | 1.024 KB                  | Een paar minuten MP3-muziek                 |
| 1 GB           |gigabyte      | 1.024 MB                  | Enkele uren video of honderden foto’s       |
| 1 TB           |terabyte      | 1.024 GB                  | 250–300 films in HD                         |
| 1 PB           |petabyte      | 1.024 TB                  | Gigantische datacenters, archieven          |
| 1 EB           |exabyte       | 1.024 PB                  | Internet-scale opslag                       |
| 1 ZB           |zettabyte     | 1.024 EB                  | Wereldwijd internet, zeer theoretisch       |

</details>

<details>
<summary><strong>
Welke taken moet de operating system kernel uitvoeren tijdens het boot-process?
</strong></summary>

| Stap / Taak                     | Uitleg                                                                                             |
| ------------------------------- | -------------------------------------------------------------------------------------------------- |
| **Initialisatie van hardware**  | Detecteert en configureert CPU, geheugen (RAM), timers en basishardware.                           |
| **Memory management opstarten** | Zet de geheugenbeheerstructuren op (pagina’s, virtueel geheugen, heap/stack).                      |
| **Device drivers laden**        | Kernel laadt drivers voor opslag, netwerk, USB, enz., zodat hardware werkt.                        |
| **Bestandssysteem mounten**     | Mount het root filesystem zodat het OS bestanden kan lezen en uitvoeren.                           |
| **Kernel subsystems opstarten** | Initieert processen, scheduler, inter-process communication (IPC) en I/O subsystemen.              |
| **Init / systemd starten**      | Start het eerste gebruikersproces (`init` of `systemd`) dat alle andere gebruikersprocessen laadt. |
| **Beveiliging en privileges**   | Stelt kernel privileges en beveiligingsmechanismen in (bijv. user vs kernel mode).                 |

</details>

<details>
<summary><strong>
Wat zijn de verschillen tussen threads en processes?
</strong></summary>

| Kenmerk               | Process                          | Thread                           |
|-----------------------|----------------------------------|----------------------------------| 
| Definitie             | Zelfstandig uitvoerend programma | Lichtgewicht uitvoerende eenheid binnen een proces |
| Geheugenruimte        | Eigen geheugenruimte (virtueel)  | Delen geheugenruimte van het proces |
| Context switch        | Duurder (volledige context)      | Goedkoper (gedeelde context) |
| Communicatie          | Moeilijker (inter-process communication) | Eenvoudiger (gedeeld geheugen) |
| Overhead              | Hoger (meer resources nodig)     | Lager (minder resources nodig) |
| Gebruik               | Voor zware, geïsoleerde taken    | Voor lichte, parallelle taken binnen hetzelfde programma |

</details>

<details>
<summary><strong>
Wat zijn de vier toestanden die een process kan aannemen en licht elke toestand bondig toe?
</strong></summary>

| Toestand              | Uitleg                                                                                  |
| --------------------- | --------------------------------------------------------------------------------------- |
| **New**               | Het proces wordt aangemaakt, maar is nog niet klaar om te draaien.                      |
| **Ready**             | Het proces is klaar om te draaien, wacht op CPU-toewijzing.                             |
| **Running**           | Het proces wordt actief uitgevoerd door de CPU.                                         |
| **Blocked / Waiting** | Het proces wacht op een gebeurtenis (bijv. I/O) en kan tijdelijk niet verder uitvoeren. |

Kort gezegd:

een proces gaat van New → Ready → Running → (eventueel Blocked) en daarna weer terug naar Ready totdat het klaar is.

```mermaid
---
config:
  layout: elk
---
flowchart TB
    New["New<br>Proces wordt aangemaakt"] --> Ready["Ready<br>Wacht op CPU"]
    Ready -- Scheduler kiest proces --> Running["Running<br>Wordt uitgevoerd"]
    Running -- Timeslice op --> Ready
    Running -- Wacht op I/O --> Blocked["Blocked<br>Wacht op I/O of event"]
    Running -- Klaar --> End["End<br>Proces klaar"]
    Blocked -- I/O klaar --> Ready

     New:::Aqua
     Ready:::Peach
     Running:::Pine
     Blocked:::Rose
     End:::Sky
    classDef Pine stroke-width:1px, stroke-dasharray:none, stroke:#254336, fill:#27654A, color:#FFFFFF
    classDef Peach stroke-width:1px, stroke-dasharray:none, stroke:#FBB35A, fill:#FFEFDB, color:#8F632D
    classDef Sky stroke-width:1px, stroke-dasharray:none, stroke:#374D7C, fill:#E2EBFF, color:#374D7C
    classDef Aqua stroke-width:1px, stroke-dasharray:none, stroke:#46EDC8, fill:#DEFFF8, color:#378E7A
    classDef Rose stroke-width:1px, stroke-dasharray:none, stroke:#FF5978, fill:#FFDFE5, color:#8E2236
    linkStyle 0 stroke:#BBDEFB,fill:none
    linkStyle 1 stroke:#FFD600,fill:none
    linkStyle 2 stroke:#00C853,fill:none
    linkStyle 3 stroke:#D50000,fill:none
    linkStyle 4 stroke:#2962FF
    linkStyle 5 stroke:#D50000,fill:none

```

</details>

<details>
<summary><strong>
Wat betekenen de afkortingen TCB en PCB en licht bondig hun functie toe?
</strong></summary>

| Afkorting | Betekenis                | Functie / Toelichting                                                                                   |
|-----------|--------------------------|---------------------------------------------------------------------------------------------------------|
| **TCB**   | Thread Control Block     | Bevat informatie over een thread, zoals thread-ID, status, registers, stack pointer en prioriteit.     |
| **PCB**   | Process Control Block    | Bevat informatie over een proces, zoals proces-ID, status, geheugenbeheer, open bestanden en CPU-registraties. |

</details>

<details>
<summary><strong>
Noem vier scheduling algorithms en bespreek de eigenschappen van elke van deze scheduling algorithms (nonpreemptive/preemptive?, process priority?, …)
</strong></summary>

| Algorithm                          | Preemptive?                                               | Priority? | Eigenschappen                                                                                                             |
| ---------------------------------- | --------------------------------------------------------- | --------- | ------------------------------------------------------------------------------------------------------------------------- |
| **FCFS (First Come First Served)** | ❌ Non-preemptive                                          | ❌ Nee     | Processen worden uitgevoerd in volgorde van aankomst. Simpel, maar trage processen kunnen alles ophouden.                 |
| **SJF (Shortest Job First)**       | ❌ Meestal non-preemptive (bestaat ook preemptive variant) | ❌ Nee     | Kortste taak eerst → minimale gemiddelde wachttijd. Nadeel: je moet weten hoe lang een proces duurt.                      |
| **Round Robin (RR)**               | ✅ Preemptive                                              | ❌ Nee     | Elk proces krijgt een vaste tijdslice. Goed voor multitasking, eerlijk, maar te kleine timeslice = veel context switches. |
| **Priority Scheduling**            | ✅ Of ❌ (kan beide)                                        | ✅ Ja      | Proces met hoogste prioriteit eerst. Risico: starvation (lage prioriteit komt nooit aan de beurt).                        |

`FCFS` = “wie eerst komt, eerst maalt”

`SJF` = “korte taken eerst”

`Round Robin` = “iedereen om de beurt een beetje tijd”

`Priority` = “de belangrijkste eerst”

💡 preemptive = onderbreekbaar

</details>

<details>
<summary><strong>
Wat is een symmetrische multiprocessor architectuur en verklaar de begrippen SIMD en MIMD?
</strong></summary>

- **Symmetrische Multiprocessor (SMP) Architectuur:**
  - een systeem waarbij meerdere identieke processors (CPU's) gelijkwaardig samenwerken binnen één computer.
  - elke processor heeft toegang tot hetzelfde gedeelde geheugen en I/O-systemen.
  - taken kunnen dynamisch worden toegewezen aan elke processor, wat zorgt voor betere prestaties en schaalbaarheid.

- **SIMD (Single Instruction, Multiple Data):**
  - een parallelle verwerkingsarchitectuur waarbij één enkele instructie wordt uitgevoerd op meerdere gegevenspunten tegelijkertijd.
  - vaak gebruikt in vectorverwerking en grafische toepassingen, waar dezelfde bewerking op grote datasets moet worden toegepast.
- **MIMD (Multiple Instruction, Multiple Data):**
  - een parallelle verwerkingsarchitectuur waarbij meerdere instructies onafhankelijk worden uitgevoerd op verschillende gegevenspunten.
  - geschikt voor algemene doeleinden en complexe taken waarbij verschillende processen tegelijkertijd kunnen draaien.

![smp_simd_mimd](./assets/SIMD%20vs%20MIMD.png)

</details>

---

## Chapter 6 Specialized Computing Domains

### Vragen

<details>
<summary><strong>
Hoe onderscheiden zich `soft` real time, `hard` real time en  `firm` real time systemen t.o.v. elkaar?
</strong></summary>

- **soft real-time systemen:**
  - deadlines mogen soms worden gemist zonder ernstige gevolgen.
  - de kwaliteit van de output kan afnemen, maar het systeem blijft functioneel.
  - voorbeelden: video streaming, audio verwerking, games.

- **hard real-time systemen:**
  - deadlines moeten altijd worden gehaald; het missen van een deadline leidt tot systeemfalen of gevaarlijke situaties.
  - voorbeelden: airbagsystemen, pacemakers, anti-blokkeersystemen (ABS).

- **firm real-time systemen:**
  - deadlines mogen soms worden gemist, maar het resultaat is dan waardeloos en wordt weggeorpen.
  - het systeem blijft functioneel, maar de output na een gemiste deadline is niet bruikbaar.
  - voorbeelden: camerabeelden, sensordata, radarsystemen.

| Type real-time systeem | Deadline missen | Gevolg                                      | Voorbeelden                      |
| ---------------------- | --------------- | ------------------------------------------- | -------------------------------- |
| **Hard real-time**     | ❌ Mag nooit     | Systeem faalt / gevaarlijk                  | Airbag, pacemaker, ABS           |
| **Firm real-time**     | ⚠️ Mag soms     | Resultaat is waardeloos en wordt weggegooid | Camera frames, sensordata, radar |
| **Soft real-time**     | ✅ Mag           | Kwaliteit daalt, maar systeem blijft werken | Video, audio, games              |

</details>

<details>
<summary><strong>
Wat zijn de verschillen tussen een Real Time Operating System (RTOS) en een General Purpose Operating System (GPOS)?
</strong></summary>

- **Real Time Operating System (RTOS):**
  - ontworpen voor voorspelbare en tijdkritische taken.
  - biedt gegarandeerde responstijden en minimale latentie.
  - gebruikt in embedded systemen, industriële automatisering, medische apparatuur.
  - voorbeelden: FreeRTOS, VxWorks, RTLinux.

- **General Purpose Operating System (GPOS):**
  - ontworpen voor algemene taken en gebruikersinteracties.
  - biedt flexibiliteit en ondersteuning voor een breed scala aan toepassingen.
  - kan minder voorspelbare responstijden hebben vanwege multitasking en resource sharing.
  - voorbeelden: Windows, Linux, macOS.

| Eigenschap      | **RTOS**                                            | **GPOS**                                      |
| --------------- | --------------------------------------------------- | --------------------------------------------- |
| Doel            | **Deterministisch gedrag** (timing is voorspelbaar) | **Gebruiksgemak en throughput**               |
| Reactietijd     | **Gegarandeerd en voorspelbaar**                    | **Niet gegarandeerd, kan variëren**           |
| Scheduling      | Gericht op **deadlines en prioriteiten**            | Gericht op **fairness en performance**        |
| Deadline missen | Kan **kritisch** zijn (zeker in hard real-time)     | Geen probleem, alleen trager                  |
| Preemptie       | Vaak **volledig preemptive met prioriteiten**       | Preemptive, maar niet deadline-gericht        |
| Overhead        | **Laag en lichtgewicht**                            | **Zwaarder** (veel services, GUI, drivers, …) |
| Toepassingen    | Embedded, industrie, automotive, medisch            | PC, laptop, smartphone, server                |
| Voorbeelden     | FreeRTOS, VxWorks, Zephyr                           | Windows, Linux, macOS                         |

RTOS = doet dingen op tijd en voorspelbaar

GPOS = doet dingen zo snel en zo handig mogelijk, maar niet strikt op tijd

</details>

<details>
<summary><strong>
Hoe functioneert een mutex bij shared resources in een RTOS?

- Verklaar het principe van thread preemption.

- Verklaar het principe van priority inversion
</strong></summary>

- **Mutex (Mutual Exclusion):**
  - een synchronisatiemechanisme dat wordt gebruikt om toegang tot gedeelde resources te beheren.
  - wanneer een thread een mutex vergrendelt, kunnen andere threads niet dezelfde resource gebruiken totdat de mutex wordt vrijgegeven
  - zorgt ervoor dat slechts één thread tegelijk toegang heeft tot de gedeelde resource.
  - voorkomt race conditions en zorgt voor thread-safe toegang.

- **Thread Preemption:**
  - het proces waarbij een hogere prioriteit thread de CPU kan overnemen van een lagere prioriteit thread.
  - in een preemptive RTOS kan de scheduler op elk moment beslissen om een lopende thread te onderbreken als een thread met hogere prioriteit klaar is om te draaien.
  - zorgt ervoor dat kritieke taken snel kunnen worden uitgevoerd, wat essentieel is voor real-time prestaties.

- **Priority Inversion:**
  - een situatie waarin een hogere prioriteit thread wordt geblokkeerd doordat een lagere prioriteit thread een benodigde resource vasthoudt.
  - kan leiden tot vertragingen en het missen van deadlines in een RTOS.
  - oplossingen omvatten priority inheritance, waarbij de lagere prioriteit thread tijdelijk de hogere prioriteit krijgt om de resource sneller vrij te geven.

</details>

<details>
<summary><strong>
Hoe functioneert een semaphore bij shared resources in een RTOS en wat is een counting semaphore?
</strong></summary>

- deze is vergelijkbaar met een mutex maar kan door meerdere threads worden gebruikt.
- kan worden vrijgegeven door een andere thread dan diegene die hem heeft verkregen.

- **counting semaphore:**
  - een type semaphore dat een teller bijhoudt die aangeeft hoeveel threads tegelijkertijd toegang kunnen krijgen tot een gedeelde resource.
  - wanneer een thread de semaphore "neemt" (wait), wordt de teller verlaagd.
  - wanneer een thread de semaphore "geeft" (signal), wordt de teller verhoogd.
  - als de teller op nul staat, moeten threads wachten totdat de semaphore wordt vrijgegeven door een andere thread.
  - wordt vaak gebruikt voor het beheren van toegang tot een pool van bronnen, zoals verbindingen of buffers.
  - voorbeeld:
    - als een counting semaphore is ingesteld op 3, kunnen maximaal 3 threads tegelijkertijd toegang krijgen tot de gedeelde resource.

</details>

<details>
<summary><strong>
Wat is een critical section en hoe garandeert men de ongestoorde verwerking van deze sectie?
</strong></summary>

- een critical section is een deel van de code waarin gedeelde resources worden benaderd of gemodificeerd.
- om ongestoorde verwerking te garanderen, worden synchronisatiemechanismen zoals mutexen of semaforen gebruikt om ervoor te zorgen dat slechts één thread tegelijk toegang heeft tot de critical section.
- dit voorkomt race conditions en zorgt voor gegevensintegriteit.
- meestal wordt de critical section beschermd door het vergrendelen van een mutex voordat de code wordt uitgevoerd en het vrijgeven van de mutex nadat de code is voltooid.

</details>

<details>
<summary><strong>
Benoem de 3 manieren om een computer uit te breiden met een GPU.

Waarom wordt de performantie van een computerarchitectuur verhoogd indien de architectuur wordt uitgebreid met een GPU?
</strong></summary>

- **Manieren om een computer uit te breiden met een GPU:**
  1. **Dedicated GPU (Discrete GPU):**
     - Een aparte grafische kaart die in een PCIe-slot op het moederbord wordt geplaatst.
     - Voorbeelden: NVIDIA GeForce, AMD Radeon.
  2. **Integrated GPU (Ingebouwde GPU):**
     - Een GPU die is geïntegreerd in de CPU of het moederbord.
     - Voorbeelden: Intel HD Graphics, AMD APU's.
  3. **External GPU (eGPU):**
     - Een externe behuizing met een GPU die via een snelle verbinding (zoals Thunderbolt) op de computer wordt aangesloten.
     - Geschikt voor laptops of systemen zonder ruimte voor een interne GPU.

- **Verhoging van performantie door een GPU:**
  - GPU's zijn ontworpen voor parallelle verwerking en kunnen duizenden threads tegelijk uitvoeren.
  - Dit maakt ze bijzonder geschikt voor taken zoals grafische rendering, wetenschappelijke berekeningen en machine learning, waar veel gelijktijdige berekeningen nodig zijn.
  - Door de zware rekenlast van deze taken naar de GPU te verplaatsen, wordt de CPU ontlast, waardoor de algehele systeemprestaties verbeteren.
  - Bovendien hebben GPU's gespecialiseerde hardware voor grafische bewerkingen, wat resulteert in snellere verwerkingstijden voor visuele taken.
  - Dit leidt tot een soepelere gebruikerservaring bij grafisch intensieve toepassingen zoals gaming, videobewerking en 3D-modellering.
  - Kortom, de toevoeging van een GPU verbetert de verwerkingskracht en efficiëntie van een computer aanzienlijk, vooral voor taken die baat hebben bij parallelle verwerking.

</details>

<details>
<summary><strong>
Geef enkele concrete voorbeelden van applicaties die sterk baat hebben bij het gebruik van een GPU.
</strong></summary>

- **Gaming:**
  - Moderne videogames maken gebruik van geavanceerde grafische effecten en hoge resoluties, wat aanzienlijke rekenkracht vereist die door GPU's wordt geleverd.
    - Voorbeelden:
      - AAA-titels zoals "Cyberpunk 2077", "Call of Duty", "Assassin's Creed".

- **Videobewerking en rendering:**
  - Software voor videobewerking en 3D-rendering gebruikt GPU's om complexe bewerkingen en effecten snel uit te voeren.
  - Voorbeelden:
    - Adobe Premiere Pro, DaVinci Resolve, Blender.

- **Wetenschappelijke simulaties:**
  - Veel wetenschappelijke toepassingen, zoals klimaatmodellen en moleculaire dynamica, gebruiken GPU's voor het versnellen van berekeningen.
  - Voorbeelden:
    - GROMACS, ANSYS Fluent., MATLAB.

- **Machine learning en AI:**
  - GPU's worden veel gebruikt voor het trainen en uitvoeren van neurale netwerken vanwege hun vermogen om grote hoeveelheden matrixberekeningen parallel uit te voeren.
  - Voorbeelden:
    - TensorFlow, PyTorch, Caffe.

</details>

---

## Chapter 7 Processor and Memory Architectures

### Vragen

<details>
<summary><strong>
Bespreek de verschillen tussen een von Neumann, Harvard en modified Harvard architectuur
</strong></summary>

- **Von Neumann Architectuur:**
  - Gebruikt één enkele geheugenruimte voor zowel instructies als data.
  - CPU haalt zowel instructies als data uit hetzelfde geheugen, wat kan leiden tot een bottleneck (von Neumann bottleneck).
  - Eenvoudiger ontwerp en goedkoper om te implementeren.
  - Voorbeeld:
    - traditionele computersystemen.

- **Harvard Architectuur:**
  - Heeft gescheiden geheugenruimtes voor instructies en data.
  - CPU kan gelijktijdig instructies en data ophalen, wat de prestaties verbetert.
  - Complexer ontwerp en duurder om te implementeren.
  - Voorbeeld:
    - digitale signaalprocessors (DSP's).

- **Modified Harvard Architectuur:**
  - Combineert elementen van zowel von Neumann als Harvard architecturen.
  - Heeft gescheiden caches voor instructies en data, maar deelt hetzelfde hoofdgeheugen.
  - Biedt de voordelen van gelijktijdige toegang tot instructies en data, terwijl het ontwerp eenvoudiger blijft dan een volledige Harvard architectuur.
  - Voorbeeld:
    - moderne CPU's met gescheiden L1 caches voor instructies en data.

![architectures](./assets/neuman%20vs%20harvard%20or%20combo.png)

</details>

<details>
<summary><strong>
Licht volgende “von Neumann” security issues bondig toe:

- self-modifying code
- buffer overflow

</strong></summary>

- **Self-modifying code:**

  - code die zichzelf tijdens de uitvoering wijzigt.

    - kan leiden tot onvoorspelbaar gedrag en beveiligingsrisico's, omdat het moeilijk is om te controleren wat de code doet.

    - kan worden misbruikt door aanvallers om kwaadaardige code in te voeren of bestaande code te veranderen.

    - voorbeelden:

      - virussen en malware die zichzelf aanpassen om detectie te vermijden.

      - legitieme toepassingen die dynamisch code genereren voor optimalisatie.

- **buffer overflow:**

  - een beveiligingsfout waarbij een programma meer data in een buffer schrijft dan deze kan bevatten.

    - kan leiden tot het overschrijven van aangrenzende geheugenlocaties, wat kan resulteren in crashes, gegevenscorruptie of het uitvoeren van kwaadaardige code.

    - vaak gebruikt door aanvallers om controle over een systeem te krijgen door schadelijke code in het overschreven geheugen te plaatsen.

    - voorbeelden:

      - stack-based buffer overflows waarbij de return-adres van een functie wordt overschreven.

      - heap-based buffer overflows die leiden tot geheugenmanipulatie.

</details>

<details>
<summary><strong>
Hoe werkt het DOS terminate and stay resident program concept (TSR) voor multiprogramming?
</strong></summary>

- **Terminate and Stay Resident (TSR) Programs:**

  - een techniek die werd gebruikt in oudere besturingssystemen zoals MS-DOS om programma's in het geheugen te houden nadat ze waren beëindigd.

  - TSR-programma's laden zichzelf in het geheugen en blijven actief op de achtergrond, waardoor ze snel kunnen worden herstart zonder opnieuw te hoeven laden vanaf de schijf.

  - dit maakte het mogelijk om meerdere programma's tegelijkertijd te laten draaien, wat een vorm van multiprogramming mogelijk maakte in een enkelvoudig taakbesturingssysteem.

  - voorbeelden van TSR-programma's zijn muisdrivers, klemborden en kleine hulpprogramma's die altijd beschikbaar moeten zijn.

</details>

<details>
<summary><strong>
Bespreek hoe het 32-bit virtueel adres $00402003 wordt omgezet in een fysiek adres, d.m.v. het Windows NT
pagineringsmodel, dat gebruikt maakt van CR3, een page table directory, page table en page offset
</strong></summary>

- **Inleiding:**
  - In het Windows NT pagineringsmodel wordt virtueel geheugen vertaald naar fysiek geheugen via een hiërarchische structuur bestaande uit een Page Directory en Page Tables.
  - Het proces begint met het CR3-register, dat het fysieke adres van de Page Directory Base (PDB) bevat.

- **Virtueel Adres Opdeling:**
  - Het 32-bit virtuele adres $00402003 wordt opgesplitst in drie delen:
    - Page Directory Index (PDI): bits 22-31
    - Page Table Index (PTI): bits 12-21
    - Page Offset: bits 0-11

- hex $00402003 = bin 0000 0000 0100 0000 0010 0000 0000 0011

- **Stap 1: CR3 Register**
  - Het CR3-register bevat het fysieke adres van de Page Directory Base (PDB), die de start is van de pagineringstructuur.
  - In dit geval verwijst CR3 naar de Page Directory die nodig is voor de vertaling.
  
- **Stap 2: Page Directory Index (PDI)**
  - Het virtuele adres $00402003 wordt opgesplitst in verschillende delen.
  - De eerste 10 bits (bits 22-31) worden gebruikt als de Page Directory Index (PDI).
  - Voor $00402003 is de PDI 0x0010 (16 in decimaal).
  - Deze index wordt gebruikt om de juiste Page Directory Entry (PDE) te vinden in de Page Directory.

- **Stap 3: Page Table Index (PTI)**
  - De volgende 10 bits (bits 12-21) worden gebruikt als de Page Table Index (PTI).
  - Voor $00402003 is de PTI 0x0002 (2 in decimaal).
  - Deze index wordt gebruikt om de juiste Page Table Entry (PTE) te vinden in de Page Table die door de PDE wordt aangegeven.

- **Stap 4: Page Offset**
  - De laatste 12 bits (bits 0-11) van het virtuele adres worden gebruikt als de Page Offset.
  - Voor $00402003 is de Page Offset 0x0003 (3 in decimaal).
  - Dit offset wordt toegevoegd aan het fysieke adres dat door de PTE wordt aangegeven om het uiteindelijke fysieke adres te verkrijgen.

  - **Stap 5: Fysiek Adres Berekenen**
  - Nadat de juiste PDE en PTE zijn gevonden, wordt het fysieke adres berekend door het basisadres van de pagina (verkregen uit de PTE) te combineren met de Page Offset.
  - Het uiteindelijke fysieke adres is dus het basisadres van de pagina plus de offset 0x0003.
  - Dit resulteert in het fysieke adres dat overeenkomt met het virtuele adres $00402003.

- **Samenvatting:**
  - Het virtuele adres $00402003 wordt vertaald naar een fysiek adres door gebruik te maken van het CR3-register, de Page Directory, de Page Table en de Page Offset volgens het Windows NT pagineringsmodel.
  - Elke stap in het proces zorgt ervoor dat het juiste fysieke geheugenadres wordt gevonden voor de gegeven virtuele adresruimte.
  - Dit mechanisme maakt efficiënte geheugenbeheer en bescherming mogelijk in moderne besturingssystemen.

- dit zorgt ervoor dat je programma's meer geheugen kunnen gebruiken dan fysiek beschikbaar is, en dat elk programma zijn eigen virtuele adresruimte heeft, wat de veiligheid en stabiliteit van het systeem verhoogt.

- er zijn 1024 page directory entries (10 bits) en 1024 page table entries (10 bits), dus elke page is 4KB (2^12 bytes).

hierdoor kan je 4GB virtueel geheugen hebben (2^32 bytes).

dit is ook de reden waarom 32-bit systemen vaak beperkt zijn tot 4GB RAM.

- 64 bit systemen gebruiken een vergelijkbaar model, maar met meer niveaus van paginering en grotere adressen.

dit resulteert in maximaal 16 exabyte virtueel geheugen (2^64 bytes).

we zitten dus nog wel even safe :)

![paged virtual memory](./assets/paged%20virtual%20mem.png)

</details>

<details>
<summary><strong>
Bespreek hoe de omzetting van virtuele adressen naar fysieke adressen wordt versneld door gebruik te maken van
een Memory Management Unit (MMU) en een Translation Lookaside Buffer (TLB).
</strong></summary>

- **Memory Management Unit (MMU):**

  - een hardwarecomponent die verantwoordelijk is voor het vertalen van virtuele adressen naar fysieke adressen.
  - beheert de paginering en segmentatie van geheugen, waardoor elk proces zijn eigen virtuele adresruimte kan hebben.
  - zorgt voor geheugenbescherming door te controleren of een proces toegang heeft tot bepaalde geheugenlocaties.
  - verantwoordelijk voor het bijhouden van de paginatabellen die de vertalingen bevatten.
  - werkt samen met de CPU om geheugenadressen efficiënt te beheren.

- **Translation Lookaside Buffer (TLB):**

  - een kleine, snelle cache binnen de MMU die recent gebruikte vertalingen van virtuele naar fysieke adressen opslaat.
  - wanneer de CPU een virtueel adres opvraagt, controleert de MMU eerst de TLB om te zien of de vertaling al beschikbaar is.
  - als de vertaling in de TLB wordt gevonden (TLB hit), kan het fysieke adres snel worden opgehaald zonder de paginatabellen te hoeven raadplegen.
  - als de vertaling niet in de TLB wordt gevonden (TLB miss), moet de MMU de paginatabellen raadplegen om de vertaling te vinden, wat meer tijd kost.
  - na het ophalen van de vertaling uit de paginatabellen, wordt deze toegevoegd aan de TLB voor toekomstige snelle toegang.

- **Versnelling van Adresomzetting:**

als er een locatie word opgeraagd zal de mmu eerst in de tlb kijken of die er al in staat, als die er in staat (tlb hit) kan die snel het fysieke adres teruggeven, als die er niet in staat (tlb miss) moet die de page tables gaan opzoeken wat veel trager is. dus hoe meer hits hoe sneller het systeem.

![MMU and TLB](./assets/MMU%20en%20TLB.png)
</details>

---

# Chapter 8 Performance-Enhancing Techniques

**Cache hit/miss:** zit data in cache of niet.

**Locality:** data dichtbij in tijd en plaats.

**Direct / Set / Full associative:** verschillende manieren om cache te koppelen.

**Write-through / write-back:** direct naar RAM of later.

**Pipeline:** meerdere instructies tegelijk in verschillende fases.

**Out-of-order:** CPU herschikt instructies voor snelheid.

---

# Chapter 9 Specialized Processor Extensions

**Interrupt vs exception:** interrupt = extern, exception = intern.

**Privilege modes:** kernel / user.

**IEEE754:** sign, exponent (biased), mantissa.

**DVFS:** Dynamic Voltage and Frequency Scaling. P â‰ˆ C Â· VÂ² Â· f

**TPM:** beveiligde chip voor sleutels en integriteit.

---

Einde samenvatting.
