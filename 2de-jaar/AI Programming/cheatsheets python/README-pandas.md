# cheatsheet pandas-commands

<!-- Data-analyse en manipulatie met DataFrame/Series; lezen/schrijven, transformeren en aggregeren -->
> Data-analyse en manipulatie met DataFrame/Series; lezen/schrijven, transformeren en aggregeren

```python
import pandas as pd
```

## DataFrame / Series aanmaken

```python
df = pd.DataFrame({'Naam': ['Kyell','Anna'], 'Leeftijd':[19, 20]})
s = pd.Series([10, 20, 30], index=['a','b','c'])
```

## Data inlezen / opslaan

```python
pd.read_csv("bestand.csv")                 # CSV → DataFrame
pd.read_excel("bestand.xlsx")              # Excel → DataFrame
df.to_csv("bestand.csv", index=False)      # DataFrame → CSV
df.to_excel("bestand.xlsx", index=False)   # DataFrame → Excel
```

## Data inspecteren

```python
df.head(5)                                 # Eerste 5 rijen
df.tail(5)                                 # Laatste 5 rijen
df.shape                                   # (rows, columns)
df.columns                                 # Kolomnamen
df.info()                                  # Info over types en nulls
df.describe()                              # Statistieken van numerieke kolommen
```

## Selectie & indexering

```python
df['Naam']                                 # Kolom als Series
df[['Naam','Leeftijd']]                    # Meerdere kolommen
df.iloc[0]                                 # Eerste rij
df.iloc[0,1]                               # Specifiek element
df.loc[0, 'Naam']                          # Rij 0, kolom 'Naam'
df[df['Leeftijd'] > 19]                    # Filter rijen
```

## Bewerken / transformeren

```python
df['Leeftijd'] + 1                         # Elementgewijze bewerking
df['NieuweKolom'] = df['Leeftijd']*2       # Nieuwe kolom toevoegen
df.drop('NieuweKolom', axis=1)             # Kolom verwijderen
df.rename(columns={'Naam':'Voornaam'})     # Kolomnaam hernoemen
df.sort_values('Leeftijd')                 # Sorteren op kolom
```

## Missing values

```python
df.isnull()                                # True als NaN
df.dropna()                                # Verwijder rijen met NaN
df.fillna(0)                               # Vul NaN met waarde
```

## Groeperen / aggregeren

```python
df.groupby('Leeftijd').mean()              # Gemiddelde per groep
df.groupby('Leeftijd')['Naam'].count()     # Aantal per groep
```
