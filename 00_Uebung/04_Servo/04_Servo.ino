/* Befehle:
pinMode(PIN, OUTPUT oder INPUT); <- definiert den PIN, OUTPUT gibt Strom und INPUT misst den Strom am PIN
digitalWrite(PIN, HIGH oder LOW); <- schaltet eine etwas EIN (HIGH) oder AUS (LOW)
digitalRead(PIN); <- liest den PIN aus. Falls Strom ankommt ist es HIGH und kein Strom LOW
WERT = digitalRead(PIN); <- das HIGH oder LOW welches gemessen wurde, speichern wir in der Variable WERT (Achtung WERT muss bei den Variabel noch definiert werden!)
delay(ZEIT); <- macht eine Pause mit der ZEIT in millisekunden
analogWrite(PIN, 0 bis 255); <- neben digital gibt es auch analoge Signale. Hier gibt es nicht nur HIGH oder LOW, sondern du kannst eine Zahl von 0 bis 255 einsetzen.
*/

// NEU! Wir benutzen den Servo. Mit dem Servo-Motor können verschiedene Richtungen anzeigen lassen.
// um den Servo zu nutzen, müssen wir die Bibliothek aufrufen. Falls beim Upload eine Fehlermeldung kommt, dann melde dich beim Coach

#include <Servo.h> //Die Servobibliothek wird aufgerufen. Sie wird benötigt, damit die Ansteuerung des Servos vereinfacht wird.
 
Servo servoXYZ; //Erstellt für das Programm ein Servo mit dem Namen „servoXYZ“
//TODO: Erstelle noch einen zweiten Servo


void setup()
{
//TODO: Finde heraus an welchem PIN der Servo angeschlossen ist (orange Kabel). Ändere anschliessend das X in die Zahl um.
servoXYZ.attach(X); //mit dem XXX.attach müssen wir definieren, wo der Servo angeschlossen ist. (XXX=Servoname)
//TODO: Definiere hier noch deinen zweiten Servo

 
}

void loop()
{
servoXYZ.write(0); //Position 1 ansteuern mit dem Winkel 0° // TEST: Steuere andere Winkel an.
delay(1000); //Das Programm stoppt für XX Sekunden //TEST: Ändere das Delay - was passiert?

//TODO: Fahre mit dem Servo noch weitere Positionen an
 
//TODO: Welcher Servo ist oben und welcher unten?

//TODO: Servo oben: Finde die 3 Positonen, Kugel holen, Sensor, Kugel abladen (notiere diese auf einem Blatt)

//TODO: Servo unten: Finde die 5 Positionen für die verschiedenen Farben (notiere diese auf einem Blatt)
 
 
}
