# AI Fundamentals – Samenvatting en Antwoorden

---

## Hoofdstuk 1 – Introduction and Examples

<details>
<summary><strong>Wat is Artificiële Intelligentie? Geef een mogelijke definitie en licht de sterke en zwakke
aspecten toe in deze definitie.</strong></summary>

**Definitie (Elaine Rich):**  
AI is de studie van hoe we computers dingen kunnen laten doen waar mensen op dit moment beter in zijn.

**Sterktes:**

- Dynamische definitie
- Niet vastgepind op mens-nabootsing

**Zwaktes:**

- Wat vandaag AI is, is morgen gewone software

</details>

<details>
<summary><strong>Omschrijf het experiment van psycholoog Valentin Braitenberg om intelligent gedrag bij
systemen te demonsteren.</strong></summary>

Eenvoudige systemen met sensoren en motoren kunnen **schijnbaar intelligent gedrag** vertonen.

**opzet**

- Voertuig met twee sensoren (licht) en twee motoren
- Sensoren verbonden met motoren (direct of cross-wired)
- Verschillende verbindingen leiden tot verschillend gedrag (aantrekken, vermijden, nieuwsgierigheid)

**resultaten**

- Eenvoudige verbindingen leiden tot complex gedrag.

![Braitenberg-voertuig](./assets/Braitenberg%20robots.png)

💡 Belangrijk: complex gedrag betekent niet dat het systeem intern complex is.

</details>

<details>
<summary><strong>Wat zijn de vier fundamentele strategieën binnen AI? Eén ervan is: ‘systemen’ gedragen zich als
mensen. Geef telkens een concreet voorbeeld voor elk van deze strategieën.</strong></summary>

1. Handelen als mensen – chatbots

   - chatbots zoals ELIZA imiteren menselijk gesprek.

2. Denken als mensen – IBM Watson

    - IBM Watson gebruikt natuurlijke taalverwerking en kennisrepresentatie om vragen te beantwoorden.

3. Rationeel denken – logische systemen

    - Logische systemen gebruiken formele logica om geldige conclusies te trekken.

4. Rationeel handelen – intelligente agents

    - Intelligente agents nemen beslissingen om hun doelen te bereiken, zoals zelfrijdende auto's.

</details>

<details>
<summary><strong> Bespreek de Turing test om intelligentie bij ‘systemen’ aan te tonen.</strong></summary>

De Turingtest stelt dat een machine intelligent is als een mens haar, via tekstuele interactie, niet kan onderscheiden van een andere mens.

![Turing Test Diagram](./assets/turing%20test.png)

</details>

<details>
<summary><strong>Vijf belangrijke mijlpalen in AI</strong></summary>

- **1936 – Alan Turing: Turing machine**

  - Basis voor computationele theorie.
  - Formele definitie van algoritmen.

- **1956 – Dartmouth Conference**

  - Eerste officiële AI-conferentie.
  - Introductie van de term "Artificial Intelligence".
  - Start van AI-onderzoek als academisch veld.

- **1997 – Deep Blue**

  - Eerste schaakcomputer die wereldkampioen Garry Kasparov versloeg.
  - Toonde de kracht van brute-force zoekalgoritmen in games.
  - Legde de basis voor verdere ontwikkeling van AI in strategische spellen.

- **2012 - ImageNet & AlexNet**

  - Doorbraak in beeldherkenning met diepe neurale netwerken.
  - Significant verbeterde nauwkeurigheid bij het classificeren van afbeeldingen.
  - Versnelde de adoptie van deep learning in diverse AI-toepassingen.

- **2016 – AlphaGo**

  - Eerste AI die een professionele Go-speler versloeg.
  - Combineerde deep learning met Monte Carlo Tree Search.
  - Toonde het potentieel van AI in complexe, strategische omgevingen.

</details>

<details>
<summary><strong> Veel gekende inferentie- of leerprocessen zijn onbepaalbaar/onbeslisbaar. Wat betekent dit
praktisch voor artificiële intelligentie?</strong></summary>

het betekent dat er geen algemene algoritmen bestaan die voor alle mogelijke gevallen een oplossing kunnen bieden. In de praktijk betekent dit dat AI-systemen vaak heuristieken, benaderingen of beperkingen moeten gebruiken om problemen op te lossen, omdat ze niet altijd een perfecte of optimale oplossing kunnen garanderen.

