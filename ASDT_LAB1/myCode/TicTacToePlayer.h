/*
 * TicTacToePlayer.h
 *
 *  Created on: 01-Dec-2025
 *      Author: agraw
 */

#ifndef TICTACTOEPLAYER_H_
#define TICTACTOEPLAYER_H_

#include"TicTacToeBoard.h"
#include"TicTacToeConsoleView.h"

class TicTacToePlayer {
private:
	FieldState player;
	TicTacToeBoard *board;
	TicTacToeConsoleView *view;
public:
	TicTacToePlayer(FieldState ply, TicTacToeBoard *b, TicTacToeConsoleView *v);


	FieldState getPlayer() const;

	virtual bool placeStone() = 0;

	virtual ~TicTacToePlayer();
};

#endif /* TICTACTOEPLAYER_H_ */
