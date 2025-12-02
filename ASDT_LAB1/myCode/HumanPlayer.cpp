/*
 * HumanPlayer.cpp
 *
 *  Created on: 01-Dec-2025
 *      Author: agraw
 */

#include "HumanPlayer.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(FieldState ply, TicTacToeBoard *b, TicTacToeConsoleView *v)
 :TicTacToePlayer(ply, b, v) {
}

bool HumanPlayer::placeStone(){

	return false;
}
