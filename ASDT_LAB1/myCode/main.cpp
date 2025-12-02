// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
#include "TicTacToeBoard.h"
#include "TicTacToeConsoleView.h"

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
	TicTacToeBoard board;				///< Instance of TicTacToeBoard
	TicTacToeConsoleView view(&board);	///< Instance of Console view


	cout << "Initial board state: " << endl;


	board.setFieldState(1, 1, Player1);
	board.setFieldState(0, 1, Player1);
	board.setFieldState(2, 1, Player1);
	view.print();

	FieldState winner = board.checkWinner() ;
	cout << "the winner is :" <<winner <<endl;

    // TODO: Add your program code here

	return 0;
}
