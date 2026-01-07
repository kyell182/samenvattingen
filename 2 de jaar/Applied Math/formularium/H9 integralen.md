#  H9 Formularium Integralen

---

## Primitieve functie / Onbepaalde integraal

Definitie:  
Als \( F'(x) = f(x) \) voor alle \( x \in ]a, b[ \), dan is \( f \) **primitiveerbaar** en \( F \) een **primitieve functie** van \( f \).  

- Primitieve is niet uniek: \( F + c \), met \( c \in \mathbb{R} \), is ook een primitieve van \( f \).  
- Notatie onbepaalde integraal:  

$$
\int f(x) \, dx = F(x) + c
$$

---

## Basisprimitieven / Standaardintegralen

| $f(x)$ | $\int f(x) \, dx$ | $f(x)$ | $\int f(x) \, dx$ |
|------|-----------|------|----------|
| $0$ | $c$ | $\cos x$ | $\sin x$ |
| $x^n, n\neq-1$ | $\dfrac{x^{n+1}}{n+1}$ | $\dfrac{1}{\cos^2 x}$ | $\tan x$ |
| $\dfrac{1}{x}$ | $\ln\|x\|$ | $\dfrac{1}{\sin^2 x}$ | $-\cot x$ |
| $e^x$ | $e^x$ | $\dfrac{1}{\sqrt{1-x^2}}$ | $\arcsin x$ |
| $a^x$ | $\dfrac{a^x}{\ln a}$ | $\dfrac{1}{1+x^2}$ | $\arctan x$ |
| $\sin x$ | $-\cos x$ | | |

💡 Opmerking: bij onbepaalde integralen kan altijd een constante c worden toegevoegd.


---

## Rekenregels onbepaalde integraal

| Regel | Formule |
|------|---------|
| Constante factor | $\int c f(x) \, dx = c \int f(x) \, dx$ |
| Som / verschil | $\int (f(x) \pm g(x)) \, dx = \int f(x) \, dx \pm \int g(x) \, dx$ |
| Substitutie | $\int f(g(x)) g'(x) \, dx = \int f(u) \, du$, met $u = g(x)$ |

❗ er bestaan **geen algemene regels voor product of quotiënt** van functies.

---

## Bepaalde integraal

Definitie:  
De bepaalde integraal van f over [a, b] (Riemannintegraal):

$$
\int_a^b f(x) \, dx = \lim_{n \to \infty} \sum_{i=0}^{n-1} f(x_i) \Delta x
$$

Hoofdstelling van de integraalrekening:

$$
\int_a^b f(x) \, dx = F(b) - F(a), \quad \text{met } F' = f
$$

---

## Extra rekenregels bepaalde integralen

| Regel | Formule |
|------|---------|
| Constante factor | $\int_a^b c f(x) \, dx = c \int_a^b f(x) \, dx$ |
| Som / verschil | $\int_a^b (f(x) \pm g(x)) \, dx = \int_a^b f(x) \, dx \pm \int_a^b g(x) \, dx$ |
| Splitsen van interval | $\int_a^b f(x) \, dx = \int_a^c f(x) \, dx + \int_c^b f(x) \, dx$ |
| Substitutie | $\int_a^b f(g(x)) g'(x) \, dx = \int_{u(a)}^{u(b)} f(u) \, du$, $u = g(x)$ |

---

## Oppervlaktes

- Als f ≥ 0 op [a, b]:  
$$
\text{Oppervlakte} = \int_a^b f(x) dx
$$
- Als f ≤ 0 op [a, b]:  
$$
\text{Oppervlakte} = -\int_a^b f(x) dx
$$
- Algemeen: totale oppervlakte met mogelijk negatieve stukken:  
$$
\text{Oppervlakte} = \int_a^b |f(x)| dx
$$
- Voor meerdere grafieken: oppervlakte tussen f(x) en g(x):  
$$
\text{Oppervlakte} = \int_a^b |f(x) - g(x)| dx
$$
- Bij opsplitsen van integratiegebied voor tekenwissel:  
$$
\int_a^b |f(x)| dx = \sum_{i} \int_{x_i}^{x_{i+1}} |f(x)| dx
$$
waar op elk interval \( [x_i, x_{i+1}] \) f(x) constant positief of negatief is.
