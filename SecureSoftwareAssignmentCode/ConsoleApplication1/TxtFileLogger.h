#pragma once
#include "Logger.h"

class TxtFileLogger : public Logger {
public:
	void log(std::string msg);
};