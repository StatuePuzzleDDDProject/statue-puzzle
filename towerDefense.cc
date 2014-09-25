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
#include "type.h"
#include "tower.h"
#include "path.h"
#include "map.h"
#include "constructionBox.h"
#include "attributeBox.h"
#include "button.h"
#include "drawFunctions.h"
#include "drawConstants.h"
#include "systemUpdater.h"
#include "gameMaps.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Button newGame;
Button quit;
Button continueButton;
Map* currentMap;
Player* player;
ConstructionBox towerBox;
AttributeBox* playerStats;
GameMaps* allMaps;



void drawStartScreen() {

	//draw background
	Point llcorner(0,0);
	drawSolidRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, llcorner, WIDTH_INCREMENT, "black");

	// Draw title
	string titleText = "GAC Tower Defense";
	int titleTextWidth = titleText.size() * CHAR_WIDTH;
	Point titlePos(SCREEN_WIDTH / 2 - titleTextWidth / 2, SCREEN_HEIGHT - 5 * CHAR_OFFSET);
	cwin << Message(titlePos, titleText, "yellow");

	// Draw start game button
	string newGameText = "Start a new game";
	int newGameTextWidth = newGameText.size() * CHAR_WIDTH;
	double newGameHeight = SCREEN_HEIGHT / 15;
	Point newGamePos(SCREEN_WIDTH / 2 - newGameTextWidth / 2, SCREEN_HEIGHT * 0.5);
	newGame = Button(newGamePos, newGameHeight, newGameText, "yellow");
	newGame.draw();

	//Draw quit button
	string quitText = "Quit";
	int quitTextWidth = quitText.size() * CHAR_WIDTH;
	double quitHeight = SCREEN_HEIGHT / 15;
	Point quitPos(SCREEN_WIDTH / 2 - quitTextWidth / 2, SCREEN_HEIGHT * 0.25);
	quit = Button(quitPos, quitHeight, quitText, "yellow");
	quit.draw();
}

void drawWinScreen() {
	//draw background
	Point llcorner(0,0);
	drawSolidRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, llcorner, WIDTH_INCREMENT, "black");

	// Draw title
	string titleText = "Congratulations! You won!";
	int titleTextWidth = titleText.size() * CHAR_WIDTH;
	Point titlePos(SCREEN_WIDTH / 2 - titleTextWidth / 2, SCREEN_HEIGHT * 0.75);
	cwin << Message(titlePos, titleText, "yellow");

	string supportText = "Try to beat your high score";
	int supportTextWidth = supportText.size() * CHAR_WIDTH;
	Point supportPos(SCREEN_WIDTH / 2 - supportTextWidth / 2, SCREEN_HEIGHT * 0.6);
	cwin << Message(supportPos, supportText, "yellow");

	string scoreText = "Your score: " + intToString(player->getScore());
	int scoreTextWidth = scoreText.size() * CHAR_WIDTH;
	Point scorePos(SCREEN_WIDTH / 2 - scoreTextWidth / 2, SCREEN_HEIGHT * 0.5);
	cwin << Message(scorePos, scoreText, "yellow");

	//Draw continue button
	string continueText = "Play Again";
	int continueTextWidth = continueText.size() * CHAR_WIDTH;
	double continueHeight = SCREEN_HEIGHT / 15;
	Point continuePos(SCREEN_WIDTH / 2 - continueTextWidth / 2, SCREEN_HEIGHT * 0.25);
	continueButton = Button(continuePos, continueHeight, continueText, "yellow");
	continueButton.draw();
}

void drawNameScreen() {
	//draw background
	Point llcorner(0,0);
	drawSolidRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, llcorner, WIDTH_INCREMENT, "black");

	// Draw title
	string titleText = "GAC Tower Defense";
	int titleTextWidth = titleText.size() * CHAR_WIDTH;
	Point titlePos(SCREEN_WIDTH / 2 - titleTextWidth / 2, SCREEN_HEIGHT - 5 * CHAR_OFFSET);
	cwin << Message(titlePos, titleText, "yellow");

	// Draw prompt to enter name
	cwin << Message(llcorner, "", "black");
	string playerName = cwin.get_string("Enter a name: ");
	player = new Player(playerName, 50);

}

