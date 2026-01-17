# cheatsheet matplotlib.pyplot

<!-- Plotten van 2D-grafieken: lijnen, scatter, bar, histogrammen, subplots en styling -->
> Plotten van 2D-grafieken: lijnen, scatter, bar, histogrammen, subplots en styling

```python
import matplotlib.pyplot as plt  # 2D plotting API (lijnen, scatter, bar, histogrammen)
```

## Data

```python
x = np.linspace(0, 10, 100)
y = np.sin(x)
```

## Basis plot

```python
plt.plot(x, y)                  # Lijnplot
plt.show()                      # Toon plot
```

## Labels & titel

```python
plt.xlabel("X-as")              # X-as label
plt.ylabel("Y-as")              # Y-as label
plt.title("Voorbeeld Plot")     # Titel
```

## Meerdere lijnen

```python
y2 = np.cos(x)
plt.plot(x, y, label="sin(x)")
plt.plot(x, y2, label="cos(x)")
plt.legend()                     # Toon legenda
```

## Stijlen en kleuren

```python
plt.plot(x, y, color='red', linestyle='--', marker='o')
```

## Scatter plot

```python
plt.scatter(x, y)                # Punten plot
```

## Bar chart

```python
plt.bar([1,2,3], [10,20,15])     # Staafdiagram
```

## Histogram

```python
plt.hist(np.random.randn(1000), bins=30)   # Histogram
```

## Subplots

```python
plt.subplot(2,1,1)               # Rij 2, kolom 1, eerste plot
plt.plot(x, y)
plt.subplot(2,1,2)               # Tweede plot
plt.plot(x, y2)
```

## Opslaan

```python
plt.savefig("plot.png")          # Opslaan als bestand
```
