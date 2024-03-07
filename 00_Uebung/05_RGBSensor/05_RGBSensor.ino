// Libraries einbinden
#include "Wire.h"               // für Kommunikation I2C
#include "Adafruit_TCS34725.h"  // für RGB-Sensor


uint16_t red, green, blue, clear;


// Color Sensor-Objekt initialisieren
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

// Setup wird einmal beim Start ausgeführt
void setup() {

  Serial.begin(9600); 
 
  // Überprüfen, ob Color Sensor sich auch zurückmeldet
  if (tcs.begin()){
    // Alles OK
    Serial.println("\nSensor gefunden");
    } else {
    // Kein Sensor gefunden. Programm an dieser Stelle einfrieren
    Serial.println("TCS34725 nicht gefunden ... Ablauf gestoppt!");
    while (1); // Halt!
    }

}

// Loop wird dauernd von oben nach unten durchgegangen
void loop() {

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
  }

  else if ((int(clear) > int(red)) && (int(clear) > int(green)) && (int(clear) > int(blue)) && (int(clear) > 200)) {
    Serial.println("\nWeiss");
  }

  else if ((int(red) > int(green)) && (int(red) > int(blue) && !(int(clear) > 100))) {
    Serial.println("\nRot");
  }

  else if ((int(green) > int(red)) && (int(green) > int(blue) && !(int(clear) > 100))) {
    Serial.println("\nGrün");
  }

  else if ((int(blue) > int(red)) && (int(blue) > int(green) && !(int(clear) > 100))) {
    Serial.println("\nBlau");
  }

  else {
    Serial.println("\nNICHT ERKANNT"); 
  }

//TODO: Lade den Code auf den Arduino Nano. Öffne den Serial Monitor (oben rechts Symbol mit Lupe) und schaue ob die Farben richtig erkannt werden
// Du kannst von Hand den Servo drehen und die Kugeln aufladen und dann über den Sensor fahren von Hand  
// TEST: Falls die Farbzuteilung falsch ist, überlege welcher Wert nicht stimmt. Bei Unklarheiten melde dich beim Coach.  
  }













