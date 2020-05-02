#include "captureType.h"

//empty constructor
captureType::captureType()
{
	
}


captureType::captureType(double volt, double amps, uint32_t time)
{
	this->_volt = volt;
	this->_amps = amps;
	this->_time = time;
}