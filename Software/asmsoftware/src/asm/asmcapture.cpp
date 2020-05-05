/*
ASM library
asmcapture.cpp
created by
Philipp Mandl
Florian Luttenberger
copyright by: ABOVE

create date 3.10.2019
*/

#include <asmcapture.h>;


	// timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	// uint8_t current = currentpeak * sqrt(2);
	// uint8_t voltage = voltagepeak * sqrt(2);

	// uint16_t p = voltage * current*cos(angle)*sqrt(3);
	// uint16_t q = voltage * current*sin(angle)*sqrt(3);
	// uint16_t s = voltage * current*sqrt(3);


	// uint8_t angle = 0;
	// angle = 360 * _frequency*(currentpeaktimestamp- voltagepeektimestamp);
	// constrain(angle, 0, 90);

	

	ASM::ASM(uint8_t mode, uint8_t frequency){
		
	}
	// void begin(); //startet den dreck beinhaltet den gaanzen dreck     bearbeitet fehler oder so wenns is
	// void messwerte(float strom, float spannung); //speichert die messwerte in die Liste
	// measurepoint getResult(); //liest Daten von liste und startet berechnung
	// void stop(char* fehler); //wenn benutzereingabe (NOT AUS)
	// uint8_t _frequency;
	// std::vector<measurepoint> measurePoints; 
	// uint8_t[] getPoints();
	// uint8_t[] getPeak(int index); //gets indizes of peak
	// void getAngle(Uscheitelwertzeitpunktindex, Ischeitelwertzeitpunktindex);
	// uint8_t[] ergebnisse;

	// void error();