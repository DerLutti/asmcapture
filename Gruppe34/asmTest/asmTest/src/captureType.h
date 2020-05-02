//class for a list, which contains all datatypes of one measurement
#pragma once
#include <stdint.h>
class captureType
{

public:
	double _volt;
	double _amps;
	uint32_t _time;

	captureType();
	captureType(double volt, double amps, uint32_t time);
};

