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
const int wartezeit = 300;

void setup() { // setup() wird einmal beim Start des Arduino ausgeführt

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

  // Der Servo hängt am PWM-Pin 3 und 5
  topServo.attach(9);
  bottomServo.attach(3);
}

void loop() {
  topServo.write(PosLager);  //unter lager
  delay(wartezeit);
  topServo.write(PosSensor);  //ueber sensor
  delay(wartezeit);

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
  Serial.print(b);

  // Versuch der Farbfeststellung anhand der r,g,b-Werte.
  // Am besten mit Rot, Grün, Blau anfangen die die Schwellenwerte
  // mit der seriellen Ausgabe entsprechend anpassen
  if ((clearcol > 200) && (r > 0.8) && (g > 1) && (b > 0.7)) {
    Serial.println("\tWeiss");
    bottomServo.write(20);
    delay(wartezeit);
    topServo.write(PosRutsche);  
    delay(wartezeit);
  } else if ((clearcol < 200) && (r > 1.2) && (g < 1) && (b < 0.8)) {
    Serial.println("\tRot");
    bottomServo.write(50);
    delay(wartezeit);
    topServo.write(PosRutsche);  
    delay(wartezeit);
  } else if ((clearcol < 200) && (r < 1) && (g > 1.2) && (b < 1.1)) {
    Serial.println("\tGrün");
    bottomServo.write(80);
    delay(wartezeit);
    topServo.write(PosRutsche);  
    delay(wartezeit);
  } else if ((clearcol < 200) && (r > 0.6) && (g > 0.9) && (b > 1.2)) {
    Serial.println("\tBlau");
    bottomServo.write(115);
    delay(wartezeit);
    topServo.write(PosRutsche);  
    delay(wartezeit);
  } else if ((clearcol < 100) && (r < 1.1) && (g < 1.2) && (b < 1.1)) {
    Serial.print("\tSchwarz");
    bottomServo.write(150);
    delay(wartezeit);
    topServo.write(PosRutsche);  
    delay(wartezeit);
  }
  // Wenn keine Regel greift
  else {
    Serial.println("\tNICHT ERKANNT");
  }
}
