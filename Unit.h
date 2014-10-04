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
#include "Square.h"
#include "drawConstants.h"
#include "drawFunctions.h"

class Unit {

public:

	Unit(string orientation, Point point, string color, Square* square);

private:

string orientation; //0:North 1:South 2:East 3:West
Point llposition; 
string color;
Square* square;

void turn(string direction); 

void move();

string getOrientation();

void setOrientation(string orientation);

Point getLLPosition();

void setLLPosition(Point point);

Square* getSquare();

void setSquare(Square* square);

string getColor();

void setColor(string color);

void moveNorth();
void moveSouth();
void moveEast();
void moveWest();

void turnNorth();
void turnSouth();
void turnEast();
void turnWest();
};

#endif 
