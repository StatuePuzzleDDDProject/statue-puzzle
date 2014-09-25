/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             tower.h
 PURPOSE:          Towers are objects built on the map by the player that destroy units.
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef TOWER_H_
#define TOWER_H_

#include <string>
#include "type.h"
#include "Square.h"

class Tower {
public:

	Tower();

	Tower(std::string name, int damage, int range, int attackDelay, int cost, Type type, Square location, std::string colorA, std::string colorB);

	std::string getName() const;
	int getDamage() const;
	int getRange() const;
	int getAttackDelay() const;
	Type getType() const;
	Square getLocation() const;
	bool getCanAttack() const;
	std::string getColorA() const;
	std::string getColorB() const;
	int getDelayCount() const;
	int getCost() const;

	void setName(std::string name);
	void setDamage(int damage);
	void setRange(int range);
	void setType(Type type);
	void setAttackDelay(int attackDelay);
	void setLocation(Square location);
	void setCanAttack(bool canAttack);
	void setColorA(std::string color);
	void setColorB(std::string color);
	void setDelayCount(int delayCount);
	void setCost(int cost);

	/* PURPOSE: makes this tower attack the EnemyUnit at the specified Square
	*/
	void attack(Square square);

	/* PURPOSE: draws this tower on the map
	*/
	void draw();

	/* RETURNS: true if the specified Square is within this tower's attack radius, false otherwise
	*/
	bool inRange(Square occupiedSquare);

	/* PURPOSE: increments the delayCount counter
	*/
	void countDelay();


private:
	std::string name;

	int damage;
	int range;
	int attackDelay;
	Type type;
	Square location;
	bool canAttack;

	std::string colorA;
	std::string colorB;

	/* REMARKS: the counter that keeps track of when this tower may attack based on its attackDelay; if this tower's
	 * delayCount is greater than its attackDelay, it can attack
	*/
	int delayCount;

	int cost;
};

#endif /* TOWER_H_ */
