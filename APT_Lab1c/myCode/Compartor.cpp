/*
 * Compartor.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "Compartor.h"


Compartor::Compartor() {
	relay = false;
}

bool Compartor::compareTemp(int currentTemp, int setTemp) {
	if(currentTemp < setTemp){
		setRelayState(1);
	}
	else{
		setRelayState(0);
	}
	return relay;
}


bool Compartor::getRelayState() const {
	return relay;
}

bool Compartor::setRelayState(int n) {
	if(n == 1){
		relay = true;
	}
	else{
		relay = false;
	}
	return true;
}

Compartor::~Compartor() {
	// TODO Auto-generated destructor stub
}

