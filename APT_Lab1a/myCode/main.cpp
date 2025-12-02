// Standard (system) header files
#include <iostream>
#include <cstdlib>

// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"


// Main program
int main ()
{
	ReversiBoard board;				///< Instance of ReversiBoard
	ReversiConsoleView view(&board);///< Instance of Console view


	cout << "Initial board state: " << endl;
	view.print();

	bool cPlayerN = false;

	/*
	 * Infinte loop until the game is over*/
	while(!board.isGameOver()){

		FieldState cPlayer = (cPlayerN == false) ? Player1 : Player2;

		if(!board.hasValidMove(cPlayer)){
			cout << playerName(cPlayer) << " has no valid move, skipping";
			cPlayerN = !cPlayerN;
			continue;
		}

		int x,y;
		cout << playerName(cPlayer) << " Enter the Coordinate (x y): ";
		cin >> x >> y;

		if(x < 0 || x > 7 || y < 0  || y > 7){
			cout << "Invalid Co-ordinates Try Again" <<endl;
			continue;
		}

		cout << "\n" << playerName(cPlayer) <<" place at (" <<
				x << "," << y << ")" << endl;

		bool success = board.setFieldState(x, y, cPlayer);


		if(success){
			cout << "Move Successful" << endl;
			view.print();
			cPlayerN = !cPlayerN;
		}
		else{
			cout << "Invalid Move"<< endl;
		}


	}

	cout << "Game Over" << endl;

	return 0;
}
