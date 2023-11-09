#include <iostream>
#include "LoggerDecorator.h"

LoggerDecorator::LoggerDecorator(std::unique_ptr<Logger> logger, uint16_t aformatType) : contents{ std::move(logger) }, formatType(aformatType)
{
}

void LoggerDecorator::log(std::string msg)
{
	msg = FormatMessage(msg);
	contents->log(msg);
}

std::string LoggerDecorator::EncryptDecrypt(std::string msg)
{
	char key = 'A'; //Any letter [XOR Encryption]
	std::string encryptyedMSG = msg;
	for (uint16_t i = 0; i <= msg.length(); i++)
	{
		encryptyedMSG[i] = msg[i] ^ key;
	}
	return encryptyedMSG;
}

std::string LoggerDecorator::FormatMessage(std::string msg)
{
	std::cout << " Formatting: ";
	switch (formatType)
	{
	case 1: //No Formatting
		std::cout << " No formatting!" << std::endl;
		return msg;
		break;

	case 2: //Encrypted Formatting 
		std::cout << "Encrypted Formatting! " << std::endl;
		return EncryptDecrypt(msg);
		break;

	default:
		std::cout << "Unknown Format: " << std::endl;
		return msg;
		break;
	}
}