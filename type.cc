#include "type.h"
#include <string>

Type::Type () {
	name = "normal";
	weakness = "none";
	strength = "none";
	multiplier = 1.0;
}

Type::Type(std::string name, std::string weakness, std::string strength, double multiplier) {
	this->name = name;
	this->weakness = weakness;
	this->strength = strength;
	this->multiplier = multiplier;
}

std::string Type::getName() {
	return name;
}

std::string Type::getWeakness() {
	return weakness;
}

std::string Type::getStrength() {
	return strength;
}

double Type::getMultiplier() {
	return multiplier;
}
