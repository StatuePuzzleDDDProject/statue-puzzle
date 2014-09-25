#include <string>
#include "tower.h"
#include <cmath>
#include "drawFunctions.h"

Tower::Tower() {
	this->name = "Tower";
	this->damage = 0;
	this->range = 0;
	this->attackDelay = 0;
	this->type = type;
	this->location = location;
	this->canAttack = true;
	this->colorA = "black";
	this->colorB = "white";
	this->delayCount = 0;
	this->cost = 0;
}

Tower::Tower(std::string name, int damage, int range, int attackDelay, int cost, Type type, Square location, std::string colorA, std::string colorB) {
	this->name = name;
	this->damage = damage;
	this->range = range;
	this->attackDelay = attackDelay;
	this->type = type;
	this->location = location;
	this->canAttack = true;
	this->colorA = colorA;
	this->colorB = colorB;
	this->delayCount = 0;
	this->cost = cost;
}

std::string Tower::getName() const {
	return this->name;
}

int Tower::getDamage() const {
	return this->damage;
}

int Tower::getRange() const {
	return this->range;
}

int Tower::getAttackDelay() const {
	return this->attackDelay;
}

Type Tower::getType() const {
	return this->type;
}

Square Tower::getLocation() const {
	return this->location;
}

int Tower::getCost() const {
	return this->cost;
}

bool Tower::getCanAttack() const {
	return this->canAttack;
}

std::string Tower::getColorA() const {
	return this->colorA;
}

std::string Tower::getColorB() const {
	return this->colorB;
}

int Tower::getDelayCount () const {
	return this->delayCount;
}

void Tower::setName(std::string name) {
	this->name = name;
}

void Tower::setDamage(int damage) {
	this->damage = damage;
}

void Tower::setRange(int range) {
	this->range = range;
}

void Tower::setType(Type type) {
	this->type = type;
}

void Tower::setAttackDelay(int attackDelay) {
	this->attackDelay = attackDelay;
}

void Tower::setLocation(Square location) {
	this->location = location;
}

void Tower::setCanAttack(bool canAttack) {
	this->canAttack = canAttack;
}

void Tower::setColorA(std::string color) {
	this->colorA = color;
}

void Tower::setColorB(std::string color) {
	this->colorB = color;
}

void Tower::setDelayCount(int delayCount) {
	this->delayCount = delayCount;
}

void Tower::setCost(int cost) {
	this->cost = cost;
}

void Tower::attack(Square square) {
	double adjustedX = location.get_location().get_x() + 0.0 * SQUARE_SIZE;
	double adjustedY = location.get_location().get_y() + 0.0 * SQUARE_SIZE;
	Point adjustedLoc = Point(adjustedX,adjustedY);

	drawMapTower(SQUARE_SIZE * 0.8, adjustedLoc, "white", colorB);
	Point target (square.get_location().get_x() + 0.4, square.get_location().get_y() + 0.4, colorA);
	cwin << target;
	usleep(100000);
	draw();
}

//unused?
void Tower::draw() {
	double adjustedX = location.get_location().get_x() + 0.0 * SQUARE_SIZE;
	double adjustedY = location.get_location().get_y() + 0.0 * SQUARE_SIZE;
	Point adjustedLoc = Point(adjustedX,adjustedY);

	drawMapTower(SQUARE_SIZE * 0.8, adjustedLoc, colorA, colorB);
}

bool Tower::inRange(Square occupiedSquare) {
	double xDistance = abs (location.get_location().get_x() - occupiedSquare.get_location().get_x());
	double yDistance = abs (location.get_location().get_y() - occupiedSquare.get_location().get_y());
	double totalDistance = xDistance + yDistance;
	if (totalDistance <= range) {
		return true;
	}
	return false;
}

void Tower::countDelay() {
	delayCount++;
}

