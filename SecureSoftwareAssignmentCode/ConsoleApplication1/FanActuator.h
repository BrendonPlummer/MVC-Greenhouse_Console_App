#pragma once
#include <iostream>

class FanActuator
{
	bool fanActive{ false };
	uint16_t fanSpeed{ 50 };
	uint16_t fanActivationTemp{ 25 };

public:

	FanActuator(void) {};
	void ToggleFan(bool);
	void SetFanSpeed(uint16_t);
	uint16_t GetFanSpeed(void);
	bool getFanState(void);
	uint16_t getFanActivationTemp(void);
	void Configure(void);
};