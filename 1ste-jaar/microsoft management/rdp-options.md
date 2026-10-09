# RDP Configuratie Overzicht

Dit overzicht toont alle RDP-opties in deze configuratie, met hun huidige waarde en betekenis.

| Categorie | Parameter | Huidige waarde | Mogelijke waarden | Uitleg |
| :-- | :-- | :-- | :-- | :-- |
| Scherm | `screen mode id` | `i:2` | `1` = Venster<br>`2` = Volledig scherm | Bepaalt of RDP in venster of full-screen opent. |
| Scherm | `use multimon` | `i:0` | `0` = Enkel scherm<br>`1` = Meerdere monitoren | Schakelt ondersteuning voor meerdere monitoren in/uit. |
| Scherm | `desktopwidth` | `i:1920` | Positief getal (pixels) | Breedte van de remote sessie in pixels. |
| Scherm | `desktopheight` | `i:1080` | Positief getal (pixels) | Hoogte van de remote sessie in pixels. |
| Scherm | `session bpp` | `i:32` | `16`, `24`, `32` | Kleurdiepte van de sessie (hoger = mooiere kleuren, meer bandbreedte). |
| Prestaties | `connection type` | `i:7` | `2` = Breedband<br>`7` = LAN | Optimalisatieprofiel op basis van netwerksnelheid. |
| Prestaties | `disable wallpaper` | `i:0` | `0` = Achtergrond tonen<br>`1` = Achtergrond verbergen | Achtergrond uitschakelen kan prestaties verbeteren. |
| Prestaties | `allow font smoothing` | `i:0` | `0` = Uit<br>`1` = Aan | Maakt tekstweergave vloeiender op afstand. |
| Prestaties | `disable themes` | `i:0` | `0` = Thema's aan<br>`1` = Thema's uit | Visuele thema's uitschakelen voor extra snelheid. |
| Prestaties | `compression` | `i:1` | `0` = Uit<br>`1` = Aan | Comprimeert dataverkeer om bandbreedte te besparen. |
| Redirection | `audiomode` | `i:0` | `0` = Audio lokaal afspelen<br>`1` = Audio op remote pc<br>`2` = Geen audio | Stuurt geluid naar lokaal toestel, remote toestel, of schakelt uit. |
| Redirection | `redirectclipboard` | `i:1` | `0` = Uit<br>`1` = Aan | Maakt kopieren/plakken tussen lokale en remote pc mogelijk. |
| Redirection | `redirectprinters` | `i:1` | `0` = Uit<br>`1` = Aan | Lokale printers beschikbaar maken in de remote sessie. |
| Redirection | `keyboardhook` | `i:2` | `0` = Sneltoetsen lokaal<br>`1` = Sneltoetsen remote<br>`2` = Alleen remote in full-screen | Bepaalt waar toetsencombinaties zoals `Alt+Tab` terechtkomen. |
| Beveiliging | `full address` | `s:PC...` | Hostnaam of IP-adres | Doelcomputer waar de RDP-verbinding naartoe gaat. |
| Beveiliging | `authentication level` | `i:0` | `0` = Geen controle<br>`1` = Waarschuwen<br>`2` = Blokkeren | Hoe streng identiteit en certificaat van de remote host gecontroleerd worden. |
| Beveiliging | `negotiate security` | `i:1` | `0` = Uit<br>`1` = Aan | Laat client/server automatisch beste beveiligingslaag kiezen. |
| Beveiliging | `gatewayusagemethod` | `i:4` | `0` = Geen gateway<br>`1` = Altijd via gateway<br>`4` = Automatisch | Bepaalt wanneer een RD Gateway gebruikt wordt. |