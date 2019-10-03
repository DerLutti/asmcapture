/*
ASM library
asmcapture.cpp
created by
Philipp Mandl
Florian Luttenberger
copyright by: ABOVE

create date 3.10.2019
*/

/*init:
liest wichtige Parameter ein (Modus, Phasenzahl, Nennspannung, Nennstrom)
Modus:
'stardelta' Stern-Dreieck Anlauf
'startup' normale Messung, fährt Maschine nach Messung herunter
initialisiert Modus und Maschine
startet Maschine
startet Messung*/
void ASM::ASM(enum mode, uint8_t  phasenr, uint8_t nvoltage, uint8_t ncurrent) {
	if (mode = stardelta) {

	}
	else if(mode = startup){

	}
}

/*readData:
liest Daten von Messgeräten ein
formatiert Daten als Array von Strukturen (Zeit, Strom, Spannung)
schreibt Daten in ein JSON Dokument*/
void ASM::readData() {
	using namespace std::chrono;

	unsigned int timestamp;
	double current;
	double voltage;

	timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	current = analogRead();
	voltage = analogRead();

	struct ASM::impData ret {
		voltage,
		current,
		timestamp
	};

	writeJSON(ret);
}

/*processData:
liest Daten von einem JSON Dokument
rechnet den Scheitelwert des Sinus und die Phasenverschiebung des Sinus aus (3 mal für 3 verschiedene Punkte)
rechnet mit dem Scheitelwert den Effektivwert aus
(rechnet P,Q und S aus)
schreibt die errechneten Daten in eine JSON Datei*/
ASM::processData() {
	uint8_t currentpeak = 0;
	uint8_t voltagepeak = 0;

	for (int i = 0; i < 10; ++i) {
		if (readJSON() > currentpeak) {
			currentpeak = readJSON();
		}
	}
	uint8_t current = currentpeak * sqrt(2);

	for (int i = 0; i < 10; ++i) {
		if (readJSON() > voltagepeak) {
			voltagepeak = readJSON();
		}
	}
	uint8_t voltage = voltagepeak * sqrt(2);

	writeJSON();
}

/*getResult:
liest die Werte aus der JSON Datei aus
gibt die Werte in die Konsole aus
(zeichnet einen Osanna Kreis)*/
ASM::getResult() {



}

/*struct Data
hat Strom (double), Spannung (double) und Time (uint)*/
	ASM::structData() {

	}

/*
readJSON
liest aus der JSON Dateien ein
return Array von Strukturen
return String*/
	ASM::readJSON() {

	}

/*writeJSON
param: String, Array (overload)
schreibt String bzw Array in eine JSON
return null*/
	ASM::writeJSON() {

	}

/*getData
liest Daten von dem Messgerät ein
formatiert Daten als Struktur Data*/
	ASM::getData() {

	}

/*splitSine
liest Daten von JSON ein
unterteilt den Sinus nach Timestamp
return timestamp start1, stop1, start2, stop2, start1, stop1*/
	ASM::splitSine() {

	}

/*getPosWave
kriegt von splitSine params
schaut wann >0
schaut wann steigt
schaut ob volle Halbwelle
return Array pos Welle*/
	ASM::getPosWave() {

	}

/*
getParams
kriegt Daten von getPosWave
rechnet Frequenz aus
rechnet Phasenverschiebung (Delta Nulldurchgang) mit f aus
berechnet peak mit eine positive Halbwelle suchen und von der das Max ist peak
berechnet Effektivwert aus Peak
return Effektivwert I, U, Phi*/
	ASM::getParams() {

	}
