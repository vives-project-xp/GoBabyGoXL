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
De rode kabels zijn de voedingen. Je kunt zien dat er twee afzonderlijke voedingen zijn: de voeding van de ESP (5V), die je gebruikt om de H-brug van stroom te voorzien, en de voeding van de auto. Deze laatste sluit je rechtstreeks aan op de batterij en voedt de motor zelf, die op 24V werkt.

Daarnaast zie je nog twee groene kabels. Deze dienen om de H-brug aan te sturen zodat deze kan schakelen tussen links- en rechtsom draaien:

- pin 27 voor DN1
- pin 26 voor DN2
## Auto 
Bij de auto zie je dat je twee kabels moet aansluiten. Dit komt doordat je de originele vooruit/achteruit-joystick vervangt door je eigen joystick. Je sluit het als volgt aan:

- pin 2 op de gele kabel in de auto
- pin 15 op de groene kabel

Daarnaast blijft er nog een zwarte kabel over in de auto; deze sluit je gewoon aan op de GND van je ESP.