#include <iostream>
#include "ConsoleLogger.h"

void ConsoleLogger::log(std::string msg) 
{
	std::cout << "[CONSOLE_LOG]: " << msg << std::endl;
}