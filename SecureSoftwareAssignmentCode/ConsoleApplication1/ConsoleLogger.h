#pragma once
#include "Logger.h"

class ConsoleLogger : public Logger {
public:
	void log(std::string msg);
};