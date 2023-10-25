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

servoXYZ.write(90); //Position 2 ansteuern mit dem Winkel 90°
delay(1000); //Das Programm stoppt für XX Sekunden

servoXYZ.write(180); //Position 3 ansteuern mit dem Winkel 180°
delay(1000);//Das Programm stoppt für XX Sekunden

servoXYZ.write(20); //Position 4 ansteuern mit dem Winkel 20°
delay(1000);//Das Programm stoppt für XXX Sekunden

}