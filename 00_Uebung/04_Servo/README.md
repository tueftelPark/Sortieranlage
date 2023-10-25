# Übung Servo

Erweitere den Code so dass mit dem Servo neue Positionen angefahren werden.


</br>

<h3>Befehlsliste</h3>

<ul>
<li>pinMode(PIN, OUTPUT oder INPUT); <- definiert den PIN, OUTPUT gibt Strom und INPUT misst den Strom am PIN</li>
<li>digitalWrite (PIN, HIGH oder LOW); <- schaltet eine etwas EIN (HIGH) oder AUS (LOW)</li>
<li>digitalRead(PIN); <- liest den PIN aus. Falls Strom ankommt ist es HIGH und kein Strom LOW</li>
<li>WERT = digitalRead(PIN); <- das HIGH oder LOW welches gemessen wurde, speichern wir in der Variable WERT (Achtung WERT muss bei den Variabel noch definiert werden!)</li>
<li>delay(ZEIT); <- macht eine Pause mit der ZEIT in millisekunden</li>
<li>analogWrite(PIN, 0 bis 255); <- neben digital gibt es auch analoge Signale. Hier gibt es nicht nur HIGH oder LOW, sondern du kannst eine Zahl von 0 bis 255 einsetzen.</li>
</ul> 
</br>
<h3>Neu</h3>
 Wir benutzen den Servo. Mit dem Servo-Motor können verschiedene Richtungen anzeigen lassen.
Um den Servo zu nutzen, müssen wir die Bibliothek aufrufen. Falls beim Upload eine Fehlermeldung kommt, dann melde dich beim Coach

</br>
</br>

<div style="text-align:center;">
  <img src="https://github.com/tueftelPark/Einfuehrung/assets/113671718/55ef706e-bb0e-4ddd-87bc-ab2793da5086" alt="Beschreibung des Bildes">
</div>

