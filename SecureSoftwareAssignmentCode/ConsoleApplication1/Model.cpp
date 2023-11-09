#include "Model.h"
#include "ConsoleLogger.h"
#include "TxtFileLogger.h"
#include "LoggerDecorator.h"

	Model::Model(void) { retrieveDataFromDatabase(); }

	const std::string Model::getName(void) const 
	{
		return this->name;
	}
	void Model::setName(const std::string name) 
	{
		this->name = name;
	}
	uint16_t Model::getTemperature(void) const
	{
		uint16_t newTemp = temp.Read();
		
		if (newTemp >= fan.getFanActivationTemp())
			fan.ToggleFan(true);
		else
			fan.ToggleFan(false);

		return newTemp;
	}
	void Model::setTemperature(const uint16_t t)
	{
		temp.Write(t);
	}
	uint16_t Model::getHumidity(void) const
	{
		return hum.Read();
	}
	void Model::setHumidity(const uint16_t hum)
	{
		this->hum.Write(hum);
	}
	uint16_t Model::getDewdrop(void) const
	{
		return dewpoint.Read();
	}
	void Model::setDrewdrop(const uint16_t dewpoint)
	{
		this->dewpoint.Write(dewpoint);
	}
	void Model::setSampling(const uint16_t sampling)
	{
		samplingPeriod = sampling;
	}
	uint16_t Model::getSampling(void) 
	{
		return samplingPeriod;
	}
	bool Model::getFanState(void)
	{
		return fan.getFanState();
	}
	void Model::retrieveDataFromDatabase(void) 
	{
		setName("The SmartHouse");
		setTemperature(25);
		setDrewdrop(15);
		setHumidity(21);
		fan.ToggleFan(true);
	}
	void Model::ConfigureSensors(void)
	{
		temp.Configure(); 
		hum.Configure();
		dewpoint.Configure();
		fan.Configure();
	}
	void Model::ConfigureLogger(void)
	{

	}
	void Model::Log(void)
	{
		uint16_t loggerType;       // variable to store the input
		uint16_t formatType;

		std::cout << "\n SELECT LOGGER [1: TXT FILE, 2: CONSOLE] : ";
		std::cin >> loggerType;
		std::cout << "\n SELECT FORMAT [1: NONE, 2: ENCRYPTED] : ";
		std::cin >> formatType;

		std::unique_ptr<Logger> logger;

		switch (loggerType) {
		case L_TEXT_FILE:
			logger = std::make_unique<TxtFileLogger>();
			break;

		case L_CONSOLE:
			logger = std::make_unique<ConsoleLogger>();
			break;

		default:
			std::cout << "NO LOGGER" << std::endl;
			break;
		} //switch

		switch (formatType)
		{
		case F_NONE:
			logger = std::make_unique<LoggerDecorator>(std::move(logger), formatType);
			break;

		case F_ENCRYPTED:
			logger = std::make_unique<LoggerDecorator>(std::move(logger), formatType);
			break;

		default:
			std::cout << "NO FORMAT" << std::endl;
			break;

		}

		std::string logMessage = "\nLog: \ntemp = " + std::to_string(getTemperature()) + "[C]" +
			"\nDewpoint = " + std::to_string(getDewdrop()) + "[C]" +
			"\nHumidity = " + std::to_string(getHumidity()) + "[%]" +
			"\nFanState = " + std::to_string(getFanState()) + "[ON/OFF]\n\n";

		logger->log(logMessage);   // virtual dispatch
	}
