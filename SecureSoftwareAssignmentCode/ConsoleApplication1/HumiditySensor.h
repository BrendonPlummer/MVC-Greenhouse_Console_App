#pragma once
//DirectoryIncludes
#include <iostream>
//Header Includes


class HumiditySensor
{
	uint16_t hum{ 35 };

public:
	HumiditySensor(void) {};
	void Write(int newValue);
	int Read(void);
	void Configure(void);
};