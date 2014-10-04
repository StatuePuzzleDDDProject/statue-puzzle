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

void Unit::turnNorth()
{
	this->square->draw(SQUARE_SIZE * 0.8);
	drawNorthUnit(SQUARE_SIZE,llposition,this->color);
	this->orientation = 0;
}

void Unit::turnSouth()
{
	this->square->draw(SQUARE_SIZE * 0.8);
	drawSouthUnit(SQUARE_SIZE,llposition,this->color);
	this->orientation = 1;
}

void Unit::turnEast()
{
	this->square->draw(SQUARE_SIZE * 0.8);	
	drawEastUnit(SQUARE_SIZE,llposition,this->color);
	this->orientation = 2;
}

void Unit::turnWest()
{
	this->square->draw(SQUARE_SIZE * 0.8);
	drawWestUnit(SQUARE_SIZE,llposition,this->color);
	this->orientation = 3;
}

void Unit::turn(int direction)
{
	
       if(direction == 0)
       {
	if(orientation == 0)
		turnWest();
	else if(orientation == 1)
		turnEast();
	else if(orientation == 2)
		turnNorth();
	else if(orientation == 3)
		turnSouth();
       }
       else if(direction == 1)
       {
	if(orientation == 0)
		turnEast();
	else if(orientation == 1)
		turnWest();
	else if(orientation == 2)
		turnSouth();
	else if(orientation == 3)
		turnNorth();
       }
}

void Unit::moveNorth()
{
	Point newllposition(this->llposition.get_x()-SQUARE_SIZE,this->llposition.get_y());
	bool withinLimits = true;
	Square* newSquare = this->square->get_north_neighbor();		
	withinLimits = isSquareLoc(newSquare->get_num());
	if(withinLimits == true)		
	{
		this->square->draw(SQUARE_SIZE*0.8);		
		drawNorthUnit(SQUARE_SIZE,newllposition,this->color);
		this->square = newSquare;
	}
}

void Unit::moveSouth()
{
	Point newllposition(this->llposition.get_x()-SQUARE_SIZE,this->llposition.get_y());
	bool withinLimits = true;	
	Square* newSquare = this->square->get_south_neighbor();	
	withinLimits = isSquareLoc(newSquare->get_num());
	if(withinLimits == true)		
		{
			this->square->draw(SQUARE_SIZE*0.8);		
			drawSouthUnit(SQUARE_SIZE,newllposition,this->color);	
			this->square = newSquare;	 
		}
}

void Unit::moveEast()
{

	Point newllposition(this->llposition.get_x()-SQUARE_SIZE,this->llposition.get_y());
	bool withinLimits = true;	
	Square* newSquare = this->square->get_east_neighbor();	
	withinLimits = isSquareLoc(newSquare->get_num());
	if(withinLimits == true)		
		{
			this->square->draw(SQUARE_SIZE*0.8);		
			drawEastUnit(SQUARE_SIZE,newllposition,this->color);
			this->square = newSquare;
		}
}

void Unit::moveWest()
{
	Point newllposition(this->llposition.get_x()-SQUARE_SIZE,this->llposition.get_y());
	bool withinLimits = true;
	Square* newSquare = this->square->get_west_neighbor();		
	withinLimits = isSquareLoc(newSquare->get_num());
	if(withinLimits == true)		
		{
			this->square->draw(SQUARE_SIZE*0.8);		
			drawWestUnit(SQUARE_SIZE,newllposition,this->color);
			this->square  = newSquare;
		}
}
void Unit::move(int direction) // 0 : left, 1 :right
{
 	if(this->orientation == 0)
	{
	 moveNorth();
	}else if(this->orientation == 1)
	{
	 moveSouth();
	}else if(this->orientation == 2)
	{
         moveEast();
	}else if(this->orientation == 3)
	{
         moveWest();
	}	
}


