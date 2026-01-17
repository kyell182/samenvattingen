# cheatsheet numpy-commands

<!-- Numerieke arrays en lineaire algebra; efficiënte vector-/matrixbewerkingen (NumPy) -->
> Numerieke arrays en lineaire algebra; efficiënte vector-/matrixbewerkingen (NumPy)

```python
import numpy as np  # Snel werken met arrays, vector/matrixoperaties en numerieke functies
```

## Array aanmaken

```python
a = np.array([1, 2, 3])                 # 1D array
b = np.array([[1, 2], [3, 4]])          # 2D array
np.zeros((3,3))                         # 3x3 nullen
np.ones((2,2))                          # 2x2 enen
np.eye(3)                               # Identiteitsmatrix 3x3
np.arange(0, 10, 2)                     # 0,2,4,6,8
np.linspace(0, 1, 5)                    # 5 gelijk verdeelde punten 0→1
np.random.rand(3,3)                     # Willekeurige floats [0,1)
np.random.randn(3,3)                    # Normale verdeling N(0,1)
np.random.randint(0, 10, (2,3))         # Willekeurige ints 0-9
```

## Array info

```python
a.shape                                 # Vorm
a.dtype                                 # Datatype
a.size                                  # Aantal elementen
a.ndim                                  # Aantal dimensies
```

## Basisbewerkingen

```python
np.add(a, b)                             # Optellen
np.subtract(a, b)                        # Aftrekken
np.multiply(a, b)                        # Elementgewijs vermenigvuldigen
np.divide(a, b)                          # Elementgewijs delen
np.power(a, 2)                           # Elementgewijs kwadraat
np.sqrt(a)                               # Vierkantswortel
np.sum(a)                                # Som
np.mean(a)                               # Gemiddelde
np.max(a), np.min(a)                     # Max/min
```

## Matrixbewerkingen

```python
a @ b                                    # Matrixvermenigvuldiging
np.matmul(a, b)                          # Zelfde als @
a.T                                      # Transponeren
np.linalg.inv(a)                         # Inverse
np.linalg.det(a)                         # Determinant
```

## Indexering & slicing

```python
a[0]                                     # Eerste rij/element
a[:,1]                                   # Tweede kolom
a[1,2]                                   # Specifiek element
a[1:3, :]                                # Rijen 1-2
```

## Reshaping & concatenatie

```python
a.reshape(1, -1)                          # Vorm wijzigen
np.concatenate([a, b], axis=0)            # Samenvoegen over rijen
np.vstack([a, b])                         # Vertical stack
np.hstack([a, b])                         # Horizontal stack
```

## Random & shuffle

```python
np.random.shuffle(a)                       # In-place schudden
np.random.seed(42)                         # Zaad voor reproduceerbaarheid
```
