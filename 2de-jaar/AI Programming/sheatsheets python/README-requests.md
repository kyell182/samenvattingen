# cheatsheet requests-commands

<!-- Eenvoudige HTTP-client voor GET/POST, headers, params, sessions en JSON-responses (niet stdlib) -->
> Eenvoudige HTTP-client voor GET/POST, headers, params, sessions en JSON-responses (niet stdlib)

```python
import requests
```

## Basis HTTP requests

```python
r = requests.get("https://example.com")                         # GET request
r = requests.post("https://example.com", data={"key":"value"})  # POST request
r = requests.put("https://example.com", data={"key":"value"})   # PUT request
r = requests.delete("https://example.com")                      # DELETE request
r = requests.head("https://example.com")                        # Alleen headers ophalen
r = requests.options("https://example.com")                     # Opties ophalen


# GET request met query parameters
r = requests.get("https://httpbin.org/get", params={"search": "python"})   # GET met query-params; params worden in URL gezet
print("GET:", r.status_code, r.json())                                     # print status en JSON-body (r.json() kan falen als geen JSON)

# POST request met data
r = requests.post("https://httpbin.org/post", data={"username": "user", "password": "pass"})  # POST met form-data (use json= voor JSON-body)
print("POST:", r.status_code, r.json())                                                       # toon status en geparste JSON

# PUT request om data bij te werken
r = requests.put("https://httpbin.org/put", data={"key": "new_value"})   # PUT request (update), hier met form-data
print("PUT:", r.status_code, r.json())                                   # toon antwoord

# DELETE request
r = requests.delete("https://httpbin.org/delete")  # Verwijder-resource request
print("DELETE:", r.status_code, r.json())          # vaak lege body, controleer status

# HEAD request (alleen headers)
r = requests.head("https://httpbin.org/get")       # HEAD vraagt alleen headers op, geen body
print("HEAD headers:", r.headers)                  # toon ontvangen headers

# OPTIONS request (om HTTP-methodes te controleren)
r = requests.options("https://httpbin.org/get")         # OPTIONS vraagt ondersteunde methods op
print("OPTIONS Allow header:", r.headers.get("Allow"))  # 'Allow' header bevat toegestane methods
```

## Response object

```python
r.status_code                                    # HTTP statuscode (200, 404, ...)
r.text                                           # Response body als string
r.content                                        # Response body als bytes
r.json()                                         # JSON-inhoud (dict)
r.headers                                        # Response headers
r.cookies                                        # Cookies
r.url                                            # Definitief URL (na redirects)
r.history                                        # Lijst van redirects

# Maak een GET request naar een testsite
r = requests.get("https://httpbin.org/get")                 # Voer GET uit en bewaar response

# HTTP statuscode
print("Status code:", r.status_code)                        # 200 = OK, 4xx/5xx = fout

# Response body als string
print("Text (eerste 100 chars):", r.text[:100])             # Body als tekst (leesbaar)

# Response body als bytes
print("Content (eerste 50 bytes):", r.content[:50])         # Raw bytes (voor binaire data)

# JSON-inhoud als dict
print("JSON:", r.json())                                    # Parse JSON naar dict (fout als geen JSON)

# Response headers
print("Headers:", r.headers)                                # Headers dict (Content-Type, etc.)

# Cookies
print("Cookies:", r.cookies)                                # Cookies die server terugstuurt

# Definitief URL (na eventuele redirects)
print("URL:", r.url)                                        # Echte URL na redirects

# Lijst van redirects (als er redirects waren)
print("Redirect history:", r.history)                       # Lijst met eerdere Response objects
```

## Query parameters & headers

```python
params = {"q":"zoekterm"}                                    # query-parameters als dict
r = requests.get("https://example.com", params=params)       # GET met params -> URL krijgt querystring

headers = {"User-Agent": "my-app"}                           # custom headers als dict
r = requests.get("https://example.com", headers=headers)     # stuur headers mee met request

params = {"q": "python"}                                     # zoekterm voorbeeld
r = requests.get("https://httpbin.org/get", params=params)   # httpbin echoert ontvangen params
print("GET met params:", r.url)                              # toon volledige URL inclusief params
print(r.json())                                              # parse en print JSON-response (kan exception geven)

## Custom headers
headers = {"User-Agent": "my-app/1.0"}                       # voorbeeld van User-Agent header
r = requests.get("https://httpbin.org/get", headers=headers) # verzend custom header
print("Custom headers verzonden:", r.request.headers)        # headers die client daadwerkelijk stuurde
print(r.json())                                              # geparste JSON van response
```

## Timeouts & errors

```python
r = requests.get("https://example.com", timeout=5)   # Vraag met timeout: wacht max 5 seconden op antwoord
try:
    r.raise_for_status()                             # Raise HTTPError bij 4xx/5xx statuscodes
except requests.exceptions.HTTPError as e:
    print(e)                                         # Toon de HTTP-fout (status en boodschap)

try:
    # stel timeout in op 2 seconden
    r = requests.get("https://httpbin.org/delay/3", timeout=2)  # Simuleer trage endpoint, verwacht timeout
    r.raise_for_status()                                        # trigger exception bij 4xx/5xx
except requests.exceptions.Timeout:
    print("Request timed out!")                                 # Specifieke afhandeling voor timeouts
except requests.exceptions.HTTPError as e:
    print("HTTP error:", e)                                     # Afhandeling van HTTP-fouten (4xx/5xx)
except requests.exceptions.RequestException as e:
    print("Request error:", e)                                  # Vangt overige request-gerelateerde fouten
```

## Cookies & sessies

```python
s = requests.Session()                                    # Maak een Session: hergebruik verbindingen en bewaar cookies
s.get("https://example.com")                              # Voer een GET uit via de sessie (cookies/headers worden meegestuurd)
s.post("https://example.com/login", data={"u":"pw"})      # POST via de sessie (bv. login); server kan cookie zetten voor volgende
```

**voorbeelden :**

```python
s = requests.Session()                                   # Maak een Session om verbindingen en cookies te hergebruiken

r = s.get("https://httpbin.org/cookies/set?name=value")  # Eerste GET: endpoint zet een cookie; response in r
print("Cookies na set:", r.cookies)                      # Toon cookies die de server in deze response teruggaf (CookieJar)

r = s.get("https://httpbin.org/cookies")                 # Volgende GET: session stuurt eerder ingestelde cookie automatisch mee
print("Alle cookies in sessie:", r.json())               # Print JSON-antwoord met de cookies die de server ontvangt

login_data = {"username": "user", "password": "pass"}    # Voorbereid POST-formulierdata (login-voorbeeld)
r = s.post("https://httpbin.org/post", data=login_data)  # POST via dezelfde sessie (cookies/headers behouden)
print("POST met sessie:", r.json())                      # Toon geparste JSON-response (httpbin echoot verzonden data)
```
