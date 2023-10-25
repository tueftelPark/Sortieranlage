# Übung Ton

Ergänze den Code so dass der Buzzer verschiedene Töne ausgibt
</br>
</br>

<h3>Befehlsliste</h3>

<ul>
<li>pinMode(PIN, OUTPUT oder INPUT); <- definiert den PIN, OUTPUT gibt Strom und INPUT misst den Strom am PIN</li>
<li>digitalWrite (PIN, HIGH oder LOW); <- schaltet eine etwas EIN (HIGH) oder AUS (LOW)</li>
<li>digitalRead(PIN); <- liest den PIN aus. Falls Strom ankommt ist es HIGH und kein Strom LOW</li>
<li>WERT = digitalRead(PIN); <- das HIGH oder LOW welches gemessen wurde, speichern wir in der Variable WERT (Achtung WERT muss bei den Variabel noch definiert werden!)</li>
<li>delay(ZEIT); <- macht eine Pause mit der ZEIT in millisekunden</li>
</ul> 
</br>

Die Erzeugung des Tones basiert maßgeblich auf dem Befehl „tone(x, y)“, 
wobei der x-Wert den Pin angibt, an dem der Lautsprecher mit der positiven Seite angeschlossen ist und der y-Wert, der die Tonhöhe angibt.

<h3>NEU</h3>

Wir lernen Variabeln! Eine Variabel ist ein Wort welche wir anstelle einer Zahl verwenden können
mit int sagen wir dem Arduino, dass es sich um eine Zahl handelt. int Taster = 6; bedeutet wir geben dem Wort Taster die Zahl 6.
Jedes Mal wenn wir das Wort Taster nutzen, dann nimmt das Arduino die Zahl 6. In unserem Fall ist die Zahl 6 der PIN an welchem
der Taster angeschlossen ist.



<div style="text-align:center;">
  <img src="https://github.com/tueftelPark/Einfuehrung/assets/113671718/0363a440-d90e-42b6-b6ad-312082f1d090" alt="Beschreibung des Bildes">
</div>

