/*
 * ReversiConsolleView.cpp
 *
 *  Created on: 13-Nov-2025
 *      Author: Dikshant Agrawal
 */

#include <iostream>
#include "ReversiConsoleView.h"


using namespace std;

ReversiConsoleView::ReversiConsoleView(const ReversiBoard* board) :
		me(board){};

void ReversiConsoleView::print() const {

	if(!me){
		return;
	}



	cout << "  0 1 2 3 4 5 6 7" << endl;
	for(int i = 0 ; i < 8 ; i++){
		cout << i << " ";
		for(int j = 0 ; j < 8 ; j++){
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



ReversiConsoleView::~ReversiConsoleView() {
	// TODO Auto-generated destructor stub
}

