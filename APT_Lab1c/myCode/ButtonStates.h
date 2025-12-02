/*
 * ButtonStates.h
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef BUTTONSTATES_H_
#define BUTTONSTATES_H_

/*
 * @brief enum to define which button is pressed
 * */
enum Buttons {
	NONE,		///<No button
	PLUS,		///<Plus button
	MINUS,		///<Minus button
	POWER,		///<Power button
	TIMER		///<Timer button
};

class ButtonStates {
private:
	Buttons bStates;	///< Declaration of bStates enum defined by Buttons
public:

	/*
	 * @brief to handle the Plus button pressed state
	 * */
	void plusPressed();

	/*
	 * @brief to handle the Plus button pressed state
	 * */
	void timerPressed();

	/*
	 * @brief to handle the Minus button pressed state
	 * */
	void minusPressed();

	/*
	 * @brief to handle the Power button pressed state
	 * */
	void powerPressed();

	/*
	 * @brief to fetch the current state of button pressed
	 * @return Buttons with current pressed
	 * */
	Buttons getState() const;

	/*
	 * @brief Constructor to initialize the state to NONE
	 * */
	ButtonStates();
	virtual ~ButtonStates();
};

#endif /* BUTTONSTATES_H_ */
