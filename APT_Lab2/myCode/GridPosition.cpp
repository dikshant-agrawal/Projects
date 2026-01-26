/*
 * GridPosition.cpp
 *
 *  Created on: 03-Jan-2026
 *      Author: agraw
 */

#include "GridPosition.h"

GridPosition::GridPosition(char row, int column)
			:row(row), column(column){}

GridPosition::GridPosition(const std::string &position) {
	if(position.length() < 2){
		return;
	}

	//The first element in the string is assigned as row
	row = position[0];

	//Remaining elements is converted to int and assigned as column
	column = std::stoi(position.substr(1));
}

bool GridPosition::isValid() const {
	bool result = row>= 'A' && row<= 'Z' && column >0 ;
	return result;
}

char GridPosition::getRow() const {
	return row;
}

int GridPosition::getColumn() const {
	return column;
}

GridPosition::operator std::string() const {
	return std::string(1, row) + std::to_string(column);
}

bool GridPosition::operator ==(const GridPosition &other) const {
	return row == other.row && column == other.column;
}

/*
 * Operator overloading <
 * This is done in order to arrange the ships in a set in top left
 * to bottom right order as it compares rows and columns*/
bool GridPosition::operator <(const GridPosition &other) const {
	if(row != other.row){
		return row < other.row;
	}
	return column < other.column;
}
