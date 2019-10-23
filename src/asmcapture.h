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
#include <math.h>		/* sqrt */
#include <list>			/* list */
#include <fstream>		/* Filestream */
#include <string>		/* working with string */

//JSON stuff
#include "rapidjson/writer.h" /*JSON write*/
#include "rapidjson/reader.h" /*JSON read*/
#include "rapidjson/stringbuffer.h" /*JSON buffer*/


#include <libmcp3204.h>

#include <fstream>

#define ADS_ADDR 0x48

class ASM {
public:

	void ASM(enum mode, uint8_t  phasenr, uint16_t nvoltage, uint16_t ncurrent, uint8_t frequency ); //verbinden mit Schnittstelle und initialisierung
	void readData(); //liest Daten vom Messgerät ein und schreibt Daten in JSON Dokument
	void processData(); //liest Daten von JSON rechnet Daten und schreibt in JSON Dokument
	void getResult(); //liest Daten von JSON und gibt sie aus
private:
	readJSON(char* PATH_TO_FILE);	//die JSON einlesen 
	writeJSON(char* PATH_TO_FILE, std::string toWrite);
	writeJSON(char* PATH_TO_FILE, impData[] toWrite);

	void saveData(uint16_t current, uint16_t voltage, uint32_t timestamp, uint16_t p, uint16_t q, uint16_t s); //Strom, Spannung, timestamp , p, q, s
	void saveData(uint16_t current, uint16_t voltage, uint32_t timestamp); //Strom, Spannung, timestamp
	uint16_t _readJSON(); //von JSON Datei lesen
	void writeJSON(); //in JSON Datei schreiben
	uint16_t _getData(); //liest Daten von Messgerät ein.
	uint16_t _getPosWaveTs(); //splitSine in positive halbwelle
	void stardelta(); //sterndreieck anlauf
	uint8_t _calculateangle(uint32_t currentpeaktimestamp, uint32_t voltagepeektimestamp); //berechnet winkel
	uint8_t _frequency;
<<<<<<< HEAD

	struct impData {
		double U;
		double I;
		unsigned int time;
	};
=======
	//GPIO
	uint8_t NS = 22;
	uint8_t SS = 23;
	uint8_t DS = 24;

>>>>>>> d02feee289320c5587c2806361bf491fae151b97
};

#endif //asmcapture.h
