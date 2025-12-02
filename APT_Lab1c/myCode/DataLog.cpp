/*
 * DataLog.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "DataLog.h"

DataLog::DataLog() {
	logCurrent = 0;
	logDesired = 0;

}

bool DataLog::logger(double lC, double lD) {

	logCurrent = lC;
	logDesired = lD;

	return true;
}

char DataLog::getLogger() const {

	return 'L';
}

DataLog::~DataLog() {
	// TODO Auto-generated destructor stub
}

