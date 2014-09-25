#include "attributeBox.h"
#include <vector>
#include "ccc_win.h"
#include <iostream>


AttributeBox::AttributeBox(Player* player, double mapWidth, double mapHeight, std::string color, Point llcorner) {
	this->BOX_WIDTH = mapWidth;
	this->BOX_HEIGHT = 0.1 * mapHeight;
	this->title = player->getName();

	this->categories.push_back(player->getScoreCategory());
	this->categories.push_back(player->getHealthCategory());
	this->categories.push_back(player->getGoldCategory());

	this->NUM_STATS = categories.size();
	this->TEXT_BOX_WIDTH = 1 / (3.0 * NUM_STATS + 1) * BOX_WIDTH;
	this->TEXT_BOX_HEIGHT = 0.15 * BOX_HEIGHT;
	this->color = color;
	this->llcorner = llcorner;
	this->player = player;
	createTitle();
	calculateTextBoxPositions();
}

void AttributeBox::createTitle() {
	int titleLength = title.size();
	const double TITLE_X_POS = BOX_WIDTH / 2 - titleLength / 4;
	const double TITLE_Y_POS = SCREEN_HEIGHT;
	titlePos = Point(TITLE_X_POS, TITLE_Y_POS);
}

void AttributeBox::calculateTextBoxPositions() {
	const double X_OFFSET = 1 / (8.0 * NUM_STATS) * BOX_WIDTH;
	const double Y_OFFSET = 0.5 * BOX_HEIGHT;
	const double BOX_Y_OFFSET = 0.75;

	//for first box only
	int numChars = categories[0].getName().size();
	Point textPos(llcorner.get_x() + X_OFFSET, llcorner.get_y() + Y_OFFSET);
	textBoxTextPositions.push_back(textPos);
	Point boxPos(textPos.get_x() + numChars * CHAR_WIDTH, textPos.get_y() - BOX_Y_OFFSET);
	textBoxPositions.push_back(boxPos);
	double currentX = boxPos.get_x() + TEXT_BOX_WIDTH;

	for(int i = 1; i < NUM_STATS; i++) {
		numChars = categories[i].getName().size();
		Point textPos(currentX + X_OFFSET, llcorner.get_y() + Y_OFFSET);
		textBoxTextPositions.push_back(textPos);
		Point boxPos(textPos.get_x() + numChars * CHAR_WIDTH, textPos.get_y() - BOX_Y_OFFSET);
		textBoxPositions.push_back(boxPos);
		currentX = boxPos.get_x() + TEXT_BOX_WIDTH;
	}
}


void AttributeBox::draw() {
	//draws overall box structure
	drawSolidRectangle(BOX_WIDTH, BOX_HEIGHT, llcorner, WIDTH_INCREMENT, color);

	//draws player's name
	cwin << Message(titlePos, title);

	//draws text boxes and their text
	for(int unsigned i = 0; i < textBoxPositions.size(); i++) {
		drawSolidRectangle(TEXT_BOX_WIDTH, TEXT_BOX_HEIGHT, textBoxPositions[i], WIDTH_INCREMENT, "white");
		cwin << Message(textBoxTextPositions[i], categories[i].getName());
		Point quantityPos(textBoxPositions[i].get_x(), textBoxPositions[i].get_y() + CHAR_OFFSET);
		cwin << Message(quantityPos, categories[i].getQuantity());
	}
}

void AttributeBox::updateQuantities() {
	this->categories[0].setQuantity(player->getScore());
	this->categories[1].setQuantity(player->getHealth());
	this->categories[2].setQuantity(player->getGold());

	for(int unsigned i = 0; i < textBoxPositions.size(); i++) {
		drawSolidRectangle(TEXT_BOX_WIDTH, TEXT_BOX_HEIGHT, textBoxPositions[i], WIDTH_INCREMENT, "white");
		cwin << Message(textBoxTextPositions[i], categories[i].getName());
		Point quantityPos(textBoxPositions[i].get_x(), textBoxPositions[i].get_y() + CHAR_OFFSET);
		cwin << Message(quantityPos, categories[i].getQuantity());
	}
}

//void test() {
//	//test AttributeBox
//	Category gold("Gold", 100);
//	Category crystal("Crystal", 50);
//	Category score("Score", 0);
//	Category blah("blah", 0);
//
//	Player player1("Helen", 100, 50);
//	Point p(0,0);
//	AttributeBox playerStats(player1, 30.0, 30.0, "red", p);
//	cwin.coord(0,30,30,0);
//	playerStats.draw();
//}
