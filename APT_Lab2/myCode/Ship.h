/*
 * Ship.h
 *
 *  Created on: 03-Jan-2026
 *      Author: agraw
 */

#ifndef SHIP_H_
#define SHIP_H_
#include "GridPosition.h"
#include <set>

class Ship {
private:
	GridPosition bow;	///< GridPosition bow : Stores the end1 of ship
	GridPosition stern;	///< GridPosition stern : Stores the end2 of ship
public:
	/*
	 * @brief Constructor to create a ship on grid
	 * @param GridPosition& bow : position of bow (end1) of the ship
	 * @param GridPosition& Stern : position of stern (end2) of the ship
	 */
	Ship(const GridPosition& bow, const GridPosition& stern);

	/*
	 * @brief To check if the ship placement is valid
	 * The function checks if the ship row is between A-Z and column is >0 ;
	 * It invokes method lenght() to get the lenght of ship and check if
	 * it is between 2 and 5 units
	 * @return true if condition satisfies else false
	 */
	bool isValid() const;

	/*
	 * @brief getter function to fetch the position of bow
	 * @return GridPosition bow
	 */
	GridPosition getBow() const;

	/*
	 * @brief getter function to fetch the position of stern
	 * @return GridPosition stern
	 */
	GridPosition getStern() const;

	/*
	 * @brief Helper function to check the lenght of ship
	 * @return Lenght of ship
	 */
	int lenght() const;

	/*
	 * @brief Iterates over Gridposition to check all the occupied
	 * grids by a particular ship
	 * @return set<GridPosition> with all the GridPositions occupied
	 * of that ship.
	 */
	std::set<GridPosition> occupiedArea() const;

	/*
	 * @brief Iterates over Gridposition to check all the occupied
	 * grids by a particular ship and add all the 8 neighbouring grid blocks
	 * in order to envaluate that no other ship touches it.
	 * @return set<GridPosition> with all the GridPositions blocked by
	 * that ship.
	 */
	std::set<GridPosition> blockedArea() const;

};

#endif /* SHIP_H_ */
