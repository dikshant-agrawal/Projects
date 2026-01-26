/*
 * Ship.cpp
 *
 *  Created on: 03-Jan-2026
 *      Author: agraw
 */

#include "Ship.h"


Ship::Ship(const GridPosition &bow, const GridPosition &stern)
			: bow(bow), stern(stern){}

bool Ship::isValid() const {
	if(!bow.isValid() || !stern.isValid()){
		return false;
	}

	bool isHorizontal = (bow.getRow() == stern.getRow());
	bool isVertical = (bow.getColumn() == stern.getColumn());

	if(!isHorizontal && !isVertical){
		return false;
	}

	int shipLenght = lenght();

	if (shipLenght >= 2 && shipLenght <= 5){
		return true;
	}
	else{
		return false;
	}

}


int Ship::lenght() const {
	if(bow.getRow() == stern.getRow()){
		int shipLenght = bow.getColumn() - stern.getColumn();
		return (shipLenght < 0 ? -shipLenght : shipLenght) + 1;
	}
	else{
		int shipLenght = bow.getRow() - stern.getRow();
		return (shipLenght < 0 ? -shipLenght : shipLenght) + 1;
	}
}

GridPosition Ship::getBow() const {
	return bow;
}

GridPosition Ship::getStern() const {
	return stern;
}

std::set<GridPosition> Ship::occupiedArea() const {
	std::set<GridPosition> result;

	if(bow.getRow() == stern.getRow()){
		int bowPos = bow.getColumn();
		int sternPos = stern.getColumn();

		if(bowPos > sternPos){
			int tempVar = bowPos;
			bowPos = sternPos;
			sternPos = tempVar;
		}

		for(int x = bowPos; x <= sternPos; ++x){
			result.insert(GridPosition(bow.getRow(), x));
		}
	}

	else{
		char bowPos = bow.getRow();
		char sternPos = stern.getRow();

		if(bowPos > sternPos){
			char tempVar = bowPos;
			bowPos = sternPos;
			sternPos = tempVar;
		}

		for(char x = bowPos; x<= sternPos ; ++x){
			result.insert(GridPosition(x, bow.getColumn()));
		}
	}

	return result;
}


std::set<GridPosition> Ship::blockedArea() const {
	std::set<GridPosition> result;

	for (const auto& testPos : occupiedArea()){
		for(int pX = -1; pX <= 1; ++pX){
			for(int pY = -1; pY <= 1; ++pY){
				GridPosition block(testPos.getRow() + pX,
									testPos.getColumn() + pY);
				if(block.isValid()){
					result.insert(block);
				}
			}
		}
	}

	return result;
}
