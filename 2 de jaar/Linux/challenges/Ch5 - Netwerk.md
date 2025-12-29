# Oefeningen - Ch5: Verbinden met een netwerk

Hieronder vind je een reeks oefeningen van oplopende moeilijkheidsgraad, met telkens een oplossing en een korte toelichting.

---

## 1. Wat is je IP-adres?
**Opdracht**: Toon het IP-adres van je machine.

**Oplossing**:
````bash
ip a

 inet 10.0.2.15/24 brd 10.0.2.255 scope global dynamic noprefixroute enp0s3

 inet6 fd17:625c:f037:2:a00d:1d77:b67b:7dee/64 scope global temporary dynamic 
````

## 2. Controleer de netwerkverbinding
**Opdracht**: Kijk of je systeem verbonden is met het internet.

**Oplossing**:
````bash
ping -c 10 8.8.8.8
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=255 time=20.4 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=255 time=26.1 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=255 time=19.1 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=255 time=19.3 ms
64 bytes from 8.8.8.8: icmp_seq=5 ttl=255 time=20.5 ms
64 bytes from 8.8.8.8: icmp_seq=6 ttl=255 time=19.8 ms
64 bytes from 8.8.8.8: icmp_seq=7 ttl=255 time=19.7 ms
64 bytes from 8.8.8.8: icmp_seq=8 ttl=255 time=20.9 ms
64 bytes from 8.8.8.8: icmp_seq=9 ttl=255 time=22.9 ms
64 bytes from 8.8.8.8: icmp_seq=10 ttl=255 time=20.6 ms
````


## 3. Domeinnaam testen
**Opdracht**: Controleer of DNS werkt door google.com te pingen.

**Oplossing**:
````bash
ping google.com -c 10
PING google.com (74.125.133.139) 56(84) bytes of data.
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=1 ttl=255 time=28.2 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=2 ttl=255 time=21.7 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=3 ttl=255 time=21.3 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=4 ttl=255 time=39.5 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=5 ttl=255 time=23.2 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=6 ttl=255 time=20.4 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=7 ttl=255 time=22.4 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=8 ttl=255 time=25.2 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=9 ttl=255 time=22.2 ms
64 bytes from wo-in-f139.1e100.net (74.125.133.139): icmp_seq=10 ttl=255 time=25.8 ms

--- google.com ping statistics ---
10 packets transmitted, 10 received, 0% packet loss, time 9464ms
rtt min/avg/max/mdev = 20.405/24.988/39.517/5.340 ms
````


## 4. Toon alle netwerkinterfaces
**Opdracht**: Toon de status van alle netwerkinterfaces op het systeem.

**Oplossing**:
````bash
ip a

1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute 
       valid_lft forever preferred_lft forever
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 08:00:27:5e:03:69 brd ff:ff:ff:ff:ff:ff
    altname enx0800275e0369
    inet 10.0.2.15/24 brd 10.0.2.255 scope global dynamic noprefixroute enp0s3
       valid_lft 67675sec preferred_lft 67675sec
    inet6 fd17:625c:f037:2:a00d:1d77:b67b:7dee/64 scope global temporary dynamic 
       valid_lft 85953sec preferred_lft 13953sec
    inet6 fd17:625c:f037:2:a00:27ff:fe5e:369/64 scope global dynamic mngtmpaddr noprefixroute 
       valid_lft 85953sec preferred_lft 13953sec
    inet6 fe80::a00:27ff:fe5e:369/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
````


## 5. Schakel een netwerkinterface tijdelijk uit
**Opdracht**: Schakel interface `enp0s3` uit.

**Oplossing**:
````bash
sudo nmcli device disconnect enp0s3
````

## 6. Activeer dezelfde interface opnieuw
**Oplossing**:
````bash
sudo nmcli device connect enp0s3
````

## 7. Gebruik nmtui om IP-configuratie te bekijken
**Opdracht**: Start de tekstinterface om je netwerkinstellingen te wijzigen.

