#include "HumiditySensor.h"
#include <cstdlib>

void HumiditySensor::Write(int newValue)
{
	hum = newValue;
}

int HumiditySensor::Read(void) 
{
	uint16_t newHum = this->hum + (rand() % 80) + 1; 
	return newHum;
}


void HumiditySensor::Configure(void)
{
	std::cout << "[HUMID] No configurable options\n";
}