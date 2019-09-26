# Asynchronmaschine Datenerfassung und -auswertung

## Klasse asm:

### init:
- liest wichtige Parameter ein (Modus, Phasenzahl, Nennspannung, Nennstrom)
 + Modus: 'stardelta' Stern-Dreieck Anlauf
- initialisiert Modus und Maschine

### readData:
- liest Daten von Messgeräten ein 
- formatiert Daten als Array von Strukturen (Zeit, Strom, Spannung)
- schreibt Daten in ein JSON Dokument

### processData:
- liest Daten von einem JSON Dokument
- rechnet den Scheitelwert des Sinus und die Phasenverschiebung des Sinus aus (3 mal für 3 verschiedene Punkte)
- rechnet mit dem Scheitelwert den Effektivwert aus
- (rechnet P,Q und S aus)
- schreibt die errechneten Daten in eine JSON Datei

### getResult: 
- liest die Werte aus der JSON Datei aus
- gibt die Werte in die Konsole aus
- (zeichnet einen Osanna Kreis)