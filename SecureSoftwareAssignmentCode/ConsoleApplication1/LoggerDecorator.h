#pragma once
#include "Logger.h"

class LoggerDecorator : public Logger {

	uint16_t formatType;
	std::unique_ptr<Logger> contents;

	void log(std::string);
	std::string EncryptDecrypt(std::string msg); //Could add encryption type

public:
	LoggerDecorator(std::unique_ptr<Logger> logger, uint16_t aformatType);
	virtual std::string FormatMessage(std::string msg); //Could also add more formatting	-	[[, uint16_t formatType]]
};