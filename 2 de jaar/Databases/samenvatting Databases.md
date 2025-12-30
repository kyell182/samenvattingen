# samenvatting Databases

## Inhoudsopgave


# Hoofdstuk 1: Inleiding tot Databases

**1.1. Wat is data en in welke vormen komt het voor?**
<details><summary>Antwoord</summary>

- **Ruwe data**: Onbewerkte feiten en cijfers zonder context.
- **Dataverwerking**: Het proces van het organiseren, structureren en analyseren van data om nuttige informatie te verkrijgen.
- **Informatie**: Georganiseerde en verwerkte data die betekenisvol is.
- **Kennis**: Informatie die is geïnterpreteerd en begrepen, vaak gebruikt voor besluitvorming.

- **Vormen van data**:
  - Gestructureerde data: Georganiseerd in tabellen (bijv. databases).
  - Ongestructureerde data: Niet georganiseerd (bijv. tekstbestanden, afbeeldingen).
  - Semi-gestructureerde data: Gedeeltelijk georganiseerd (bijv. XML, JSON).

![data flow](./assets/flow%20van%20ruwe%20data%20naar%20info.png)

</details>

**1.2. Wat is een database en welke voordelen biedt het gebruik ervan?**
<details><summary>Antwoord</summary>

- **Database**: Een georganiseerde verzameling van gegevens die elektronisch wordt opgeslagen en beheerd.
- **Voordelen van databases**:
  - Efficiënte opslag en beheer van grote hoeveelheden data.
  - Snelle toegang tot gegevens via query's.
  - Gegevensintegriteit en consistentie door regels en beperkingen.
  - Meerdere gebruikers kunnen gelijktijdig toegang krijgen tot dezelfde data.
  - Beveiliging van gegevens door toegangscontrole en autorisatie.
  - Back-up en herstelmogelijkheden om gegevensverlies te voorkomen.
  - Schaalbaarheid om te groeien met de behoeften van een organisatie.

</details>

**1.3. geef een paar toepassingen van databases?**
<details><summary>Antwoord</summary>

- **Toepassingen van databases**:
  - Klantrelatiebeheer (CRM) systemen.
  - E-commerce platforms.
  - Financiële systemen (bankieren, boekhouding).
  - Gezondheidszorgsystemen (patiëntendossiers).
  - Voorraadbeheer en logistiek.
  - Sociale media platforms.
  - Onderzoeksdatabases voor wetenschappelijke studies.
  - Contentmanagementsystemen (CMS) voor websites.
  - Educatieve platforms voor studenten- en cursusbeheer.

</details>

**1.4. welke 2 soorten data worden er onderscheiden en wat zijn de voor en nadelen?**
<details><summary>Antwoord</summary>

- **Vluchtige data**:
  - dat wordt geladen in het geheugen (RAM).
  - in code: gebruik makn van variabelen.

  - **Voordelen**:
    - Snelle toegang en verwerking.
    - Geschikt voor tijdelijke opslag (bijv. RAM).
  - **Nadelen**:
    - Verliest gegevens bij stroomuitval.
    - Beperkte opslagcapaciteit.

