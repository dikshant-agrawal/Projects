/*
 * ReversiBoard.h
 *
 *  Created on: 06-Nov-2025
 *      Author: Dikshant Agrawal
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

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
 * @class ReversiBoard
 * @brief Represents a Reversi game board with piece placement & validation.
 */
class ReversiBoard {
private:
	int rows;	///< Number of rows on the board
	int cols;	///< Number of columns on the board
	std::vector<std::vector<FieldState>> board;		///< 2D board

	/**
	 * @param row for Row index
	 * @param col for Column index
	 * @param player for Current player
	 * @param testRow for Row Direction (-1,0,1)
	 * @param testRow for Column Direction (-1,0,1)
	 * @return True is fliping is possible
	 **/
	bool canFlip(int row, int col, FieldState player, int testRow,
			int testCol) const;

	/**
	 * @brief Flip opponent pieces in a given direction.
	 * @param row for Row index
	 * @param col for Column index
	 * @param player for Current player
	 * @param testRow for Row Direction (-1,0,1)
	 * @param testRow for Column Direction (-1,0,1)
	 **/
	void flip(int row, int col, FieldState player, int testRow,
			int testCol);

public:
	/**
	 * @brief Constructor to initialize the board.
	 * @param r Number of rows (default is set to 8)
	 * @param c Number of columns (default is set to 8)
	 **/
	ReversiBoard(int r=8, int c=8);

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

	/*
	 * @brief Check if there the player has any valid move left
	 **/
	bool hasValidMove(FieldState player) const;

	/*
	 * @brief Check if the game is over or not
	 **/
	bool isGameOver() const;

	/*
	 * @brief Destructor class to kill the board
	 */
	virtual ~ReversiBoard();
};

#endif /* REVERSIBOARD_H_ */
