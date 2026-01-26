/*
 * part2tests.cpp
 *
 *  Created on: 07-Jan-2026
 *      Author: agraw
 *
 *      Test for ships alignment and placement rules Exercise 2.2
 */

#include "Board.h"
#include <iostream>
#include "parttests.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue2(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * testing for ship placement and valid positions
 */
void part2tests () {

	//Horizontal Ship placement test
    GridPosition bow1("B2");
    GridPosition stern1("B4");
    Ship Ship1(bow1, stern1);


    assertTrue2(Ship1.isValid(),
    		"Bow:B2, Stern: B4 Horizontal Ship not considered valid");
    assertTrue2(Ship1.getBow() == bow1,
    		"Bow:B2 getBow returns wrong value");
    assertTrue2(Ship1.getStern() == stern1,
    		"Stern:B4 getStern returns wrong value");

    //Vertical Ship placement test
    GridPosition bow2("B2");
    GridPosition stern2("D2");
    Ship Ship2(bow2, stern2);

    assertTrue2(Ship2.isValid(),
    		"Bow:B2, Stern: D2 Vertical Ship not considered valid");
    assertTrue2(Ship2.getBow() == bow2,
    		"Bow:B2 getBow returns wrong value");
    assertTrue2(Ship2.getStern() == stern2,
    		"Stern:D2 getStern returns wrong value");

    //Diagonal Ship placement test
    GridPosition bow3("B2");
    GridPosition stern3("D4");
    Ship Ship3(bow3, stern3);

    assertTrue2(!Ship3.isValid(),
    		"Bow:B2, Stern: D4 Diagonal Ship is considered valid");

    //Ship of Length 6 placement test
    GridPosition bow4("B2");
    GridPosition stern4("B8");
    Ship Ship4(bow4, stern4);

    assertTrue2(!Ship4.isValid(),
    		"Bow:B2, Stern: B8 Ship of length 6 is considered valid");


    //Occupied Area Function testing
    assertTrue2(
        Ship{GridPosition{"B2"}, GridPosition{"E2"}}.occupiedArea()
        == set<GridPosition>{
            GridPosition{"B2"},
            GridPosition{"C2"},
            GridPosition{"D2"},
            GridPosition{"E2"}
        },
        "occupiedArea() incorrect for vertical ship"
    );

    assertTrue2(
        Ship{GridPosition{"C4"}, GridPosition{"C6"}}.occupiedArea()
        == set<GridPosition>{
            GridPosition{"C4"},
            GridPosition{"C5"},
            GridPosition{"C6"}
        },
        "occupiedArea() incorrect for horizontal ship"
    );


    //Blocked Area placement testing
    OwnGrid grid{10, 10};


    Ship s1{GridPosition{"B2"}, GridPosition{"B4"}};
    Ship s2{GridPosition{"D2"}, GridPosition{"D4"}};
    Ship s3{GridPosition{"C4"}, GridPosition{"E4"}};  	// touches s1
    Ship s4{GridPosition{"B3"}, GridPosition{"B5"}};	//Overlaps s1

    assertTrue2(grid.placeShip(s1),
               "Failed to place valid first ship");

    assertTrue2(grid.placeShip(s2),
               "Failed to place non-touching second ship");

    assertTrue2(!grid.placeShip(s3),
               "Placed ship that touches another ship");

    assertTrue2(!grid.placeShip(s4),
               "Placed overlapping ship");

}





