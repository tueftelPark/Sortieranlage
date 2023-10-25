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

void setup()
{
servoXYZ.attach(8); //mit dem XXX.attach müssen wir definieren, wo der Servo angeschlossen ist. (XXX=Servoname)
}

void loop()
{
servoXYZ.write(0); //Position 1 ansteuern mit dem Winkel 0°
delay(1000); //Das Programm stoppt für XX Sekunden 

// Fahre mit dem Servo noch weitere Positionen an
 
}
