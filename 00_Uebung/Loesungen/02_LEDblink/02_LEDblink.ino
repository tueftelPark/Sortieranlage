void setup() //Wir starten mit dem Setup
{

pinMode(7, OUTPUT); // Pin 7 ist ein Ausgang.
pinMode(8,OUTPUT); // Pin 8 ist ein Ausgang.

}

void loop() // Das Hauptprogramm beginnt
{

digitalWrite(7, HIGH); // Schalte die LED an Pin7 an.

delay(1000); // Warte 1000 Millisekunden.

digitalWrite(7, LOW); // Schalte die LED an Pin7 aus.

digitalWrite(8, HIGH); // Schalte die LED an Pin8 ein.

delay(1000); // Warte 1000 Millisekunden.

digitalWrite(8, LOW); // Schalte die LED an Pin8 aus.
}
