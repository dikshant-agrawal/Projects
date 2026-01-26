/*
 * Board.h
 *
 *  Created on: 04-Jan-2026
 *      Author: agraw
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "OwnGrid.h"
#include "OpponentGrid.h"

class Board {
private:
	int rows;				   ///< rows in a board
	int columns;			   ///< columns in a board
	OwnGrid ownGrid;		   ///< Owngrid with given rows and columns
	OpponentGrid opponentGrid; ///< OpponentGrid with given rows and columns

public:
	/*
	 * @brief Constructor to create a board with given rows and columns
	 * @param int row : row on grids.
	 * @param int columns : column on grids.
	 */
	Board(int rows, int columns);

	/*
	 * @brief getter function to get rows on board
	 * @return int rows.
	 */
	int getRows() const;

	/*
	 * @brief getter function to get columns on board
	 * @return int columns.
	 */
	int getColumns() const;

	/*
	 * @brief getter function to owngrid on board
	 * @return owngrid reference
	 */
	OwnGrid& getOwnGrid();

	/*
	 * @brief getter function to opponent grid on board
	 * @return opponent grid reference
	 */
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
