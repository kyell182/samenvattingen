# AI Fundamentals – Samenvatting en Antwoorden (VIVES Brugge)

*Bachelor ICT & Elektronica – 2e jaar*

---

## Inleiding

Dit document is een **samenvatting van de leerstof en een beantwoording van de referentievragen** uit de cursus **AI Fundamentals**. De tekst is geschreven vanuit het perspectief van een **student 2e bachelor ICT & Elektronica aan VIVES** en is gebaseerd op de cursusinhoud. De focus ligt op **begrip, overzicht en voorbereiding op het examen**, niet op academische formuleringen.

---

# Hoofdstuk 1 – Introduction and Examples

<details>
<summary><strong>Wat is Artificiële Intelligentie (AI)?</strong></summary>

**Definitie (Elaine Rich):**  
AI is de studie van hoe we computers dingen kunnen laten doen waar mensen op dit moment beter in zijn.

**Sterktes:**
- Dynamische definitie
- Niet vastgepind op mens-nabootsing

**Zwaktes:**
- Wat vandaag AI is, is morgen gewone software

📷 *Hier kan je een schema toevoegen dat klassieke software vergelijkt met AI (regels vs. leren).* 
</details>

<details>
<summary><strong>Braitenberg-experiment</strong></summary>

Eenvoudige systemen met sensoren en motoren kunnen **schijnbaar intelligent gedrag** vertonen.

➡️ Belangrijk: complex gedrag betekent niet dat het systeem intern complex is.
</details>

<details>
<summary><strong>Vier fundamentele AI-strategieën</strong></summary>

1. Handelen als mensen – chatbots
2. Denken als mensen – IBM Watson
3. Rationeel denken – logische systemen
4. Rationeel handelen – intelligente agents

📷 *Overzichtsdiagram met de vier categorieën.*
</details>

<details>
<summary><strong>De Turing Test</strong></summary>

Een machine is intelligent als een mens via tekst geen verschil ziet tussen mens en machine.

📷 *Schema van de Turing Test.*
</details>

<details>
<summary><strong>Vijf belangrijke mijlpalen in AI</strong></summary>

- 1936 – Alan Turing: Turing machine
- 1956 – Dartmouth Conference
- 1997 – Deep Blue
- 2016 – AlphaGo

📷 *Tijdslijn-afbeelding.*
</details>

<details>
<summary><strong>Onbeslisbaarheid & NP-compleetheid</strong></summary>

Sommige AI-problemen hebben geen algoritmische oplossing of zijn niet efficiënt oplosbaar.

➡️ Daarom gebruikt AI heuristieken.
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

