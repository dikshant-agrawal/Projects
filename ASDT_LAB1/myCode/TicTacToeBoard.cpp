/*
 * TicTacToeBoard.cpp
 *
 *  Created on: 01-Dec-2025
 *      Author: agraw
 */

#include "TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard(int r, int c) {
	rows = r;
	cols = c;
	board.resize(rows, std::vector<FieldState>(cols, Empty));

}

bool TicTacToeBoard::setFieldState(int row, int col, FieldState player) {
	// If it is out of board boundaries
	if(row < 0 || row >= rows || col < 0 || col >= cols){
		return false;
	}

	// If it is already occupied by some player
	if(board[row][col] != Empty){
		return false;
	}

	// Set the player on the board
	board[row][col] = player;
	return true;

}

FieldState TicTacToeBoard::getFieldState(int row, int col) const {
	return board[row][col];
}


bool TicTacToeBoard::isBoardFull() const {
	for(int i = 0; i < rows; i++){
		for(int j = 0 ; j < cols ; j++){
			if(board[i][j] == Empty){
				return false;
			}
		}
	}
	return true;
}

///<Array to hold the values of rows and cols
WinCheck wins[8] = {
		{0,0, 0,1, 0,2},	///<Row 0
		{1,0, 1,1, 1,2},	///<Row 1
		{2,0, 2,1, 2,2},	///<Row 2

		{0,0, 1,0, 2,0},	///<Col 0
		{0,1, 1,1, 2,1},	///<Col 1
		{0,2, 1,2, 2,2},	///<Col 2

		{0,0, 1,1, 2,2},	///<Main Diagonal
		{0,2, 1,1, 2,0},	///<Anti Diagonal

};

FieldState TicTacToeBoard::checkWinner() const {
	for(int i=0; i<8; i++){
		FieldState c1 = board[wins[i].r1][wins[i].c1];
		FieldState c2 = board[wins[i].r2][wins[i].c2];
		FieldState c3 = board[wins[i].r3][wins[i].c3];

		if(c1 != Empty && c1==c2 && c2==c3){
			return c1;
		}
	}
	return Empty;

}

bool TicTacToeBoard::isDraw() const {
	return isBoardFull() && (checkWinner()== Empty);
}

void TicTacToeBoard::resetBoard() {
	for(int i = 0; i < rows; i++){
		for(int j = 0 ; j < cols ; j++){
			board[i][j] = Empty;
		}
	}
}

TicTacToeBoard::~TicTacToeBoard() {
	// TODO Auto-generated destructor stub
}

