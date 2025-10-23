# Joystick 

## joystick_uitlezen

Om de waarden van de joystick in te lezen, hebben we een code geschreven die de toestand van de schakelaars van de joystick doorstuurt naar de ESP32. Deze toestanden worden vervolgens weergegeven in de Serial Monitor. De volgende stap is om de besturing aan te passen, zodat we met de joystick vooruit en achteruit kunnen rijden, en naar links en rechts kunnen sturen.

![filmpje_joystick](./afbeeldingen/IMG_0028.mp4)


## voor-achteruit_code
In deze code hebben we de vooruit/achteruitfunctie, die oorspronkelijk door de joystick werd aangestuurd, vervangen door de ESP32. De ESP32 beslist nu zelf of de auto vooruit of achteruit rijdt. Dit gebeurt via twee pinnen die hoog worden gezet; afhankelijk van welke pin hoog staat, zal de auto vooruit of achteruit bewegen.
