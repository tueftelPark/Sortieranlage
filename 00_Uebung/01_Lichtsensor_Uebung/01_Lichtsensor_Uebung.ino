
//TODO: Welche PIN Nummer hat die LED -> schaue dazu auf dem Sensor-Kit und ersetze unten das X mit der Nummer (ohne das D)
int LED = X; //Hier speichern wir eine Zahl (der PINvon unserer LED) auf das Wort LED

void setup() { //Das Setup wird nur einmal ausgeführt -> Beim Start des Arduinos
Serial.begin(9600); //Starte die Kommunikation mit dem Serial Monitor
pinMode(LED,OUTPUT);  //Definiere die LED (PIN X) als OUTPUT (OUTPUT = Arduino gibt Strom an LED) 

}
 
void loop() { //Der Loop-Bereich wird immer wiederholt solange das Arduino läuft
  //TODO: Welche PIN Nummer hat der Licht-Sensor -> schaue dazu auf dem Sensor-Kit und ersetze unten das X mit der Nummer (inklusive das A)
  int licht = analogRead(AX); // lese die Werte aus dem Lichtsensor und speichere diese auf der Variable (Wort) Licht ab.
 
 //TODO: Du kannst jetzt oben dein Arduino auswählen und mit dem Pfeil-Symbol den Code auf das Arduino hochladen (Du musst hier nichts schreiben)

  Serial.print("Helligkeit: "); //Schreibe das Wort Helligkeit: in den Serial Monitor (unten oder oben rechts bei der Lupe öffnen)
  Serial.println(licht); // Schreibt den Wert, welchen wir in der Variabel "licht" gespeichert haben
 
 //TODO: Öffne den Serial Monitor (oben rechts die Lupe) und schaue welche Werte die Helligkeit hat - Versuche jetzt den Code unten anzupassen, damit deine LED leuchtet wenn es dunkel wird.
 if (licht < 2) { //wenn der Licht-Wert kleiner ist als 2, dann mache....
 digitalWrite(LED, HIGH); //schaltet die LED ein
 }
 else { //falls das if nicht zutrifft, dann mache...
 digitalWrite(LED, LOW); //schaltet die LED aus
 }

  delay(100); // Pause zwischen den Messungen in Millisekunden
  
}