# Oefeningen - Ch4: Gebruikers en groepen beheren

In deze oefeningen leer je hoe je gebruikers en groepen beheert in Linux. De moeilijkheidsgraad neemt stapsgewijs toe.

---

## 1. Toon alle gebruikers
**Opdracht**: Toon de lijst van alle gebruikers op het systeem.

**Oplossing**:
```bash
cat /etc/passwd
```

---

## 2. Maak een nieuwe gebruiker aan
**Opdracht**: Voeg een gebruiker `jan` toe aan het systeem.

**Oplossing**:
```bash
sudo adduser jan
```

---

## 3. Geef `jan` een wachtwoord
**Opdracht**: Stel een wachtwoord in voor `jan`.

**Oplossing**:
```bash
sudo passwd jan
```

---

## 4. Verwijder gebruiker `jan`
**Opdracht**: Verwijder enkel het account `jan`, maar laat de bestanden staan.

**Oplossing**:
```bash
sudo userdel jan
```

---

## 5. Verwijder gebruiker en zijn bestanden
**Opdracht**: Verwijder `jan` en zijn persoonlijke bestanden.

**Oplossing**:
```bash
sudo rm -r /home/jan
```

---

## 6. Bekijk info over gebruiker `student`
**Opdracht**: Toon de volledige regel over `student` uit `/etc/passwd`.

**Oplossing**:
```bash
grep student /etc/passwd
```

---

## 7. Kijk in welk bestand de wachtwoorden staan
**Opdracht**: Toon het versleutelde wachtwoord van een gebruiker.

**Oplossing**:
```bash
sudo cat /etc/shadow | grep student
```

---

## 8. Voeg een gebruiker toe aan de groep `sudo`
**Opdracht**: Geef `student` beheerdersrechten.

**Oplossing**:
```bash
sudo usermod -aG sudo student
```

---

## 9. Toon van welke groepen een gebruiker lid is
**Opdracht**: Toon de groepen van `student`.

**Oplossing**:
```bash
groups student
```

---

## 10. Maak een nieuwe groep `project`
**Opdracht**: Voeg een groep toe voor een projectteam.

**Oplossing**:
```bash
sudo groupadd project
```

---

## 11. Voeg `student` toe aan groep `project`
**Opdracht**: Geef `student` toegang tot de projectgroep.

**Oplossing**:
```bash
sudo usermod -aG project student
```

---

## 12. Kijk of `student` lid is van `project`
**Opdracht**: Controleer of de groepslidmaatschap juist is.

**Oplossing**:
```bash
id student
```

---

## 13. Verwijder een groep
**Opdracht**: Verwijder de groep `project`.

**Oplossing**:
```bash
sudo groupdel project
```

---

## 14. Maak een serviceaccount aan
**Opdracht**: Maak een gebruiker `backup` aan die niet kan inloggen.

**Oplossing**:
```bash
sudo useradd -r -s /usr/sbin/nologin backup
```

---

## 15. Schakel gebruiker tijdelijk uit
**Opdracht**: Blokkeer tijdelijk de gebruiker `student`.

**Oplossing**:
```bash
sudo usermod -L student
```

---

