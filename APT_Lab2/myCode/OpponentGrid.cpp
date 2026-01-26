/*
 * OpponentGrid.cpp
 *
 *  Created on: 04-Jan-2026
 *      Author: agraw
 */

#include "OpponentGrid.h"

OpponentGrid::OpponentGrid(int rows, int columns)
		:rows(rows), columns(columns){}

int OpponentGrid::getRows() {
	return rows;
}

int OpponentGrid::getColumns() {
	return columns;
}


void OpponentGrid::shotResult(const Shot& shot, Shot::Impact impact)
{
    GridPosition targetPos = shot.getTargetPosition();
    shots[targetPos] = impact;

    if (impact != Shot::Impact::SUNKEN){
    	return;
    }

    GridPosition bow = targetPos;
    GridPosition stern = targetPos;

    // vertical scan
    for (char r = targetPos.getRow() - 1; r >= 'A'; r--) {
        GridPosition Pos(r, targetPos.getColumn());
        if (!shots.count(Pos) || shots[Pos] == Shot::Impact::NONE){
        	break;
        }
        bow = Pos;
    }

    for (char r = targetPos.getRow() + 1; r <= 'A' + rows - 1; r++) {
        GridPosition Pos(r, targetPos.getColumn());
        if (!shots.count(Pos) || shots[Pos] == Shot::Impact::NONE){
        	break;
        }
        stern = Pos;
    }

    // horizontal scan
    if (bow == stern) {
        for (int c = targetPos.getColumn() - 1; c >= 1; c--) {
            GridPosition Pos(targetPos.getRow(), c);
            if (!shots.count(Pos) || shots[Pos] == Shot::Impact::NONE){
            	break;
            }
            bow = Pos;
        }

        for (int c = targetPos.getColumn() + 1; c <= columns; c++) {
            GridPosition Pos(targetPos.getRow(), c);
            if (!shots.count(Pos) || shots[Pos] == Shot::Impact::NONE){
            	break;
            }
            stern = Pos;
        }
    }

    sunkenShips.push_back(Ship(bow, stern));
}


std::map<GridPosition, Shot::Impact> OpponentGrid::getShotsAt() const {
	return shots;
}

std::vector<Ship> OpponentGrid::getSunkenShips() const{
	return sunkenShips;
}
