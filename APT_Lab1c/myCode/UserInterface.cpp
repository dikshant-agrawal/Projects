/*
 * UserInterface.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface(Timer &t)
: temperature(0), setTemperature(20), timer(t)
{}


void UserInterface::setDisplayTemp(int temp) {
	temperature = temp;
}


void UserInterface::readButton(ButtonStates &btn) {
	switch (btn.getState()){
	case PLUS: increaseTemperature(); break;
	case MINUS: decreaseTemperature(); break;
	case POWER: powerDisplay(); break;
	case NONE: break;
	case TIMER: startTimer(); break;
	}
}

void UserInterface::increaseTemperature() {
	++setTemperature;
}

void UserInterface::decreaseTemperature() {
	if(setTemperature > 0) --setTemperature;
}

double UserInterface::getSetTemp() const {
	return setTemperature;
}

double UserInterface::getTemp() const {

	return temperature;
}

bool UserInterface::startTimer() {
	timer.setTimer(20);
	if(timer.isFinished()){
		return true;
	}
	else
		return false;

}

UserInterface::~UserInterface() {
	// TODO Auto-generated destructor stub
}

void UserInterface::powerDisplay() {
	//TODO Turn Display OFF and ON
}
