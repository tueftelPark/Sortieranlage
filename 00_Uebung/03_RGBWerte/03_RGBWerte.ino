/*
AUFGABE:
In diesem Code geht es darum, die RGB-Werte der einzelnen Holzkugeln herauszufinden.
Du brauchst:
- Papier und Schreibzeug
- Die Holzkugeln in allen Farben. 1 pro Farbe genügt.
- natürlich noch die Sortieranlage

Lese den Code und die Kommentare durch und versuche die Logik dahinter zu verstehen.
Du must nich jeden Satz genau verstehen - nur ungefähr was wann passiert.

Lasse die Messungen starten:
- indem du die Sortieranlage anschliess
- das Arduino auswählst (Arduino Nano)
- Hochlädst (Pfeil Symbol oben links)
- und anschliessend den Serial Monitor oben rechts öffnest

Du siehst jetzt Werte notiere alle 4 Werte für eine Farbe (suche einen ungefähren Durschnitt) Du musst nicht alle Werte aufschreiben!
Die Werte, welche du notiert hast, sind später noch wichtig und du musst diese bei der nächsten Übung ergänzen.
*/

#include "Servo.h"
#include "Wire.h"
#include "Adafruit_TCS34725.h"

Servo topServo;
Servo bottomServo;

// Color Sensor-Objekt initialisieren
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

int frequency = 0;
int color = 0;
const int PosLager = 180;
const int PosSensor = 90;
const int PosRutsche = 0;
const int wartezeit = 5000;

void setup() {  // setup() wird einmal beim Start des Arduino ausgeführt

  // Serielle Kommunikation zur Ausgabe der Wert im seriellen Monitor
  Serial.begin(9600);
  Serial.println("I'm ready!!");

  // Überprüfen, ob Color Sensor sich auch zurückmeldet
  if (tcs.begin()) {
    // Alles OK
    Serial.println("Sensor gefunden");
  } else {
    // Kein Sensor gefunden. Programm an dieser Stelle einfrieren
    Serial.println("TCS34725 nicht gefunden ... Ablauf gestoppt!");
    while (1)
      ;  // Halt!
  }

  // Der Servo hängt am Pin 9 und 3
  topServo.attach(9);
  bottomServo.attach(3);
}

void loop() { //Der Loop-Bereich wird immer wiederholt solange das Arduino läuft

  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  topServo.write(PosLager);  //unter lager
  delay(wartezeit);
  topServo.write(PosSensor);  //ueber sensor
  delay(wartezeit);
  for (int i = 0; i <= 10; i++) { //Diese nennt man eine for-Schlaufe, wir starten bei i = 0 und hören auf bei i=10 und bei jedem Durchgang wird ein i dazugezählt (i++) somit gehen wir 10mal durch diese Schlaufe

    // Der Sensor liefert Werte für R, G, B und einen Clear-Wert zurück
    uint16_t clearcol, red, green, blue;
    float average, r, g, b;
    tcs.getRawData(&red, &green, &blue, &clearcol);

    // Mein Versuch einer Farbbestimmung für
    // die 5 M&M-Farben Rot, Grün, Blau, Orange und Gelb

    // Durchschnitt von RGB ermitteln
    average = (red + green + blue) / 3;
    // Farbwerte durch Durchschnitt,
    // alle Werte bewegen sich jetzt rund um 1
    r = red / average;
    g = green / average;
    b = blue / average;

    // Clear-Wert und r,g,b seriell ausgeben zur Kontrolle
    // r,g und b sollten sich ca. zwischen 0,5 und 1,5
    // bewegen. Sieht der Sensor rot, dann sollte r deutlich über 1.0
    // liegen, g und b zwischen 0.5 und 1.0 usw.
    Serial.print("\tClear:");
    Serial.print(clearcol);
    Serial.print("\tRed:");
    Serial.print(r);
    Serial.print("\tGreen:");
    Serial.print(g);
    Serial.print("\tBlue:");
    Serial.println(b);

  } //Schlaufe fertig

  bottomServo.write(80); //Servo in Position fahren
  delay(wartezeit);
  topServo.write(PosRutsche); //Kugel nach unten auswerfen
  delay(5000);
}