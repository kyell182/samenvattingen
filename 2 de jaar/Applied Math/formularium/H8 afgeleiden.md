# H8 Formularium Afgeleiden

---

## Raaklijn in x = a

$$
y = f'(a)(x - a) + f(a)
$$

---

## Definitie afgeleide

$$
f'(a) = \lim_{x \to a} \frac{f(x) - f(a)}{x - a}
$$

---

## Hogere afgeleiden

$$
f''(x), \quad f'''(x), \quad f^{(n)}(x)
$$

---

## Interpretatie van de afgeleide

$$
f'(a) > 0 \Rightarrow f \text{ stijgt}
$$

$$
f'(a) < 0 \Rightarrow f \text{ daalt}
$$

$$
f'(a) = 0 \Rightarrow \text{horizontale raaklijn}
$$

---

# Standaardafgeleiden

| $f(x)$ | $f'(x)$ | | $f(x)$ | $f'(x)$ |
|------|-------|---|------|-------|
| $c$ | $0$ | | $\sin x$ | $\cos x$ |
| $x$ | $1$ | | $\cos x$ | $-\sin x$ |
| $x^n$ | $n x^{n-1}$ | | $\tan x$ | $\dfrac{1}{\cos^2 x}$ |
| $\sqrt{x}$ | $\dfrac{1}{2\sqrt{x}}$ | | $e^x$ | $e^x$ |
| $\dfrac{1}{x}$ | $-\dfrac{1}{x^2}$ | | $a^x$ | $a^x \ln a$ |
| $\ln x$ | $\dfrac{1}{x}$ | | $\log_a x$ | $\dfrac{1}{x \ln a}$ |

---

# Rekenregels

| Regel | Formule |
|------|---------|
| Constante factor | $(c f(x))' = c f'(x)$ |
| Som | $(f(x) + g(x))' = f'(x) + g'(x)$ |
| Verschil | $(f(x) - g(x))' = f'(x) - g'(x)$ |
| Product | $(f(x)g(x))' = f'(x)g(x) + f(x)g'(x)$ |
| Quotiënt | $\left(\dfrac{f(x)}{g(x)}\right)' = \dfrac{f'(x)g(x) - f(x)g'(x)}{g(x)^2}$ |
| Kettingregel | $(f(g(x)))' = f'(g(x)) \cdot g'(x)$ |

---

# Extrema

$$
f'(x_0) = 0
$$

- Minimum: f' verandert van negatief naar positief  
- Maximum: f' verandert van positief naar negatief  
- Randextrema: controleer waarden op de grenzen van het domein

---

# Buigpunten

$$
f''(x_0) = 0
$$

$$
f'' \text{ verandert van teken}
$$

---

# Buigraaklijn

$$
y = f'(x_0)(x - x_0) + f(x_0)
$$

---

# Zoekschema

| Gezocht | Methode |
|--------|---------|
| Stationair punt | $f'(x) = 0$ |
| Extrema | tekenonderzoek $f'$ |
| Buigpunten | $f''(x) = 0 + tekenverandering$ |
| Raaklijn | $y = f'(a)(x - a) + f(a)$ |
| Buigraaklijn | $y = f'(x_0)(x - x_0) + f(x_0)$ |