document.addEventListener('DOMContentLoaded', () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    const form = document.getElementById('textForm');
    // Selecteer het formulier

    form.addEventListener('submit', (event) => {
        event.preventDefault();
        // Voorkom dat het formulier wordt verzonden

        const textarea = document.getElementById('textarea');
        const text = textarea.value;
        // Haal de tekst uit de textarea

        const charCount = text.length;
        // Tel het aantal karakters

        const wordCount = text.trim().split(/\s+/).length;
        // Tel het aantal woorden door de tekst eerst te trimmen (om voor- en achteraan whitespace te verwijderen),
        // vervolgens de tekst te splitsen op één of meer whitespace karakters (spaties, tabs, nieuwe regels),
        // en ten slotte de lengte van de resulterende array te nemen, wat het aantal woorden vertegenwoordigt.

        const upperText = text.toUpperCase();
        // Zet de tekst om in hoofdletters

        const outputDiv = document.getElementById('output');
        // Selecteer het div-element om de output te tonen

        // Maak een nieuw <p> element voor de tekst in hoofdletters
        const upperTextElement = document.createElement('p');
        upperTextElement.textContent = upperText;

        // Maak een nieuw <p> element voor het aantal karakters
        const charCountElement = document.createElement('p');
        charCountElement.textContent = `Aantal karakters: ${charCount}`;

        // Maak een nieuw <p> element voor het aantal woorden
        const wordCountElement = document.createElement('p');
        wordCountElement.textContent = `Aantal woorden: ${wordCount}`;

        // Verwijder alle bestaande childs van het outputDiv
        while (outputDiv.firstChild) {
            outputDiv.removeChild(outputDiv.firstChild);
        }

        // Voeg de nieuwe elementen toe aan het outputDiv
        outputDiv.appendChild(upperTextElement);
        outputDiv.appendChild(charCountElement);
        outputDiv.appendChild(wordCountElement);
    });
});