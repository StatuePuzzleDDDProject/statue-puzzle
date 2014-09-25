/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             constructionBox.h
 PURPOSE:          The user interface for building towers, ending the current game, and starting the next wave
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef CONSTRUCTIONBOX_H_
#define CONSTRUCTIONBOX_H_

#include "ccc_win.h"
#include "category.h"
#include "player.h"
#include "tower.h"
#include "drawConstants.h"
#include "drawFunctions.h"
#include "Square.h"
#include "button.h"
#include "towerButton.h"

class ConstructionBox {
public:

	ConstructionBox();

	ConstructionBox(vector<Tower> towers, double mapWidth, double mapHeight, std::string color, Point llcorner);

	void createTitle();

	void createIcons();

	void createButtons();

	void draw();

	Button getReadyButton() const;

	Button getCancelButton() const;

	Button getEndGameButton() const;

	double getBoxHeight() const;

	double getBoxWidth() const;

	vector<TowerButton> getTowerButtons() const;

	vector<Tower> getTowers() const;


private:
	vector<Tower> towers;
	vector<TowerButton> towerButtons;
	Button cancelTower;
	Button ready;
	Button endGame;
	double BOX_WIDTH;
	double BOX_HEIGHT;

	/* REMARKS: the width of each towerButton in this ConstructionBox
	*/
	double ICON_WIDTH;

	/* REMARKS: the height of each towerButton in this ConstructionBox
	*/
	double ICON_HEIGHT;
	std::string title;
	Point titlePos;

	/* REMARKS: the number of tower options the player has for building towers
	*/
	int NUM_STATS;
	vector<Point> iconTextPositions;
	vector<Point> iconPositions;
	std::string color;
	Point llcorner;

};


#endif /* CONSTRUCTIONBOX_H_ */
