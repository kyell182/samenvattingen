# cheatsheet os-commands

<!-- Handelt paden, bestanden, mappen, omgevingsvariabelen en procesinfo -->
> Handelt paden, bestanden, mappen, omgevingsvariabelen en procesinfo

```python
import os
```

## Pad en bestandsinfo

```python
os.getcwd()                        # Huidige werkmap
os.chdir("pad/naar/map")           # Verander werkmap
os.listdir("pad")                  # Lijst van bestanden/mappen
os.path.exists("bestand.txt")      # True als bestand/map bestaat
os.path.isfile("bestand.txt")      # True als het een bestand is
os.path.isdir("mapnaam")           # True als het een map is
os.path.getsize("bestand.txt")     # Grootte in bytes
os.path.abspath("bestand.txt")     # Absoluut pad teruggeven
os.path.basename("/pad/naam.txt")  # Bestandsnaam zonder pad
os.path.dirname("/pad/naam.txt")   # Enkel de mapnaam
os.path.join("map", "bestand.txt") # Combineer paden correct
```

## Bestanden en mappen

```python
os.mkdir("nieuwe_map")             # Maak nieuwe map
os.makedirs("a/b/c")               # Maak submappen recursief
os.rmdir("mapnaam")                # Verwijder lege map
os.removedirs("a/b/c")             # Verwijder lege mappen recursief
os.remove("bestand.txt")           # Verwijder bestand
os.rename("oud.txt", "nieuw.txt")  # Hernoem bestand of map
```

## Omgevingsvariabelen

```python
os.environ["USER"]                 # Lees omgevingsvariabele
os.environ["NEUWE_VAR"] = "123"    # Stel variabele in
os.getenv("PATH")                  # Veilig ophalen (kan None geven)
```

## Procesinformatie

```python
os.name                            # OS-type ('posix', 'nt', ...)
os.getpid()                        # Huidige proces-ID
os.getlogin()                      # Ingelogde gebruiker
os.system("dir")                   # Voer shell-commando uit
os.startfile("bestand.txt")        # Open bestand met standaardapp (Windows)
```

## Paden (submodule)

```python
from os import path
path.exists("bestand.txt")         # Controleer of pad bestaat
path.join("map", "bestand.txt")    # Combineer paden
```
