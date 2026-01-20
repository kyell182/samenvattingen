document.addEventListener("DOMContentLoaded", () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    let obj = [
        // Array van objecten met gegevens van verschillende steden
        {
            city: "Brugge",
            population: 118325,
            area: "138.4 km²"
        },
        {
            city: "Gent",
            population: 262219,
            area: "156.18 km²"
        },
        {
            city: "Antwerpen",
            population: 525935,
            area: "204.51 km²"
        },
        {
            city: "Leuven",
            population: 101394,
            area: "56.63 km²"
        },
        {
            city: "Mechelen",
            population: 86715,
            area: "33.71 km²"
        }
    ];

    function toggleInfo() {
        // Functie om de informatie in het div-element te tonen of te verbergen
        let div = document.querySelector('div');
        // Selecteer het eerste <div> element in het document
        if (div.innerHTML === "") {
            // Als het div-element leeg is, voeg de informatie toe
            obj.forEach(city => {
                // Loop door elk object in de array
                div.innerHTML += `
                    <p>City: ${city.city}</p>
                    <p>Population: ${city.population}</p>
                    <p>Area: ${city.area}</p>
                    <hr>
                `;
                // Voeg de informatie van de stad toe aan het div-element
            });
            // Log het object naar de console
            console.log(obj);
        } else {
            // Als het div-element niet leeg is, maak het leeg
            div.innerHTML = "";
        }
    }

    let button = document.querySelector('button');
    // Selecteer de knop

    button.addEventListener('click', toggleInfo);
    // Voeg een click event listener toe aan de knop die de toggleInfo functie oproept
});