heuristieken zijn vuistregels of benaderingen die helpen bij het vinden van goede oplossingen binnen redelijke tijd, ook al garanderen ze niet altijd de beste oplossing. AI-onderzoekers moeten dus vaak compromissen sluiten tussen nauwkeurigheid, efficiëntie en haalbaarheid bij het ontwerpen van AI-systemen.

</details>

<details>
<summary><strong>Wat is de NP-compleetheid van een algoritme?</strong></summary>

Een probleem is NP-compleet als een oplossing snel te controleren is, maar het probleem zelf even moeilijk is als alle andere NP-problemen.
Als er ooit een efficiënt algoritme wordt gevonden voor één NP-compleet probleem, dan zijn alle NP-problemen efficiënt oplosbaar.
Omdat dit niet het geval is, gebruikt artificiële intelligentie in de praktijk heuristieken en benaderingen in plaats van exacte oplossingen.

</details>

<details>
<summary><strong>

Verklaar volgende begrippen:

- Reflex agent
- Distributed agent
- Learning agent
- Hardware agent

</strong></summary>

- **Reflex agent** :

  - Neemt beslissingen op basis van de huidige perceptie.
  - Werkt met conditionele regels (if-then).
  - Voorbeeld: thermostaat die de temperatuur regelt.

- **Distributed agent** :

  - Bestaat uit meerdere samenwerkende agents.
  - Verdeelt taken en informatie.
  - Voorbeeld: swarm robots die samenwerken om een taak uit te voeren.

- **Learning agent** :

  - Kan zijn prestaties verbeteren door ervaring.
  - Bestaat uit een leercomponent, een prestatiecomponent, een criticus en een probleemomgevingsmodel.
  - Voorbeeld: een zelfrijdende auto die leert van rijervaringen.

- **Hardware agent** :

  - Fysieke entiteit die taken uitvoert.
  - Voorbeeld: robotarm in een fabriek.

</details>

<details>
<summary><strong>

Gegeven: een ‘agent met geheugen’ kan zich verplaatsen in een 2D-vlak. Via een real-time klok ontvangt de ‘agent’ periodiek (∆𝑡) zijn exacte positie (𝑥, 𝑦) in Cartesiaanse coördinaten.
• Opgave:
o Geef de formule, om de snelheid te bepalen op basis van de positie op tijdstippen 𝑡 en 𝑡 − ∆𝑡.
o Geef de formule, om de versnelling te bepalen op basis van de positie op tijdstippen 𝑡, 𝑡 − ∆𝑡 en
𝑡 − 2∆𝑡

</strong></summary>

### Snelheid en versnelling van een agent in 2D

**Snelheid**

De snelheid vector op tijdstip \(t\) wordt berekend met:  

![snelheid](./assets/snelheid.png)

**Versnelling**

De versnelling vector op tijdstip \(t\) wordt berekend met:  

![versnelling](./assets/versnelling.png) 
---

### Uitleg van componenten

| Symbool | Betekenis |
|---------|-----------|
| \(x_t, y_t\) | Positie van de agent op tijdstip \(t\) |
| \(x_{t-\Delta t}, y_{t-\Delta t}\) | Positie één tijdstap eerder |
| \(x_{t-2\Delta t}, y_{t-2\Delta t}\) | Positie twee tijdstappen eerder |
| \(\Delta t\) | Tijd tussen twee opeenvolgende metingen |
| \(\vec{v}(t)\) | Snelheid vector op tijdstip \(t\) |
| \(\lvert\vec{v}(t)\rvert\) | Absolute snelheid (snelheidsnorm) |
| \(\vec{a}(t)\) | Versnelling vector op tijdstip \(t\) |

</details>

<details>
<summary><strong>Teken de generieke architectuur van een knowledge-based system en licht toe.</strong></summary>

**Een Knowledge-Based System (KBS) bestaat uit twee dingen:**

Kennisbank (Knowledge Base) – hier staat alle info en regels over een onderwerp.

Denkmachine (Inference Engine) – dit gebruikt de kennis om dingen te berekenen of beslissingen te nemen.

**Waarom scheiden handig is:**

- Je hoeft de denkmachine maar één keer te maken.

- Wil je het systeem voor iets nieuws gebruiken? Vervang gewoon de kennisbank, niet alles opnieuw programmeren.

