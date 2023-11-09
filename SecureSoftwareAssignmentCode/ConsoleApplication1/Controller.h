#pragma once
#include "Model.h"
#include "View.h"

class Controller {
	Model model;
	View view;
	bool logged{ false };

	std::string name;
	std::string pass;
	std::string systemPass = "1234"; 
public:
	void configureSensor(void);
	void readData(void);
	void run(void);
};

