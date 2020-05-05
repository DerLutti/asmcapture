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

//hier  zusaetzliche libs hinzufuegen
#include <chrono>		/* timestamp */
#include <stdio.h>      /* printf */
#include <math.h>		/* sqrt */
#include <vector>			/*list*/
#include <fstream>

#define ADS_ADDR 0x48

class ASM {
public:

	ASM(uint8_t mode, uint8_t frequency); //verbinden mit Schnittstelle und initialisierung
	void begin(); //startet den dreck beinhaltet den gaanzen dreck     bearbeitet fehler oder so wenns is
	void messwerte(float strom, float spannung); //speichert die messwerte in die Liste
	measurepoint getResult(); //liest Daten von liste und startet berechnung
	void stop(char* fehler); //wenn benutzereingabe (NOT AUS)

	struct measurepoint{
		float I;
		double U;
		int t;
	};
private:

	uint8_t _frequency;
	std::vector<measurepoint> measurePoints; 
	uint8_t[] getPoints();
	uint8_t[] getPeak(int index); //gets indizes of peak
	void getAngle(Uscheitelwertzeitpunktindex, Ischeitelwertzeitpunktindex);
	uint8_t[] ergebnisse;

	void error();
};

#endif //asmcapture.h
