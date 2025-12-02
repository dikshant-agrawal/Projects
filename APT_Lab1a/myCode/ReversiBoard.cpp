/*
 * ReversiBoard.cpp
 *
 *  Created on: 06-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include "ReversiBoard.h"
#include <iostream>

/**
 * Constructor implementation
 */
ReversiBoard::ReversiBoard(int r, int c) {
	rows = r;
	cols = c;
	board.resize(rows, std::vector<FieldState>(cols, Empty));

	board[3][3] = Player1;
	board[3][4] = Player2;
	board[4][3] = Player2;
	board[4][4] = Player1;
}

FieldState ReversiBoard::getFieldState(int row, int col) const{
	return board[row][col];
}

bool ReversiBoard::canFlip(int row, int col, FieldState player, int testRow,
		int testCol) const {
	FieldState opponent = (player == Player1) ? Player2 : Player1;

	int cRow = row + testRow;
	int cColumn = col + testCol;

	if(cRow < 0 || cRow >= rows || cColumn <0 || cColumn >=cols){
		return false;
	}

	if(board[cRow][cColumn] != opponent){
		return false;
	}

	cRow += testRow;
	cColumn += testCol;

	while(cRow >=0 && cRow < rows && cColumn >=0 && cColumn < cols){
		FieldState cState = board[cRow][cColumn];

		if(cState == Empty){
			return false;
		}

		if(cState == player){
			return true;
		}


		cRow += testRow;
		cColumn += testCol;

	}


	return false;
}

void ReversiBoard::flip(int row, int col, FieldState player, int testRow,
		int testCol) {
	// Check for opponent
	FieldState opponent = (player == Player1) ? Player2 : Player1;

	int cRow = row + testRow;
	int cColumn = col + testCol;

	while (cRow >= 0 && cRow < rows && cColumn >= 0 && cColumn < cols &&
	       board[cRow][cColumn] == opponent)
	{
	    board[cRow][cColumn] = player;
	    cRow += testRow;
	    cColumn += testCol;
	}

}

bool ReversiBoard::setFieldState(int row, int col, FieldState player){

	// If it is out of board boundaries
	if(row < 0 || row >= rows || col < 0 || col >= cols){
		return false;
	}

	if(board[row][col] != Empty){
		return false;
	}

	bool flipped = false;

	for(int testRow = -1; testRow <= 1; testRow++){
		for(int testColumn = -1 ; testColumn <=1; testColumn++){
			if(testRow == 0 && testColumn == 0){
				continue;
			}

			if(canFlip(row, col, player, testRow, testColumn)){
				flip(row, col, player, testRow, testColumn);
				flipped = true;
			}
		}
	}

	if(!flipped){
		return false;
	}

	board[row][col] = player;
	return true;
}

std::string playerName(FieldState p){
	switch(p){
	case FieldState::Player1: return "Player 1 (X)";
	case FieldState::Player2: return "Player 2 (O)";
	default: return "Invalid Player";
	}
}



bool ReversiBoard::isBoardFull() const {
	for(int i = 0; i < rows; i++){
		for(int j = 0 ; j < cols ; j++){
			if(board[i][j] == Empty){
				return false;
			}
		}
	}
	return true;
}

bool ReversiBoard::hasValidMove(FieldState player) const {

	for(int i = 0; i < rows; i++){
		for(int j = 0 ; j < cols ; j++){
			if(board[i][j] != Empty){
				continue;
			}

			for(int testRow = -1; testRow <= 1; testRow++){
				for(int testCol = -1; testCol <= 1; testCol++){
					if(testRow == 0 && testCol == 0){
						continue;
					}
					if(canFlip(i, j, player, testRow, testCol)){
						return true;
					}
				}
			}
		}
	}


	return false;
}

bool ReversiBoard::isGameOver() const {

	return isBoardFull() ||
			(!hasValidMove(Player1) && !hasValidMove(Player2));
}


ReversiBoard::~ReversiBoard() {
}

