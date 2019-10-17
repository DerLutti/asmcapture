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
void ASM::ASM(enum mode, uint8_t  phasenr, uint8_t nvoltage, uint8_t ncurrent, uint8_t frequency) {
	_frequency = frequency;
	//setup the pins as outputs
	GPIO.setup(_NS, GPIO.OUT);
	GPIO.setup(_SS, GPIO.OUT);
	GPIO.setup(_DS, GPIO.OUT);
	if (mode = stardelta) {
		stardelta();
}else if(mode = startup){
	GPIO.output(_NS, GPIO.HIGH);
	GPIO.output(_DS, GPIO.HIGH);
}
}

/*	stardelta
regelt den einschaltvorgang für stern-dreieck*/
void ASM::stardelta() {
	GPIO.output(_NS, GPIO.HIGH);
	GPIO.output(_SS, GPIO.HIGH);
	//pm:wait ka for wos
	GPIO.output(_SS, GPIO.LOW);
	GPIO.output(_DS, GPIO.HIGH);
}

/*readData:
liest Daten von Messgeräten ein
formatiert Daten als Array von Strukturen (Zeit, Strom, Spannung)
schreibt Daten in ein JSON Dokument*/
void ASM::readData() {
	using namespace std::chrono;

	uint32_t timestamp;
	uint16_t current;
	uint16_t voltage;

	timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	current = _getData(i);	//wert auslesen
	voltage = _getData(u);

	structData(current,voltage,timestamp);
}

/*processData:
liest Daten von einem JSON Dokument
rechnet den Scheitelwert des Sinus und die Phasenverschiebung des Sinus aus (3 mal für 3 verschiedene Punkte)
rechnet mit dem Scheitelwert den Effektivwert aus
(rechnet P,Q und S aus)
schreibt die errechneten Daten in eine JSON Datei*/
void ASM::processData() {
	uint16_t currentpeak = 0;
	uint16_t voltagepeak = 0;
	uint8_t angle = 0;

	for (int i = 0; i < 1000; ++i) {
		if (readJSON(timestamps[]) > currentpeak) {
			currentpeak = readJSON();
		}
	}
	uint8_t current = currentpeak * sqrt(2);

	for (int i = 0; i < 1000; ++i) {
		if (readJSON() > voltagepeak) {
			voltagepeak = readJSON();
		}
	}
	uint8_t voltage = voltagepeak * sqrt(2);

	angle = calculateangle(currentpeaktimestamp,voltagepeektimestamp);

	uint16_t p = voltage * current*cos(angle)*sqrt(3);
	uint16_t q = voltage * current*sin(angle)*sqrt(3);
	uint16_t s = voltage * current*sqrt(3);

	structData(current, voltage, timestamp, p, q, s);
}

/*getResult:
liest die Werte aus der JSON Datei aus
gibt die Werte in die Konsole aus
(zeichnet einen Osanna Kreis)*/
void ASM::getResult() {
	printf("U: "_readJSON());
	printf("Uscheitel: "_readJSON());
	printf("I: "_readJSON());
	printf("Ischeitel: "_readJSON());
	printf("Phasenverschiebung: "_readJSON());
	printf("P: "_readJSON());
	printf("Q: "_readJSON());
	printf("S: "_readJSON());
	
	//Textdatei oder so ausgeben
	ofstream file("speicher.txt");
	file << "U: " << _readJSON() << '\n'
		<< "Uscheitel: " << _readJSON() << '\n'
		<< "I: " << _readJSON() << '\n'
		<< "Ischeitel: " << _readJSON() << '\n'
		<< "Phasenverschiebung: " << _readJSON() << '\n'
		<< "P: " << _readJSON() << '\n'
		<< "Q: " << _readJSON() << '\n'
		<< "S: " << _readJSON() << '\n'
		<< endl;
}

/*struct Data
hat Strom (double), Spannung (double) und Time (uint)*/
	void ASM::structData(uint16_t current, uint16_t voltage, uint32_t timestamp) {
		writeJSON();
	}
	void ASM::structData(uint16_t current, uint16_t voltage, uint32_t timestamp, uint16_t p, uint16_t q, uint16_t s) {
		writeJSON();
	}

/*
readJSON
liest aus der JSON Dateien ein
return Array von Strukturen
return String*/
	uint16_t ASM::_readJSON() {

	}

/*writeJSON
param: String, Array (overload)
schreibt String bzw Array in eine JSON
return null*/
	void ASM::writeJSON() {

	}

/*getData
liest Daten von dem Messgerät ein
formatiert Daten als Struktur Data*/
	uint16_t ASM::_getData(char16_t mode) {
		int fd;
		MCP3204 ADC;
		char error[20];
		MCP3204_init(&fd, "/dev/spidev0.1", &ADC, mode_SPI_00, 2.491, error);
		if (mode = u) {
			MCP3204_convert(fd, singleEnded, CH0, &ADC, error);
		}
		else if (mode = i) {
			MCP3204_convert(fd, singleEnded, CH1, &ADC, error);
		}
		return MCP3204_analogValue(ADC); //returns the analog value of the input
	}

/*getPosWaveTs
soll alle timestamps einer postiven halben periodendauer ausgeben*/
	uint16_t ASM::_getPosWaveTs() {
		uint8_t toleranz = 5;
		while ((_readJSON(TSaktuell)-_readJSON(TS0))<20)
		{
			if ((Wert > toleranz) || (Wert < toleranz)) 
			{
				writeJSON(U I und TS);
			}
		}
		return 1;
	}

/*calculateangle:
berechnet winkel aus Ts*/
	uint8_t ASM::_calculateangle(uint32_t currentpeaktimestamp, uint32_t voltagepeektimestamp) {
		uint8_t angle = 0;
		angle = 360 * _frequency*(currentpeaktimestamp- voltagepeektimestamp);
		constrain(angle, 0, 90);
		return angle;
	}
