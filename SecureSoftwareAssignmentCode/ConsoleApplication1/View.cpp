#include <string>
#include <iostream>
#include <iomanip>
#include "View.h"
#include "Choice.h" 

using namespace std;

void View::PrintModelDetails(const Model& m) const 
{
	cout << "**************************************" << endl;
	cout << "Welcome to the " << m.getName() << endl;
	cout << "Temperature: " << m.getTemperature() << endl;
	cout << "Dewpoint: " << m.getDewdrop() << endl;
	cout << "Humidity: " << m.getHumidity() << endl;
	cout << "**************************************" << endl;
}

void View::DisplayHeader(void) 
{
	cout << " Time" << setw(6) <<" Temp" << setw(10) << " Dew" << setw(10) << " Hum" << setw(10) << " Fan" << endl;
	cout << "[Hour]"<< setw(6) <<" [C]" << setw(10) << " [C]" << setw(10) << " [%]" << setw(10) << "[T/F]" << endl;
}

void View::DisplayData(uint16_t hour, uint16_t temp, float hum, uint16_t dew, bool fan) 
{
	ios init(NULL);
	init.copyfmt(cout);
	cout << setfill('0') << setw(2) << hour;
	cout.copyfmt(init);
	cout << setw(10) << temp << setw(10) << dew << setw(10) << hum << setw(10) << fan << endl;
}

void View::Message(std::string s) 
{
	cout << s << endl;
}

Choice View::MainMenu(void) 
{
	int input = 0;
	cout << "\nWelcome to the Smart Greenhouse\n";
	cout << "Select an option stated below\n";
	cout << "---------------------------------\n";
	cout << (int)(Choice::Information) << ": Information about the device\n";
	cout << (int)(Choice::Login) << ": Log in\n";
	cout << (int)(Choice::Read) << ": Read data\n";
	cout << (int)(Choice::Configure) << ": Configure\n";
	cout << (int)(Choice::Log) << ": Log\n";
	cout << (int)(Choice::Quit) << ": Quit\n";
	cout << "Your choice :";
	cin >> input;
	return (Choice)input;
}
