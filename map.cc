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
	for (int row = 0; row < 6; row++) {
		for (int col = 0; col < 5; col++) {
			if (isSquareLoc(row,col)) {
				mapSquares[row][col] = new Square(Point (col * SQUARE_SIZE + BOARD_OFFSET_X, (5-row) * SQUARE_SIZE + BOARD_OFFSET_Y));
			} else {
				mapSquares[row][col] = NULL;
			}
		}
	}


}

void Map::initializeWindow() {
	cwin.coord(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0);
}

// draws the map in the window with appropriate colors
void Map::draw() {
	for (double i = 0; i < WIDTH; i += 0.05) {
		Point lineStart (i, 0);
		Point lineEnd (i, HEIGHT);
		Line toDraw (lineStart, lineEnd, buildableColor);
		cwin << toDraw;
	}
	drawSquares();

}

void Map::drawSquares() {
	for (int row = 0; row < 6; row++) {
		for (int col = 0; col < 5; col++) {
			if (mapSquares[row][col] != NULL) {
				mapSquares[row][col]->draw(SQUARE_SIZE * 0.8);
			} 
		}
	}
}

bool Map::isSquareLoc(int row, int col) {
	if (row < 3) return true;
	if ((row == 3 || row == 4) && (col > 0 && col < 4)) return true;
	if (row == 5 && col == 2) return true;
	return false;
}

std::string Map::getBuildableColor() {
	return buildableColor;
}

vector<vector<Square*> > Map::getPositions() {
	return positions;
}

void Map::setPositions(vector<vector<Square*> > positions) {
	this->positions = positions;
}
