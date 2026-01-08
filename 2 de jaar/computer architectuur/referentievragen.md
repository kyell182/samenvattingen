# Computer Architecture: referentievragen en antwoorden

---

## Chapter 1 – Introducing Computer Architecture

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

❗dit probleem werd opgelost door locking mechanisms te ontwerpen. deze zorgden ervoor dat de tandwielen werden vergrendeld en in geldige posities werden geforceerd.

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
  
  - **Seriële verwerking:** instructies worden sequentieel uitgevoerd, wat kan leiden tot bottlenecks (Von Neumann bottleneck).

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
  
- hierdoor kan het fysieke adres worden berekend als: fysieke adres = (segment × 16) + offset.
  
- aangezien zowel het segment als het offset 16 bits zijn, resulteert dit in een maximaal fysiek adres van 20 bits (16 + 4), wat overeenkomt met 2^20 = 1 MB aan adresseerbaar geheugen.

![intel 8088 chip](./assets/intel%208088%20chip.png)

</details>

<details>
<summary><strong>
Omschrijf de Wet Van Moore.

 Bespreek enkele limieten die de linearisatie van deze wet in de toekomst niet meer ondersteunen.

- Verklaar de afkortingen CPU en GPU en verklaar enkele essentiële verschillen tussen de werking van een CPU en een GPU.

</strong></summary>

- **Wet van Moore:**

  - het aantal transistors op een geïntegreerde schakeling verdubbelt ongeveer elke twee jaar, wat leidt tot een exponentiële groei in rekenkracht en een afname van de kosten per transistor.

- **Limieten van de Wet van Moore:**
  
  - **Fysieke limieten:**
    - naarmate transistors kleiner worden, komen ze dichter bij de atomaire schaal, men kan niet kleiner gaan dan atomen.
  - **Warmteontwikkeling:**
    - hogere transistor dichtheden leiden tot meer warmte, wat koelingsproblemen veroorzaakt.
  - **energieverbruik:**
    - kleinere transistors kunnen leiden tot hogere lekstromen, wat het energieverbruik verhoogt. wat leidt tot inefficiëntie.
  - **Kosten:**
    - de kosten voor het produceren van steeds kleinere transistors stijgen aanzienlijk.
  - **snelheid:**
    - er zijn fysieke en technische beperkingen aan hoe snel transistors kunnen schakelen.

</details>

<details>
<summary><strong>
Verklaar de afkortingen CPU en GPU en verklaar enkele essentiële verschillen tussen de werking van een CPU en een GPU.
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

# Chapter 3 – Processor Elements

## Vragen

• Verklaar de afkorting CISC en de afkorting RISC en benoem de verschillen tussen beide computerarchitecturen.

• Verklaar de werking van de 6502 stapel-instructies PHA en PLA. De werking van de 6502 stapel is volgens het LIFO-principe en wat is de relatie met het S-register en de processorvlaggen?

• Verklaar het verschil tussen een maskable en non-maskable interrupt. Wat zijn de adressen van de interrupt service routines van beide interrupts en welke interrupt is level- of edge sensitive?

• Licht de 3 manieren van I/O-processing toe en wat zijn de verschillen tussen port-mapped I/O en memory-mapped I/O?

• Exercise 4 checksum

## Antwoorden

**CISC:** Complex Instruction Set Computer. Veel complexe instructies.
**RISC:** Reduced Instruction Set Computer. Weinig simpele instructies, sneller te pipelinen.

**PHA/PLA:** PHA pusht A op stack, PLA haalt van stack. Stack pointer = S-register.

**Maskable:** kan uitgeschakeld worden. **Non-maskable:** kan niet genegeerd worden (kritisch).

**I/O:** polling, interrupts, DMA.
Port-mapped = aparte adresruimte. Memory-mapped = I/O in geheugenruimte.

**Checksum:** bytes optellen, 2’s complement nemen, later alles samen optellen → moet 0 geven.

---

# Chapter 5 – Hardware-Software Interface

## Vragen

(alle originele vragen uit syllabus)

## Antwoorden

**PCI:** Peripheral Component Interconnect
**PCIe:** PCI express

**BIOS:** Basic Input Output System
**POST:** Power On Self Test
**UEFI:** moderne vervanger van BIOS

**MBR limiet:** max 2 TB en 4 partities. UEFI/GPT lost dit op.

**Process vs thread:** thread deelt geheugen, process niet.

**Process toestanden:** new, ready, running, waiting, terminated.

**TCB/PCB:** Thread Control Block / Process Control Block

**Scheduling:** FCFS, Round Robin, Priority, Shortest Job First

**SMP:** meerdere identieke CPU’s. SIMD = vector, MIMD = meerdere instructiestromen.

---

# Chapter 6 – Specialized Computing Domains

## Antwoorden in het kort

**Hard real-time:** deadline missen = fout.
**Soft:** mag soms missen.
**Firm:** resultaat nutteloos na deadline.

**RTOS vs GPOS:** RTOS = voorspelbaar in tijd.

**Mutex:** lock op resource.
**Semaphore:** teller voor meerdere toegangen.

**Critical section:** stuk code dat maar door één thread tegelijk mag gebruikt worden.

**GPU voordeel:** massaal parallel → grafiek, AI, video.

---

# Chapter 7 – Processor and Memory Architectures

**Von Neumann:** data + code samen.
**Harvard:** apart.
**Modified:** mix.

**MMU + TLB:** versnellen virtueel → fysiek adres.

---

# Chapter 8 – Performance-Enhancing Techniques

**Cache hit/miss:** zit data in cache of niet.

**Locality:** data dichtbij in tijd en plaats.

**Direct / Set / Full associative:** verschillende manieren om cache te koppelen.

**Write-through / write-back:** direct naar RAM of later.

**Pipeline:** meerdere instructies tegelijk in verschillende fases.

**Out-of-order:** CPU herschikt instructies voor snelheid.

---

# Chapter 9 – Specialized Processor Extensions

**Interrupt vs exception:** interrupt = extern, exception = intern.

**Privilege modes:** kernel / user.

**IEEE754:** sign, exponent (biased), mantissa.

**DVFS:** Dynamic Voltage and Frequency Scaling. P ≈ C · V² · f

**TPM:** beveiligde chip voor sleutels en integriteit.

---

Einde samenvatting.
