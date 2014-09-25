#include "EnemyUnit.h"
#include "type.h"
#include "Square.h"
#include "ccc_win.h"
#include "drawConstants.h"


EnemyUnit::EnemyUnit() {
	this->name = "Unit";
	this->speed = 50;
	this->type = Type();
	this->goldReward = 100;
	this->scoreReward = 1;
	this->maxHealth = 200;
	this->health = 200;
	this->color = "black";
	this->distanceTraveled = 0;
	this->square = Square();
}

EnemyUnit::EnemyUnit(std::string name, int speed, Type type, int goldReward, int scoreReward, int maxHealth, std::string color, Square square) {
	this->name = name;
	this->speed = speed;
	this->type = type;
	this->goldReward = goldReward;
	this->scoreReward = scoreReward;
	this->maxHealth = maxHealth;
	this->health = maxHealth;
	this->color = color;
	this->square = square;
	this->distanceTraveled = 0;
}

void EnemyUnit::move(Square square) {
	setSquare(square);
	distanceTraveled++;
	drawUnit();
}

void EnemyUnit::takeDamage(Tower tower) {
	Type towerType = tower.getType();
	int totalDamage = tower.getDamage();
	if (type.getWeakness() == towerType.getName()) {
		totalDamage *= type.getMultiplier();
	} else if (type.getStrength() == towerType.getName()) {
		totalDamage /= type.getMultiplier();
	}
	health -= totalDamage;
	tower.attack(square);
	drawUnit();
}

bool EnemyUnit::isDead() {
	if (health <= 0) {
		return true;
	}
	return false;
}

void EnemyUnit::drawUnit() {
	Point position = square.get_location();
	Point adjustedPosition = Point (position.get_x() + 0.4, position.get_y() + 0.4, color);
	cwin << adjustedPosition;
}

void EnemyUnit::setName(std::string name) {
	this->name = name;
}

void EnemyUnit::setSpeed(int speed) {
	this->speed = speed;
}

void EnemyUnit::setType(Type type) {
	this->type = type;
}

void EnemyUnit::setGoldReward(int goldReward) {
	this->goldReward = goldReward;
}

void EnemyUnit::setScoreReward(int scoreReward) {
	this->scoreReward = scoreReward;
}

void EnemyUnit::setDirection(char direction) {
	this->direction = direction;
}

void EnemyUnit::setMaxHealth(int maxHealth) {
	this->maxHealth = maxHealth;
}

void EnemyUnit::setColor(std::string color) {
	this->color = color;
}

void EnemyUnit::setSquare(Square square) {
	this->square = square;
}

std::string EnemyUnit::getName() {
	return name;
}

int EnemyUnit::getSpeed() {
	return speed;
}

Type EnemyUnit::getType() {
	return type;
}

int EnemyUnit::getGoldReward() {
	return goldReward;
}

int EnemyUnit::getScoreReward() {
	return scoreReward;
}

int EnemyUnit::getMaxHealth() {
	return maxHealth;
}

char EnemyUnit::getDirection() {
	return direction;
}

std::string EnemyUnit::getColor() {
	return color;
}

Square EnemyUnit::getSquare() {
	return square;
}

int EnemyUnit::getDistanceTraveled() {
	return distanceTraveled;
}
