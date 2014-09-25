/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             systemUpdater.h
 PURPOSE:          A class for updating the states of all objects in the game
 COMPILER:         gcc version 4.2.1
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef SYSTEMUPDATER_H_
#define SYSTEMUPDATER_H_

#include <string>
#include "map.h"
#include "EnemyUnit.h"
#include "Square.h"
#include "tower.h"
#include "attributeBox.h"
#include "player.h"
#include "path.h"

class SystemUpdater {
public:
	SystemUpdater();
	SystemUpdater (Map* map, Player* player, AttributeBox* playerStats);

	/* PURPOSE: Updates the state of all towers and units on the map as well as waves and player stats
	*/
	void update();
	bool isUpdating();

	/* PURPOSE: Removes the EnemyUnit at the specified position in the EnemyUnit vector from the map
	*/
	void removeEnemy(int position);

private:
	bool inUpdate;
	Map* map;
	vector <EnemyUnit> enemies;
	Player* player;
	AttributeBox* playerStats;

};


#endif /* SYSTEMUPDATER_H_ */
