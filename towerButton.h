/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             towerButton.h
 PURPOSE:          Towerbuttons are buttons that allow a player to construct towers on the map
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef TOWERBUTTON_H_
#define TOWERBUTTON_H_

#include "button.h"
#include "tower.h"

class TowerButton : public Button {
public:
	TowerButton();
	TowerButton(Point llcorner, double height, std::string text, std::string primaryColor, std::string secondaryColor, Tower tower, double ICON_SIZE);

	/* PURPOSE: draws this towerButton on the interface
	*/
	virtual void draw();

private:
	/* REMARKS: this button's width
	*/
	double ICON_WIDTH;

	/* REMARKS: this button's height
	*/
	double ICON_HEIGHT;

	/* REMARKS: the secondary color of the tower image drawn on this towerButton - see drawMapTower in drawFunctions.h
	*/
	std::string secondaryColor;

	/* REMARKS: the particular tower this towerButton is associated with
	*/
	Tower tower;
};



#endif /* TOWERBUTTON_H_ */
