#include <iostream>
#include <fstream>
#include "TxtFileLogger.h"

void TxtFileLogger::log(std::string msg)
{
	std::ofstream outFile("logs.txt", std::ios::app | std::ios::out);
	try {
		if (!(outFile.fail()))
		{
			if (outFile.is_open())
				outFile << msg;
		}
	}
	catch (std::ofstream::failure e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	outFile.close();
};