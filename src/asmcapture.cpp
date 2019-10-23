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
<<<<<<< HEAD
	}else if(mode = startup){

	}
=======
}else if(mode = startup){
	GPIO.output(_NS, GPIO.HIGH);
	GPIO.output(_DS, GPIO.HIGH);
}
>>>>>>> d02feee289320c5587c2806361bf491fae151b97
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
std::list<ASM::impData> ASM::_readJSON(std::string PATH_TO_FILE, std::string arrayName) {
	//TODO: getFile to Buffer
	using namespace std;
	ifstream inputFile(PATH_TO_FILE);
	stringstream jsonDocumentBuffer;
	string inputLine;
	list<ASM::impData> ret;

	while (getline(inputFile, inputLine))
	{
		jsonDocumentBuffer << inputLine << "\n";
	}
	rapidjson::Document inDoc;
	inDoc.Parse(jsonDocumentBuffer.str().c_str());

	assert(inDoc.IsObject());

	const rapidjson::Value& vals = config[arrayName];
	assert(vals.IsArray());

	for (rapidjson::Value::ConstValueIterator itr = vals.Begin(); itr != vals.End(); ++itr)
	{
		const rapidjson::Value& vals = *itr;
		assert(vals.IsObject()); // each attribute is an object
		list.push_back(vals) //iterator
		for (rapidjson::Value::ConstMemberIterator itr2 = vals.MemberBegin(); itr2 != vals.MemberEnd(); ++itr2)
		{
			//TODO: dont writeout write to List
			//itr2->name.GetString U, I, Time
			//itr2->value.GetDouble, GetUint
			std::cout << itr2->name.GetString() << " : " << itr2->value.GetString() << std::endl;
		}
	}
}

for (std::list<Student>::iterator it = data.begin(); it != data.end(); ++it) {
	std::cout << it->name;
}

/*writeJSON
param: String, Array (overload)
schreibt Array in eine JSON
return null*/
void ASM::writeJSON(std::string PATH_TO_JSON, std::string arrayName, std::List<ASM::impData> toWrite) {
	using namespace rapidjson;
	using namespace std;

	StringBuffer json_buff;
	Writer<StringBuffer> write(json_buff);

	write.StartObject();
	write.Key(arrayName);
	write.StartArray();
	for (list<ASM::impData>::iterator i = toWrite.begin(); i != toWrite.end(); i++)
	{
		write.StartObject();
		write.Key("Timestamp");
		write.Uint(toWrite.time);
		write.Key("U");
		write.Double(toWrite.U);
		write.Key("I");
		write.Double(toWrite.I);
		write.EndObject();
	}
	write.EndArray();
	write.EndObject();
	
	ofstream outFile(PATH_TO_JSON);
	outFile << json_buff.GetString();
	outFile.close;
}
// TODO: Overload writeJSON with S, P, Q, PHI

/*getData
liest Daten von dem Messgerät ein
formatiert Daten als Struktur Data*/
<<<<<<< HEAD
uint16_t ASM::_getData(char16_t mode) {
	uint16_t data=0;
	if (mode = u) {
		data = 0;
=======
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
>>>>>>> d02feee289320c5587c2806361bf491fae151b97
	}
	else if (mode = i) {
		data = 0;
	}
	return data;
}

/*getPosWaveTs
<<<<<<< HEAD
soll alle timestamps einer postiven halbenn periodendauer ausgeben*/
uint16_t ASM::_getPosWaveTs() {
		
}

/*	stardelta
regelt den einschaltvorgang für stern-dreieck*/
void ASM::stardelta() {

}
=======
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
>>>>>>> d02feee289320c5587c2806361bf491fae151b97

/*calculateangle:
berechnet winkel aus Ts*/
uint8_t ASM::_calculateangle(uint32_t currentpeaktimestamp, uint32_t voltagepeektimestamp) {
	uint8_t angle = 0;
	angle = 360 * _frequency*(currentpeaktimestamp- voltagepeektimestamp);
	constrain(angle, 0, 90);
	return angle;
}
