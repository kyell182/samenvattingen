
# Oplossingen: Bestandsrechten in Linux (Challenges 1 t.e.m. 5)

## ✅ Challenge 1: Basisrechten verkennen

1. **Bestand aanmaken:**
   ```bash
   touch oefenbestand.txt
   ```

2. **Rechten bekijken:**
   ```bash
   ls -l oefenbestand.txt
   ```
   Voorbeeldoutput:
   ```
   -rw-rw-r-- 1 gebruiker groep 0 datum tijd oefenbestand.txt
   ```

3. **Uitleg:**
   - `-` = gewoon bestand
   - `rw-` = gebruiker mag lezen & schrijven
   - `rw-` = groep mag lezen & schrijven
   - `r--` = anderen mogen alleen lezen

---

## ✅ Challenge 2: Rechten wijzigen met symbolische notatie

1. **Leesrecht voor others verwijderen:**
   ```bash
   chmod o-r oefenbestand.txt
   ```

2. **Uitvoerrechten voor user toevoegen:**
   ```bash
   chmod u+x oefenbestand.txt
   ```

3. **Rechten herstellen naar origineel (`rw-rw-r--`):**
   ```bash
   chmod 664 oefenbestand.txt
   ```

---

## ✅ Challenge 3: Rechten instellen met numerieke notatie

1. **Instellen op `rw-r--r--` (644):**
   ```bash
   chmod 644 oefenbestand.txt
   ```

2. **Instellen op `rwxr-xr--` (754):**
   ```bash
   chmod 754 oefenbestand.txt
   ```

3. **Uitleg:**
   - **644** = gebruiker: lezen+schrijven (4+2), groep: lezen (4), anderen: lezen (4)
   - **754** = gebruiker: lezen+schrijven+uitvoeren (7), groep: lezen+uitvoeren (5), anderen: lezen (4)

---

## ✅ Challenge 4: Script uitvoeren

1. **Script aanmaken:**
   ```bash
   echo "echo Hallo Linux!" > hallo.sh
   ```

2. **Uitvoeren (lukt niet):**
   ```bash
   ./hallo.sh
   ```
   ➤ Foutmelding: *Permission denied*

3. **Uitvoerrechten geven & opnieuw uitvoeren:**
   ```bash
   chmod u+x hallo.sh
   ./hallo.sh
   ```

4. **Verwachte output:**
   ```
   Hallo Linux!
   ```

---

## ✅ Challenge 5: Umask begrijpen

1. **Umask opvragen:**
   ```bash
   umask
   ```
   ➤ Voorbeeld: `002`

2. **Nieuw bestand aanmaken en controleren:**
   ```bash
   touch test.txt
   ls -l test.txt
   ```

   ➤ Output: `-rw-rw-r--`  
   De `w`-permissie werd **weggefilterd voor anderen**.

3. **Uitleg:**
   - Standaardrechten voor bestanden zijn 666 (rw-rw-rw-)
   - Umask 002 trekt 2 af van het derde getal → `rw-rw-r--`
