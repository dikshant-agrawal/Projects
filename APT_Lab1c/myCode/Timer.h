/*
 * Timer.h
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef TIMER_H_
#define TIMER_H_

class Timer {
private:
	int elapsedTime;	///< To hold the time elapsed from the start time
	int setTime;		///< Time till which timer should run

public:
	/*
	 * @brief Constructor for the initialization of variables
	 * */
	Timer();

	/*
	 * @brief to set the time for timer (set using UserInterface Class)
	 * @param int t for the total set time
	 * @return bool true if timer is set
	 * */
	bool setTimer(int t);

	/*
	 * @brief Implementation of the counter logic
	 * @return int elapsedTime
	 * */
	int cycleCounter();

	/*
	 * @brief to fetch the set time of the timer
	 * @return int setTime
	 * */
	int getSetTime()const;

	/*
	 * @brief to fetch the elapsed time from start
	 * @return int elapsedTime
	 * */
	int getTimer() const;

	/*
	 * @brief to check weather the timer has finished counting
	 * @return bool true if setTime = elapsedTime if not false
	 * */
	bool isFinished() const;

	/*
	 * @brief reset the elapsedTime to zero.
	 * */
	void reset();

	virtual ~Timer();
};

#endif /* TIMER_H_ */
