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
	readJSON();	//die JSON einlesen 
	writeJSON();
};

#endif //asmcapture.h
