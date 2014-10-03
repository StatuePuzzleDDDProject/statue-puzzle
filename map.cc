#include <string>
#include <iostream>
#include "ccc_win.h"
//#include "tower.h"
#include "map.h"
#include "drawConstants.h"
#include "drawFunctions.h"
#include <cstdlib>

// for testing purposes only
Map::Map() {
	this->WIDTH = 1;
	this->HEIGHT = 1;
	this->buildableColor = "forest green";
	this->playerColor = "blue";
	this->statueColor = "red";
	this->endSquareColor = "orange";

	initializeWindow();
	Square* s = new Square();
	vector<Square*> v;
	positions.push_back(v);
	positions[0].push_back(s);
}

Map::~Map() {
	for (int i = 0; i < 30; i++) {
		delete mapSquares[i];
	}
}

Map::Map(std::string buildableColor, double height, double width, double squareSize) {
	this->HEIGHT = height;
	this->WIDTH = width;
	this->buildableColor = buildableColor;
	this->endSquareColor = "orange";
	initializeWindow();

	//first, fill map with buildable squares
	for (int i = 0; i < 30; i++) {
		if (isSquareLoc(i)) {
			bool isEndSquare = endSquare(i);
			std::string squareColor;
			if (isEndSquare) {
					squareColor = endSquareColor;
			} else {
					squareColor = "brown";
			}
			int row = 6;
			if (i > 24) row = 0;
			else if (i > 19) row = 1;
			else if (i > 14) row = 2;
			else if (i > 9) row = 3;
			else if (i > 4) row = 4;
			else {
				row = 5;
			}
			mapSquares[i] = new Square(Point (i % 5 * SQUARE_SIZE + BOARD_OFFSET_X, row * SQUARE_SIZE + BOARD_OFFSET_Y), squareColor, isEndSquare, i);
		} else {
			mapSquares[i] = NULL;
		}
	}

	//then, set square neighbors
	mapSquares[0]->set_south_neighbor(mapSquares[5]);
	mapSquares[0]->set_east_neighbor(mapSquares[1]);

	mapSquares[1]->set_south_neighbor(mapSquares[6]);
	mapSquares[1]->set_east_neighbor(mapSquares[2]);
	mapSquares[1]->set_west_neighbor(mapSquares[0]);

	mapSquares[2]->set_south_neighbor(mapSquares[7]);
	mapSquares[2]->set_east_neighbor(mapSquares[3]);
	mapSquares[2]->set_west_neighbor(mapSquares[1]);

	mapSquares[3]->set_south_neighbor(mapSquares[8]);
	mapSquares[3]->set_east_neighbor(mapSquares[4]);
	mapSquares[3]->set_west_neighbor(mapSquares[2]);

	mapSquares[4]->set_west_neighbor(mapSquares[3]);
	mapSquares[4]->set_south_neighbor(mapSquares[9]);

	//second row
	mapSquares[5]->set_south_neighbor(mapSquares[10]);
	mapSquares[5]->set_east_neighbor(mapSquares[6]);
	mapSquares[5]->set_north_neighbor(mapSquares[0]);

	mapSquares[6]->set_south_neighbor(mapSquares[11]);
	mapSquares[6]->set_east_neighbor(mapSquares[7]);
	mapSquares[6]->set_west_neighbor(mapSquares[5]);
	mapSquares[6]->set_north_neighbor(mapSquares[1]);

	mapSquares[7]->set_south_neighbor(mapSquares[12]);
	mapSquares[7]->set_east_neighbor(mapSquares[8]);
	mapSquares[7]->set_west_neighbor(mapSquares[6]);
	mapSquares[7]->set_north_neighbor(mapSquares[2]);

	mapSquares[8]->set_south_neighbor(mapSquares[13]);
	mapSquares[8]->set_east_neighbor(mapSquares[9]);
	mapSquares[8]->set_west_neighbor(mapSquares[7]);
	mapSquares[8]->set_north_neighbor(mapSquares[3]);

	mapSquares[9]->set_north_neighbor(mapSquares[4]);
	mapSquares[9]->set_west_neighbor(mapSquares[8]);
	mapSquares[9]->set_south_neighbor(mapSquares[14]);

	//third row
	mapSquares[10]->set_north_neighbor(mapSquares[5]);
	mapSquares[10]->set_east_neighbor(mapSquares[11]);

	mapSquares[11]->set_north_neighbor(mapSquares[6]);
	mapSquares[11]->set_east_neighbor(mapSquares[7]);
	mapSquares[11]->set_west_neighbor(mapSquares[5]);

	mapSquares[12]->set_south_neighbor(mapSquares[16]);
	mapSquares[12]->set_east_neighbor(mapSquares[13]);
	mapSquares[12]->set_west_neighbor(mapSquares[11]);
	mapSquares[12]->set_north_neighbor(mapSquares[7]);

	mapSquares[13]->set_south_neighbor(mapSquares[17]);
	mapSquares[13]->set_east_neighbor(mapSquares[14]);
	mapSquares[13]->set_west_neighbor(mapSquares[12]);
	mapSquares[13]->set_north_neighbor(mapSquares[8]);

	mapSquares[14]->set_west_neighbor(mapSquares[13]);
	mapSquares[14]->set_south_neighbor(mapSquares[9]);	

	//fourth row
	mapSquares[16]->set_south_neighbor(mapSquares[21]);
	mapSquares[16]->set_east_neighbor(mapSquares[17]);
	mapSquares[16]->set_north_neighbor(mapSquares[11]);

	mapSquares[17]->set_north_neighbor(mapSquares[12]);
	mapSquares[17]->set_east_neighbor(mapSquares[18]);
	mapSquares[17]->set_west_neighbor(mapSquares[16]);
	mapSquares[17]->set_south_neighbor(mapSquares[22]);

	mapSquares[18]->set_south_neighbor(mapSquares[23]);
	mapSquares[18]->set_west_neighbor(mapSquares[17]);
	mapSquares[18]->set_north_neighbor(mapSquares[13]);

	mapSquares[21]->set_east_neighbor(mapSquares[22]);
	mapSquares[21]->set_north_neighbor(mapSquares[16]);

	mapSquares[22]->set_west_neighbor(mapSquares[21]);
	mapSquares[22]->set_south_neighbor(mapSquares[27]);		
	mapSquares[22]->set_north_neighbor(mapSquares[17]);
	mapSquares[22]->set_east_neighbor(mapSquares[23]);

	mapSquares[23]->set_west_neighbor(mapSquares[22]);
	mapSquares[23]->set_north_neighbor(mapSquares[18]);

	mapSquares[27]->set_north_neighbor(mapSquares[22]);

}

bool Map::endSquare(int num) {
	if (num == 6 || num == 8) return true;
	return false;
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
	for (int i = 0; i < 30; i++) {
		if (mapSquares[i] != NULL) {
			mapSquares[i]->draw(SQUARE_SIZE * 0.8);
		} 
	}
}

std::string Map::getBuildableColor() {
	return buildableColor;
}

void Map::setPositions(vector<vector<Square*> > positions) {
	this->positions = positions;
}