**Oplossing**:
````bash
sudo nmtui
````


## 8. Statisch IP instellen via nmcli
**Opdracht**: Stel het IP-adres in op 192.168.56.10/24 met gateway 192.168.56.1.

**Oplossing**:
````bash
sudo nmcli con mod  "Wired connection 1" ipv4.addresses 192.168.56.10/24 
sudo nmcli con mod "Wired connection 1" ipv4.gateway 192.168.56.1
````


## 9. Welke poorten zijn open?
**Opdracht**: Toon alle actieve netwerkservices en poorten.

**Oplossing**:
````bash
sudo ss -tulnp
[sudo] password for student: 
Netid          State           Recv-Q          Send-Q                     Local Address:Port                      Peer Address:Port          Process                                          
udp            UNCONN          0               0                                0.0.0.0:43954                          0.0.0.0:*              users:(("avahi-daemon",pid=724,fd=14))          
udp            UNCONN          0               0                                0.0.0.0:5353                           0.0.0.0:*              users:(("avahi-daemon",pid=724,fd=12))          
udp            UNCONN          0               0                                   [::]:43971                             [::]:*              users:(("avahi-daemon",pid=724,fd=15))          
udp            UNCONN          0               0                                   [::]:5353                              [::]:*              users:(("avahi-daemon",pid=724,fd=13))          
tcp            LISTEN          0               4096                           127.0.0.1:631                            0.0.0.0:*              users:(("cupsd",pid=926,fd=7))                  
tcp            LISTEN          0               4096                               [::1]:631                               [::]:*              users:(("cupsd",pid=926,fd=6))
````



## 10. Installeer en gebruik mtr
**Opdracht**: Analyseer de route naar google.com in realtime.

**Oplossing**:
````bash
mtr google.com
````


## 11. SSH beveiligen
**Opdracht**: Schakel SSH-login als root uit.

**Oplossing**:
````bash
sudo nano /etc/ssh/sshd_config
````
* dan PermitRootLogin op no zetten

* dan de ssh service herstarten

````bash
sudo systemctl restart sshd
````



## 12. SSH sleutelpaar genereren
**Opdracht**: Genereer een SSH-keypair.

**Oplossing**:
````bash
ssh-keygen -t rsa
Generating public/private rsa key pair.
Enter file in which to save the key (/home/student/.ssh/id_rsa): 
Enter passphrase for "/home/student/.ssh/id_rsa" (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/student/.ssh/id_rsa
Your public key has been saved in /home/student/.ssh/id_rsa.pub
````


## 13. Zet publieke sleutel over naar andere machine
**Opdracht**: Kopieer je privat sleutel naar de VM.

**Oplossing**:
````bash
scp ./id_rsa.pub root@bachelor-vm-23:~/.ssh/authorized_keys
````

## 14. Firewall instellen met UFW
**Opdracht**: Laat enkel SSH-verkeer toe, alles anders blokkeren.

**Oplossing**:
````bash
sudo ufw enable
sudo ufw allow ssh
````


## 15. Diagnosticeer DNS-probleem
**Situatie**: `ping 8.8.8.8` werkt, maar `ping google.com` niet.

**Oplossing**:
````bash
ping google.com
nslookup google.com
```` 
* om te zie of het effectief niet werkt
* daarna de dns instellingen controleren
````bash
cat /etc/resolv.conf
````
* je moet een regel zien zoals
````bash
nameserver 8.8.8.8
nameserver 1.1.1.1
````
* als er daar niets staat of iets verkeerd dan kan je hier de dns server toevoegen.

* daarna opnieuw testen
````bash
ping google.com
````
je kan ook controleren of het geen firewall probleem is als **ufw** `poort 53` blokkeert
````bash
sudo ufw status | grep 53
````
of
````bash
sudo ufw status verbose
````
kijk ook zeker via `ss` of `netstat` of de services werken.
````bash
sudo ss -tulnp
````