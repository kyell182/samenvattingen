# Systeemmonitoring in Linux – 25 Uitdagende Oefeningen (2de jaar Bachelor Elektronica-ICT)

## 1. Controleer de uptime van het systeem en bereken hoe lang het systeem gemiddeld online is gebleven per dag sinds de laatste boot.
**Oplossing:** Gebruik `uptime` of `who -b` om de laatste bootdatum op te vragen en reken zelf om.

## 2. Schrijf een script dat elke minuut de CPU-load logt naar een bestand, gedurende 1 uur.
**Oplossing:** Gebruik `uptime` of `cat /proc/loadavg` in combinatie met `watch` of een `cronjob`.

## 3. Vergelijk het RAM-gebruik van twee gelijktijdig draaiende processen.
**Oplossing:** Gebruik `ps aux --sort=-%mem | head` of `htop` en interpreteer de kolommen.

## 4. Gebruik `iostat` om te bepalen welk block device het meeste wordt gebruikt.
**Oplossing:** `iostat -dx 5 3` en bekijk `%util`.

## 5. Visualiseer netwerkverkeer live met `nload` en leg uit wanneer een interface overbelast zou zijn.
**Oplossing:** Installeer `nload`, observeer interface met hoogste in/out en evalueer verbruik.

## 6. Monitor I/O-activiteit van een bepaald proces met `iotop`.
**Oplossing:** Gebruik `sudo iotop -P` en filter op PID.

## 7. Zoek met `ss` alle open poorten op het systeem, inclusief het proces dat ze geopend heeft.
**Oplossing:** `sudo ss -tulnp`

## 8. Gebruik `ip` om het IP-adres van elke actieve netwerkinterface weer te geven.
**Oplossing:** `ip -br addr show up`

## 9. Stel met `watch` een commando op dat de 5 processen met de meeste CPU toont, elke 2 seconden.
**Oplossing:** `watch -n 2 "ps aux --sort=-%cpu | head -6"`

## 10. Gebruik `ping` en `mtr` om het netwerkpad naar google.com te analyseren.
**Oplossing:** `ping -c 5 google.com` gevolgd door `mtr google.com`

## 11. Gebruik `traceroute` en verklaar de verschillen tussen de paden naar twee willekeurige IP-adressen.
**Oplossing:** Voer `traceroute` uit en analyseer netwerkinfrastructuur of latency.

## 12. Stel een `crontab` in die elke dag om 02:00 het RAM-gebruik naar een logfile schrijft.
**Oplossing:** `crontab -e` → `0 2 * * * free -h > ~/ramlog.txt`

## 13. Bekijk actieve gebruikerssessies en logtijden met `w` en `who`.
**Oplossing:** `w` toont idle-tijd, `who` toont loginmoment.

## 14. Zoek gebruikers met mislukte loginpogingen via `faillog`.
**Oplossing:** `sudo faillog` en eventueel `faillog -u username`

## 15. Gebruik `journalctl` om fouten van de laatste 24 uur weer te geven.
**Oplossing:** `journalctl --since "24 hours ago" -p err`

## 16. Geef alle actieve systemd-services weer die falen of niet draaien.
**Oplossing:** `systemctl list-units --state=failed`

## 17. Zoek in `/var/log` naar fouten gelinkt aan `sshd`.
**Oplossing:** `grep -i sshd /var/log/auth.log` (of `journalctl -u ssh`)

## 18. Gebruik `less` om door een logbestand te scrollen. Zoek interactief naar "error".
**Oplossing:** `/error` in `less /var/log/syslog`

## 19. Volg een logbestand live met `tail -f` en noteer een gebeurtenis als ze verschijnt.
**Oplossing:** `tail -f /var/log/syslog`

## 20. Scan je lokale netwerk naar actieve hosts met `nmap`.
**Oplossing:** `sudo nmap -sn 192.168.1.0/24`

## 21. Maak een script dat het gemiddelde CPU-gebruik logt over 10 minuten met `sar`.
**Oplossing:** `sar -u 60 10` in een script, loggen met `>> logfile`

## 22. Toon alle processen op je systeem die meer dan 500 MB RAM gebruiken.
**Oplossing:** `ps aux | awk '$6 > 500000'`

## 23. Gebruik `btop` om live gebruik van CPU, RAM en schijf te monitoren. Neem een screenshot van een piek.
**Oplossing:** Start `btop`, observeer, maak screenshot.

## 24. Toon processen gesorteerd op levensduur met `ps`.
**Oplossing:** `ps -eo pid,etime,cmd --sort=etime`

## 25. Schrijf een script dat bij overmatig RAM-gebruik (>90%) automatisch een melding stuurt naar een logfile.
**Oplossing:** Gebruik `free` en `awk` om RAM-gebruik te berekenen en log bij overschrijding.