- **Niet-vluchtige data**:
  - Data wordt opgeslagen naar een bestand of schijf.
  - in code: gebruik maken van bestanden of databases.

  - **Voordelen**:
    - Permanente opslag van gegevens (bijv. harde schijven, SSD's).
    - Behoudt gegevens bij stroomuitval.
  - **Nadelen**:
    - Langzamere toegang in vergelijking met vluchtige data.
    - Kan duurder zijn in termen van opslagmedia.

</details>

**1.5. Geef een overzicht van de verschillende bestandstypen**
<details><summary>Antwoord</summary>

1. Ecxel-bestanden (.xls, .xlsx)

    ![excel](./assets/Excel%20bestand.png)

2. CSV-bestanden (.csv)

    ![csv](./assets/csv%20bestand.png)

3. XML-bestanden (.xml)

    ![xml](./assets/XML%20bestand.png)

4. JSON-bestanden (.json)

    ![json](./assets/Json%20bestand.png)

5. Binaire bestanden (.bin, .dat)

    ![binair](./assets/bin%20bestand.png)

6. Access-bestanden (.mdb, .accdb)

    ![access](./assets/access%20bestand.png)


</details>

**1.6. Welke van de bovenstaande bestandstypen behoren tot de vlakke datastructuren en wat zijn de mogelijke nadelen?
<details><summary>Antwoord</summary>

- Excel-bestanden (.xls, .xlsx)
- CSV-bestanden (.csv)

**Nadelen van vlakke datastructuren**:
- men kan hier moeilijk relaties tussen data leggen.

- is ok voor kleine datasets, maar niet voor grote datasets.

</details>

**1.7. welke van de bovenstaande bestandstypen zijn geneste datastructuren en wat zijn de mogelijke voordelen?**
<details><summary>Antwoord</summary>

- XML-bestanden (.xml)

![xml](./assets/geneste%20XML.png)

- JSON-bestanden (.json)

![json](./assets/geneste%20Json.png)

**Voordelen van geneste datastructuren**:
- kunnen complexe gegevensmodellen weergeven.
- maken hiërarchische relaties tussen gegevens mogelijk.
- flexibel en uitbreidbaar voor verschillende soorten gegevens.
- geschikt voor webtoepassingen en API's.
- makkelijk te lezen en te begrijpen door zowel mensen als machines.
- ondersteunen meerdere niveaus van gegevensorganisatie.

</details>

**1.8. Wat zijn mogelijke nadelen van bovenstaande datastructuren en wat is de oplossing?**
<details><summary>Antwoord</summary>

- **problemen :
  - kunnen maar door 1 proces of applicatie tegelijk geschreven worden.
  - zeer traag om data te zoeken.
  - traag bij het toevegen, verwijderen of bijwerken van data.

- **Oplossing**:
  - gebruik maken van databasesystemen die gelijktijdige toegang, snelle zoekmogelijkheden en efficiënte gegevensmanipulatie bieden.

![vergelijkende tabel](./assets/vergelijkende%20tabel%20datatypes.png)

</details>

**1.9. Wat is het doel van een databank (database management system - DBMS)?**
<details><summary>Antwoord</summary>

- digitale opslagplaats voor gegevens.
- kan flexibel geraadpleegd, beheerd en bijgewerkt worden door meerdere gebruikers tegelijk.
  - doorzoeen van gegevens
  - toevoegen van gegevens
  - verwijderen van gegevens
- speelt dus een cruciale rol voor het `archiveren` en het `actueel houden` van data.

</details>

**1.10. uit hoeveel componenten bestaat een DBMS en welke zijn dat?**
<details><summary>Antwoord</summary>

Een DBMS bestaat uit vier hoofdcomponenten:

1. gebruikers : 
   - mensen die de database gebruiken en beheren.
   - kunnen verschillende rollen hebben, zoals databasebeheerders, ontwikkelaars en eindgebruikers.

2. Databankapplicaties :

   - Gewone gebruikers :
        - kant en klaarapplicaties die interactie hebben met de database.
        - bijv:
          - Boekhoudsoftware
          - CRM-systemen.

    - Administrators :
        - gebruiken programma's om de database te beheren.
        - bijv:
          - MySQL Workbench
          - SQL Server Management Studio.

3. DBMS-software :
   - draait op de achtergrond en dient om de databanken te creëren, beheren en onderhouden.
   - belangerijkste taak is het handhaven van de integriteit van de gegevens :
     - voldoen aan regels
     - consistentie van de gegevens

4. Databank zelf :
   - bevat bij elkaar horende data/gegevens die opgeslagen zin in sets van onderlinge gerelateerde tabellen.

![databases relaties](./assets/databases%20relations.png)

</details>

