/*
 * Safety.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "Safety.h"

Safety::Safety() {
	maxTemperature = 25;	///< Maximum allowed temperature by the logic
	minTemperature = 15;	///< Minimum allowed temperature by the logic
}

bool Safety::safetyStatus(double cTemp) const {

	if((minTemperature < cTemp) && (cTemp < maxTemperature)){
		return true;
	}

	return false;
}

Safety::~Safety() {
}

double Safety::maxTemp() const {
	return maxTemperature;
}

double Safety::minTemp() const {
	return minTemperature;
}
