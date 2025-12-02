/*
 * TicTacToePlayer.cpp
 *
 *  Created on: 01-Dec-2025
 *      Author: agraw
 */

#include "TicTacToePlayer.h"

TicTacToePlayer::TicTacToePlayer(FieldState ply, TicTacToeBoard *b, TicTacToeConsoleView *v)
		:player(ply), board(b), view(v){}

TicTacToePlayer::~TicTacToePlayer() {
	// TODO Auto-generated destructor stub
}

FieldState TicTacToePlayer::getPlayer() const {
	return player;
}
