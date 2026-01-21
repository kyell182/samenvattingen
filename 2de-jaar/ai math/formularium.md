# AI Maths – Formularium VIVES

## Hoofdstuk 0 — MATLAB Basis

### Variabelen

```matlab
a = 5  
ans = laatste resultaat  

Speciale constanten:
pi = π  
exp(1) = e  
i² = -1  
Inf = ∞ 

```

---

### Rekenregels in MATLAB

| Wiskunde | MATLAB |
|---------|---------|
| a + b | a + b |
| a - b | a - b |
| a · b | a * b |
| a / b | a / b |
| a^b | a^b |
| √x | sqrt(x) |
| ln(x) | log(x) |
| log10(x) | log10(x) |
| \| x \| | abs(x) |

---

### Arrays (Matrices)

Algemene vorm:

```matlab
A = [a11 a12; a21 a22]
```

Element:

```matlab
A(i,j)
```

Rij:

```matlab
A(i,:)
```

Kolom:

```matlab
A(:,j)
```

Speciale matrices:

```matlab
zeros(n,m)  % n x m nullen
ones(n,m)   % n x m enen
eye(n)      % n x n eenheidsmatrix
rand(n,m)   % n x m willekeurige getallen [0,1]
randn(n,m)  % n x m normaalverdeelde willekeurige getallen
```

---

### Rijen / Vectoren

```matlab
x = a : h : b  % (start : stap : einde)
```

---

### Arraybewerkingen (element per element)

```matlab
A .* B  % elementgewijze vermenigvuldiging
A .^ B  % elementgewijze macht
A ./ B  % elementgewijze deling
A .^ B  % elementgewijze macht
```

---

### Nuttige functies

```matlab
size(A)    % afmetingen van A
length(A)  % lengte van vector A
sum(A)     % som van elementen
prod(A)    % product van elementen
mean(A)    % gemiddelde
max(A)     % maximum

A' = getransponeerde  % transponeren
inv(A) = inverse van A  % matrixinverse
```

---

### Vergelijkingen oplossen

Symbolisch:

```matlab
solve(f(x) = 0) % nulwaarde zoeken
```

Numeriek:

```matlab
fzero(f, startwaarde) % nulwaarde zoeken
```

Lineair stelsel:

```matlab
A x = b     
x = A \ b 
```

---

### Afleiden en integreren

Afgeleide:

```matlab
diff(f(x), x)
```

Tweede afgeleide:

```matlab
diff(f(x), x, 2)
```

Onbepaalde integraal:

```matlab
int(f(x), x)
```

Bepaalde integraal:

```matlab
int(f(x), x, a, b)
```

---

## Hoofdstuk 1 — Vectoren

Vector:

```math
\vec{v} = (v_1, v_2, v_3)
```

Norm:

```math
||\vec{v}|| = \sqrt{v_1^2 + v_2^2 + v_3^2}
```

Eenheidsvector:

```math
\vec{v} = \frac{\vec{v}}{||\vec{v}||}
```

---

### Optelling

```math
\vec{u} + \vec{v} = (u_1+v_1, u_2+v_2, u_3+v_3)
```

---

### Scalair product

```math
\vec{u} \cdot \vec{v} = u_1v_1 + u_2v_2 + u_3v_3
```

```math
\vec{u} \cdot \vec{v} = ||\vec{u}|| ||\vec{v}|| \cos(\theta) 
```

Hoek:

```math
\cos(\theta) = \frac{\vec{u} \cdot \vec{v}}{||\vec{u}|| \, ||\vec{v}||}
```

```math
\cos(\theta) = \frac{\vec{u} \cdot \vec{v}}{\sqrt{\vec{u} \cdot \vec{u}} \, \sqrt{\vec{v} \cdot \vec{v}}}
```

---

### Vectorieel product

```math
\vec{u} \times \vec{v} = \text{determinant}
```

```matlab
| i   j  k |  
| u1 u2 u3 |  
| v1 v2 v3 |
```

Norm:

```math
||\vec{u} \times \vec{v}|| = ||\vec{u}|| ||\vec{v}|| \sin(\theta)
```

---

## Hoofdstuk 2 — Matrices

matrix optelling:

```math
A + B = C \text{ met } c_{ij} = a_{ij} + b_{ij}
```

matrix Aftrekking:

```math
A - B = C \text{ met } c_{ij} = a_{ij} - b_{ij}
```

⚠️ matrixen moeten dezelfde dimensies hebben!

matrix Scalair vermenigvuldiging:

```math
k A = B \text{ met } b_{ij} = k a_{ij}
```

Matrixproduct:

```math
(m×n)(n×p) = (m×p)
```

Getransponeerde:

```math
A^T \text{ of } A' \text{ (rijen en kolommen wisselen)}
```

---

## Hoofdstuk 3 — Determinanten

2×2:

```text
A = | a  b |  
    | c  d |
```

```math
det(A) = ad - bc
```

3×3:

```text
A = | a  b  c |  
    | d  e  f |  
    | g  h  i |
```

```math
det =
aei + bfg + cdh - ceg - bdi - afh
```

Inverse bestaat als:

```math
det(A) ≠ 0
```

Inverse:

```math
A^{-1} = \frac{1}{det(A)} \cdot adj(A)
```

adjunct:

```math
adj(A) = \text{getransponeerde van de matrix van de cofactoren}
```

---

## Hoofdstuk 5 — Eigenwaarden en SVD

Eigenwaardeprobleem:

```math
A v = λ v
```

Karakteristieke vergelijking:

```math
\det(A - \lambda I) = 0
```

Diagonaliseerbaar:

```math
A = P D P^{-1}
```

Macht:

```math
Aⁿ = P Dⁿ P^{-1}
```

SVD:

```math
A = U Σ V^{T}
```

---

## Hoofdstuk 6 — Functies van twee veranderlijken

Partiële afgeleiden:

```math
\frac{\partial f}{\partial x} 
\quad \text{en} \quad
\frac{\partial f}{\partial y}  
```

Gradiënt:

```math
\nabla f = \left( \frac{\partial f}{\partial x}, \frac{\partial f}{\partial y} \right)
```

---

## Hoofdstuk 7 — Normale verdeling

Dichtheidsfunctie:

```math
f(x) = \frac{1}{\sigma \sqrt{2\pi}} e^{-\frac{(x - \mu)^2}{2\sigma^2}}
```

μ = gemiddelde  
σ = standaardafwijking  

Standaardiseren:

```math
z = \frac{x - \mu}{\sigma}
```