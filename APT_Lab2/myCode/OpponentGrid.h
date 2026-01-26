/*
 * OpponentGrid.h
 *
 *  Created on: 04-Jan-2026
 *      Author: agraw
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_
#include"Ship.h"
#include "Shot.h"
#include<vector>
#include<map>

class OpponentGrid {
private:
	int rows;									///< rows in grid
	int columns;								///< columns in grid
	std::map<GridPosition, Shot::Impact> shots;	///< Grid position, Impact
	std::vector<Ship> sunkenShips;				///< Sunken ships

public:
	/*
	 * @brief Constructor to create a opponent grid with given rows
	 * and columns
	 * @param int row : rows on grid.
	 * @param int columns : columns on grid.
	 */
	OpponentGrid(int rows, int columns);

	/*
	 * @brief getter function to get the rows in owngrid
	 * @return rows
	 */
	int getRows();

	/*
	 * @brief getter function to get the columns in owngrid
	 * @return columns
	 */
	int getColumns();

	/*
	 * @brief Records that a shot on owngrid is placed by opponent.
	 * @param Shot& shot: The grid position on which shot is placed
	 * @param Shot::Impact Impact : NONE; HIT or SUNKEN.
	 */
	void shotResult(const Shot& shot, Shot::Impact impact);

	/*
	 * @brief getter function to return shots.
	 * @return map shots
	 */
	std::map<GridPosition, Shot::Impact> getShotsAt() const;

	/*
	 * @brief getter function to return sunkenShips.
	 * @return vector of sunkenShips
	 */
	std::vector<Ship> getSunkenShips() const;
};

#endif /* OPPONENTGRID_H_ */
