# sammenvating AI Programming

## Intuïtie van kunstmatige intelligentie ( Hoofdstuk 1 )

Waarom bestaat er geen eensluidende definitie van kunstmatige intelligentie?

Er bestaat geen vaste of eenvoudige definitie van intelligentie.

Wat men onder “intelligentie” verstaat, verschilt van persoon tot persoon en hangt af van de context.

Daarom bestaat er ook geen eenduidige definitie van kunstmatige intelligentie.

De betekenis van AI is dus subjectief en afhankelijk van hoe men intelligentie zelf bekijkt.

---

Wat is het verschil tussen kwantitatieve en kwalitatieve data? Geef enkele concrete voorbeelden van beide soorten data.

**Soorten gegevens**

- Kwantitatieve gegevens

  - Kwantitatieve gegevens zijn **meetbaar** en kunnen in **getallen** worden uitgedrukt.

    **Voorbeelden:**

    - Aantal mensen in een ruimte
    - Temperatuur van een ruimte
    - Gewicht van een persoon

- Kwalitatieve gegevens

  - Kwalitatieve gegevens zijn **niet meetbaar met getallen** en beschrijven een **eigenschap of kenmerk**.

    **Voorbeelden:**

    - Kleur van een ruimte
    - Geur van een ruimte
    - Smaak van een gerecht

---

Wat is het verschil tussen data, informatie en kennis?

- Data, Informatie en Kennis

  - **Data** = ruwe feiten en cijfers zonder betekenis.
  - **Informatie** = verwerkte data die **betekenis** heeft gekregen.
  - **Kennis** = informatie die **begrepen** is en kan worden gebruikt om **beslissingen te nemen**.

```mermaid
---
config:
  layout: elk
---
flowchart LR
    A[Data
    Ruwe feiten en cijfers] --> B[Informatie
    Verwerkte data met betekenis]
    B --> C[Kennis
    Begrepen informatie
    voor beslissingen]
```

---

Wat is een algoritme? Wat is een AI-algoritme? Wat zijn de componenten van een algoritme?

- **Algoritme**

  - een reeks duidelijke instructies om een probleem op te lossen.

- **AI-algoritme**

  - een algoritme dat gebruikt wordt voor problemen waarvoor menselijke intelligentie nodig is.

    - Het kan leren uit data
    - Het wordt beter naarmate het meer gebruikt wordt

- Elk algoritme bestaat uit:

  - **Input**

    - de gegevens die je erin stopt

  - **Verwerking**

    - de stappen/instructies die worden uitgevoerd

  - **Output**

    - het resultaat

---

Noem een ​​paar categorieën problemen die mensen proberen op te lossen met behulp van (AI) algoritmen.

- Enkele problemen die met AI-algoritmen worden opgelost:

  - Beeldherkenning (bv. gezichten of objecten herkennen)

  - Spraakherkenning (bv. spraak omzetten naar tekst)

  - Natuurlijke taalverwerking (bv. tekst begrijpen en genereren)

  - Autonoom rijden (bv. zelfrijdende auto’s)

```mermaid
flowchart TD
    AI[AI-algoritmen] --> B[Beeldherkenning]
    AI --> S[Spraakherkenning]
    AI --> T[Natuurlijke taalverwerking]
    AI --> A[Autonoom rijden]
```

---

Wat is het verschil tussen een lokale beste oplossing en een globale beste oplossing?

- Lokale beste oplossing:

  - De beste oplossing binnen een **beperkt deel** van de oplossingsruimte
  
  - Niet noodzakelijk de allerbeste oplossing

- Globale beste oplossing:

  - De beste oplossing binnen de **volledige** oplossingsruimte

  - Dit is de **echte optimale** oplossing

```mermaid
graph TD
    %% Berg-achtergrond als opeenvolgende toppen
    Start((1)) --> Top1((2)) 
    Top1 --> Top2((3))
    Top2 --> Top3((4))
    Top3 --> Top4((5))
    Top4 --> Einde((6))

    %% Labels voor toppen
    Top1 -->|Lokale top| L1[Lokale beste oplossing]
    Top2 -->|Lokale top| L2[Lokale beste oplossing]
    Top4 -->|Globale top| G1[Globale beste oplossing]

    %% Styling
    class L1,L2 lokal
    class G1 global

    classDef lokal fill:#f9d5d3,stroke:#e34c26,stroke-width:2px;
    classDef global fill:#d3f9d8,stroke:#28a745,stroke-width:3px;

```

