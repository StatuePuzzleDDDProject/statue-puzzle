/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             attributeBox.h
 PURPOSE:          Displays the current Player's current stats: name, gold, health, and score
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef ATTRIBUTEBOX_H_
#define ATTRIBUTEBOX_H_

#include <vector>
#include "ccc_win.h"
#include "category.h"
#include "player.h"
#include "drawFunctions.h"
#include "drawConstants.h"

class AttributeBox {
public:

	AttributeBox(Player* player, double mapWidth, double mapHeight, std::string color, Point llcorner);

	void calculateTextBoxPositions();

	/* PURPOSE: sets the initial quantities of all the current Player's stats in this attributeBox
	*/
	void initializeQuantities();

	void createTitle();

	/* PURPOSE: displays this attributeBox in the window
	*/
	void draw();

	/* PURPOSE: updates the quantities of all the current Player's stats in this attributeBox to their current values
	*/
	void updateQuantities();


private:
	/* REMARKS: the player whose stats this attributeBox keeps track of
	*/
	Player* player;

	/* REMARKS: the player stats this attributeBox keeps track of
	*/
	vector<Category> categories;
	double BOX_WIDTH;
	double BOX_HEIGHT;
	double TEXT_BOX_WIDTH;
	double TEXT_BOX_HEIGHT;

	/* REMARKS: the number of player stats this attributeBox keeps track of
	*/
	int NUM_STATS;
	std::string title;
	Point titlePos;
	vector<Point> textBoxPositions;
	vector<Point> textBoxTextPositions;
	std::string color;
	Point llcorner;

};



#endif /* ATTRIBUTEBOX_H_ */
