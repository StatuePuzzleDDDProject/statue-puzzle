/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             player.h
 PURPOSE:          A Player is the person playing the TowerDefense game
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>
#include "ccc_win.h"
#include "category.h"
#include "tower.h"

class Player {

public:

	Player();

	Player(std::string name, int gold);

	/* PURPOSE: adds a tower to the player's current tower list - this is
	 * called every time a player constructs a tower on the map
	*/
	void addTower(Tower tower);

	std::string getName() const;
	Category getScoreCategory() const;
	Category getHealthCategory() const;
	Category getGoldCategory() const;
	int getScore();
	int getHealth() const;
	int getGold() const;
	vector<Tower> getTowers() const;
	Tower getLastTower() const;
	int getMaxHealth() const;
	int getScoreToLevel() const;
	int getInitialGold() const;

	void clearTowers();

	void setScore(int score);
	void setHealth(int health);
	void setGold(int gold);
	void setScoreToLevel (int pointsMore);
	void setInitialGold (int gold);

	void addGold(int gold);
	void addScore(int score);
	void takeDamage();
	void levelUp();

private:
	/* REMARKS: The maximum health this player can have
	*/
	int maxHealth;
	std::string name;
	Category score;

	/* REMARKS: The player's current health
	*/
	Category health;

	/* REMARKS: The player's current gold
	*/
	Category gold;

	/* REMARKS: The list of towers this player has constructed on the current map
	*/
	vector<Tower> towers;

	/* REMARKS: how many points this player needs to increase their level;
	 * at every level increase, the player gains health or gold
	*/
	int scoreToLevel;

	/* REMARKS: the amount of gold this player starts with at the beginning of the current map
	*/
	int initialGold;
};

#endif /* PLAYER_H_ */