- De kennis staat los van hoe het gebruikt wordt, dus makkelijk aan te passen en te onderhouden.

**Kort voorbeeld:**

- Stel je hebt een medisch systeem voor griep.

- Wil je hetzelfde systeem voor verkoudheid?

- Gewoon de kennisbank vervangen → de denkmachine blijft hetzelfde.

![Knowledge-Based System Architecture](./assets/KBS.png)

**Uitleg van componenten:**

- **Knowledge Base** : Bevat feiten en regels over de wereld.

- **Inference Engine** : Past logica toe om nieuwe kennis af te leiden.

</details>

# Hoofdstuk 2 – Machine Learning & Data Mining


## Types Machine Learning

📷 *Schema dat supervised, unsupervised en reinforcement learning vergelijkt.*

| Type | Data | Feedback | Typisch voorbeeld | Wanneer gebruiken |
|-----|------|----------|------------------|------------------|
| Supervised | Met labels | Correct/fout | Spamfilter | Als juiste output gekend is |
| Unsupervised | Zonder labels | Geen | Clustering | Structuur zoeken in data |
| Reinforcement | Acties + beloning | Reward/penalty | AlphaGo | Beslissingen over tijd |

---

## Generalization

Het vermogen van een model om **nieuwe data correct te behandelen**.

---

## Learning agent

Agent die:
- Prestaties evalueert
- Zichzelf verbetert

---

## Data Mining

Automatisch ontdekken van **patronen in grote datasets**.

Voorbeelden:
- Fraudedetectie
- Marketing

---

## Statistische formules

<details>
<summary><strong>Gemiddelde</strong></summary>

**Formule:**  
μ = (1/n) Σ xi

**Uitleg per onderdeel:**
- **xi**: individuele meetwaarde
- **Σ xi**: som van alle meetwaarden
- **n**: aantal meetwaarden
- **μ**: gemiddelde

➡️ Het gemiddelde is de centrale waarde van de dataset.
</details>

<details>
<summary><strong>Standaardafwijking</strong></summary>

**Formule:**  
σ = √[(1/n) Σ (xi − μ)²]

**Uitleg per onderdeel:**
- **xi − μ**: afwijking t.o.v. het gemiddelde
- **(xi − μ)²**: kwadratische afwijking
- **Σ**: som van alle afwijkingen
- **1/n**: gemiddelde afwijking
- **√**: terug naar originele schaal

➡️ Geeft aan hoe sterk data verspreid is.
</details>

<details>
<summary><strong>Covariantie</strong></summary>

**Formule:**  
cov(x,y) = (1/n) Σ (xi − μx)(yi − μy)

**Uitleg per onderdeel:**
- **(xi − μx)**: afwijking van x
- **(yi − μy)**: afwijking van y
- **Product**: gezamenlijke verandering
- **cov(x,y)**: samenhang tussen x en y

➡️ Positief = samen stijgen, negatief = tegengesteld.
</details>

<details>
<summary><strong>Correlatiecoëfficiënt</strong></summary>

**Formule:**  
ρ = cov(x,y) / (σx σy)

**Uitleg per onderdeel:**
- **cov(x,y)**: covariantie
- **σx, σy**: standaardafwijkingen
- **Deling**: normalisatie

➡️ Waarde tussen −1 en +1.
</details>

---

## Perceptron

Lineaire classifier:

f(x) = sign(w·x + b)

Leert via iteratieve gewichtsaanpassing.

---

## Afstanden (Nearest Neighbor)

| Afstand | Formule | Betekenis | Gebruik |
|--------|---------|-----------|---------|
| Euclidisch | √Σ(xi−yi)² | Rechte lijn | Continue data |
| Manhattan | Σ|xi−yi| | Rasterafstand | Grid / stadsblokken |
| Hamming | # verschillen | Bits tellen | Binaire data |

---

## k-Nearest Neighbor (k-NN)

📷 *2D-plot met datapunten en cirkel rond het nieuwe punt (visualisatie van k).*

Classificatie via **meerderheid van k dichtste buren**.

---

## Lazy vs Eager learning

| Kenmerk | Lazy learning | Eager learning |
|--------|---------------|----------------|
| Leren | Bij query | Vooraf |
| Voorbeeld | k-NN | Decision Tree |
| Opslag | Veel data | Model |
| Snelheid predictie | Traag | Snel |

