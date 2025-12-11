# Uitleg Elektrisch schema

## Joystick
Alle blauwe kabels zijn datakabels die je op de volgende pinnen soldeert:

- pin 25 voor vooruit
- pin 21 voor achteruit
- pin 22 voor links
- pin 17 voor rechts

Het maakt niet uit hoe je de joystick positioneert, zolang je logica maar overeenkomt met de gewenste richtingen.
Alle zwarte kabels gaan naar de GND van je ESP.

## H-brug
De rode kabels zijn de voedingen. Je kunt zien dat er twee afzonderlijke voedingen zijn: de voeding van de ESP (5V), die je gebruikt om de H-brug van stroom te voorzien, en de voeding van de auto. Deze laatste sluit je aan op de dc converter die je aansluit op de voeding van de auto(24V)

Daarnaast zie je nog twee groene kabels. Deze dienen om de H-brug aan te sturen zodat deze kan schakelen tussen links- en rechtsom draaien:

- pin 27 voor DN1
- pin 26 voor DN2
## Auto 
Bij de auto zie je dat je twee kabels moet aansluiten. Dit komt doordat je de originele vooruit/achteruit-joystick vervangt door je eigen joystick. Je sluit het als volgt aan:

- pin 2 op de gele kabel in de auto
- pin 15 op de groene kabel

Daarnaast blijft er nog een zwarte kabel over in de auto; deze sluit je gewoon aan op de GND van je ESP.

## Esp

Om de ESP te voeden hebben we een DC-converter met USB-aansluiting aangeschaft, zodat we de ESP rechtstreeks kunnen aansluiten. Deze converter zou normaal tot 24 V moeten werken, maar tijdens onze tests viel hij al uit bij 22 V. Daarom hebben we een extra DC-converter van 24 V naar 12 V gekocht, die we bovendien gebruiken om de motor van stroom te voorzien.