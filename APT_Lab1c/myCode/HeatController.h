/*
 * HeatController.h
 *
 *  Created on: 16-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef HEATCONTROLLER_H_
#define HEATCONTROLLER_H_

#include"UserInterface.h"
#include"Compartor.h"
#include"Safety.h"

class HeatController {
private:
	UserInterface &ui;		///< to hold the reference of the UserInterface
	Compartor &cmp;			///< to hold the reference of the comparator
	Safety &sft;			///< to hold the reference of the safety


public:

	/*
	 * @brief Constructor to initialize the variables
	 * @param UserInterface &ui_: for the content of UserIterface
	 * @param Compartor &cmp_: for the content of Compartor
	 * @param Safety &sft_: for the content of Safety
	 * */
	HeatController(UserInterface &ui_, Compartor &cmp_, Safety &sft_);

	/*
	 * @brief to run the heat controller forever*/
	void run();
	virtual ~HeatController();
};

#endif /* HEATCONTROLLER_H_ */
