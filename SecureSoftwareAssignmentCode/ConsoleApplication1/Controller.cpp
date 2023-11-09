
#include <string>
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include "Controller.h"
#include "Choice.h"

using namespace std;

void Controller::run(void) {

	Choice choice = Choice::Login;
	while (choice != Choice::Quit) {
		choice = view.MainMenu();
		switch (choice) {
		case Choice::Information: //Model details
			view.PrintModelDetails(model);
			break;

		case Choice::Login: 
			//Authenticator pattern here
			cout << "Name: ";
			cin >> name;
			cout << "Password: \n";
			cin >> pass;

			if (pass == systemPass)
			{
				logged = true;
				cout << "Welcome " + name + " to the SmartHouse" << endl;
			}
			else
				cout << "Unfortunately these credentials do not match." << endl;
			break;

		case Choice::Read: 
			readData();
			break;

		case Choice::Configure:
			if (logged) configureSensor();
			else view.Message("You have to be Admin to configure sensor");
			break;

		case Choice::Log:
			if (logged) model.Log();
			else view.Message("You have to be Admin to log information");
			break;

		default:
			break;
		}
	}
}

void Controller::readData(void) {
	uint16_t temp = model.getTemperature();
	uint16_t dewdrop = model.getDewdrop();
	uint16_t hum = model.getHumidity();
	bool fan = model.getFanState();

	view.DisplayHeader();
	for (int i = 1; i <= 24; i++) {

		temp = model.getTemperature();
		dewdrop = model.getDewdrop();
		hum = model.getHumidity();
		fan = model.getFanState();

		view.DisplayData(i, temp, hum, dewdrop, fan);
		std::this_thread::sleep_for(std::chrono::milliseconds(model.getSampling()));
	}

	model.Log();
}

void Controller::configureSensor(void){

	int samplingPeriod = model.getSampling();
	view.Message("\Current sampling Period [ms]:");
	view.Message(std::to_string(samplingPeriod));
	view.Message("\nEnter new sampling Period [ms]:");
	cin >> samplingPeriod;
	model.setSampling(samplingPeriod);
	cout << "======================================\n";
	cout << "   Configuring Sensors  " << endl;
	model.ConfigureSensors();
	cout << "======================================" << endl;
}