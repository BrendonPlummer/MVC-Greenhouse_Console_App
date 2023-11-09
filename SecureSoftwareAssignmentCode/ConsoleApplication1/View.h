#pragma once
#include <string>
#include "Model.h"
#include "Choice.h" 

class View {
public:
	void PrintModelDetails(const Model &m) const;
	Choice MainMenu(void);
	void DisplayData(uint16_t, uint16_t, float, uint16_t, bool);
	void DisplayHeader(void);
	void Message(std::string s);
};