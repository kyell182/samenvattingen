document.addEventListener("DOMContentLoaded", () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    const jsonString = '[{"age": "3", "weight": "3.5"}, {"age": "4", "weight": "5"}, {"age": "6.5", "weight": "7"}, {"age": "11", "weight": "14"}, {"age": "4", "weight": "5.5"}, {"age": "8", "weight": "12"}]';
    // JSON-string met gegevens van verschillende meetpunten

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

            dataTable.addColumn('number', 'Leeftijd');
            // Voeg een kolom toe voor de leeftijd

            dataTable.addColumn('number', 'Gewicht');
            // Voeg een kolom toe voor het gewicht

            data.forEach(entry => {
                dataTable.addRow([parseFloat(entry.age), parseFloat(entry.weight)]);
                // Voeg een rij toe aan de DataTable met de leeftijd en het gewicht
            });

            const options = {
                title: 'Leeftijd vs Gewicht',
                hAxis: { title: 'Leeftijd' },
                vAxis: { title: 'Gewicht' },
                legend: 'none',
                trendlines: {
                    0: {
                        type: 'polynomial',
                        degree: 3,
                        visibleInLegend: true
                    }
                }
                // Opties voor de grafiek, inclusief de polynomiale trendlijn
            };

            const chart = new google.visualization.ScatterChart(document.getElementById('chart_div'));
            // Maak een nieuw ScatterChart object en selecteer het element met de id 'chart_div'

            chart.draw(dataTable, options);
            // Teken de grafiek met de gegevens en opties
        });
    });
});