#include "Square.h"
#include <iostream>
#include "drawFunctions.h"

Square::Square() {
	this->color = "blue";
	this->isBuildable = false;
	this->isPath = false;
	this->isOccupied = false;
	this->location = Point(15, 15);
}

Square::Square(Point location) {
	this->color = "blue";
	this->isBuildable = false;
	this->isPath = false;
	this->isOccupied = false;
	this->location = location;
}

Square::Square(std::string color, bool isBuildable, bool isPath, Point location) {
	this->color = color;
	this->isBuildable = isBuildable;
	this->isPath = isPath;
	this->isOccupied = false;
	this->location = location;
}

void Square::draw(Point location, double size) {
	drawSolidRectangle(size, size, location, WIDTH_INCREMENT, color);

}

std::string Square::get_color() const {
	return color;
}

bool Square::get_buildable() const {
	return isBuildable;
}

bool Square::get_path() const {
	return isPath;
}

bool Square::get_occupied() const {
	return isOccupied;
}

Point Square::get_location() {
	return location;
}

void Square::set_color(std::string color) {
	this->color = color;
}

void Square::set_buildable(bool isBuildable) {
	this->isBuildable = isBuildable;
}

void Square::set_path(bool isPath) {
	this->isPath = isPath;
}

void Square::set_occupied(bool isOccupied) {
	this->isOccupied = isOccupied;
}

void Square::set_location(Point location) {
	this->location = location;
}
