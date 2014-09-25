#include "towerButton.h"
#include "drawFunctions.h"
#include "ccc_win.h"

TowerButton::TowerButton() : Button() {
	secondaryColor = "black";
	this->tower = Tower();
}

TowerButton::TowerButton(Point llcorner, double height, std::string text, std::string primaryColor, std::string secondaryColor, Tower tower, double ICON_SIZE) : Button(llcorner, height, text, primaryColor) {
	Button::setWidth(ICON_SIZE);
	Button::setHeight(ICON_SIZE);
	Button::setText(text);
	Button::setTextPos(Point(llcorner.get_x() + height * 0.3, llcorner.get_y() + height * 1.3));
	this->secondaryColor = secondaryColor;
	this->tower = tower;

}

void TowerButton::draw() {
	double width = Button::getWidth();
	Point llcorner = Button::getLLcorner();
	std::string color = Button::getColor();
	drawMapTower(width, llcorner, color, secondaryColor);
	drawRectangle(width, width, llcorner, "white");
	cwin << Message (Button::getTextPos(), Button::getText(), "gold");
}


