/*
ASM library
asmcapture.h
created by
Philipp Mandl
Florian Luttenberger
copyright by: ABOVE

create date 3.10.2019
*/

#ifndef asmcapture_h
#define asmcapture_h

//hier  zusätzliche libs hinzufügen
#include <chrono>		/* timestamp */
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

class ASM {
public:

	ASM(enum mode, uint8_t  phasenr, uint8_t nvoltage, uint8_t ncurrent ); //verbinden mit Schnittstelle und initialisierung
	readData(); //liest Daten vom Messgerät ein und schreibt Daten in JSON Dokument
	processData(); //liest Daten von JSON rechnet Daten und schreibt in JSON Dokument
	getResult(); //liest Daten von JSON und gibt sie aus
private:
	structData(); //Strom, Spannung, timestamp
	readJSON(); //von JSON Datei lesen
	writeJSON(); //in JSON Datei schreiben
	getData(); //liest Daten von Messgerät ein.
	//nächsten zwei könnten zusammengefasst werden
	splitSine(); //returned Sinus nach Timestamp
	getPosWave(); //splitSine in positive halbwelle
	getParams(); //rechnet Frequenz aus,phi U und I
};

#endif //asmcapture.h
