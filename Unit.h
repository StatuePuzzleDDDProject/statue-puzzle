/* FILE:             Unit.h
 PURPOSE:          A Unit is either a player or a statue
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <vector>
#include "ccc_win.h"

class Unit {

public:

	Unit(int o, Point p);

private:

int orientation; //0:North 1:South 2:East 3:West
Point position; 

void turn(int direction); //type = 0 => turn and type = 1 => move //direction 0:North 1:South 2:East 3:West

void move(int direction);

int getOrientation();

void setOrientation(int o);

Point getPosition();

void setPosition(Point p);
	
void draw(int type, int direction);
};

#endif 
