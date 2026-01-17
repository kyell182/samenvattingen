# python queueu-library cheatsheet

> **Let op:** noem je eigen Python-bestanden niet naar standaardbibliotheekmodules (bijv. `queue.py`).
> Als je dat wel doet, zal `import queue` je lokale bestand importeren in plaats van de stdlib, wat TypeError/ImportError kan veroorzaken.
> Oplossingen: hernoem je bestand, verwijder `__pycache__` en herstart je interpreter.

```python
from queue import Queue, LifoQueue, PriorityQueue, SimpleQueue, Empty, Full
```

## Queue-types

```python
q = Queue(maxsize=0)        # FIFO-queue (eerste erin, eerste eruit)
lq = LifoQueue(maxsize=0)   # LIFO-queue (stackgedrag)
pq = PriorityQueue(maxsize=0)  # Prioriteitsqueue (laagste waarde eerst)
sq = SimpleQueue()           # Eenvoudige, onbeperkte FIFO (sneller, geen taaktracking)
```

## Basisoperaties

```python
q.put(item)                 # Voeg item toe (blokkeert als vol)
q.put_nowait(item)          # Voeg toe zonder blokkeren (raise Full)
q.get()                     # Haal item op (blokkeert als leeg)
q.get_nowait()              # Haal op zonder blokkeren (raise Empty)
```

## Statuscontroles

```python
q.qsize()                   # Aantal items (niet altijd accuraat bij multithreading)
q.empty()                   # True als leeg
q.full()                    # True als vol
```

## Taakafhandeling

```python
q.task_done()               # Markeer 1 taak als voltooid
q.join()                    # Wacht tot alle geplaatste taken afgewerkt zijn
```

## Nieuwe functie (Python 3.13+)

```python
q.shutdown(immediate=False) # Sluit de queue af, blokkeert verdere put/get
```

## Exceptions

```python
# queue.Empty  -> bij get_nowait() op lege queue

# queue.Full   -> bij put_nowait() op volle queue

# queue.ShutDown -> bij bewerking op afgesloten queue
```

# from queue import SimpleQueue, Empty

## Aanmaken

```python
q = SimpleQueue()            # Eenvoudige thread-safe FIFO-queue (geen limiet, geen taaktracking)
```

## Basisoperaties

```python
q.put(item)                  # Voeg item toe (blokkeert nooit)
q.put_nowait(item)           # Zelfde als put(), altijd succesvol
q.get()                      # Haal item op (blokkeert als leeg)
q.get_nowait()               # Haal item op zonder blokkeren (raise Empty)

```

## Statuscontroles

```python
q.qsize()                    # Aantal items in queue (ongeveer)
q.empty()                    # True als leeg, anders False
```

## Exceptions

```python
 queue.Empty  -> bij get_nowait() op lege queue
```
