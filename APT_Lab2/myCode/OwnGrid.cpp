/*
 * OwnGrid.cpp
 *
 *  Created on: 04-Jan-2026
 *      Author: agraw
 */

#include "OwnGrid.h"


OwnGrid::OwnGrid(int rows, int columns)
		: rows(rows), columns(columns), remaningShips({
										{5,1},
										{4,2},
										{3,3},
										{2,4}}) {}

int OwnGrid::getRows() const {
	return rows;
}

int OwnGrid::getColumns() const {
	return columns;
}

bool OwnGrid::placeShip(const Ship &ship) {
	if(!ship.isValid()){
		return false;
	}

	for(const auto& position : ship.occupiedArea()){
		if(position.getRow() - 'A' + 1 > rows ||
				position.getColumn() > columns){
			return false;
		}
	}

	for(const auto& existing : ships){
		for(const auto& position : ship.occupiedArea()){
			if(existing.blockedArea().count(position)){
				return false;
			}
		}
	}

	int lenght = ship.lenght();

	if(!isShipAvailable(lenght)){
		return false;
	}

	occupyShip(lenght);
	ships.push_back(ship);

	return true;

}

const std::vector<Ship> OwnGrid::getShips() const {
	return ships;
}

bool OwnGrid::isShipAvailable(int lenght) const {
	auto available = remaningShips.find(lenght);
	if(available == remaningShips.end()){
		return false;
	}

	return available->second > 0;
}

void OwnGrid::occupyShip(int lenght) {
	remaningShips[lenght]--;
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot) {

	GridPosition targetHit = shot.getTargetPosition();
	shotAt.insert(targetHit);

	for(const Ship& ship : ships){
		const std::set<GridPosition>& isOccupied = ship.occupiedArea();

		if(isOccupied.count(targetHit) == 1){

			int hitCount = 0;

			for(const auto& position : isOccupied){
				if(shotAt.count(position) == 1){
					++hitCount;
				}
			}

			if(hitCount == ship.lenght()){
				return Shot::Impact::SUNKEN;
			}

			return Shot::Impact::HIT;

		}
	}
	return Shot::Impact::NONE;
}

const std::set<GridPosition> OwnGrid::getShotAt() const {
	return shotAt;
}
