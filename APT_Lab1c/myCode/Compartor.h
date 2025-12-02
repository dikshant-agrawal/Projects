/*
 * Compartor.h
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef COMPARTOR_H_
#define COMPARTOR_H_

class Compartor {
private:
	bool relay;
public:

	/*
	 * @brief Constructor to initialize the variables
	 * */
	Compartor();

	/*
	 * @brief to compare the current temperature with set point
	 * @param int currentTemp : takes the current sensor reading
	 * @param int setTemp : takes the desired set temperature
	 * @return bool true if its within range else false
	 * */
	bool compareTemp(int currentTemp, int setTemp);

	/*
	 * @brief to get the current position of the water supply relay
	 * @return bool true if its ON else false
	 * */
	bool getRelayState() const;

	/*
	 * @brief to set the water supply relay in ON or OFF state
	 * @param int n 0 for OFF and 1 for ON
	 * @return bool true if its ON else false
	 * */
	bool setRelayState(int n);

	/*
	 * @brief Destructor
	 * */
	virtual ~Compartor();
};

#endif /* COMPARTOR_H_ */
