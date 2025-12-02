/*
 * ReversiConsolleView.h
 *
 *  Created on: 13-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"



class ReversiConsoleView {

private:

	const ReversiBoard* me;	///< pointer to hold the address internally

public:
	/*
	 * @brief Print the board in the console
	 */
	void print() const;

	/*
	 * @brief Constructor to hold the pointer to the ReversiBoard
	 * @param Pointer to the ReversiBoard Instance
	 */
	ReversiConsoleView(const ReversiBoard* board);

	/*
	 * @brief Destructor class to kill the Console VIew
	 */
	virtual ~ReversiConsoleView();
};

#endif /* REVERSICONSOLEVIEW_H_ */
