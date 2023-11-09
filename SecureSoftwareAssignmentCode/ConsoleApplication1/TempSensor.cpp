#include "TempSensor.h"
#include <cstdlib>


void TempSensor::Write(uint16_t newValue)
{
	this->temp = uint16_t(newValue);
}

uint16_t TempSensor::Read(void)
{ 
	double newTemp = this->temp + (rand() % 60) + 32; //Generates value in Fahrenheit [F]
	newTemp = (newTemp - 32.0) / 1.8; //Converts to celsius [C]
	return (uint16_t)newTemp;
}

void TempSensor::Configure(void)
{
	std::cout << "[TEMP] No configurable options\n";
}