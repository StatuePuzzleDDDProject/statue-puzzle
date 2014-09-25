#include <vector>
#include "ccc_win.h"
#include "constructionBox.h"

ConstructionBox::ConstructionBox() {
}

ConstructionBox::ConstructionBox(vector<Tower> towers, double mapWidth, double mapHeight, std::string color, Point llcorner) {
	this->towers = towers;
	this->BOX_WIDTH = mapWidth;
	this->BOX_HEIGHT = mapHeight / 5;
	this->title = "Towers";


	this->NUM_STATS = towers.size();
	this->ICON_WIDTH = BOX_WIDTH / 10;
	this->ICON_HEIGHT = ICON_WIDTH;
	this->color = color;
	this->llcorner = llcorner;
	createTitle();
	createButtons();
	createIcons();
}

void ConstructionBox::createTitle() {
	int titleLength = title.size();
	const double TITLE_X_POS = BOX_WIDTH / 2 - titleLength / 4;
	const double TITLE_Y_POS = BOX_HEIGHT;
	titlePos = Point(TITLE_X_POS, TITLE_Y_POS);
}

void ConstructionBox::createIcons() {
	const double X_OFFSET = 1 / (10.0 * NUM_STATS + 1) * BOX_WIDTH;
	const double Y_OFFSET = BOX_HEIGHT / 5;
	const double ICON_Y_OFFSET = 0.2;

	//for first box only
	int numChars = towers[0].getName().size();
	double lengthDiff = numChars * CHAR_WIDTH - ICON_WIDTH;
	Point textPos(llcorner.get_x() + X_OFFSET, llcorner.get_y() + Y_OFFSET);
	iconTextPositions.push_back(textPos);
	Point iconPos(textPos.get_x() + lengthDiff / 2, textPos.get_y() + ICON_Y_OFFSET);
	iconPositions.push_back(iconPos);
	towerButtons.push_back(TowerButton(iconPos, ICON_HEIGHT, intToString(towers[0].getCost()), towers[0].getColorA(), towers[0].getColorB(), towers[0], ICON_WIDTH));
	double currentX = textPos.get_x() + numChars * CHAR_WIDTH;

	// rest of boxes
	for(int i = 1; i < NUM_STATS; i++) {
		numChars = towers[i].getName().size();
		lengthDiff = numChars * CHAR_WIDTH - ICON_WIDTH;
		Point textPos(currentX + X_OFFSET, llcorner.get_y() + Y_OFFSET);
		iconTextPositions.push_back(textPos);
		Point iconPos(textPos.get_x() + lengthDiff / 2, textPos.get_y() + ICON_Y_OFFSET);
		iconPositions.push_back(iconPos);
		towerButtons.push_back(TowerButton(iconPos, ICON_HEIGHT, intToString(towers[i].getCost()), towers[i].getColorA(), towers[i].getColorB(), towers[i], ICON_WIDTH));
		currentX = textPos.get_x() + numChars * CHAR_WIDTH;
	}
}

void ConstructionBox::createButtons() {
	const std::string cancelText = "Cancel";
	const std::string readyText = "I'm Ready!";
	const std::string endGameText = "End Game";

	const double BUTTON_HEIGHT = BOX_HEIGHT / 5;

	const double X_OFFSET = BOX_WIDTH * 1.0 / 15;
	const double Y_OFFSET = BOX_HEIGHT * 1.0 / 10;

	double buttonWidth = CHAR_WIDTH * max(max(cancelText.size(), readyText.size()), endGameText.size());

	const double BUTTON_X_POS = BOX_WIDTH - X_OFFSET - buttonWidth;
	const double BUTTON_Y_POS = BOX_HEIGHT - Y_OFFSET - BUTTON_HEIGHT;

	Point cancelButtonPos(BUTTON_X_POS, BUTTON_Y_POS);
	cancelTower = Button(cancelButtonPos, BUTTON_HEIGHT, cancelText, "white");
	Point readyButtonPos(BUTTON_X_POS, BUTTON_Y_POS - Y_OFFSET - BUTTON_HEIGHT);
	ready = Button(readyButtonPos, BUTTON_HEIGHT, readyText, "white");
	Point endGameButtonPos(BUTTON_X_POS, BUTTON_Y_POS - 2 * Y_OFFSET - 2 * BUTTON_HEIGHT);
	endGame = Button(endGameButtonPos, BUTTON_HEIGHT, endGameText, "white");
}

void ConstructionBox::draw() {
	drawSolidRectangle(BOX_WIDTH, BOX_HEIGHT, llcorner, WIDTH_INCREMENT, color);
	cwin << Message(titlePos, title);
	//draws icons and their text
	for(int unsigned i = 0; i < iconPositions.size(); i++) {
		towerButtons[i].draw();
		cwin << Message(iconTextPositions[i], towers[i].getName());
	}
	//draws buttons
	cancelTower.draw();
	ready.draw();
	endGame.draw();

}

Button ConstructionBox::getReadyButton() const {
	return ready;
}

Button ConstructionBox::getCancelButton() const {
	return cancelTower;
}

Button ConstructionBox::getEndGameButton() const {
	return endGame;
}

double ConstructionBox::getBoxHeight() const {
	return BOX_HEIGHT;
}

double ConstructionBox::getBoxWidth() const {
	return BOX_WIDTH;
}

vector<TowerButton> ConstructionBox::getTowerButtons() const {
	return towerButtons;
}

vector<Tower> ConstructionBox::getTowers() const {
	return towers;
}



//void test() {
//	Type fire("Fire", "Water", "Nature", 2);
//	Type water("Water", "Nature", "Fire", 3);
//	Tower t1("Meteor", 23, 5, 2, fire, Square());
//	Tower t2("Rain", 20, 10, 2, water, Square());
//	Tower t3("Blah Blah Blah", 19, 10, 2, fire, Square());
//	Tower t4("Goop", 18, 6, 2, water, Square());
//	vector<Tower> towers;
//	towers.push_back(t1);
//	towers.push_back(t2);
//	towers.push_back(t3);
//	towers.push_back(t4);
//
//	Point p(0,0);
//	ConstructionBox towerBox(towers, 30.0, 30.0, "red", p);
//	cwin.coord(0,30,30,0);
//	towerBox.draw();
//}



