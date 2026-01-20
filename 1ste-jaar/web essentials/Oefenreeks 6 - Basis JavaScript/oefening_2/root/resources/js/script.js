document.addEventListener("DOMContentLoaded", () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    let obj = {name: "Kyell DE Windt", birthdate: "02/03/1992", address: "Gistelse Steenweg 566", tel: "0472504101"};
    // Object met de gegevens van de persoon

    function calculateAge(birthdate) {
        // Functie om de leeftijd te berekenen op basis van de geboortedatum
        let today = new Date();
        // Huidige datum
        let birthDate = new Date(birthdate);
        // Geboortedatum omzetten naar een Date object
        let age = today.getFullYear() - birthDate.getFullYear();
        // Leeftijd berekenen op basis van het verschil in jaren
        let m = today.getMonth() - birthDate.getMonth();
        // Verschil in maanden berekenen
        if (m < 0 || (m === 0 && today.getDate() < birthDate.getDate())) {
            age--;
            // Als de huidige maand en dag voor de geboortedatum liggen, leeftijd met 1 verlagen
        }
        return age;
        // Geretourneerde leeftijd
    }

    function toggleInfo() {
        // Functie om de informatie in het div-element te tonen of te verbergen
        let div = document.querySelector('div');
        // Selecteer het eerste <div> element in het document
        if (div.innerHTML === "") {
            // Als het div-element leeg is, voeg de informatie toe
            div.innerHTML = `
                <p>Name: ${obj.name}</p>
                <p>Age: ${calculateAge(obj.birthdate)}</p>
                <p>Address: ${obj.address}</p>
                <p>Tel: ${obj.tel}</p>
            `;
            // Log het object en de berekende leeftijd naar de console
            console.log(obj);
            console.log(`Age: ${calculateAge(obj.birthdate)}`);
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