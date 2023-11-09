#pragma once
#include <iostream>

class Logger
{
public:
	virtual void log(std::string msg) = 0;
	virtual ~Logger() {};
};