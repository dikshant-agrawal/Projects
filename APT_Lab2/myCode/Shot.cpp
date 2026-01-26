/*
 * Shot.cpp
 *
 *  Created on: 05-Jan-2026
 *      Author: agraw
 */

#include "Shot.h"


Shot::Shot(const GridPosition& targetPosition)
			: targetPosition(targetPosition){}

GridPosition Shot::getTargetPosition() const {
	return targetPosition;
}

