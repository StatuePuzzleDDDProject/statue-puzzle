/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             wave.h
 PURPOSE:          A class that holds a group of EnemyUnits that move through the map's path when systemUpdater updates
 COMPILER:         gcc version 4.2.1
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef WAVE_H_
#define WAVE_H_

#include "EnemyUnit.h"
#include <vector>
#include <string>

class Wave {
public:
	Wave();
	Wave(vector<EnemyUnit> enemies);

	/* PURPOSE: Releases a single EnemyUnit from this wave onto the map
	 * RETURNS: the EnemyUnit released
	*/
	EnemyUnit releaseEnemy();

	vector<EnemyUnit> getWave();
	void setWave(vector<EnemyUnit> enemies);

private:
	vector <EnemyUnit> enemies;
};


#endif /* WAVE_H_ */
