#include <iostream>
#include "Unit.h"
//#include "category.h"

Unit::Unit(int o, Point p) {
	this->orientation; //0:North 1:South 2:East 3:West
	this->position; 
}

int Unit::getOrientation(){
	return this->orientation;
}

void Unit::setOrientation(int o){
	this->orientation = o;
}

Point Unit::getPosition(){
	return this->position;
}

void Unit::setPosition(Point p){
	this->position = p;
}

void Unit::draw(int type, int direction) //type = 0 => turn and type = 1 => move //direction 0:North 1:South 2:East 3:West
{

}

void Unit::turn(int direction)
{
	//calls draw();
}

void Unit::move(int direction)
{
	//calls draw();
}


