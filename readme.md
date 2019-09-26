# Asynchronmaschine Datenerfassung und -auswertung

Das Programm f�hrt eine ASM hoch, misst Strom und Spannung und gibt den Osanna Kreis der ASM aus.
Es gibt eine Einstellung bei dem das Programm die Maschine in Stern-Dreieck hochf�hrt
Der Kurzschlusspunkt ist in den ersten 100 ms, w�hrend die Maschine anl�uft
Der Leerlaufpunkt ist nachdem die Maschine hochgefahren ist
Der dritte Punkt ist w�hrend die Maschine hochfahrt

## Klasse asm:

### public:

#### init:
- liest wichtige Parameter ein (Modus, Phasenzahl, Nennspannung, Nennstrom)
	+ Modus: 
		* 'stardelta' Stern-Dreieck Anlauf
		* 'startup' normale Messung, f�hrt Maschine nach Messung herunter
- initialisiert Modus und Maschine
	+ startet Maschine
	+ startet Messung

#### readData:
- liest Daten von Messger�ten ein 
- formatiert Daten als Array von Strukturen (Zeit, Strom, Spannung)
- schreibt Daten in ein JSON Dokument

#### processData:
- liest Daten von einem JSON Dokument
- rechnet den Scheitelwert des Sinus und die Phasenverschiebung des Sinus aus (3 mal f�r 3 verschiedene Punkte)
- rechnet mit dem Scheitelwert den Effektivwert aus
- (rechnet P,Q und S aus)
- schreibt die errechneten Daten in eine JSON Datei

#### getResult: 
- liest die Werte aus der JSON Datei aus
- gibt die Werte in die Konsole aus
- (zeichnet einen Osanna Kreis)

### private:

#### struct Data
- hat Strom (double), Spannung (double) und Time (uint)

#### readJSON
- liest aus der JSON Dateien ein 
- return Array von Strukturen
- return String

#### writeJSON 
- param: String, Array (overload)
- schreibt String bzw Array in eine JSON
- return null

#### getData
- liest Daten von dem Messger�t ein 
- formatiert Daten als Struktur Data

#### splitSine
- liest Daten von JSON ein
- unterteilt den Sinus nach Timestamp
- return timestamp start1, stop1, start2, stop2, start1, stop1

### getPosWave
- kriegt von splitSine params
- schaut wann >0
- schaut wann steigt
- schaut ob volle Halbwelle
- return Array pos Welle

#### getParams
- kriegt Daten von getPosWave
- rechnet Frequenz aus
- rechnet Phasenverschiebung (Delta Nulldurchgang) mit f aus
- berechnet peak mit eine positive Halbwelle suchen und von der das Max ist peak
- berechnet Effektivwert aus Peak
- return Effektivwert I, U, Phi