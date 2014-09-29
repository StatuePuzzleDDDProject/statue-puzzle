#include <string>
#include <iostream>
#include "ccc_win.h"
//#include "tower.h"
#include "map.h"
#include "drawConstants.h"
#include <cstdlib>

// for testing purposes only
Map::Map() {
	this->WIDTH = 1;
	this->HEIGHT = 1;
	this->buildableColor = "blue";

	initializeWindow();
	Square* s = new Square();
	vector<Square*> v;
	positions.push_back(v);
	positions[0].push_back(s);
}

Map::~Map() {
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			delete positions[row][col];
		}
	}
}

Map::Map(std::string buildableColor, double height, double width, double squareSize) {
	this->HEIGHT = height;
	this->WIDTH = width;
	this->buildableColor = buildableColor;

	initializeWindow();

	//first, fill map with buildable squares
	for (int row = 0; row < HEIGHT; row++) {
		positions.push_back(vector<Square*>());
		for (int col = 0; col < WIDTH; col++) {
			positions[row].push_back(new Square(Point (col, row + MAP_OFFSET)));
		}
	}




}

void Map::initializeWindow() {
	cwin.coord(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0);
}

// draws the map in the window with unit path and appropriate colors
void Map::draw() {
	for (double i = 0; i < WIDTH; i += 0.05) {
		Point lineStart (i, MAP_OFFSET);
		Point lineEnd (i, HEIGHT + MAP_OFFSET);
		Line toDraw (lineStart, lineEnd, buildableColor);
		cwin << toDraw;
	}
}


std::string Map::getBuildableColor() {
	return buildableColor;
}

vector<vector<Square*> > Map::getPositions() {
	return positions;
}

int Map::getOffset() {
	return MAP_OFFSET;
}

void Map::setPositions(vector<vector<Square*> > positions) {
	this->positions = positions;
}