void drawInterface() {
	playerStats->draw();

	Type liberalArts ("LArts", "", "", 1.0);
	Type mcs ("MatCS", "Athlt", "LabSc", 2.0);
	Type humanities ("Humns", "SoSci", "Athlt", 2.0);
	Type athlete ("Athlt", "Humns", "MatCS", 2.0);
	Type socialSci ("SoSci", "LabSc", "Humns", 2.0);
	Type labSci ("LabSc", "MatCS", "SoSci", 2.0);

	Type fire("Fire", "Water", "Nature", 2);
	Type water("Water", "Nature", "Fire", 3);
	Tower t1("LArts", 15, 5, 2, 10, liberalArts, Square(), "black", "gold");
	Tower t2("MatCS", 40, 3, 2, 30, mcs, Square(), "blue", "green");
	Tower t3("Athlt", 25, 3, 1, 40, athlete, Square(), "firebrick", "khaki");
	Tower t4("Humns", 40, 5, 3, 20, humanities, Square(), "gold", "red");
	Tower t5("SoSci", 15, 10, 3, 15, socialSci, Square(), "sea green", "purple");
	Tower t6("LabSc", 15, 7, 2, 15, labSci, Square(), "turquoise", "white");

	vector<Tower> towers;
	towers.push_back(t1);
	towers.push_back(t2);
	towers.push_back(t3);
	towers.push_back(t4);
	towers.push_back(t5);
	towers.push_back(t6);

	Point p(0,0);
	towerBox = ConstructionBox (towers, SCREEN_WIDTH, SCREEN_HEIGHT, "red", p);
	towerBox.draw();
}

void drawMap(Map* map) {
	map->draw();
}

void drawGameOver() {
	//draw background
	Point llcorner(0,0);
	drawSolidRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, llcorner, WIDTH_INCREMENT, "black");

	// Draw title
	string titleText = "Game Over!";
	int titleTextWidth = titleText.size() * CHAR_WIDTH;
	Point titlePos(SCREEN_WIDTH / 2 - titleTextWidth / 2, SCREEN_HEIGHT * 0.75);
	cwin << Message(titlePos, titleText, "yellow");

	string scoreText = "Your score: " + intToString(player->getScore());
	int scoreTextWidth = scoreText.size() * CHAR_WIDTH;
	Point scorePos(SCREEN_WIDTH / 2 - scoreTextWidth / 2, SCREEN_HEIGHT * 0.65);
	cwin << Message(scorePos, scoreText, "yellow");

	//Draw continue button
	string continueText = "Continue";
	int continueTextWidth = continueText.size() * CHAR_WIDTH;
	double continueHeight = SCREEN_HEIGHT / 15;
	Point continuePos(SCREEN_WIDTH / 2 - continueTextWidth / 2, SCREEN_HEIGHT * 0.25);
	continueButton = Button(continuePos, continueHeight, continueText, "yellow");
	continueButton.draw();

}

//returns index of clicked tower in towerButtons, -1 if no tower button clicked
int towerButtonClicked(Point p) {
	vector<TowerButton> towerButtons = towerBox.getTowerButtons();
	for (unsigned int i = 0; i < towerButtons.size(); i++) {
		if (towerButtons[i].inRange(p)) {
			return i;
		}
	}
	return -1;
}

bool isValidTowerLoc(Point p) {
	vector<Point> pathSquares = currentMap->getPathSquares();
	for (unsigned int i = 0; i < pathSquares.size(); i++) {
		double x = p.get_x();
		double y = p.get_y();
		double squareX = pathSquares[i].get_x();
		double squareY = pathSquares[i].get_y() + MAP_OFFSET;
		if (x >= squareX && x <= squareX + SQUARE_SIZE && y >= squareY && y <= squareY + SQUARE_SIZE) {
			return false;
		}
		if (y < MAP_OFFSET || y > MAP_HEIGHT + MAP_OFFSET) {
			return false;
		}
	}
	return true;
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
	delete playerStats;
	delete allMaps;
}

