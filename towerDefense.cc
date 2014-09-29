/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             towerDefense.cc
 PURPOSE:          Tower Defense Game: Main Game
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/
#include "ccc_win.h"
#include "player.h"
//#include "type.h"
//#include "tower.h"
//#include "path.h"
#include "map.h"
//#include "constructionBox.h"
//#include "attributeBox.h"
//#include "button.h"
#include "drawFunctions.h"
#include "drawConstants.h"
//#include "systemUpdater.h"
//#include "gameMaps.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//Button newGame;
//Button quit;
//Button continueButton;
Map* currentMap;
Player* player;
//ConstructionBox towerBox;
//AttributeBox* playerStats;
//GameMaps* allMaps;





void drawInterface() {
	//playerStats->draw();


}

void drawMap(Map* map) {
	map->draw();
}




// finds the square on the map that Point p is inside
Square* pointToSquare(Point p) {
	vector<vector<Square*> > mapSquares = currentMap->getPositions();
	for (unsigned int i = 0; i < mapSquares.size(); i++) {
		for (unsigned int j = 0; j < mapSquares[i].size(); j++) {
			double x = p.get_x();
			double y = p.get_y();
			double squareX = mapSquares[i][j]->get_location().get_x();
			double squareY = mapSquares[i][j]->get_location().get_y();
			if (x >= squareX && x <= squareX + SQUARE_SIZE && y >= squareY && y <= squareY + SQUARE_SIZE) {
				return mapSquares[i][j];
			}
		}
	}
	//need to error handle here
	return new Square();
}

void takeOutTheTrash() {
	delete currentMap;
	delete player;
}

int ccc_win_main() {
	cwin.coord(0,30,30,0);
	// player starts new game, enters a name
	//drawStartScreen();
	Point clickPos(0,0);
	currentMap = new Map ("forest green", MAP_HEIGHT, MAP_WIDTH, SQUARE_SIZE);
	drawMap(currentMap);
	drawInterface();
	while(true) {
		
		

			

			// new map, new gameMaps
			//allMaps = new GameMaps();


			//SystemUpdater systemUpdater(currentMap, player, playerStats);
			clickPos = Point (-1,-1);
			bool playerEndsGame = false;

			//start of tower building and wave cycle
	
		
	}
	return 0;

}
