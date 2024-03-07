// Libraries einbinden
#include "Servo.h"              // für Servos
#include "Wire.h"               // für Kommunikation I2C
#include "Adafruit_TCS34725.h"  // für RGB-Sensor


// Servo-Objekt initialisieren und Variabeln definieren
Servo bottomservo;                  // Servo Rutsche
Servo topservo;                 // Servo Löffel
uint16_t red, green, blue, clear;


// Color Sensor-Objekt initialisieren
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);


//TODO: Ändere die Positionen so, dass der untere Servo an die richtige Stelle fährt um die Kugeln abzuladen.

const int PosSchwarz = ?;
const int PosBlau = ?;
const int PosGruen = ?;
const int PosRot = ?;
const int PosWeiss = ?;
const int PosLeer = ?;

//TODO: Ändere die Positionen so, dass der obere Servo an die richtige Stelle fährt um die Kugeln abzuholen und freizugeben.

const int PosLager = ?;
const int PosSensor = ?;
const int PosRutsche = ?;



// Setup wird einmal beim Start ausgeführt
void setup() {

  Serial.begin(9600); // öffnet den serial port für die Kommunikation zum PC, Datenrate wird auf 9600 bps eingestellt
 
  // Überprüfen, ob Color Sensor sich auch zurückmeldet
  if (tcs.begin()){
    // Alles OK
    Serial.println("\nSensor gefunden");
    } else {
    // Kein Sensor gefunden. Programm an dieser Stelle einfrieren
    Serial.println("TCS34725 nicht gefunden ... Ablauf gestoppt!");
    while (1); // Halt!
    }

// TODO: Servo Pins definieren (organge Kabel)
  bottomservo.attach(?); 
  topservo.attach(?);
  

  
  // Servos in Grundstellung fahren
  bottomservo.write(90);
  topservo.write(180);
  delay(2000);
  
}








// Loop wird dauernd von oben nach unten durchgegangen
void loop() {


  topservo.write(PosLager); //unter lager
  delay(1500);
  topservo.write(PosSensor); //ueber sensor
  delay(1000);  
  tcs.getRawData(&red, &green, &blue, &clear); //RGB Werte auslesen
  delay(1000);  
  

 
  Serial.print("\tRed:"); Serial.print(int(red));
  Serial.print("\t\tGreen:"); Serial.print(int(green));
  Serial.print("\tBlue:"); Serial.print(int(blue));
  Serial.print("\t\tCl:"); Serial.print(int(clear));
  delay(500);
  Serial.print("\n");


  if (( (int(clear) < 40))) {
    Serial.println("\nSchwarz");
    bottomservo.write(PosSchwarz);
  }

  else if ((int(clear) > int(red)) && (int(clear) > int(green)) && (int(clear) > int(blue)) && (int(clear) > 200)) {
    Serial.println("\nWeiss");
    bottomservo.write(PosWeiss);
  }

  else if ((int(red) > int(green)) && (int(red) > int(blue) && !(int(clear) > 100))) {
    Serial.println("\nRot");
    bottomservo.write(PosRot);
  }

  else if ((int(green) > int(red)) && (int(green) > int(blue) && !(int(clear) > 100))) {
    Serial.println("\nGrün");
    bottomservo.write(PosGruen);
  }

  else if ((int(blue) > int(red)) && (int(blue) > int(green) && !(int(clear) > 100))) {
    Serial.println("\nBlau");
    bottomservo.write(PosBlau);
  }

  else {
    Serial.println("\nNICHT ERKANNT"); 
    bottomservo.write(PosLeer);
  }

  delay(1000);
  topservo.write(PosRutsche); //ueber rutsche
  delay(1000);
  }













