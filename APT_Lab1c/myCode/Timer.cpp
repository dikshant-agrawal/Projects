/*
 * Timer.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "Timer.h"

Timer::Timer() {
	elapsedTime = 0;
	setTime = 0;
}

bool Timer::setTimer(int t) {
	setTime = t;
	return true;
}

int Timer::cycleCounter() {
	for(int i = 0; i < setTime; i++){
		elapsedTime++;
	}
	return elapsedTime;
}

int Timer::getSetTime() const {
	return setTime;
}

int Timer::getTimer() const {
	return elapsedTime;
}

bool Timer::isFinished() const {
	if(elapsedTime != setTime){
		return false;
	}

	return true;
}

void Timer::reset() {
	elapsedTime = 0;
}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

