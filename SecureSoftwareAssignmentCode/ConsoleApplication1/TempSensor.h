#pragma once
#include <iostream>
#include "FanActuator.h"

class TempSensor
{
	uint16_t temp{ 20 };
public:
	TempSensor(void) {};
	void Write(uint16_t newValue);
	uint16_t Read(void);
	void Configure(void);
};