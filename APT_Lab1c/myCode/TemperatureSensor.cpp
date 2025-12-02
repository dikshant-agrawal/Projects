/*
 * TemperatureSensor.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor() {
	currentTemperature = 0;

}


double TemperatureSensor::getTemp() const{
	return currentTemperature;
}


TemperatureSensor::~TemperatureSensor() {
	// TODO Auto-generated destructor stub
}

