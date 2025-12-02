/*
 * TicTacToeConsoleView.cpp
 *
 *  Created on: 01-Dec-2025
 *      Author: agraw
 */

#include "TicTacToeConsoleView.h"
#include <iostream>


using namespace std;

TicTacToeConsoleView::TicTacToeConsoleView(const TicTacToeBoard *board):
		me(board){};

void TicTacToeConsoleView::print() const {

	if(!me){
		return;
	}


	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			FieldState state = me->getFieldState(i,j);
			if(state == Empty){
				cout << ". ";
			}
			else if (state == Player1){
				cout << "X ";
			}
			else{
				cout << "O ";
			}
		}
		cout <<endl;
	}
}

TicTacToeConsoleView::~TicTacToeConsoleView() {
	// TODO Auto-generated destructor stub
}

