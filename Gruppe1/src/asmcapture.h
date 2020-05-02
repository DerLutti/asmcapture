/*

*/

#ifndef asmcapture_h
#define asmcapture_h




#include <Arduino.h>

class asm {
public:

	asm(); //verbinden mit Schnittstelle
	readData();

private:
	readJSON(char* PATH_TO_FILE);	//die JSON einlesen 
	writeJSON(char* PATH_TO_FILE, char[] toWrite);
	writeJSON(char* PATH_TO_FILE, impData[] toWrite);

	struct impData {
		double U;
		double I;
		unsigned int time;
	};
};

#endif //asmcapture.h
