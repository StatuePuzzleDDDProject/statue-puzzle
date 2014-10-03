#include <iostream>
#include "Unit.h"
#include "Square.h"
//#include "category.h"

Unit::Unit(int o, Point p, string c, Square s) {
	this->orientation = o; //0:North 1:South 2:East 3:West
	this->llposition = p; 
	this->color = c;
	this->square = s;
}

int Unit::getOrientation(){
	return this->orientation;
}

void Unit::setOrientation(int o){
	this->orientation = o;
}

Point Unit::getLLPosition(){
	return this->llposition;
}

void Unit::setLLPosition(Point p){
	this->llposition = p;
}

string Unit::getColor(){
	return this->color;
}

void Unit::setColor(string c){
	this->color = c;
}

Square Unit::getSquare(){
	return this->square;
}

void Unit::setSquare(Square s){
	this->square = s;
}

void Unit::turn(int direction)
{
	if(direction == 0)
	{
		this->square.draw();
		drawNorthUnit(squareSize,llposition,this->color);
	}
        if(direction == 1)
	{
		this->square.draw();
		drawSouthUnit(squareSize,llposition,this->color);
	}
        if(direction == 2)
	{
		this->square.draw();	
		drawEastUnit(squareSize,llposition,this->color);
	}
        if(direction == 3)
	{
		this->square.draw();
		drawWestUnit(squareSize,llposition,this->color);
	}
}

void Unit::move(int direction)
{
	
	if(direction == 0)
	{
		Point newllposition = new Point(this->llposition-squareSize,this->llposition);
		bool withinLimits = true;		
		withinLimits = isSquareLoc(newllposition);
		if(withinLimits == true)		
			{
				this->square.draw(squareSize*0.8);		
				drawNorthUnit(squareSize,newllposition,this->color);
				this->square = this->square.neighborNorth;
			}
	}
        if(direction == 1)
	{
		Point newllposition = new Point(this->llposition-squareSize,this->llposition);
		bool withinLimits = true;		
		withinLimits = isSquareLoc(newllposition);
		if(withinLimits == true)		
			{
				this->square.draw(squareSize*0.8);		
				drawSouthUnit(squareSize,newllposition,this->color);
				this->square = this->square.neighborSouth;
			}
	}
        if(direction == 2)
	{
		Point newllposition = new Point(this->llposition-squareSize,this->llposition);
		bool withinLimits = true;		
		withinLimits = isSquareLoc(newllposition);
		if(withinLimits == true)		
			{
				this->square.draw(squareSize*0.8);		
				drawEastUnit(squareSize,newllposition,this->color);
				this->square = this->square.neighborEast;
			}
	}
        if(direction == 3)
	{
		Point newllposition = new Point(this->llposition-squareSize,this->llposition);
		bool withinLimits = true;		
		withinLimits = isSquareLoc(newllposition);
		if(withinLimits == true)		
			{
				this->square.draw(squareSize*0.8);		
				drawWestUnit(squareSize,newllposition,this->color);
				this->square = this->square.neighborWest;
			}
	}
	
}


