document.addEventListener('DOMContentLoaded', () => {
    // Wacht tot het DOM volledig is geladen voordat de code wordt uitgevoerd

    const img = [
        // Array van afbeeldingsbestanden
        "resources/images/one_star.jpg",
        "resources/images/two_star.jpg",
        "resources/images/three_star.jpg",
        "resources/images/four_star.jpg",
        "resources/images/five_star.jpg",
        "resources/images/six_star.jpg",
        "resources/images/seven_star.jpg"
    ];

    let currentIndex = 0;
    // Huidige index van de afbeelding, begint bij 0

    const imgElement = document.getElementById('image');
    // Selecteer het img-element met de id 'image'

    imgElement.src = img[currentIndex];
    // Stel de src van het img-element in op de eerste afbeelding in de array

    const button = document.getElementById("toggleButton");
    // Selecteer de knop met de id 'toggleButton'

    button.addEventListener('click', () => {
        // Voeg een click event listener toe aan de knop
        currentIndex = (currentIndex + 1) % img.length;
        // Verhoog de index en ga terug naar 0 als de laatste afbeelding is bereikt
        imgElement.src = img[currentIndex];
        // Stel de src van het img-element in op de volgende afbeelding in de array
    });

});