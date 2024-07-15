/* Befehle:
pinMode(PIN, OUTPUT oder INPUT); <- definiert den PIN, OUTPUT gibt Strom und INPUT misst den Strom am PIN
analogRead(PIN); <- liest den Wert eines analogen Pins, PIN mit einer Zahl ersetzen, gibt einen Zahlen Wert zurück (je nach dem wie laut es ist)
delay(ZEIT); <- macht eine Pause mit der ZEIT in millisekunden
analogeWrite(PIN, 0 bis 255); <- NEU: neben digital gibt es auch analoge Signale. Hier gibt es nicht nur HIGH oder LOW, sondern eine Zahl von 0 bis 255.
*/


// TODO: Verbinde die RGB LED mit dem Sensorkit. Am Besten verbindest du die [- R G B] Pins mit den Pins [GND 11~ 10~ 9~]. 


// TODO: Speichere die PIN-Nummer der RGB LED unter den Variabeln LEDrot, LEDgruen und LEDblau

// TODO: Farbe rot an Pin XXX -> Wichtig nur PWM(~) nutzen! Auf deinem Arduino sind dies die Nummern mit einer kleinen Welle -> z.B. 10~
int LEDrot = XX; 
// TODO: Farbe gruen an Pin XX -> Wichtig nur PWM(~) nutzen! 
int LEDgruen = XX; 
// TODO: Farbe blau an Pin XX -> Wichtig nur PWM(~) nutzen! 

int RotAn = 255; //TEST: Variable für das Einschalten
int GruenAn = 255; //TEST: Variable für das Einschalten
int BlauAn = 255; //TEST: Variable für das Einschalten

//TODO: Ersetze das Z mit der Zahl zum Ausschalten

int RotAus = Z; //TEST: Variable für das Ausschalten
int GruenAus = Z; //TEST: Variable für das Ausschalten
int BlauAus = Z; //TEST: Variable für das Ausschalten


void setup() { //Das Setup wird nur einmal ausgeführt -> Beim Start des Arduinos

//TODO: Definiere den richtigen Pin für die rote LED als Ausgang. Ersetze YY mit INPUT oder OUTPUT
pinMode(LEDrot, YY);
//TODO: Definiere den richtigen Pin für die grüne LED als Ausgang.
pinMode(XX, YY);
//TODO: Definiere den richtigen Pin für die blaue LED als Ausgang.

Serial.begin(9600); //Starte die Kommunikation mit dem Serial Monitor

}

void loop() { //Der Loop-Bereich wird immer wiederholt solange das Arduino läuft

//TODO: Welche PIN Nummer hat der Geräuschsensor -> schaue dazu auf dem Sensor-Kit und ersetze unten das X mit der Nummer (inklusive das A)
  int sound = analogRead(AX); // lese die Werte aus dem Geräuschsensor und speichere diese auf der Variable (Wort) Licht ab.

 //TODO: Du kannst jetzt oben dein Arduino auswählen und mit dem Pfeil-Symbol (upload) den Code auf das Arduino hochladen (Du musst hier nichts schreiben)
 
  Serial.println(sound); //print the value of sound sensor

// TODO: Öffne den Serial Monitor (oben rechts die Lupe) und schaue welche Werte der Sound hat 
// -> Versuche den Code unten anzupassen, damit du mit schnipsen, reden und klatschen die verschiedenen Farben zum leuchten bringst

  if (sound < 100) { //wenn der Sound-Wert kleiner als 100 ist, dann mache...
    analogWrite(LEDrot, RotAn); //Schalte die rote LED an
    delay(1000); //LED leuchtet für 1 Sekunde
    analogeWrite(LEDrot, RotAus); //schaltet die rote LED wieder aus
  }

  else if (sound < 500) { //wenn der Sound-Wert kleiner als 500 ist, dann mache...
    analogeWrite(LEDgruen, GruenAn); //Schalte die grüne LED an
    delay(1000);
    analogeWrite(LEDgruen, GruenAus);
  }

  else { //falls das if nicht zutrifft, dann mache...
    analogeWrite(LEDblau, BlauAn); //Schalte die blaue LED an
    delay(1000);
    analogeWrite(LEDblau, BlauAus);
  }
  
}