int ccc_win_main() {
	cwin.coord(0,30,30,0);
	// player starts new game, enters a name
	drawStartScreen();
	Point clickPos(0,0);
	while(true) {
		while(!newGame.inRange(clickPos) && !quit.inRange(clickPos)) {
			clickPos = cwin.get_mouse();
		}
		if (newGame.inRange(clickPos)) {
			// game starts
			cwin.clear();

			// new player
			drawNameScreen();
			cwin.clear();

			// new attributebox

			Point playerStatsLoc(0,0.9 * SCREEN_HEIGHT);
			playerStats = new AttributeBox(player, SCREEN_WIDTH, SCREEN_HEIGHT, "red", playerStatsLoc);

			drawInterface();

			// new map, new gameMaps
			allMaps = new GameMaps();
			currentMap = allMaps->getMaps()[0];
			drawMap(currentMap);

			SystemUpdater systemUpdater(currentMap, player, playerStats);
			Button ready = towerBox.getReadyButton();
			Button cancel = towerBox.getCancelButton();
			Button endGame = towerBox.getEndGameButton();
			clickPos = Point (-1,-1);
			bool playerEndsGame = false;

			//start of tower building and wave cycle
			while(player->getHealth() > 0 && !playerEndsGame) {
				// read in clicks until a button is pressed

				if (currentMap->getWaves().size() == 0) {
					if (allMaps->getMaps().size() == 1) {
						player->addScore(player->getGold());
						drawWinScreen();
						clickPos = cwin.get_mouse();
						while(!continueButton.inRange(clickPos)) {
							clickPos = cwin.get_mouse();
						}
						break;
					}
					allMaps->removeMap();
					currentMap = allMaps->getMaps()[0];
					drawMap(currentMap);
					player->setHealth(player->getMaxHealth());
					player->clearTowers();
					player->addScore(player->getGold());
					player->setGold(player->getInitialGold());
					systemUpdater = SystemUpdater(currentMap, player, playerStats);
					playerStats->updateQuantities();
					continue;
				}

				clickPos = cwin.get_mouse();

				while((towerButtonClicked(clickPos) == -1) && (!ready.inRange(clickPos)) && (!endGame.inRange(clickPos))) {
					clickPos = cwin.get_mouse();
				}
				int towerClicked = towerButtonClicked(clickPos);
				if (towerClicked != -1) {
					// a tower button has been clicked, so wait for user to click a location to build or cancel button
					clickPos = cwin.get_mouse();

					//wait for tower to be built in valid location or user to cancel tower build or user to select a different tower
					Square* newTowerSquare = pointToSquare(clickPos);
					while(!cancel.inRange(clickPos) && (!isValidTowerLoc(clickPos) || newTowerSquare->get_occupied())) {
						clickPos = cwin.get_mouse();
						newTowerSquare = pointToSquare(clickPos);
					}
					if(isValidTowerLoc(clickPos) && !newTowerSquare->get_occupied()) {
						// build tower, assign tower to the appropriate square
						vector<Tower> towerOptions = towerBox.getTowers();
						Tower towerToBuild = towerOptions[towerClicked];
						Square* newTowerSquare = pointToSquare(clickPos);
						if (towerToBuild.getCost() > player->getGold()) {
							continue;
						}
						newTowerSquare->set_occupied(true);
						player->addTower(Tower(towerToBuild.getName(), towerToBuild.getDamage(), towerToBuild.getRange(), towerToBuild.getAttackDelay(), towerToBuild.getCost(), towerToBuild.getType(), *newTowerSquare, towerToBuild.getColorA(), towerToBuild.getColorB()));
						player->getLastTower().draw();
						player->addGold(0 - towerToBuild.getCost());
						playerStats->updateQuantities();
					} else {
						// cancel button pressed - cancel current tower and wait for new click
					}
				} else if (ready.inRange(clickPos)){
					// ready button clicked: start the wave of enemies!
					systemUpdater.update();
				} else {
					// end game button clicked: end game, return to start screen
					playerEndsGame = true;
				}
			}
			if (player->getHealth() <= 0) {
				// player loses - go to a game over screen / prompt to start a new game
				drawGameOver();
				clickPos = cwin.get_mouse();
				while(!continueButton.inRange(clickPos)) {
					clickPos = cwin.get_mouse();
				}
			}
			// player loses or ends game, so return to start screen and garbage collect
			drawStartScreen();
			clickPos = cwin.get_mouse();
			takeOutTheTrash();
		} else {
			//player exits game
			exit(0);
		}
	}
	return 0;
}
