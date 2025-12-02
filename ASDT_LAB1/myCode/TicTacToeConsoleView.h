/*
 * TicTacToeConsoleView.h
 *
 *  Created on: 01-Dec-2025
 *      Author: agraw
 */

#ifndef TICTACTOECONSOLEVIEW_H_
#define TICTACTOECONSOLEVIEW_H_

#include "TicTacToeBoard.h"

class TicTacToeConsoleView {
private:
	const TicTacToeBoard *me;	///< pointer to hold the address internally
public:
	/*
	 * @brief Constructor to hold the pointer to the TicTacToeBoard
	 * @param Pointer to the TicTacToeBoard Instance
	 */
	TicTacToeConsoleView(const TicTacToeBoard *board);

	/*
	 * @brief Print the board in the console
	 */
	void print() const;


	/*
	 * @brief Destructor class to kill the Console VIew
	 */
	virtual ~TicTacToeConsoleView();
};

#endif /* TICTACTOECONSOLEVIEW_H_ */

