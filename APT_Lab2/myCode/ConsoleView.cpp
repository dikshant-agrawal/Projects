/*
 * ConsoleView.cpp
 *
 *  Created on: 04-Jan-2026
 *      Author: agraw
 */

#include "ConsoleView.h"


ConsoleView::ConsoleView(Board* board)
		:board(board){}

void ConsoleView::initGrid(char **grid, int rows, int columns) const {
	for(int r = 0; r< rows; ++r){
		for(int c = 0; c < columns; ++c){
			grid[r][c] = '~';
		}
	}
}



void ConsoleView::fillOwnGrid(char **grid) const {
	const OwnGrid& own = board->getOwnGrid();

	//For No Shots
	for(const Ship& ship : own.getShips()){
		for(const GridPosition& data : ship.occupiedArea()){
			int row = data.getRow() - 'A';
			int column = data.getColumn() - 1;
			grid[row][column] = '#';
		}
	}

	//For Shots
	for(const GridPosition& data : own.getShotAt()){
		int row = data.getRow() - 'A';
		int column = data.getColumn() - 1;

		bool hit = false;
		for(const Ship& ship : own.getShips()){
			if(ship.occupiedArea().count(data)){
				hit = true;
				break;
			}
		}
		grid[row][column] = hit ? 'O' : '^';

	}
}


void ConsoleView::fillOpponentGrid(char **grid) const{
	const OpponentGrid& opponent = board->getOpponentGrid();

	for(const auto& data : opponent.getShotsAt()){
		int row = data.first.getRow() - 'A';
		int column = data.first.getColumn() - 1;

		if(data.second == Shot::Impact::NONE){
			grid[row][column] = '^';
		}
		else{
			grid[row][column] = 'O';
		}
	}

	for(const Ship& ship : opponent.getSunkenShips()){
		for(const GridPosition& data : ship.occupiedArea()){
			int row = data.getRow() - 'A';
			int column = data.getColumn() - 1;
			grid[row][column] = '#';
		}
	}

}

void ConsoleView::printHeader(int columns) {
	std::cout << " ";
	for(int c = 1; c<= columns; ++c){
		std::cout << c << " ";
	}
}

void ConsoleView::print() {
	int rows = board->getRows();
	int columns = board->getColumns();

	char** own = new char*[rows];
	char** opp = new char*[rows];

	for(int i = 0; i< rows; ++i){
		own[i] = new char[columns];
		opp[i] = new char[columns];
	}

	initGrid(own, rows, columns);
	initGrid(opp, rows, columns);

	fillOwnGrid(own);
	fillOpponentGrid(opp);

	printHeader(columns);
	std::cout<< "  ";
	printHeader(columns);
	std::cout<< "\n";

	for (int r = 0; r < rows; ++r) {
		std::cout << char('A' + r) << " ";
		for (int c = 0; c < columns; ++c)
			std::cout << own[r][c] << " ";

		std::cout << "  ";

		std::cout << char('A' + r) << " ";
		for (int c = 0; c < columns; ++c)
			std::cout << opp[r][c] << " ";

		std::cout << "\n";
	}

	for (int i = 0; i < rows; ++i) {
		delete[] own[i];
		delete[] opp[i];
	}
	delete[] own;
	delete[] opp;
}

