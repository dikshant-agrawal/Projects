/*
 * UserInterface.h
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include "Timer.h"
#include "ButtonStates.h"

class UserInterface {
private :
	double temperature;	///< to hold the current temperature from sensor
	int setTemperature; ///< to hold the desired temperature from the user
	Timer &timer;		///< to hold a copy of timer instance (not owned)

public:

	/*
	 * @brief to read the button pressed state
	 * @param ButtonStates &btn : to check which button is pressed
	 * */
	void readButton(ButtonStates &btn);

	/*
	 * @brief to increase the temperature setting based on button state
	 * */
	void increaseTemperature();

	/*
	 * @brief to decrease the temperature setting based on button state
	 * */
	void decreaseTemperature();

	/*
	 * @brief to Power ON or OFF the display
	 * */
	void powerDisplay();

	/*
	 * @brief to start the timer based on button state
	 * @return bool true if timer starts succesfully else false
	 * */
	bool startTimer();

	/*
	 * @brief to get the desired temperature to print on display
	 * @return double the desired set temperature
	 * */
	double getSetTemp() const;

	/*
	 * @brief to get the current temperature to print on display
	 * @return double the current temperature from the sensor
	 * */
	double getTemp() const;

	/*
	 * @brief to increase the temperature setting based on button state
	 * @param int temp : to print the temperature on the display
	 * */
	void setDisplayTemp(int temp);

	/*
	 * @brief Constructor to initalize the Timer instance and variables
	 * */
	UserInterface(Timer &t);
	virtual ~UserInterface();
};

#endif /* USERINTERFACE_H_ */
