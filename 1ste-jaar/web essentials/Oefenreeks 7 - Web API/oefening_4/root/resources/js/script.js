document.addEventListener('DOMContentLoaded', () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    const jsonString = '[{"year": "2020", "revenue": 50245}, {"year": "2021", "revenue": 65898}, {"year": "2022", "revenue": 68688}, {"year": "2023", "revenue": 80526}, {"year": "2024", "revenue": 203366}]';
    // JSON-string met de omzet van de laatste 5 jaar van een bedrijf

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

            dataTable.addColumn('string', 'Jaar');
            // Voeg een kolom toe voor het jaar

            dataTable.addColumn('number', 'Omzet');
            // Voeg een kolom toe voor de omzet

            data.forEach(entry => {
                dataTable.addRow([entry.year, entry.revenue]);
                // Voeg een rij toe aan de DataTable met het jaar en de omzet
            });

            const options = {
                title: 'Omzet van de laatste 5 jaar',
                hAxis: { title: 'Jaar' },
                vAxis: { title: 'Omzet' },
                legend: 'none'
                // Opties voor het staafdiagram
            };

            const chart = new google.visualization.ColumnChart(document.getElementById('chart_div'));
            // Maak een nieuw ColumnChart object en selecteer het element met de id 'chart_div'

            chart.draw(dataTable, options);
            // Teken het staafdiagram met de gegevens en opties
        });
    });
});