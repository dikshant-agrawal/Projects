/*
 * workPresentation.cpp
 *
 *  Created on: 09-Jan-2026
 *      Author: agraw
 */

#include "Board.h"
#include "ConsoleView.h"
#include <iostream>
#include "parttests.h"


void workPresentation(){

	Board board(10, 10);
	ConsoleView view(&board);

	// Place the first ship on Own Grid
	Ship ownShip1(GridPosition("B2"),GridPosition("B4"));
	board.getOwnGrid().placeShip(ownShip1);
	std::cout<< "Place the first ship on Own Grid" << std::endl;
	view.print(); //Grid View

	// Place the Second ship on Own Grid
	Ship ownShip2(GridPosition("D4"),GridPosition("G4"));
	board.getOwnGrid().placeShip(ownShip2);
	std::cout<< "Place the Second ship on Own Grid" << std::endl;
	view.print(); //Grid View

	// Place the Third ship on Own Grid
	Ship ownShip3(GridPosition("F6"),GridPosition("F9"));
	board.getOwnGrid().placeShip(ownShip3);
	std::cout<< "Place the Third ship on Own Grid" << std::endl;
	view.print(); //Grid View

	// Place the First Shot on Own Grid
	Shot shot1(GridPosition("B2"));
	board.getOwnGrid().takeBlow(shot1);
	std::cout<< "Place the First Shot on Own Grid" << std::endl;
	view.print(); //Grid View

	// Place the Second Shot on Own Grid
	Shot shot2(GridPosition("B3"));
	board.getOwnGrid().takeBlow(shot2);
	std::cout<< "Place the Second Shot on Own Grid" << std::endl;
	view.print(); //Grid View

	// Place the Third Shot on Own Grid
	Shot shot3(GridPosition("B4"));
	board.getOwnGrid().takeBlow(shot3);
	std::cout<< "Place the Third Shot on Own Grid" << std::endl;
	view.print(); //Grid View

	// Place the Fourth Shot on Own Grid
	Shot shot4(GridPosition("A4"));
	board.getOwnGrid().takeBlow(shot4);
	std::cout<< "Place the Fourth Shot on Own Grid" << std::endl;
	view.print(); //Grid View

	board.getOwnGrid().getShotAt().count(GridPosition("A4"));

	//Shots for shotResult in Opponent Grid
	Shot oppShot1(GridPosition("C2"));
	Shot oppShot2(GridPosition("C3"));
	Shot oppShot3(GridPosition("C4"));
	Shot oppShot4(GridPosition("C5"));


	board.getOpponentGrid().shotResult(oppShot1, Shot::Impact::NONE);
	std::cout<< "Place the First MISS Shot on Opponent Grid" << std::endl;
	view.print(); //Grid View

	board.getOpponentGrid().shotResult(oppShot2, Shot::Impact::HIT);
	std::cout<< "Place the Second HIT Shot on Opponent Grid" << std::endl;
	view.print(); //Grid View

	board.getOpponentGrid().shotResult(oppShot3, Shot::Impact::HIT);
	std::cout<< "Place the Third HIT Shot on Opponent Grid" << std::endl;
	view.print(); //Grid View

	board.getOpponentGrid().shotResult(oppShot4, Shot::Impact::SUNKEN);
	std::cout<< "Place the Fourth SUNKEN Shot on Opponent Grid" << std::endl;
	view.print(); //Grid View

}




