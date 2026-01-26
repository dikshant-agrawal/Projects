/*
 * GridPosition.h
 *
 *  Created on: 03-Jan-2026
 *      Author: agraw
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include "iostream"

class GridPosition {
private:
	char row;			///< row on grid
	int column;			///< column on grid
public:

	/*
	 * @brief Constructor to create a Grid Position
	 * @param int row : row on grid.
	 * @param int columns : column on grid.
	 */
	GridPosition(char row, int column);

	/*
	 * @brief Constructor to create a Grid Position using String Position
	 * and store it in row and column
	 * @param String Position : Parses the Row and Column from string
	 */
	GridPosition(const std::string& position);


	bool isValid() const;

	/*
	 * @brief getter function to get the row
	 * @return row
	 */
	char getRow() const;

	/*
	 * @brief getter function to get the column
	 * @return column
	 */
	int getColumn() const;

	/*
	 * @brief operator overloading of string to make a string from
	 * row and column
	 */
	operator std::string() const;

	/*
	 * @brief operator overloading of == which compares if row is
	 * equal and column is equal then the grid position is equal
	 * @return true if the row and column are same.
	 */
	bool operator==(const GridPosition& other) const;

	/*
	 * @brief operator overloading of < as set uses this internally to
	 * arrange itself in ascending order.
	 * And hence the set can be arranged in Top-left - bottom-right sequence
	 * @return true if the condition is satisfied else false.
	 */
	bool operator<(const GridPosition& other) const;
};

#endif /* GRIDPOSITION_H_ */
