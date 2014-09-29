#include <iostream>
#include "player.h"
#include "category.h"


Player::Player() {
	name = "Player";
	gold = Category ("Gold", 0);
	score = Category ("Score", 0);
	health = Category("Health", 3);
	maxHealth = 3;
	scoreToLevel = 1000;
	initialGold = 50;
}

Player::Player(std::string name, int gold) {
	this->name = name;
	this->gold = Category("Gold", gold);
	this->score = Category("Score", 0);
	this->health = Category ("Health", 3);
	maxHealth = 3;
	scoreToLevel = 1000;
	initialGold = 50;
}

void Player::levelUp() {
	maxHealth++;
	setHealth(getHealth() + 1);
	if ((scoreToLevel / 1000) % 2 == 0) {
		initialGold += 25;
	}
	scoreToLevel += 1000;
}

void Player::addGold(int gold) {
	this->gold.changeQuantity(gold);
}

void Player::addScore(int score) {
	this->score.changeQuantity(score);
	if (this->score.getQuantity() >= scoreToLevel) {
		levelUp();
	}
}

void Player::takeDamage() {
	health.changeQuantity(-1);
}

void Player::addTower (Tower tower) {
	towers.push_back(tower);
}

std::string Player::getName() const {
	return name;
}

Tower Player::getLastTower () const {
	return towers[towers.size() -1];
}

int Player::getScore()  {
	return score.getQuantity();
}

int Player::getHealth() const {
	return health.getQuantity();
}

int Player::getGold() const {
	return gold.getQuantity();
}

int Player::getMaxHealth() const {
	return maxHealth;
}

int Player::getInitialGold() const {
	return initialGold;
}

int Player::getScoreToLevel() const {
	return scoreToLevel;
}

Category Player::getScoreCategory() const {
	return score;
}

Category Player::getHealthCategory() const {
	return health;
}

Category Player::getGoldCategory() const {
	return gold;
}

vector<Tower> Player::getTowers() const {
	return towers;
}

void Player::setHealth(int health) {
	this->health.setQuantity(health);
}

void Player::setGold(int gold) {
	this->gold.setQuantity(gold);
}

void Player::setInitialGold (int gold) {
	initialGold = gold;
}

void Player::setScoreToLevel (int score) {
	scoreToLevel = score;
}

void Player::clearTowers() {
	while (towers.size() != 0) {
		towers.pop_back();
	}
}
