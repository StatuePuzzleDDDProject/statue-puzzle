#include <iostream>
#include "Unit.h"
#include "Square.h"

Unit::Unit(string orientation, Point point, string color, Square* square) {
	this->orientation = orientation; 
	this->llposition = point; 
	this->color = color;
	this->square = square;
}

string Unit::getOrientation(){
	return this->orientation;
}

void Unit::setOrientation(string orientation){
	this->orientation = orientation;
}

Point Unit::getLLPosition(){
	return this->llposition;
}

void Unit::setLLPosition(Point point){
	this->llposition = point;
}

string Unit::getColor(){
	return this->color;
}

void Unit::setColor(string color){
	this->color = color;
}

Square* Unit::getSquare(){
	return this->square;
}

void Unit::setSquare(Square* square){
	this->square = square;
}

void Unit::turnNorth()
{
	this->square->draw(SQUARE_SIZE * 0.8);
	drawNorthUnit(SQUARE_SIZE,llposition,this->color);
	this->orientation = "north";
}

void Unit::turnSouth()
{
	this->square->draw(SQUARE_SIZE * 0.8);
	drawSouthUnit(SQUARE_SIZE,llposition,this->color);
	this->orientation = "south";
}

void Unit::turnEast()
{
	this->square->draw(SQUARE_SIZE * 0.8);	
	drawEastUnit(SQUARE_SIZE,llposition,this->color);
	this->orientation = "east";
}

void Unit::turnWest()
{
	this->square->draw(SQUARE_SIZE * 0.8);
	drawWestUnit(SQUARE_SIZE,llposition,this->color);
	this->orientation = "west";
}

void Unit::turn(string direction)
{
	
       if(direction.compare("left"))
       {
	if(orientation.compare("north") == 0)
		turnWest();
	else if(orientation.compare("south") == 0)
		turnEast();
	else if(orientation.compare("east") == 0)
		turnNorth();
	else if(orientation.compare("west") == 0)
		turnSouth();
       }
       else if(direction.compare("south"))
       {
	if(orientation.compare("north") == 0)
		turnEast();
	else if(orientation.compare("south") == 0)
		turnWest();
	else if(orientation.compare("east") == 0)
		turnSouth();
	else if(orientation.compare("west") == 0)
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
void Unit::move() 
{
 	if(this->orientation.compare("north") == 0)
	{
	 moveNorth();
	}else if(this->orientation.compare("south") == 0)
	{
	 moveSouth();
	}else if(this->orientation.compare("east") == 0)
	{
         moveEast();
	}else if(this->orientation.compare("west") == 0)
	{
         moveWest();
	}	
}


