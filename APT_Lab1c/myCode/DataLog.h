/*
 * DataLog.h
 *
 *  Created on: 15-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef DATALOG_H_
#define DATALOG_H_

class DataLog {
private:
	double logCurrent;	///<to hold the current temperature from sensor
	double logDesired;	///< to hold the desired temperature by user
public:

	/*
	 * @brief to store the temperature logs in fixed time interval
	 * @param double lC : current temperature
	 * @param double lD : desired temperature
	 * @return bool : true if logging is success else false
	 * */
	bool logger(double lC , double lD);

	/*
	 * @brief to fetch the entire logs
	 * @return char : shares the log history in char arrayS
	 * */
	char getLogger()const;

	/*
	 * @brief Constructor to initialize the variables
	 * */
	DataLog();
	virtual ~DataLog();
};

#endif /* DATALOG_H_ */
