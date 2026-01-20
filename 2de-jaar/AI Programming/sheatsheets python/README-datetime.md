# cheatsheet datetime-commands

<!-- Handelt datetime, date, time en timedelta: maken, formatteren, parseren en berekeningen -->
> Handelt datetime, date, time en timedelta: maken, formatteren, parseren en berekeningen

```python
from datetime import datetime, date, time, timedelta  # Datum/tijd helpers uit stdlib
```

## Huidige datum/tijd

```python
datetime.now()                    # Huidige lokale datum + tijd
datetime.utcnow()                 # Huidige UTC-tijd
date.today()                      # Huidige datum (YYYY-MM-DD)
```

## Datum/tijd aanmaken

```python
datetime(2025, 10, 8, 14, 30)     # Jaar, maand, dag, uur, minuut
date(2025, 10, 8)                 # Alleen datum
time(14, 30, 0)                   # Alleen tijd
```

## Componenten uitlezen

```python
dt = datetime.now()
dt.year                            # Jaar
dt.month                           # Maand
dt.day                             # Dag
dt.hour                            # Uur
dt.minute                          # Minuut
dt.second                          # Seconde
dt.weekday()                       # 0 = maandag, 6 = zondag
```

## Datum/tijd berekeningen

```python
delta = timedelta(days=7)          # 7 dagen
dt + delta                         # Een week later
dt - delta                         # Een week eerder
(d2 - d1).days                     # Verschil in dagen
```

## Formatteren (naar tekst)

```python
dt.strftime("%Y-%m-%d %H:%M:%S")   # "2025-10-08 14:30:00"
date.today().isoformat()           # "2025-10-08"
```

## Parseren (van tekst)

```python
datetime.strptime("2025-10-08", "%Y-%m-%d")  # String → datetime
```

## Epoch / timestamps

```python
datetime.fromtimestamp(1700000000)  # Epoch → datetime
datetime.now().timestamp()          # datetime → epoch (float)
```

## Tijdsduur voorbeeld

```python
start = datetime.now()
```

## ... code uitvoeren

```python
end = datetime.now()
duur = end - start                  # timedelta object
duur.total_seconds()                # Duur in seconden
```
