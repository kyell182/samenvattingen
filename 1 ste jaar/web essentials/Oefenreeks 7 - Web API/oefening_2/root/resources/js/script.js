document.addEventListener('DOMContentLoaded', () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    const apiKey = 'c65e6a33171fad0a9d1ee196ef7c0865';
    // API-sleutel voor toegang tot de OpenWeatherMap API

    const zipCode = '8200';
    // Postcode voor de locatie

    const countryCode = 'BE';
    // Landcode voor de locatie

    // URL voor locatiegegevens
    const locationUrl = `http://api.openweathermap.org/geo/1.0/zip?zip=${zipCode},${countryCode}&appid=${apiKey}`;

    async function fetchWeatherData() {
        // Asynchrone functie om weergegevens op te halen
        try {
            // Haal locatiegegevens op
            const locationResponse = await fetch(locationUrl);
            // Wacht op de respons van de locatie-API

            const locationData = await locationResponse.json();
            // Converteer de respons naar JSON

            const { lat, lon, name } = locationData;
            // Haal de breedtegraad, lengtegraad en naam van de locatie uit de locatiegegevens

            // URL voor weergegevens
            const weatherUrl = `http://api.openweathermap.org/data/2.5/forecast?lat=${lat}&lon=${lon}&appid=${apiKey}&units=metric`;

            // Haal weergegevens op
            const weatherResponse = await fetch(weatherUrl);
            // Wacht op de respons van de weer-API

            const weatherData = await weatherResponse.json();
            // Converteer de respons naar JSON

            // Toon de naam van de woonplaats
            const cityNameElement = document.getElementById('cityName');
            // Selecteer het element met de id 'cityName'

            cityNameElement.textContent = `Weather Forecast for ${name}`;
            // Stel de tekstinhoud van het element in op de naam van de locatie

            // Selecteer het tbody-element van de tabel
            const weatherTableBody = document.querySelector('#weatherTable tbody');

            // Maak de tabel leeg
            while (weatherTableBody.firstChild) {
                weatherTableBody.removeChild(weatherTableBody.firstChild);
                // Verwijder elk kindelement van het tbody-element
            }

            // Voeg nieuwe rijen toe aan de tabel
            weatherData.list.forEach(forecast => {
                // Loop door elk weerbericht in de lijst
                const row = document.createElement('tr');
                // Maak een nieuw tabelrij-element

                const dateTimeCell = document.createElement('td');
                // Maak een nieuw tabelcel-element voor datum en tijdstip
                dateTimeCell.textContent = new Date(forecast.dt * 1000).toLocaleString();
                // Stel de tekstinhoud van de cel in op de datum en tijdstip van het weerbericht *1000 is in milliseconden omzetten = tot op 1 seconde nauwkeurig zetten
                row.appendChild(dateTimeCell);
                // Voeg de cel toe aan de rij

                const tempCell = document.createElement('td');
                // Maak een nieuw tabelcel-element voor temperatuur
                tempCell.textContent = forecast.main.temp.toFixed(1);
                // Stel de tekstinhoud van de cel in op de temperatuur van het weerbericht
                row.appendChild(tempCell);
                // Voeg de cel toe aan de rij

                const humidityCell = document.createElement('td');
                // Maak een nieuw tabelcel-element voor luchtvochtigheid
                humidityCell.textContent = forecast.main.humidity;
                // Stel de tekstinhoud van de cel in op de luchtvochtigheid van het weerbericht
                row.appendChild(humidityCell);
                // Voeg de cel toe aan de rij

                const windSpeedCell = document.createElement('td');
                // Maak een nieuw tabelcel-element voor windsnelheid
                windSpeedCell.textContent = forecast.wind.speed;
                // Stel de tekstinhoud van de cel in op de windsnelheid van het weerbericht
                row.appendChild(windSpeedCell);
                // Voeg de cel toe aan de rij

                const precipitationCell = document.createElement('td');
                // Maak een nieuw tabelcel-element voor neerslag
                const precipitation = forecast.rain ? forecast.rain['3h'] : 0;
                // Controleer of er neerslaggegevens zijn en stel de waarde in
                precipitationCell.textContent = precipitation;
                // Stel de tekstinhoud van de cel in op de neerslag van het weerbericht
                row.appendChild(precipitationCell);
                // Voeg de cel toe aan de rij

                weatherTableBody.appendChild(row);
                // Voeg de rij toe aan het tbody-element van de tabel
            });
        } catch (error) {
            console.error('Error fetching weather data:', error);
            // Log een foutmelding naar de console als er een fout optreedt bij het ophalen van de weergegevens
        }
    }

    fetchWeatherData();
    // Roep de functie aan om de weergegevens op te halen
});