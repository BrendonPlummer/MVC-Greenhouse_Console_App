#pragma once
#include <iostream>

class DewPointSensor
{
	uint16_t dewpoint{ 15 };
public:
	DewPointSensor(void) {};
	uint16_t Read(void);
	void Write(uint16_t);
	void Configure(void);
};