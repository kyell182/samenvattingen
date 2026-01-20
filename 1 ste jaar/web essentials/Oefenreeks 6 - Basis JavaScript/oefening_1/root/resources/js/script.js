document.addEventListener('DOMContentLoaded', () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    let array = Array.from({ length: 10 }, (_, i) => `Element ${i}`);
    // Maak een array van 10 elementen, waarbij elk element een string is met de tekst "Element" gevolgd door het indexnummer

    console.log(array);
    // Log de array naar de console

    console.log(array.length);
    // Log de lengte van de array naar de console

    let div = document.querySelector('div');
    // Selecteer het eerste <div> element in het document

    array.forEach(element => {
        // Loop door elk element in de array

        let p = document.createElement('p');
        // Maak een nieuw <p> element

        p.textContent = element;
        // Stel de tekstinhoud van het <p> element in op de huidige arraywaarde

        div.appendChild(p);
        // Voeg het <p> element toe als kind van het geselecteerde <div> element
    });
});