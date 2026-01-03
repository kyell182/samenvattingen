# AI MATH

dit is een samenvatting van de belangrijkste wiskundige concepten die relevant zijn voor kunstmatige intelligentie (AI). Deze samenvatting behandelt onderwerpen zoals lineaire algebra, calculus, statistiek en waarschijnlijkheid, die allemaal essentieel zijn voor het begrijpen en ontwikkelen van AI-algoritmen.

## 1. Vectoren

<details>
<summary><strong>1.1. Wat is een vector</strong></summary>

![vector](./assets/vectoren/dit%20is%20een%20vector.png)

Een vector stelt een verplaatsing voor tussen 2 punten in in de ruimte.
voorgesteld als een pijl tussen 2 punten.

Grafisch :

```math
\vec{v} = \vec{PQ}​ \\
\text{} \\
\text{ met } P( x_1, y_1 ) \\
\text{ en } Q( x_2, y_2 )
```

Een vector word volledig bepaald door :

- Groote (lengte van de pijl)
- Richting (de richting waarin de pijl wijst)
- Zin (welke kant de pijl wijst)

meestal worden vrije vectoren gebruikt.

- deze mogen verplaatst worden zonder dat hun eigenschappen veranderen.

</details>

details>
<summary><strong>1.2. speciale vectoren</strong></summary>

- **Plaatsvector**
  - een vector die de positie van een punt in de ruimte aangeeft ten opzichte van de oorsprong.

    ```math
    \vec{a} = \vec{OA}​
    ```

    ![plaatsvector grafisch](./assets/vectoren/vecor%20in%20oorsprong%20grafisch.png)

- **Nulvector**
  - een vector met een lengte van 0, die geen richting heeft.
  - met een absolute waarde van 0.

    ```math
    \vec{0} = (0, 0) \text{ in 2D}
    ```

    ![nulvector grafisch](./assets/vectoren/nul%20vector%20grafisch.png)

- **Eenheidsvector**
  - een vector met een lengte van 1, die vaak wordt gebruikt om een richting aan te geven.
  - met een absolute waarde van 1.
  - meestal worden deze met een `e` of een hoedje (^) boven de letter aangeduid.

    ![eenheidsvector](./assets/vectoren/eenheids%20vectoren.png)

**norm (lengte) :**

```math
\text{ deze word aangeduide met} ||\vec{v}||​
```

</details>

---

### 1.2. vectoren in het vlak (2D)

**voorsteling van een vector in het vlak (2D)** :

de vectoren van e1 en e2 worden de basisvectoren genoemd.
deze worden gebruikt als referentie om andere vectoren in het vlak te beschrijven.

voor basisvectoren geldt :

```math
e_1 ​= (1,0)
```

```math
e_2 ​= (0,1)
```

```math
||\vec{e_1}|| = 1
```

```math
||\vec{e_2}|| = 1
```

```math
||\vec{0}|| = 0​
```

```math
\vec{e_1}​⊥\vec{e_2}​
```

- e1 en e2 staan loodrecht op elkaar (orthogonaal = 90°).

    ![vector in 2D](./assets/vectoren/vectoren%20in%20het%20vlak.png)

de coordinaten van de vectoren zijn (x, y) waarbij x de horizontale component is en y de verticale component.

voor nulvector geldt :

```math
\vec{0} = (0, 0)
```

**lengte van een vector in 2D :**

```math
||\vec{v}|| = \sqrt{x^2 + y^2}
```

### 1.3. vectoren in de ruimte (3D)

**voorsteling van een vector in de ruimte (3D)** :

![vector in 3D](./assets/vectoren/3d%20vectoren.png)

```math
\vec{v} = (x, y, z)
```

**de basisvectoren in 3D zijn**

```math
e_1​=(1,0,0) \\
e_2​=(0,1,0) \\
e_3​=(0,0,1)
```

```math
\vec{0} = (0, 0, 0)
```

```math
\vec{e_1} ​⊥ \vec{e_2} ​⊥ \vec{e_3}​
```

**algebraische voorstelling van een vector in 3D :**

```math
\vec{a}+\vec{b} = (a_1 + b_1, a_2 + b_2, a_3 + b_3)
```
**lengte van een vector in 3D :**

```math
||\vec{v}|| = \sqrt{x^2 + y^2 + z^2}
```

### 1.4. bewerkingen met vectoren

#### 1.4.1. optelling van vectoren :

de som van 2 vectoren geeft een nieuwe vector die de gecombineerde verplaatsing van de 2 oorspronkelijke vectoren voorstelt.

in 2D geldt :

```math
\vec{a} + \vec{b} = (a_1 + b_1, a_2 + b_2)
```

in 3D geldt :

```math
\vec{a} + \vec{b} = (a_1 + b_1, a_2 + b_2, a_3 + b_3)
```

**eigenshappen :**
  
- Chasles-Möbius:
  
  ```math
  \vec{PQ} + \vec{QR} = \vec{PR}​
  ```
- de nulvector is het neutraal element voor de optelling van vectoren:
  
  ```math
  \vec{v} + \vec{0} = \vec{v}​
  ```

- elke vector heeft een tegengestelde vector:
  
  ```math
  \vec{v} = -\vec{v}​
  ```

  - bovendien geldt dat :
    
    ```math
    \vec{PQ} = -\vec{QP}
    ```

- het verschil van 2 vectoren word gedefinieerd als :
  
  ```math
  \vec{a} - \vec{b} = \vec{a} + (-\vec{b}) = \vec{c}​
  ```

- associatief :
  
  ```math
  (\vec{a} + \vec{b}) + \vec{c} = \vec{a} + (\vec{b} + \vec{c})​
  ```

- commutatief :
  
  ```math
  \vec{a} + \vec{b} = \vec{b} + \vec{a}​
  ```

#### 1.4.2. scalaire x vector

```math
k\vec{v} = (kv_1,kv_2) \text{ in 2D}
```

```math
k\vec{v} = (k\vec{v_1},k\vec{v_2},k\vec{v_3}) \text{ in 3D}
```


