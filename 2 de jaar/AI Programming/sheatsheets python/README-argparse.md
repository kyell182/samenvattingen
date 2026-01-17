# cheatsheet argparse-commands

<!-- Maakt het makkelijk om command-line argumenten te definiëren en parsen -->
> Maakt het makkelijk om command-line argumenten te definiëren en parsen

```python
import argparse  # parser bouwen voor CLI opties
```

## Parser aanmaken

```python
parser = argparse.ArgumentParser(description="Beschrijving van je script")  # maak parser met help-tekst
```

## Argumenten toevoegen

```python
parser.add_argument("input", help="Input bestand")                                   # verplicht positioneel argument
parser.add_argument("-o", "--output", help="Output bestand", default="out.txt")      # optionele output-bestandsnaam
parser.add_argument("-v", "--verbose", action="store_true", help="Toon extra info")  # boolean vlag voor verbose
parser.add_argument("-n", type=int, default=1, help="Aantal herhalingen")            # integer optie met standaardwaarde
```

## Argumenten parsen

```python
args = parser.parse_args()        # Haal arguments van command line
args.input                        # Toegang tot positional argument
args.output                       # Toegang tot optie argument
args.verbose                      # True als -v opgegeven
args.n                            # Toegang tot integer argument
```

## Voorbeeld gebruik

```python
if args.verbose:
    print(f"Invoer: {args.input}, Uitvoer: {args.output}, Aantal: {args.n}")  # toon samenvatting bij verbose
```
