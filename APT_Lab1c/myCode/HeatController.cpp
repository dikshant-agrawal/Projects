/*
 * HeatController.cpp
 *
 *  Created on: 16-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "HeatController.h"


HeatController::HeatController(UserInterface &ui_, Compartor &cmp_,
		Safety &sft_) : ui(ui_), cmp(cmp_), sft(sft_){}


void HeatController::run() {
	int current = ui.getTemp();
	int set = ui.getSetTemp();

	cmp.compareTemp(current, set);
	sft.safetyStatus(current);

}

HeatController::~HeatController() {
	// TODO Auto-generated destructor stub
}