---

## Case-Based Reasoning (CBR)

Oplossing zoeken via **gelijkaardige gevallen**.

Problemen:
- Modellering
- Similariteit
- Transformatie

---

## Entropy & Information Gain

<details>
<summary><strong>Entropy</strong></summary>

**Formule:**  
H = − Σ pi log2(pi)

**Uitleg per onderdeel:**
- **pi**: kans op klasse i
- **log2(pi)**: informatie-inhoud in bits
- **pi · log2(pi)**: bijdrage per klasse
- **Σ**: som over alle klassen
- **−**: maakt resultaat positief

➡️ Meet onzekerheid in de data.
</details>

<details>
<summary><strong>Information Gain</strong></summary>

**Formule:**  
G(D,A) = H(D) − Σ (|Di|/|D|) · H(Di)

**Uitleg per onderdeel:**
- **H(D)**: entropy vóór splitsing
- **Di**: subsets na splitsing
- **|Di|/|D|**: gewicht van subset
- **H(Di)**: entropy per subset
- **G(D,A)**: informatie-winst

➡️ Hoogste gain = beste splitsing.
</details>

# Hoofdstuk 3 – Neural Networks
 – Neural Networks

## Neuron model

📷 *Afbeelding van een artificieel neuron met inputs, gewichten, som en activatiefunctie.*

z = w·x − θ  
y = σ(z)

Activation function: introduceert **niet-lineariteit**.

---

## Fitting

- Underfitting: te simpel
- Overfitting: te complex
- Optimal: juiste balans

---

## Sigmoid

σ(x) = 1 / (1 + e^(−(x−θ)/T))

Gebruikt in **hidden & output layers**.

---

## Hebb rule

Δw = η · x · y

"Neurons that fire together, wire together."

---

## Gradient descent / Delta rule

Δw = −η · ∂E/∂w

---

## Backpropagation

- Fout van output naar input
- Gewichten aangepast via gradient descent

---

## Support Vector Machine (SVM)

Zoekt **maximale marge** tussen klassen.

Support vectors = kritische punten.

---

## Deep learning & Autoencoders

- Unsupervised pretraining
- Daarna supervised fine-tuning

---

## CNN

📷 *Schema van een CNN: convolution → pooling → fully connected.*

Structuur:
- Convolution layers
- Pooling
- Fully connected

Principe: **lokale filters + weight sharing**.

---

# Hoofdstuk 4 – Search, Games and Problem Solving

## Aantal knooppunten

N ≈ b^d

---

## Branching factor

- Average: gemiddeld
- Effective: echte impact

---

## Eigenschappen zoekalgoritmen

- Deterministic
- Observable
- Complete
- Optimal

---

## BFS & DFS

| Eigenschap | BFS | DFS |
|-----------|-----|-----|
| Strategie | Level per level | Zo diep mogelijk |
| Geheugen | Hoog | Laag |
| Volledig | Ja | Nee (oneindig) |
| Optimale oplossing | Ja (gelijke kosten) | Nee |

---

## Iterative Deepening

Combineert:
- Volledigheid BFS
- Geheugen DFS

➡️ Beste uninformed search.

---

## Heuristic search

Gebruikt schatting h(s).

---

## Greedy Search

f(s) = h(s)

---

## A* Search

<details>
<summary><strong>Evaluatiefunctie</strong></summary>

**Formule:**  
f(s) = g(s) + h(s)

**Uitleg per onderdeel:**
- **s**: huidige toestand
- **g(s)**: kost van start tot s
- **h(s)**: geschatte kost tot doel
- **f(s)**: totale geschatte kost

➡️ A* kiest de toestand met laagste f(s).
</details>

---

## Alpha-Beta Pruning

📷 *Voorbeeld-search tree met gesnoeide takken (klassiek Minimax-diagram).*

Snoeit takken als:

α ≥ β

➡️ Minder knooppunten, zelfde resultaat.

---

## Monte Carlo Tree Search (MCTS)

- Random simulaties
- Statistische evaluatie

➡️ Zeer efficiënt bij grote spelbomen.

---

## Conclusie

AI combineert:
- Leren uit data
- Zoeken in complexe ruimtes
- Rationeel handelen

Moderne AI is **data-gedreven, pragmatisch en schaalbaar**.

