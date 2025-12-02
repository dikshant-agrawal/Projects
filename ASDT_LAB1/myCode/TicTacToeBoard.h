/*
 * TicTacToeBoard.h
 *
 *  Created on: 01-Dec-2025
 *      Author: agraw
 */

#ifndef TICTACTOEBOARD_H_
#define TICTACTOEBOARD_H_

#include <vector>
#include <string>

/**
 * @enum FieldState
 * @brief Represents the state of a field on the board.
 */
enum FieldState{
	Empty,		///< Field is Empty
	Player1,	///< Field occupied by Player 1
	Player2		///< Field occupied by Player 2
};

std::string playerName(FieldState p);

/**
 * @Struct WinCheck
 * @brief Represents the rows, cols and diagnols for winning
 */
struct WinCheck{
	int r1,c1, r2,c2, r3,c3;
};

/**
 * @class TicTacToeBoard
 * @brief Represents a TicTacToeBoard game board with piece placement.
 */
class TicTacToeBoard {
private:
	int rows;	///< Number of rows on the board
	int cols;	///< Number of columns on the board
	std::vector<std::vector<FieldState>> board;		///< 2D board

public:

	/**
	 * @brief Constructor to initialize the board.
	 * @param r Number of rows (default is set to 3)
	 * @param c Number of columns (default is set to 3)
	 **/
	TicTacToeBoard(int r=3, int c=3);

	/**
	 * @brief Get the state of a field at a given position.
	 * @param row for Row index
	 * @param col for Column index
	 * @return FieldState at the given position
	 **/
	FieldState getFieldState(int row, int col) const;

	/**
	 * @brief Set the state of a field at a given position if move is valid.
	 * @param row for Row index
	 * @param col for Column index
	 * @param player for Player making the move
	 * @return True if move is valid and executed, else False
	 **/
	bool setFieldState(int row, int col, FieldState player);


	/*
	 * @brief Check if there is any empty space left on the board
	 **/
	bool isBoardFull() const;

	/**
	 * @brief Check if there's a winner on the board.
	 * @return Player1 / Player2 if winner; Empty if no winner.
	 *
	 */
	FieldState checkWinner() const;

	/**
	 * @brief Check if the game is a draw.
	 * @return True if board is full and no winner.
	 */
	bool isDraw() const;

	/**
	 * @brief Reset the board to start a new game.
	 */
	void resetBoard();

	/*
	 * @brief Destructor class to kill the board
	 */
	virtual ~TicTacToeBoard();
};

#endif /* TICTACTOEBOARD_H_ */



