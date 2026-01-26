/*
 * part2tests.cpp
 *
 *  Created on: 07-Jan-2026
 *      Author: agraw
 *
 *      Test for ships alignment and placement rules Exercise 2.2
 */

#include "Board.h"
#include "ConsoleView.h"
#include <iostream>
#include "parttests.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTest3(bool condition, std::string failedMessage) {
    if (!condition) {
        std::cout << failedMessage << std::endl;
    }
}

/**
 * @brief testing for takeBlow on own ship and shotResult on opponent ship
 */
void part3tests () {

	Board board(10, 10);
	ConsoleView view(&board);


	// Test takeBlow method in Own Grid
	Ship ownShip1(GridPosition("B2"),GridPosition("B4"));
	Ship ownShip2(GridPosition("D4"),GridPosition("G4"));
	Ship ownShip3(GridPosition("F6"),GridPosition("F9"));

	Shot shot1(GridPosition("B2"));
	Shot shot2(GridPosition("B3"));
	Shot shot3(GridPosition("B4"));
	Shot shot4(GridPosition("A4"));

	board.getOwnGrid().placeShip(ownShip1);
	board.getOwnGrid().placeShip(ownShip2);
	board.getOwnGrid().placeShip(ownShip3);

	assertTest3(board.getOwnGrid().takeBlow(shot1) == Shot::Impact::HIT,
			"Incorrect shot at B2 is captured");
	assertTest3(board.getOwnGrid().takeBlow(shot2) == Shot::Impact::HIT,
			"Incorrect shot at B3 is captured");
	assertTest3(board.getOwnGrid().takeBlow(shot3) == Shot::Impact::SUNKEN,
			"Incorrect shot at B4 is captured");
	assertTest3(board.getOwnGrid().takeBlow(shot4) == Shot::Impact::NONE,
			"Incorrect shot at A4 is captured");

	assertTest3(board.getOwnGrid().getShotAt().count(GridPosition("A4")) ==
			1, "Shot at A4 is not stored");


	//Test for shotResult in Opponent Grid
	Shot oppShot1(GridPosition("C2"));
	Shot oppShot2(GridPosition("C3"));
	Shot oppShot3(GridPosition("C4"));
	Shot oppShot4(GridPosition("C5"));
	Shot oppShot5(GridPosition("F5"));
	Shot oppShot6(GridPosition("G4"));
	Shot oppShot7(GridPosition("G5"));
	Shot oppShot8(GridPosition("G6"));
	Shot oppShot9(GridPosition("I5"));


	board.getOpponentGrid().shotResult(oppShot1, Shot::Impact::NONE);
	board.getOpponentGrid().shotResult(oppShot5, Shot::Impact::NONE);
	board.getOpponentGrid().shotResult(oppShot6, Shot::Impact::NONE);
	board.getOpponentGrid().shotResult(oppShot9, Shot::Impact::NONE);

	board.getOpponentGrid().shotResult(oppShot7, Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(oppShot8, Shot::Impact::HIT);

	board.getOpponentGrid().shotResult(oppShot2, Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(oppShot3, Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(oppShot4, Shot::Impact::SUNKEN);

	std::map<GridPosition, Shot::Impact> ShotData =
			board.getOpponentGrid().getShotsAt();

	assertTest3(ShotData.count(GridPosition("C2")) == 1,
				"Shot at C2 NONE is not stored");

	assertTest3(ShotData.count(GridPosition("C4")) == 1,
				"Shot at C4 HIT is not stored");

	assertTest3(ShotData.count(GridPosition("C5")) == 1,
				"Shot at C5 SUNKEN is not stored");

	//Grid View
	view.print();

}



