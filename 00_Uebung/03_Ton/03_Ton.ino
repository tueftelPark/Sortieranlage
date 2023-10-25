/* Befehle:
pinMode(PIN, OUTPUT oder INPUT); <- definiert den PIN, OUTPUT gibt Strom und INPUT misst den Strom am PIN
digitalWrite(PIN, HIGH oder LOW); <- schaltet eine etwas EIN (HIGH) oder AUS (LOW)
digitalRead(PIN); <- liest den PIN aus. Falls Strom ankommt ist es HIGH und kein Strom LOW
WERT = digitalRead(PIN); <- das HIGH oder LOW welches gemessen wurde, speichern wir in der Variable WERT (Achtung WERT muss bei den Variabel noch definiert werden!)
delay(ZEIT); <- macht eine Pause mit der ZEIT in millisekunden
*/

//Die Erzeugung des Tones basiert maßgeblich auf dem Befehl „tone(x, y)“, 
//wobei der x-Wert den Pin angibt, an dem der Lautsprecher mit der positiven Seite angeschlossen ist und der y-Wert, der die Tonhöhe angibt.

/*-> NEU: Wir lernen Variabeln! Eine Variabel ist ein Wort welche wir anstelle einer Zahl verwenden können
mit int sagen wir dem Arduino, dass es sich um eine Zahl handelt. int Taster = 6; bedeutet wir geben dem Wort Taster die Zahl 6.
Jedes Mal wenn wir das Wort Taster nutzen, dann nimmt das Arduino die Zahl 6. In unserem Fall ist die Zahl 6 der PIN an welchem
der Taster angeschlossen ist.
*/

//Definiere zuerst die Variabeln
int Taster = PIN ; //TODO: PIN an welchem der Taster angeschlossen ist - muss mit Zahl ergänzt werden
int Piezo = PIN; //TODO: PIN an welchem der Piezo angeschlossen ist - muss mit Zahl ergänzt werden
int Tasterstatus=0; // nicht ändern. Dies ist ein Startwert und wird definiert damit das Arduino weiss, dass es sich im eine Zahl handelt.
int Spielzeit = MILLISEKUNDEN; //TODO: Millisekunden anpassen. hier definieren wir die Zeit im Befehl delay(ZEIT) - den kennst du noch von der LED Übung! 

void setup()
{
pinMode(Taster, INPUT); // Hier nutzen wir das Wort Taster als PIN-Nummer welche oben definiert ist in den Variabeln 
  // und der Taster in ein Input, da wir den Strom messen am PIN
pinMode(XXXX, mode); // TODO: Nutze hier die Variabel für den Piezo und der Piezo gibt einen Ton aus. Ist es ein INPUT oder OUTPUT?
}

void loop()
{
Tasterstatus = digitalRead(Taster); // hier lesen wir den PIN aus mit digitalRead(PIN) und speichern den Wert in Tasterstatus
// NEU!! Wir lernen if/else - wenn das passiert mache das (if) und anonsten das andere (else)
if (Tasterstatus == HIGH) // Wenn der Taster gedrückt ist... also wenn der PIN Strom bekommt, dann ist das Signal HIGH
{
tone(Piezo, 300); // …spiele diesen Ton...
delay(XXXX); //TODO: …und zwar so lange, wie die Spielzeit definiert ist... füge hier die Variabel für die Zeit hinzu
noTone(Piezo); // Ton abschalten
}
else {
  // wenn nichts gedrückt wird, mache nichts
}
}

