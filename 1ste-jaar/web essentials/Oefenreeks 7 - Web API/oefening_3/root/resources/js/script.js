document.addEventListener("DOMContentLoaded", () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    const jsonString = '[{"city":"Brugge","population":118325,"area":138.4},{"city":"Gent","population":262219,"area":156.18},{"city":"Antwerpen","population":525935,"area":204.51},{"city":"Leuven","population":101394,"area":56.63},{"city":"Mechelen","population":86715,"area":33.71}]';
    // JSON-string met gegevens van verschillende steden

    const drawChartButton = document.getElementById('drawChartButton');
    // Selecteer de knop met de id 'drawChartButton'

    drawChartButton.addEventListener('click', () => {
        // Voeg een click event listener toe aan de knop

        const data = JSON.parse(jsonString);
        // Zet de JSON-string om naar een object

        google.charts.load('current', { packages: ['corechart'] });
        // Laad de Google Charts bibliotheek

        google.charts.setOnLoadCallback(() => {
            // Wacht tot de Google Charts bibliotheek is geladen

            const dataTable = new google.visualization.DataTable();
            // Maak een nieuw DataTable object

            dataTable.addColumn('string', 'Stad');
            // Voeg een kolom toe voor de stad

            dataTable.addColumn('number', 'Inwoners per m²');
            // Voeg een kolom toe voor het aantal inwoners per m²

            data.forEach(city => {
                const populationDensity = city.population / city.area;
                // Bereken het aantal inwoners per m²

                dataTable.addRow([city.city, populationDensity]);
                // Voeg een rij toe aan de DataTable met de stad en het aantal inwoners per m²
            });

            const options = {
                title: 'Inwoners per m² per stad',
                pieHole: 0.6,
                
                // Opties voor het taartdiagram
            };

            const chart = new google.visualization.PieChart(document.getElementById('chart_div'));
            // Maak een nieuw PieChart object en selecteer het element met de id 'chart_div'

            chart.draw(dataTable, options);
            // Teken het taartdiagram met de gegevens en opties
        });
    });
});