# Oefenreeks 1: Protocollen

Vervang `...` in de onderstaande vragen door jouw antwoord.

# Oefening 1

Via een link surf je naar http://localhost:8080/friendships/create?my_id=100&user_id=200

1. Waarvoor staat deze tekststring?
> dit is een url die verwijst naar een locatie op een server in dit geval onze local pc 

2. Welk schema wordt hier gebruikt en wat betekent dat?
> http dit staat voor hypertext transfer protocol

3. Wat is de hostname?
> local host 
4. Welke poort wordt er gebruikt? Wat is de standaardpoort voor een webserver?
> poort 8080

5. Wat is het pad en wat betekent dat juist voor de mappenstructuur op de server?
>sub folder friendship dan naar subfolder create 
men zal dan via de config file van de server verder moeten verwijzen naar de fysieke locatie van de index file.

6. Er is ook een query aanwezig, hoe weten we dit en leg uit welke parameters er doorgegeven worden?
>?my_id=100&user_id=200 het vraagteken is een query 

# Oefening 2

1. Open een terminal en zoek welk IP-adres jouw laptop heeft. Noteer ook welk commando je gebruikt hebt.
> 10.195.209.225 / ipconfig of ipconfig /all

2. Als je surft naar localhost, is dat dan ook dat IP-adres? Of is dit een ander en welke is dat dan?
> nee dit zal verwijzen naar 127.0.0.1

3. Welke Visual Code server extensie gebruik je (bv. "Preview on WebServer" of "Live server")? Welke poort gebruikt jouw server extensie?
> web server dit werkt over poort 8080

# Oefening 3

1. Welke DNS-server gebruikt jouw toestel?

>10.192.72.4 primaire
>10.192.80.2 secundaire
>10.192.80.3 secundaire 


2. Open een terminal en zoek het IP-adres op van wikipedia.org door het volgende commando uit te voeren: `nslookup wikipedia.org`
> C:\Windows\system32> nslookup wikipedia.org
Server:  dnslb.vivesnet.be
Address:  10.192.72.4

Non-authoritative answer:
Name:    wikipedia.org
Addresses:  2a02:ec80:300:ed1a::1
          185.15.59.224

3. Welke informatie kom je te weten?
> de server en het adress 
> de dns naam van de pagina wikipedia.org
> het ipv4 en ipv6 adress 185.15.59.224/2a02:ec80:300:ed1a::1
# Oefening 4

1. Onderzoek de routes tussen jouw toestel en [www.github.com](www.github.com). Plaats ook een screenshot van de console.
> C:\WINDOWS\system32> tracert www.github.com

Tracing route to github.com [140.82.121.3]
over a maximum of 30 hops:

  1     5 ms     2 ms     4 ms  MyModem.technicolor.net [192.168.0.1]
  2     5 ms    11 ms    12 ms  cust-2-128-110-94.dyn.as47377.net [94.110.128.2]
  3    20 ms    15 ms    13 ms  212.65.36.203
  4    14 ms    14 ms    13 ms  81.52.186.121
  5    14 ms    14 ms    16 ms  193.251.132.224
  6    21 ms    23 ms    17 ms  adm-b3-link.ip.twelve99.net [62.115.170.120]
  7     *        *        *     Request timed out.
  8    28 ms    23 ms    25 ms  ffm-bb2-link.ip.twelve99.net [62.115.137.223]
  9     *        *        *     Request timed out.
 10    21 ms    23 ms    19 ms  github-ic-350972.ip.twelve99-cust.net [62.115.182.171]
 11     *        *        *     Request timed out.
 12     *        *        *     Request timed out.
 13    27 ms    30 ms    28 ms  lb-140-82-121-3-fra.github.com [140.82.121.3]

# Oefening 5

1. Maak een tabel met de vaakst voorkomende server responses en categorieën
> Statuscode	    Categorie	                Beschrijving

    1xx	            Informatieve	            De aanvraag is ontvangen, en de verwerking is gaande.
    100	            Continue	                De client mag verder gaan met het verzenden van de verzoekdata.
    101	            Switching Protocols	        De server schakelt over naar het protocol dat de client heeft aangevraagd.

    2xx	            Succesfull	                De aanvraag is succesvol ontvangen, begrepen en verwerkt.
    200	            OK	                        Het verzoek was succesvol.
    201	            Created	                    Het verzoek was succesvol en er is een nieuwe resource aangemaakt.
    202	            Accepted	                Het verzoek is geaccepteerd voor verwerking, maar is nog niet voltooid.
    204	            No Content	                Het verzoek is succesvol, maar er is geen content om te retourneren.

    3xx	            Redirectie	                Er zijn verdere acties nodig om het verzoek te voltooien.
    301	            Moved Permanently	        De aangevraagde resource is permanent verplaatst naar een nieuwe URL.
    302	            Found	                    De aangevraagde resource is tijdelijk beschikbaar op een andere URL.
    304	            Not Modified	            De resource is niet gewijzigd sinds de laatste aanvraag.

    4xx	            Clientfout	                De aanvraag bevatte een fout, waardoor deze niet kan worden verwerkt.
    400	            Bad Request	                De server kon het verzoek niet begrijpen door een syntaxisfout.
    401	            Unauthorized	            Authenticatie is vereist en is mislukt of is nog niet verstrekt.
    403	            Forbidden	                De server begrijpt het verzoek, maar weigert deze uit te voeren.
    404	            Not Found	                De server kan de aangevraagde resource niet vinden.

    5xx	            Serverfout	                De server heeft een fout gemaakt bij het verwerken van het verzoek.
    500	            Internal Server Error	    Er is een interne serverfout opgetreden.
    502	            Bad Gateway	                De server ontving een ongeldige respons van de upstream server.
    503	            Service Unavailable	        De server is momenteel niet beschikbaar.


Elke statuscode geeft een specifiek type reactie aan en biedt informatie over hoe het verzoek is afgehandeld. De 1xx codes zijn informatief en worden zelden door gebruikers gezien, terwijl 2xx codes een succesvolle verwerking aanduiden. De 3xx codes wijzen op redirectie, 4xx codes op fouten door de client en 5xx codes op serverfouten.