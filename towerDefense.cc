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
#include "Unit.h"
//#include "type.h"
//#include "tower.h"
//#include "path.h"
#include "map.h"
#include "constructionBox.h"
//#include "attributeBox.h"
#include "button.h"
#include "drawFunctions.h"
#include "drawConstants.h"
//#include "systemUpdater.h"
//#include "gameMaps.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h> 
#include <fstream>

using namespace std;
Button clockwise;
Button counterClockwise;
Button reset;
Button end;
Button move;
Button cantMoveOntoStatue1;
Button cantMoveOntoStatue2;
Button cantMoveOntoStatue3;
Button crushedByStatue1;
Button crushedByStatue2;
Button crushedByStatue3;
//ConstructionBox* buttonBox;
//Button newGame;
//Button quit;
//Button continueButton;
Map* currentMap;
Unit* player;
Point clickPos(-1,-1);
Point cantDoThat1(MAP_WIDTH * 0.69, MAP_HEIGHT * 0.5);
Point cantDoThat2(MAP_WIDTH * 0.69, MAP_HEIGHT * 0.46);
Point cantDoThat3(MAP_WIDTH * 0.69, MAP_HEIGHT * 0.42);
//ConstructionBox towerBox;
//AttributeBox* playerStats;
//GameMaps* allMaps;

void drawWinScreen() {
	//draw background
	Point llcorner(0,0);
	drawSolidRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, llcorner, WIDTH_INCREMENT, "black");

	// Draw title
	string titleText = "Congratulations! You won!";
	int titleTextWidth = titleText.size() * CHAR_WIDTH;
	Point titlePos(SCREEN_WIDTH / 2 - titleTextWidth / 2, SCREEN_HEIGHT * 0.6);
	cwin << Message(titlePos, titleText, "yellow");
}

void drawControls() {
	Point llclkwise(MAP_HEIGHT/2-MAP_HEIGHT/4, 1);
	Point llcclkwise(MAP_HEIGHT/4-MAP_HEIGHT/8, 1);
	Point llreset(MAP_HEIGHT/2+MAP_HEIGHT/8, 1);
	Point llmove(MAP_HEIGHT-MAP_HEIGHT/2-1.5, 1);
	Point llend(MAP_HEIGHT-5,1);

	end = Button(llend, 3, "End Game", "white"); //reset+write to log file
	clockwise = Button(llclkwise, 3, "TurnC", "white");
	counterClockwise = Button(llcclkwise, 3, "TurnCC", "white");
	reset = Button(llreset, 3, "Reset", "white"); //simply reset board
	move = Button(llmove, 3, "Move", "white");
	cantMoveOntoStatue1 = Button(cantDoThat1, 1.2, "You can't move", "red");
	cantMoveOntoStatue2 = Button(cantDoThat2, 1.2, "onto a statue's", "red");
	cantMoveOntoStatue3 = Button(cantDoThat3, 1.2, " square!", "red");
	crushedByStatue1 = Button(cantDoThat1, 1.2, "Can't move there.", "red");
	crushedByStatue2 = Button(cantDoThat2, 1.2, "You'd be crushed", "red");
	crushedByStatue3 = Button(cantDoThat3, 1.2, "by the statue!", "red");
	counterClockwise.draw();
	clockwise.draw();
	reset.draw();
	move.draw();
	end.draw();
}

void drawCantMove() {
	cantMoveOntoStatue1.draw();
	cantMoveOntoStatue2.draw();
	cantMoveOntoStatue3.draw();
}

void drawCrushed() {
	crushedByStatue1.draw();
	crushedByStatue2.draw();
	crushedByStatue3.draw();
}

void drawInterface() {
    //playerStats->draw();
    drawControls();

    
}

void drawMap(Map* map) {
	map->draw();
}

bool buttonClicked() {
	return (clockwise.inRange(clickPos) || counterClockwise.inRange(clickPos) || move.inRange(clickPos) || reset.inRange(clickPos) || end.inRange(clickPos));
}


void takeOutTheTrash() {
	delete currentMap;
	delete player;
}

int ccc_win_main() {
	ofstream file;
	file.open("gameStream.txt");
        file << "\n NEW GAME";

	cwin.coord(0,30,30,0);
	// player starts new game, enters a name
	//drawStartScreen();

	currentMap = new Map ("forest green", MAP_HEIGHT, MAP_WIDTH, SQUARE_SIZE);
	drawMap(currentMap);
	drawInterface();
	Unit* player;
	Unit* statueTop;
	Unit* statueBottom;
	while(true) {

			// new map, new gameMaps
			bool playerEndsGame = false;
			bool win = false;

			//start of tower building and wave cycle
			while(!playerEndsGame && !win) {
				// read in clicks until a button is pressed

				clickPos = cwin.get_mouse();

				while(!buttonClicked()) {
					clickPos = cwin.get_mouse();
				}
				player = currentMap->get_player();
				statueTop = currentMap->get_top_statue();
				statueBottom = currentMap->get_bottom_statue();
				if (move.inRange(clickPos)) {
					bool hasMoved = player->move();
					// if player can move
					if (hasMoved) {
						drawSolidRectangle(10, 5, cantDoThat3,WIDTH_INCREMENT, "forest green");
						//if player is right behind a statue
						if(player->getSquare() == statueTop->getSquare()) {
							player->revert();
							statueTop->redraw();
							drawCantMove();
						} else if (player->getSquare() == statueBottom->getSquare()) {
							player->revert();
							statueBottom->redraw();		
							drawCantMove();			
						} else {
							statueTop->move();
							//if statues are adjacent and facing each other, don't let them move
							if(statueTop->getSquare() == statueBottom->getSquare()) {
								statueTop->revert();
								statueBottom->redraw();
							} else {
								statueBottom->move();	
							}						
						}

						// if two units land on same square
						if (player->getSquare() == statueTop->getSquare() || player->getSquare() == statueBottom->getSquare()) {
							statueTop->revert();
							statueBottom->revert();
							player->revert();
							drawCrushed();
						} else if (statueTop->getSquare() == statueBottom->getSquare()) {
							statueTop->revert();
							statueBottom->revert();
						} 
						if (statueTop->getSquare()->get_num() == 6 && statueBottom->getSquare()->get_num() == 8) {
							win = true;
						} else if (statueTop->getSquare()->get_num() == 8 && statueBottom->getSquare()->get_num() == 6) {
							win = true;
						}
						
					}

				} else if (clockwise.inRange(clickPos)) {
					player->turn("right");
					statueTop->turn("right");
					statueBottom->turn("right");
				} else if (counterClockwise.inRange(clickPos)) {
					player->turn("left");
					statueTop->turn("left");
					statueBottom->turn("left");
				} else if (reset.inRange(clickPos)) {
					delete currentMap;
					currentMap = new Map ("forest green", MAP_HEIGHT, MAP_WIDTH, SQUARE_SIZE);
					currentMap->draw();
					drawControls();
				} else {
					takeOutTheTrash();
                                        file << "\n END GAME - ABORT";
                                        file.close();
					exit(0);
				}


			}
			usleep(1000000);
			cwin.clear();
			drawWinScreen();
			Point llend2(MAP_HEIGHT-MAP_HEIGHT/2-1.5, 1);
			end = Button(llend2, 3, "End Game", "white");
			end.draw();
			// player loses or ends game, so return to start screen and garbage collect
			clickPos = cwin.get_mouse();

			while(!(end.inRange(clickPos))) {
				clickPos = cwin.get_mouse();
			}
			file << "END GAME - WIN";
			file.close();
			exit(0);
	}
	return 0;

}
