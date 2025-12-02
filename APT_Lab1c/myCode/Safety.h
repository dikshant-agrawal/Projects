/*
 * Safety.h
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef SAFETY_H_
#define SAFETY_H_

class Safety {
private:
	double maxTemperature; 	///< Maximum allowed temperature by the logic
	double minTemperature;	///< Minimum allowed temperature by the logic
public:
	/*
	 * @brief Checks the temperature to be in safe range of the heating unit
	 * @param double cTemp takes the currentTemperature from the sensor
	 * @return bool true if its in desired range else false
	 * */
	bool safetyStatus(double cTemp) const;

	/*
	 * @brief to fetch the maximum temperature of the safety system
	 * @return double maxTemperature
	 * */
	double maxTemp() const;

	/*
	 * @brief to fetch the minimum temperature of the safety system
	 * @return double minTemperature
	 * */
	double minTemp() const;

	/*
	 * @brief Constructor to initalize the variables.
	 * */
	Safety();
	virtual ~Safety();
};

#endif /* SAFETY_H_ */
