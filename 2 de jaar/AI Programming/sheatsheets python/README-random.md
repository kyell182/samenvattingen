# cheatsheet random-commands

> Genereert pseudowillekeurige getallen, sampling en shuffling (niet cryptografisch veilig)

```python
import random
```

## Willekeurige getallen

```python
random.random()              # Float tussen 0.0 en 1.0
random.uniform(a, b)         # Float tussen a en b
random.randint(a, b)         # Geheel getal tussen a en b (inclusief)
random.randrange(start, stop, step)  # Getal in bereik met stapgrootte
random.getrandbits(k)        # Willekeurig geheel getal met k bits
```

## Willekeurige keuzes

```python
random.choice(seq)           # Eén willekeurig element uit lijst/tuple
random.choices(seq, k=3)     # Lijst met k willekeurige elementen (met herhaling)
random.sample(seq, k=3)      # Lijst met k unieke elementen (zonder herhaling)
random.shuffle(seq)          # Schudt lijst in-place
random.seed(x)               # Stel zaad in voor reproduceerbare resultaten
```

## Willekeurige verdelingen

```python
random.gauss(mu, sigma)      # Normale verdeling (gemiddelde, std)
random.normalvariate(mu, sigma)  # Zelfde als gauss
random.expovariate(lambd)    # Exponentiële verdeling
random.betavariate(a, b)     # Beta-verdeling
random.gammavariate(a, b)    # Gamma-verdeling
random.triangular(low, high, mode)  # Driehoekverdeling
```

## Systemrandom (veiliger, cryptografisch)

```python
secure = random.SystemRandom()  # Gebruik OS random bron
secure.random()                 # Veiliger versie van random()
secure.choice(seq)              # Veiliger willekeurige keuze
```
