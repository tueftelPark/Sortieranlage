//Die Erzeugung des Tones basiert maßgeblich auf dem Befehl „tone(x, y)“, 
//wobei der x-Wert den Pin angibt, an dem der Lautsprecher mit der positiven Seite angeschlossen ist und der y-Wert, der die Tonhöhe angibt.

//Definiere zuerst die Variabeln
int Taster=6;
int Tasterstatus=0;
int Piezo = 8;
int Spielzeit = 1000;

void setup()
{
pinMode(Taster, INPUT);
pinMode(Piezo, OUTPUT);
}

void loop()
{
Tasterstatus = digitalRead(Taster);
if (Tasterstatus == HIGH) // Wenn der Taster gedrückt ist...
{
tone(Piezo, 300); // …spiele diesen Ton...
delay(Spielzeit); //…und zwar so lange, wie die Spielzeit definiert ist...
noTone(Piezo); // Ton abschalten
}
else {
  // wenn nichts gedrückt wird mache nichts
}
}

