#include "DewPointSensor.h"
#include <cstdlib>

uint16_t DewPointSensor::Read(void)
{
	double newDew = this->dewpoint + (rand() % 60) + 32; //Generates value in Fahrenheit [F]
	newDew = (newDew - 32.0) / 1.8; //Converts to celsius [C]
	return (uint16_t)newDew;
}

void DewPointSensor::Write(uint16_t dewpointVal)
{
	this->dewpoint = dewpointVal;
}

void DewPointSensor::Configure(void)
{
	std::cout << "[DEWPNT] No configurable options.\n";
}