void setup() // Hier beginnt das Setup
{ 

pinMode(13, OUTPUT); // Pin 13 wird als Ausgang definiert

} // Hier endet ein Programmabschnitt

void loop() // Hier beginnt das Hauptprogramm
{ 

digitalWrite(13, HIGH); // Schalte die Spannung an Pin 13 ein (LED AN)

delay(1000); // Warte 1000 Millisekunden (1 Sekunde)

digitalWrite(13, LOW); // Schalte die Spannung an Pin 13 aus (LED AUS)

delay(500); // Warte 500 Millisekunden (0.5 Sekunde)

} // Hier endet ein Programmabschnitt