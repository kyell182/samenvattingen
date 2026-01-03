# AI MATH

dit is een samenvatting van de belangrijkste wiskundige concepten die relevant zijn voor kunstmatige intelligentie (AI). Deze samenvatting behandelt onderwerpen zoals lineaire algebra, calculus, statistiek en waarschijnlijkheid, die allemaal essentieel zijn voor het begrijpen en ontwikkelen van AI-algoritmen.

## 1. Vectoren

<details>
<summary><strong>1.1. Wat is een vector</strong></summary>

![vector](./assets/vectoren/dit%20is%20een%20vector.png)

Een vector stelt een verplaatsing voor tussen 2 punten in in de ruimte.
voorgesteld als een pijl tussen 2 punten.

Grafisch :

![vector grafisch](./assets/vectoren/grafische%20voorstelling.png)
( pijl van punt P naar punt Q )

Een vector word volledig bepaald door :

- Groote (lengte van de pijl)
- Richting (de richting waarin de pijl wijst)
- Zin (welke kant de pijl wijst)

meestal worden vrije vectoren gebruikt.

- deze mogen verplaatst worden zonder dat hun eigenschappen veranderen.

</details>

<details>
<summary><strong>1.2. speciale vectoren</strong></summary>

- **Plaatsvector**
  - een vector die de positie van een punt in de ruimte aangeeft ten opzichte van de oorsprong.

    ![plaatsvector](./assets/vectoren/vector%20in%20de%20oorsprong%20.png)
    ![plaatsvector grafisch](./assets/vectoren/vecor%20in%20oorsprong%20grafisch.png)

- **Nulvector**
  - een vector met een lengte van 0, die geen richting heeft.
  - met een absolute waarde van 0.

    ![nulvector](./assets/vectoren/nul%20vector.png)
    ![nulvector grafisch](./assets/vectoren/nul%20vector%20grafisch.png)

- **Eenheidsvector**
  - een vector met een lengte van 1, die vaak wordt gebruikt om een richting aan te geven.
  - met een absolute waarde van 1.
  - meestal worden deze met een `e` of een hoedje (^) boven de letter aangeduid.

    ![eenheidsvector](./assets/vectoren/eenheids%20vectoren.png)

**norm (lengte) :**
- deze wordt aangeduid met ||v||.

</details>

---

### 1.2. vectoren in het vlak (2D)

**voorsteling van een vector in het vlak (2D)** :

de vectoren van e1 en e2 worden de basisvectoren genoemd.
deze worden gebruikt als referentie om andere vectoren in het vlak te beschrijven.

voor basisvectoren geldt :

- ||e1|| = 1
- ||e2|| = 1
- e1 en e2 staan loodrecht op elkaar (orthogonaal).

![vector in 2D](./assets/vectoren/vectoren%20in%20het%20vlak.png)

de coordinaten van de vectoren zijn (x, y) waarbij x de horizontale component is en y de verticale component.

- e1 = (1, 0)
- e2 = (0, 1)

voor nulvector geldt :

- 0 = (0, 0)

**lengte van een vector in 2D :**

- ||v|| = √(x² + y²)

### 1.3. vectoren in de ruimte (3D)

**voorsteling van een vector in de ruimte (3D)** :

de basisvectoren in 3D zijn e1, e2 en e3.

- e1 = (1, 0, 0)
- e2 = (0, 1, 0)
- e3 = (0, 0, 1)
- nulvector = (0, 0, 0)
- staan loodrecht op elkaar (orthogonaal).

- ||e1|| = 1
- ||e2|| = 1
- ||e3|| = 1
- ||0|| = 0

**algebraische voorstelling van een vector in 3D :**

```math
a+b = (a_1 + b_1, a_2 + b_2, a_3 + b_3)
```

