#include <iostream>
#include "Unit.h"
#include "Square.h"
//#include "category.h"


Unit::Unit(int o, Point p, string c, Square* s) {
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

Square* Unit::getSquare(){
	return this->square;
}

void Unit::setSquare(Square* s){
	this->square = s;
}

void Unit::turn(int direction)
{
	if(direction == 0)
	{
		this->square->draw(SQUARE_SIZE * 0.8);
		drawNorthUnit(SQUARE_SIZE,llposition,this->color);
	}
        if(direction == 1)
	{
		this->square->draw(SQUARE_SIZE * 0.8);
		drawSouthUnit(SQUARE_SIZE,llposition,this->color);
	}
        if(direction == 2)
	{
		this->square->draw(SQUARE_SIZE * 0.8);	
		drawEastUnit(SQUARE_SIZE,llposition,this->color);
	}
        if(direction == 3)
	{
		this->square->draw(SQUARE_SIZE * 0.8);
		drawWestUnit(SQUARE_SIZE,llposition,this->color);
	}
}

void Unit::move(int direction)
{
	
	if(direction == 0)
	{
		Point newllposition = new Point(llposition.get_x()-SQUARE_SIZE,llposition.get_y());
		bool withinLimits = true;		
		withinLimits = isSquareLoc(newllposition);
		if(withinLimits == true)		
			{
				this->square->draw(SQUARE_SIZE*0.8);		
				drawNorthUnit(SQUARE_SIZE,newllposition,this->color);
				Square* newSquare = square->get_north_neighbor();
				square = newSquare;
			}
	}
        if(direction == 1)
	{
		Point newllposition = new Point(llposition.get_x()-SQUARE_SIZE,llposition.get_y());
		bool withinLimits = true;		
		withinLimits = isSquareLoc(newllposition);
		if(withinLimits == true)		
			{
				this->square->draw(SQUARE_SIZE*0.8);		
				drawSouthUnit(SQUARE_SIZE,newllposition,this->color);
				Square* newSquare = square->get_south_neighbor();
				square = newSquare;
			}
	}
        if(direction == 2)
	{
		Point newllposition = new Point(llposition.get_x()-SQUARE_SIZE,llposition.get_y());
		bool withinLimits = true;		
		withinLimits = isSquareLoc(newllposition);
		if(withinLimits == true)		
			{
				this->square->draw(SQUARE_SIZE*0.8);		
				drawEastUnit(SQUARE_SIZE,newllposition,this->color);
				Square* newSquare = square->get_east_neighbor();
				square = newSquare;
			}
	}
        if(direction == 3)
	{
		Point newllposition = new Point(llposition.get_x()-SQUARE_SIZE,llposition.get_y());
		bool withinLimits = true;		
		withinLimits = isSquareLoc(newllposition);
		if(withinLimits == true)		
			{
				this->square->draw(SQUARE_SIZE*0.8);		
				drawWestUnit(SQUARE_SIZE,newllposition,this->color);
				Square* newSquare = square->get_west_neighbor();
				square = newSquare;
			}
	}
	
}


