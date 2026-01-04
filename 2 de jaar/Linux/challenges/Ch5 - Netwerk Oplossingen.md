# Oefeningen - Ch5: Verbinden met een netwerk

Hieronder vind je een reeks oefeningen van oplopende moeilijkheidsgraad, met telkens een oplossing en een korte toelichting.

---

## 1. Wat is je IP-adres?
**Opdracht**: Toon het IP-adres van je machine.

**Oplossing**:
```bash
ip a
```

---

## 2. Controleer de netwerkverbinding
**Opdracht**: Kijk of je systeem verbonden is met het internet.

**Oplossing**:
```bash
ping -c 3 8.8.8.8
```

---

## 3. Domeinnaam testen
**Opdracht**: Controleer of DNS werkt door google.com te pingen.

**Oplossing**:
```bash
ping -c 3 google.com
```

---

## 4. Toon alle netwerkinterfaces
**Opdracht**: Toon de status van alle netwerkinterfaces op het systeem.

**Oplossing**:
```bash
nmcli device status
```

---

## 5. Schakel een netwerkinterface tijdelijk uit
**Opdracht**: Schakel interface `enp0s3` uit.

**Oplossing**:
```bash
sudo ip link set enp0s3 down
```

---

## 6. Activeer dezelfde interface opnieuw
**Oplossing**:
```bash
sudo ip link set enp0s3 up
```

---

## 7. Gebruik nmtui om IP-configuratie te bekijken
**Opdracht**: Start de tekstinterface om je netwerkinstellingen te wijzigen.

**Oplossing**:
```bash
sudo nmtui
```

---

## 8. Statisch IP instellen via nmcli
**Opdracht**: Stel het IP-adres in op 192.168.56.10/24 met gateway 192.168.56.1.

**Oplossing**:
```bash
nmcli con mod "Wired connection 1" ipv4.addresses 192.168.56.10/24
nmcli con mod "Wired connection 1" ipv4.gateway 192.168.56.1
nmcli con mod "Wired connection 1" ipv4.method manual
nmcli con up "Wired connection 1"
```

---

## 9. Welke poorten zijn open?
**Opdracht**: Toon alle actieve netwerkservices en poorten.

**Oplossing**:
```bash
sudo ss -tuln
```

---

## 10. Installeer en gebruik mtr
**Opdracht**: Analyseer de route naar google.com in realtime.

**Oplossing**:
```bash
sudo apt install mtr
mtr google.com
```

---

## 11. SSH beveiligen
**Opdracht**: Schakel SSH-login als root uit.

**Oplossing**:
Bewerk `/etc/ssh/sshd_config` en wijzig:
```
PermitRootLogin no
```
Daarna:
```bash
sudo systemctl restart sshd
```

---

## 12. SSH sleutelpaar genereren
**Opdracht**: Genereer een SSH-keypair.

**Oplossing**:
```bash
ssh-keygen -t rsa
```

---

## 13. Zet publieke sleutel over naar andere machine
**Opdracht**: Kopieer je privat sleutel naar de VM.

**Oplossing**:
```bash
scp ~/.ssh/id_rsa.pub user@192.168.1.99:~/.ssh/authorized_keys
```

---

## 14. Firewall instellen met UFW
**Opdracht**: Laat enkel SSH-verkeer toe, alles anders blokkeren.

**Oplossing**:
```bash
sudo ufw default deny incoming
sudo ufw allow ssh
sudo ufw enable
```

---

## 15. Diagnosticeer DNS-probleem
**Situatie**: `ping 8.8.8.8` werkt, maar `ping google.com` niet.

**Oplossing**:
```bash
nslookup google.com
```
of
```bash
dig google.com
```
Controleer de inhoud van `/etc/resolv.conf`.

---
