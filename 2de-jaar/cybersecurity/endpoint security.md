# Virusdetectie & Wazuh Praktijkgids

## Hoe worden virussen gedetecteerd?

Een antivirusprogramma hanteert doorgaans twee methoden om kwaadaardige software te identificeren:

1. **Detectie van *nieuwe* virussen (Gedragsanalyse / Heuristiek):**
   * Je pc stuurt regelmatig logs door naar de servers van je antivirusprovider.
   * Als deze logs veel errors of verdachte activiteiten bevatten, kan een bepaald programma als 'virus' worden geflagged in hun database.
2. **Detectie van *gekende* virussen (Hash-matching):**
   * Voor reeds bekende virussen vergelijkt de antivirus de **hash** van een programma op jouw pc met een lijst van bekende kwaadaardige hashes in hun database.
   * Bij een match wordt het programma direct geblokkeerd.

---

## Praktijkopdracht: Wazuh Gebruiken

**Doel:** Wazuh installeren op een school-VM en je eigen Windows laptop/pc toevoegen als 'agent' om te scannen op security risks.

### Fase 1: Installatie op de VM & Sysmon op Windows

1. Download het Wazuh installatiescript op de VM:

    ```bash
    curl -sO [https://packages.wazuh.com/4.14/wazuh-install.sh](https://packages.wazuh.com/4.14/wazuh-install.sh)
    # Controleer met 'ls' of wazuh-install.sh in de map staat
    ```

2. Voer het installatiescript uit:

    ```bash
    bash ./wazuh-install.sh -a
    ```

3. Installeer **Sysmon** op je lokale Windows pc. Open een Windows Terminal *met administrator rechten* en voer in:

    ```powershell
    winget install sysmon
    ```

### Fase 2: Wazuh Agent Configureren op Windows

1. Surf op je Windows pc naar: `https://packages.wazuh.com/4.x/windows/wazuh-agent-4.14.4-1.msi` en download de agent.
2. Voer het `.msi` installatiebestand uit.
3. Vink aan het einde van de installatie (vóór je op Finish klikt) de optie aan om de agent interface direct te openen.
4. Voer in het kleine Wazuh-venster het **IP-adres van de Wazuh server** in (in dit geval de server van de docent: `10.20.10.13`).
5. Klik op **Save**, ga dan linksboven naar **Manage** en kies **Restart**.
6. Klik na de herstart op **Refresh**. Als het goed is, zie je nu een *auth key* verschijnen.

---

### Fase 3: Het Wazuh Dashboard Begrijpen

Surf naar het IP-adres van je Wazuh server en log in op de webinterface. Hier is een overzicht van de belangrijkste menu's en functionaliteiten:

| Dashboard Tab                | Wat kun je ermee?                                                                                                                                              |
| :--------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Agents summary**           | Klik op *Active* om een lijst te zien van alle actieve clients (agents).                                                                                       |
| **Malware detection**        | Geeft een zeer gedetailleerd overzicht van eventuele gevonden malware op de agents.                                                                            |
| **Vulnerability detection**  | Toont een overzicht van alle kwetsbaarheden (vulnerabilities). In de top 5 zie je direct de bijbehorende **CVE-codes**.                                        |
| **Configuration assessment** | Hier kun je specifieke agents selecteren om hun configuratie op veiligheid te beoordelen.                                                                      |
| **IT Hygiene**               | Overzicht van de netwerk- en systeemhygiëne. Tabblad *System* geeft een gedetailleerde weergave. Je kunt de gefilterde info exporteren als een `.csv` bestand. |
| **File integrity**           | Bekijk in de *Inventory* welke bestanden er allemaal gemonitord worden op wijzigingen.                                                                         |

* **Filtertip:** In elke categorie kun je bij een entry op het **[+]** of **[-]** icoontje klikken om die specifieke waarde direct in of uit te sluiten als filter.

---

### Fase 4: Praktijktest - Threat Hunting (Authenticatie Fouten)

Tijdens de les is er een test gedaan om authenticatiefouten (verkeerde wachtwoorden) te monitoren.

* *Actie:* Iedereen moest zijn laptop locken, 2x een verkeerd wachtwoord ingeven, en daarna weer unlocken.

**Hoe je dit terugziet in Wazuh:**

1. Navigeer in Wazuh naar **Threat hunting**.
2. Je ziet hier alle *authentication failures* (tijdens de les waren dit er 34 door alle studenten samen).
3. Klik linksboven op **Events** om deze foutmeldingen in detail te bekijken.

#### Handige Filters Instellen

Om specifieke incidenten in Threat Hunting of IT Hygiene te vinden, kun je de volgende filters gebruiken:

* **Filteren op hoge kwetsbaarheden:**
  * Field: `rule.level`
  * Operator: `is between`
  * Value: `7` tot `15`
* **Filteren op jouw eigen pc/laptop:**
  * Field: `agent.name`
  * Operator: `is`
  * Value: `[Kies de naam van jouw device]`

---

> **Pro-Tip voor Beheerders:**
> Als je veel fysieke devices of virtuele machines (VM's) moet beheren, kun je het beste één **"Golden Image"** maken.
> Dit is een basisinstallatie met **0 vulnerabilities** volgens Wazuh. Deze veilige template gebruik je vervolgens om te distribueren (klonen) naar alle andere systemen.
