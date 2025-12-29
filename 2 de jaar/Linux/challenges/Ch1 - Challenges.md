
# 🧪 Oefeningen: Eerste stappen op je Debian-systeem (CLI)

## 🔧 Voorwaarden
- Voer deze opdrachten uit op een verse Debian-installatie (bij voorkeur in een VM).
- Gebruik enkel de terminal. Je werkt als gewone gebruiker, tenzij anders vermeld.

---

## 📝 Opdracht 1: Oriëntatie in het systeem

1. Toon het pad van je huidige locatie op het systeem.
   - ls -l
2. Ga naar de `/etc` map en controleer opnieuw je huidige pad.
   - cd /etc
3. Keer terug naar je eigen home-map.
   - cd ~
4. Ga naar de `/usr/bin` map en tel hoeveel bestanden er in deze map staan.
    - find /usr/bin -maxdepth  -type -f | wc -l

    1016

---

## 📝 Opdracht 2: Verkenning van verborgen bestanden

1. Gebruik het juiste commando om **alle** bestanden in je home-directory te tonen, inclusief verborgen bestanden.
   - ls -la
2. Wat valt je op aan de namen van verborgen bestanden?
   - die hebben allemaal een . voor hun naam
3. Open het bestand `.bashrc` met een eenvoudige tekstlezer zoals `nano` of `less`. Zoek naar regels die beginnen met `alias`.

```linux
# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    #alias grep='grep --color=auto'
    #alias fgrep='fgrep --color=auto'
    #alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
#alias ll='ls -l'
#alias la='ls -A'
#alias l='ls -CF'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi
```

---

## 📝 Opdracht 3: Eenvoudige bestandsmanipulatie

1. Maak een nieuwe lege map aan in je home-directory met de naam `testmap`.
   - mkdir testmap
2. Ga naar deze map en maak een leeg bestand aan met de naam `oefening.txt`.
   - cd testmap
   - touch oefening.txt
3. Kopieer het bestand naar je home-directory en hernoem het tegelijk naar `kopie.txt`.
   - cp oefening.txt /home/student/kopie.txt
4. Verwijder het originele bestand in `testmap`.
   - rm /home/student/testmap/oefening.txt

---

## 📝 Opdracht 4: Bestanden verkennen

1. Toon de inhoud van `/etc/hostname`.
   - cat /etc/hostname
        - debiandewindt
2. Toon de eerste 5 regels van het bestand `/etc/passwd`.
   - student@debiandewindt:~/testmap$ cat /etc/passwd | head -5
     root:x:0:0:root:/root:/bin/bash
     daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
     bin:x:2:2:bin:/bin:/usr/sbin/nologin
     sys:x:3:3:sys:/dev:/usr/sbin/nologin
     sync:x:4:65534:sync:/bin:/bin/sync

---

## 📝 Opdracht 5: Systeembeheer met reboot/shutdown

1. Herstart het systeem via een correct commando (gebruik `sudo` indien nodig).
   - sudo reboot
2. Zet het systeem uit via een commando met 1 minuut vertraging.
   - sudo shutdown 1
