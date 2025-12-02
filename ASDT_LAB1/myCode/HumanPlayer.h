/*
 * HumanPlayer.h
 *
 *  Created on: 01-Dec-2025
 *      Author: agraw
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "TicTacToePlayer.h"

class HumanPlayer : public TicTacToePlayer{
public:
	HumanPlayer(FieldState ply, TicTacToeBoard *b, TicTacToeConsoleView *v);
	virtual bool placeStone() override;
};

#endif /* HUMANPLAYER_H_ */
