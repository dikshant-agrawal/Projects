/*
 * ConsoleView.h
 *
 *  Created on: 04-Jan-2026
 *      Author: agraw
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"

class ConsoleView {
private:
	/*
	 * @brief Pointer to board for the print methods
	 * */
	Board* board;

	/*
	 * @brief Helper function to initialize the grid with ~
	 * @param char** grid to store array of rows and columns
	 * @param int rows: number of rows in a grid array
	 * @param int columns: number of columns in a grid array
	 */
	void initGrid(char** grid, int rows, int columns) const;

	/*
	 * @brief Helper function to fill own grid with Ships, Hit, Miss and
	 * Sunken
	 * @param char** grid : array of grid to be filled
	 */
	void fillOwnGrid(char** grid)const ;

	/*
	 * @brief Helper function to fill opponent grid with Ships, Hit, Miss
	 * and Sunken as per knowledge gained from getShotsAt from opponent grid
	 * @param char** grid : array of grid to be filled
	 */
	void fillOpponentGrid(char** grid) const;

	/*
	 * @brief Helper function to print number of column
	 * @param int columns: number of columns to be printed
	 */
	void printHeader(int columns);
public:

	/*
	 * @brief Constructor for the console view instance
	 * @param Board* board: with the board pointer to point
	 */
	ConsoleView(Board* board);

	/*
	 * @brief Print function which invokes helper function and create clean
	 * console view print
	 */
	void print();
};

#endif /* CONSOLEVIEW_H_ */
