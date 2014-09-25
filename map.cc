#include <string>
#include <iostream>
#include "ccc_win.h"
#include "tower.h"
#include "map.h"
#include "drawConstants.h"
#include <cstdlib>

// for testing purposes only
Map::Map() {
	this->path = Path();
	this->WIDTH = 1;
	this->HEIGHT = 1;
	this->buildableColor = "blue";
	this->pathColor = "black";

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

Map::Map(Path path, std::string buildableColor, std::string pathColor, double height, double width, double squareSize, vector<Wave> waves) {
	this->path = path;
	this->HEIGHT = height;
	this->WIDTH = width;
	this->buildableColor = buildableColor;
	this->pathColor = pathColor;
	this->waves = waves;

	initializeWindow();

	//first, fill map with buildable squares
	for (int row = 0; row < HEIGHT; row++) {
		positions.push_back(vector<Square*>());
		for (int col = 0; col < WIDTH; col++) {
			positions[row].push_back(new Square(Point (col, row + MAP_OFFSET)));
		}
	}
	//then, change appropriate squares to path squares (set direction, make unbuildable)
	definePathSquares();



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
	drawPath();
}

//changes appropriate squares to path squares in the map array
void Map::definePathSquares() {
	int startingXPos = path.getStartingXPos();
	int startingYPos = path.getStartingYPos();
	string pathDirections = path.getDirections();
	int row = startingYPos;
	int col = startingXPos;
	for (int unsigned i = 0; i < pathDirections.size(); i++) {
		positions[row][col]->set_color("brown");
		positions[row][col]->set_path(true);
		pathSquares.push_back(Point (col, row));
		if (pathDirections.at(i) == 'n') {
			row++;
		} else if (pathDirections.at(i) == 's') {
			row--;
		} else if (pathDirections.at(i) == 'e') {
			col++;
		} else if (pathDirections.at(i) == 'w') {
			col--;
		} else {
			cerr << "invalid character in path" << endl;
			exit(1);
		}
	}
	//extract starting position of path (must be on edge of map) from path string
	//change starting position square to a path square
	//follow directions in string, char by char, changing next square to a path square
	positions[row][col]->set_color("brown");
	positions[row][col]->set_path(true);
	pathSquares.push_back(Point (col, row));
}

void Map::drawPath() {
	for (int unsigned i = 0; i < pathSquares.size(); i++) {
		int x = pathSquares[i].get_x();
		int y = pathSquares[i].get_y();
		positions[y][x]->draw(Point(x, y + MAP_OFFSET), SQUARE_SIZE * 0.8);
	}
}

EnemyUnit Map::nextUnit() {
	EnemyUnit enemyToRelease = waves[0].releaseEnemy();
	return enemyToRelease;
}

void Map::removeWave() {
	for (int unsigned i = 1; i < waves.size(); i++) {
		waves [i - 1] = waves [i];
	}
	waves.pop_back();
}

Path Map::getPath() {
	return path;
}

std::string Map::getBuildableColor() {
	return buildableColor;
}

std::string Map::getPathColor() {
	return pathColor;
}

vector<vector<Square*> > Map::getPositions() {
	return positions;
}

vector<Point> Map::getPathSquares() {
	return pathSquares;
}
vector<Wave> Map::getWaves() {
	return waves;
}

int Map::getOffset() {
	return MAP_OFFSET;
}

void Map::setPositions(vector<vector<Square*> > positions) {
	this->positions = positions;
}
