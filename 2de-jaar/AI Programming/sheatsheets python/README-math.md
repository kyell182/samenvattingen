# cheatsheet math-commands

<!-- Berekent wiskundige functies en constanten (sqrt, trig, log, combinatoriek) -->
> Berekent wiskundige functies en constanten (sqrt, trig, log, combinatoriek)

```python
import math
```

## Constanten

```python
math.pi              # π ≈ 3.14159
math.e               # e ≈ 2.71828
math.tau             # τ = 2π
math.inf             # Oneindig
math.nan             # Niet-nummer (NaN)
```

## Basisbewerkingen

```python
math.ceil(x)         # Afronden naar boven
math.floor(x)        # Afronden naar beneden
math.trunc(x)        # Wegsnijden decimale delen
math.fabs(x)         # Absolute waarde
math.factorial(x)    # n! (faculteit)
math.gcd(a, b)       # Grootste gemene deler
```

## Wiskundige functies

```python
math.sqrt(x)         # √x
math.pow(x, y)       # x^y
math.exp(x)          # e^x
math.log(x)          # ln(x)
math.log10(x)        # log₁₀(x)
math.log2(x)         # log₂(x)
```

## Trigonometrie

```python
math.sin(x)          # Sinus (x in radialen)
math.cos(x)          # Cosinus
math.tan(x)          # Tangens
math.asin(x)         # Arcsin
math.acos(x)         # Arccos
math.atan(x)         # Arctan
math.atan2(y, x)     # Arctan(y/x) met juiste kwadrant
```

## Hoekconversies

```python
math.degrees(x)      # Rad → graden
math.radians(x)      # Graden → rad
```

## Hyperbolische functies

```python
math.sinh(x)         # Sinus hyperbolicus
math.cosh(x)         # Cosinus hyperbolicus
math.tanh(x)         # Tangens hyperbolicus
```

## Overig

```python
math.isfinite(x)     # True als niet inf of NaN
math.isinf(x)        # True als oneindig
math.isnan(x)        # True als NaN
math.comb(n, k)      # Combinaties nCk
math.perm(n, k)      # Permutaties nPk
math.copysign(x, y)  # x met teken van y
```
