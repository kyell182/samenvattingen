# Praktische zaken Web Essentials

Alle oefenreeksen zijn te vinden in een `README.md` die de oefeningen beschrijft.

## Wijzigingen committen

Wijzigingen kunnen worden gecommit en terug gepusht naar GitHub met behulp van de terminal.

Navigeer naar je lokale `oefenreeksen-<gebruikersnaam>` map en open een PowerShell-venster door <kbd>Shift</kbd> ingedrukt te houden en met de rechtermuisknop op de map te klikken. Kies vervolgens `Open PowerShell window here` uit het contextmenu.

1. Voeg alle gewijzigde bestanden toe met het commando: `git add .`
2. Commit de bestanden en voeg een bericht toe: `git commit -m "Mijn bericht komt hier"`
3. Push je wijzigingen naar GitHub: `git push origin main`
4. Om zeker te weten dat alles goed is gegaan, kun je altijd het commando `git status` uitvoeren, zelfs tussen andere commando's door.

Je kunt ook naar je GitHub-pagina van deze repo navigeren en controleren of alles goed is gegaan.

Maak er een gewoonte van om regelmatig te committen en te pushen. **Ten minste na het oplossen van elke opdracht.**

## De laatste updates binnenhalen

Elke keer dat je updates wilt binnenhalen, moet je de volgende stappen volgen:

1. Zorg er eerst voor dat je geen lokale wijzigingen hebt. Dit kun je zien door het commando `git status` uit te voeren. Er zou moeten staan "nothing to commit, working tree clean". Zo niet, dan moet je eerst de wijzigingen toevoegen en committen (zie sectie [Wijzigingen committen](#committing-changes)).
2. Voer nu het commando `git pull base main --allow-unrelated-histories` uit om de nieuwste wijzigingen binnen te halen.