#pragma once
#include <string>
#include <memory>

#include "TempSensor.h"
#include "HumiditySensor.h"
#include "DewPointSensor.h"
#include "FanActuator.h"
//#include "Logger.h"
//#include "Greenhouse_Info.h"

const uint16_t MAX_LOGS = 24;

enum LoggerType { L_TEXT_FILE = 1, L_CONSOLE };
enum FormatType { F_NONE = 1, F_ENCRYPTED };

class Model {
	mutable TempSensor temp;
	mutable HumiditySensor hum;
	mutable DewPointSensor dewpoint;
	mutable FanActuator fan;

	std::string name;
	int samplingPeriod {500};

public:
	Model(void);

	const std::string getName(void) const;

	void setName(const std::string name);

	uint16_t getTemperature(void) const;

	void setTemperature(const uint16_t temp);

	uint16_t getHumidity(void) const;

	void setHumidity(const uint16_t hum);

	uint16_t getDewdrop(void) const;

	void setDrewdrop(uint16_t);
				
	void setSampling(const uint16_t sampling);

	uint16_t getSampling(void);

	bool getFanState(void);

	void retrieveDataFromDatabase(void);

	void ConfigureSensors(void);

	void ConfigureLogger(void);

	void Log(void);
};



