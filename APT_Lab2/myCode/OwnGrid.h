/*
 * OwnGrid.h
 *
 *  Created on: 04-Jan-2026
 *      Author: agraw
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_
#include "Ship.h"
#include "Shot.h"
#include<vector>
#include<map>

class OwnGrid {
private:
	int rows;							///< rows in own grid
	int columns;						///< columns in own grid
	std::vector<Ship> ships;			///< ships in own grid
	std::map<int, int> remaningShips;	///< remaining allowed ships
	std::set<GridPosition> shotAt;		///< Every fired shot by opponent

public:
	/*
	 * @brief Constructor to create a own grid with defined rows and columns
	 * @param int row : rows on grid.
	 * @param int columns : columns on grid.
	 */
	OwnGrid(int rows, int columns);

	/*
	 * @brief getter function to get the rows in owngrid
	 * @return rows
	 */
	int getRows() const;

	/*
	 * @brief getter function to get the columns in owngrid
	 * @return columns
	 */
	int getColumns() const;

	/*
	 * @brief Place a ship on owngrid and save it to ships vector
	 * @param Ship& ship : a ship with bow and stern grid positions.
	 * @return bool : True if ship is placed at valid position else false.
	 */
	bool placeShip(const Ship& ship);

	/*
	 * @brief getter function to get the placed ships on owngrid
	 * @return vector<Ship> ships : a vector type of all placed ship.
	 */
	const std::vector<Ship> getShips() const;

	/*
	 * @brief helper function for placeShip to check if a ship of given
	 * lenght is available in map of remainingShips or already occupied.
	 * @return true if the ship can be placed else false.
	 */
	bool isShipAvailable(int lenght) const;

	/*
	 * @brief helper function to remove the ship from map of remaningShips
	 * if it is successfully placed on grid.
	 */
	void occupyShip(int lenght);

	/*
	 * @brief Records that a shot on owngrid is placed by opponent.
	 * @return enum Shot::Impact value NONE if shot is missed, HIT if it
	 * hits the ship, SUNKEN if the hit was a last hit of the ship.
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/*
	 * @brief Records every shot on owngrid placed by the opponent in shotAt
	 * @return set<GridPosition> shotAt.
	 */
	const std::set<GridPosition> getShotAt() const;

};

#endif /* OWNGRID_H_ */
