# Asynchronmaschine Datenerfassung und -auswertung

## Klasse asm:

### init:
- liest wichtige Parameter ein (Modus, Phasenzahl, Nennspannung, Nennstrom)
	+ Modus: 
		* 'stardelta' Stern-Dreieck Anlauf
		* 'startup' normale Messung, f�hrt Maschine nach Messung herunter
- initialisiert Modus und Maschine
	+ startet Maschine
	+ startet Messung

### readData:
- liest Daten von Messger�ten ein 
- formatiert Daten als Array von Strukturen (Zeit, Strom, Spannung)
- schreibt Daten in ein JSON Dokument

### processData:
- liest Daten von einem JSON Dokument
- rechnet den Scheitelwert des Sinus und die Phasenverschiebung des Sinus aus (3 mal f�r 3 verschiedene Punkte)
- rechnet mit dem Scheitelwert den Effektivwert aus
- (rechnet P,Q und S aus)
- schreibt die errechneten Daten in eine JSON Datei

### getResult: 
- liest die Werte aus der JSON Datei aus
- gibt die Werte in die Konsole aus
- (zeichnet einen Osanna Kreis)