/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             EnemyUnit.h
 PURPOSE:          EnemyUnits move across a map's path and must be destroyed by a player's towers
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef ENEMYUNIT_H_
#define ENEMYUNIT_H_

#include <string>
#include "type.h"
#include "tower.h"
#include "Square.h"

class EnemyUnit {
public:
	EnemyUnit();
	EnemyUnit(std::string name, int speed, Type type, int goldReward, int scoreReward, int maxHealth, std::string color, Square square);

	/* PURPOSE: moves this unit to the specified Square
	*/
	void move(Square square);

	void takeDamage(Tower tower);

	bool isDead();

	/* PURPOSE: Draws this unit on the map
	*/
	void drawUnit();

	void setName(std::string name);
	void setSpeed(int speed);
	void setType(Type type);
	void setGoldReward(int goldReward);
	void setScoreReward(int scoreReward);
	void setMaxHealth(int maxHealth);
	void setDirection(char direction);
	void setColor(std::string color);
	void setSquare(Square square);

	std::string getName();
	int getSpeed();
	Type getType();
	int getGoldReward();
	int getScoreReward();
	int getMaxHealth();
	int getHealth();
	char getDirection();
	std::string getColor();
	Square getSquare();
	int getDistanceTraveled();


private:
	std::string name;
	int speed;
	Type type;

	/* REMARKS: The gold the player receives when this unit is killed
	*/
	int goldReward;

	/* REMARKS: The points the player receives when this unit is killed
	*/
	int scoreReward;

	/* REMARKS: The maximum health a unit can have
	*/
	int maxHealth;

	/* REMARKS: The unit's current health
	*/
	int health;

	/* REMARKS: The direction this unit is currently travelling in (n, s, e, w,)
	*/
	char direction;
	std::string color;

	/* REMARKS: The Square this unit is currently on
	*/
	Square square;

	/* REMARKS: The total number of squares this unit has occupied
	*/
	int distanceTraveled;
};


#endif /* ENEMYUNIT_H_ */