---

Wat is het verschil tussen superintelligentie, algemene intelligentie en smalle intelligentie?

- Superintelligentie:

  - Intelligentie die **hoger is dan menselijke intelligentie**

- Algemene intelligentie:

  - Intelligentie die **op elk probleem** kan worden toegepast

- Smalle intelligentie:

  - Intelligentie die **slechts op één specifiek probleem** kan worden toegepast

```mermaid
flowchart TD
    AI[Intelligentie]
    AI --> N[Smalle intelligentie
    Specifiek probleem]
    AI --> G[Algemene intelligentie
    Elk probleem]
    AI --> S[Superintelligentie
    Hoger dan menselijk]
```

---

Wat is het verband tussen op biologie geïnspireerde algoritmen, machine learning, deep learning en zoekalgoritmen?

- Biologisch geïnspireerde algoritmen:

  - Geïnspireerd door biologische processen

  - Voorbeelden:

    - genetische algoritmen
    - genetisch programmeren
    - mierenkolonie-optimalisatie
    - deeltjeszwermoptimalisatie

  - Vaak onderdeel van evolutionaire computationele methoden

- Machine learning:

  - AI-type dat **leert van data** en **in de loop van de tijd verbetert**

  - Maakt voorspellingen en beslissingen op basis van geleerde data

- Deep learning:

  - Richt zich op **diepe neurale netwerken** met veel lagen

  - Kan hoogwaardige kenmerken en representaties uit data leren

  - Kenmerken: meerlaagse architectuur, end-to-end leren

- Zoekalgoritmen:

  - Worden gebruikt om een oplossing voor een probleem te **vinden**

  - Vaak toegepast bij **optimalisatieproblemen** om de beste oplossing te vinden

- Relatie tussen deze algoritmen:

  - Allemaal typen **AI-algoritmen**

  - Gebruikt om problemen op te lossen die **intelligentie vereisen**

  - Ontworpen om **menselijke intelligentie na te bootsen** en te **leren van data**

```mermaid
flowchart TD
    AI[AI-algoritmen] --> BIO[Biologisch geïnspireerd
    Genetische algoritmen, etc.]
    AI --> ML[Machine Learning
    Leert van data, verbetert over tijd]
    ML --> DL[Deep Learning
    Diepe neurale netwerken, end-to-end leren]
    AI --> SEARCH[Zoekalgoritmen
    Optimalisatieproblemen, beste oplossing vinden]
    
    %% Styling voor duidelijkheid
    class BIO,ML,DL,SEARCH aiType
    classDef aiType fill:#d3f9d8,stroke:#28a745,stroke-width:2px
```

---

Welke drie soorten 'leren' vallen onder machine leren en kunt u elk type 'leren' kort toelichten?

- **Machine learning types**

  - **Supervised learning**
  
    - Leert van **gelabelde data**  

    - Algoritme wordt getraind om **voorspellingen** te doen op basis van geleerde data

  - **Unsupervised learning**  

    - Leert van **ongelabelde data**  

    - Algoritme ontdekt **patronen en verbanden** in de data

  - **Reinforcement learning**  

    - Leert van **feedback/beloningssysteem**

    - Algoritme leert **beslissingen nemen** op basis van ontvangen feedback

```mermaid
flowchart TD
    AI[AI-algoritmen] --> ML[Machine Learning]
    ML --> SUP[Supervised Learning
    Gelabelde data]
    ML --> UNSUP[Unsupervised Learning
    Ongelabelde data]
    ML --> RL[Reinforcement Learning
    Beloningsfeedback]
    ML --> DL[Deep Learning
    Diepe neurale netwerken]

    class SUP,UNSUP,RL,DL mlType
    class ML,AI aiType

    classDef aiType fill:#d3f9d8,stroke:#28a745,stroke-width:2px;
    classDef mlType fill:#f9f1a5,stroke:#e6b800,stroke-width:2px;

```

---