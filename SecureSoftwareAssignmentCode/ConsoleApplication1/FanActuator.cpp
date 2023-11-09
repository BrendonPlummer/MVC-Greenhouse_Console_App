#include "FanActuator.h"

void FanActuator::ToggleFan(bool state)
{
	this->fanActive = state;
}
void FanActuator::SetFanSpeed(uint16_t fanSpeed)
{
	this->fanSpeed = fanSpeed;
}
uint16_t FanActuator::GetFanSpeed(void)
{
	return this->fanSpeed;
}
uint16_t FanActuator::getFanActivationTemp(void)
{
	return fanActivationTemp;
}
bool FanActuator::getFanState(void)
{
	return this->fanActive;
}
void FanActuator::Configure(void)
{
	uint16_t newFanSpeed = 0;
	uint16_t newActivationTemp = 0;

	do {
		std::cout << "\nEnter new Fan Speed [RPM]: ";
		std::cin >> newFanSpeed;
		if (newFanSpeed <= 0 || newFanSpeed >= 100)
		{
			std::cout << "Inputted Fan speed inappropriate!\n";
			newFanSpeed = 0;
			std::cin.clear();
		}
	} while (newFanSpeed <= 0 || newFanSpeed >= 100);

	do {
		std::cout << "\nEnter new activation temperature [C]: ";
		std::cin >> newActivationTemp;
		if (newActivationTemp <= 0 || newActivationTemp >= 100)
		{
			std::cout << "Inputted activation temperature inappropriate!\n";
			newActivationTemp = 0;
			std::cin.clear();
		}
	} while (newActivationTemp <= 0 || newActivationTemp >= 100);

	this->fanSpeed = newFanSpeed;
	this->fanActivationTemp = newActivationTemp;
}