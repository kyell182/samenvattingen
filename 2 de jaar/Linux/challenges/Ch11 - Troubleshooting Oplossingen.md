# Oefeningen - Ch11: Troubleshooting Linux

Deze oefeningen helpen je stap voor stap om je troubleshootingvaardigheden in Linux te ontwikkelen. 

## 1. Toon recente kernel- of hardwarefouten
**Opdracht**: Zoek in `dmesg` naar fouten.

**Oplossing**:
```bash
dmesg | grep -Ei 'error|fail|fault|unknown'
```

---

## 2. Doorzoek logbestanden naar fouten
**Opdracht**: Zoek alle regels met 'error' in `/var/log`.

**Oplossing**:
```bash
cd /var/log
sudo grep -ir error *
```

---

## 3. Analyseer foutmeldingen uit een opgeslagen logbestand
**Opdracht**: Sla foutmeldingen op en filter later verder.

**Oplossing**:
```bash
sudo grep -ir error * > ~/errors.txt
grep ssh ~/errors.txt
```

---

## 4. Zoek mislukte logins
**Opdracht**: Toon alle mislukte loginpogingen.

**Oplossing**:
```bash
sudo faillog
```

---

## 5. Check welke services niet actief zijn
**Opdracht**: Toon alle geïnstalleerde maar niet-actieve systemd-services.

**Oplossing**:
```bash
systemctl list-units --type=service --state=inactive
```

---

## 6. Controleer of SSH correct werkt
**Opdracht**: Bekijk de log voor de SSH-dienst.

**Oplossing**:
```bash
journalctl -u ssh
```

---

## 7. Achterhaal waarom een service niet automatisch start
**Opdracht**: Kijk of een service geconfigureerd is om te starten bij boot.

**Oplossing**:
```bash
systemctl is-enabled ssh
```

---

## 8. Herinstalleer een corrupte toepassing
**Opdracht**: Verwijder en installeer curl opnieuw.

**Oplossing**:
```bash
sudo apt purge curl
sudo apt install curl
```

---

## 9. Controleer of een firewall een service blokkeert
**Opdracht**: Controleer of poort 8080 open is.

**Oplossing**:
```bash
sudo ss -tulpn | grep 8080
sudo ufw status
```

---

## 10. Traceer netwerkproblemen met traceroute
**Opdracht**: Toon via welke routers verkeer naar google.com gaat.

**Oplossing**:
```bash
traceroute google.com
```

---

## 11. Detecteer een beginnende hardwarefout
**Opdracht**: Toon foutmeldingen van de schijf via `dmesg`.

**Oplossing**:
```bash
dmesg | grep -i sda
```

---

## 12. Vergelijk hardwareconfiguratie voor en na een probleem
**Opdracht**: Gebruik `lshw` en `diff` om verschillen te vinden.

**Oplossing**:
```bash
sudo lshw > ~/hw_before.txt
# (later opnieuw)
sudo lshw > ~/hw_after.txt
diff ~/hw_before.txt ~/hw_after.txt
```

---

## 13. Automatiseer een dagelijkse logcontrole
**Opdracht**: Schrijf een script dat dagelijks fouten in `/var/log` opspoort.

**Oplossing**:
```bash
#!/bin/bash
d=$(date +%F)
grep -ir error /var/log > ~/logcheck_$d.txt
```

---

## 14. Ontdek en analyseer een rootkit of misbruik
**Opdracht**: Stel je voor dat `last` een onbekende rootgebruiker toont genaamd jamd. Gebruik `journalctl`, `grep`, `diff` en `find` om een aanval te reconstrueren.

**Oplossing**:
```bash
sudo last | grep root
grep 'jamd' /etc/passwd
sudo journalctl -u ssh | grep jamd
find /etc -type f -mtime -2
```

---
