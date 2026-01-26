/*
 * Shot.h
 *
 *  Created on: 05-Jan-2026
 *      Author: agraw
 */

#ifndef SHOT_H_
#define SHOT_H_
#include"GridPosition.h"

class Shot {
private:
	/*
	 * @brief variable to store shot position on grid
	 */
	GridPosition targetPosition;
public:
	/*
	 * @enum class Impact
	 * @brief define the types of impact on shots
	 */
	enum class Impact{
		NONE,			///< NONE	 : No ship were shot
		HIT,			///< HIT	 : A ship were hit
		SUNKEN			///< SUNKEN	 : Last shot on the ship
	};

	/*
	 * @brief Constructor to create shot fired
	 * @param targetPosition to hold the shots fired
	 */
	Shot(const GridPosition& targetPosition);

	/*
	 * @brief Getter function to fetch targetPosition
	 * @return targetPosition of type GridPosition
	 */
	GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */
