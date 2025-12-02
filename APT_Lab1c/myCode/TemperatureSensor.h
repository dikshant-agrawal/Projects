/*
 * TemperatureSensor.h
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 *
 */

#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

class TemperatureSensor {
private:
	double currentTemperature;	///< Current reading of temperature sensor

public:
	/*
	 * @brief Constructor for the initialization of variables
	 * */
	TemperatureSensor();

	/*
	 * @brief to fetch the current temperature sensor value
	 * @return double currentTemperature
	 * */
	double getTemp() const;

	virtual ~TemperatureSensor();
};

#endif /* TEMPERATURESENSOR_H_ */
