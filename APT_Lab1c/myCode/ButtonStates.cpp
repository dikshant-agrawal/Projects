/*
 * ButtonStates.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "ButtonStates.h"
#include "Safety.h"

ButtonStates::ButtonStates() {
	bStates = NONE;

}

void ButtonStates::plusPressed() {
	bStates = PLUS;
}

void ButtonStates::timerPressed() {
	bStates = TIMER;
}

void ButtonStates::minusPressed() {
	bStates = MINUS;
}

void ButtonStates::powerPressed() {
	bStates = POWER;
}

Buttons ButtonStates::getState() const {
	return bStates;
}

ButtonStates::~ButtonStates() {
	bStates = NONE;
}

