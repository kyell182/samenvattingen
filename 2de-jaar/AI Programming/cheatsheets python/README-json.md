# cheatsheet json-commands

<!-- Behandelt JSON-serialisatie en -deserialisatie (Python <-> JSON; lezen/schrijven) -->
> Behandelt JSON-serialisatie en -deserialisatie (Python <-> JSON; lezen/schrijven)

```python
import json
```

## Python → JSON (opslaan of printen)

```python
data = {"naam": "Kyell", "leeftijd": 19}

json_string = json.dumps(data)               # Converteer naar JSON-string
json_string = json.dumps(data, indent=4)     # Mooie opmaak (inspringing)
json_string = json.dumps(data, sort_keys=True)  # Sorteer sleutels

with open("data.json", "w") as f:
    json.dump(data, f, indent=4)             # Schrijf naar bestand
```

## JSON → Python (inlezen)

```python
loaded = json.loads(json_string)             # JSON-string naar dict
with open("data.json") as f:
    loaded = json.load(f)                    # Lees JSON-bestand
```

## Extra opties

```python
json.dumps(data, ensure_ascii=False)         # Bewaar speciale tekens (bv. é)
json.dumps(data, separators=(",", ":"))      # Compacte JSON (geen spaties)
```
