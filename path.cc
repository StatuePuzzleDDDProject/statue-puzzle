#include "ccc_win.h"
#include "path.h"
#include <string>

Path::Path() {
	directions = "";
}

Path::Path(Point startingPos, std::string directions) {
	this->startingPos = startingPos;
	this->directions = directions;
}

double Path::getStartingXPos() const {
	return startingPos.get_x();
}

double Path::getStartingYPos() const {
	return startingPos.get_y();
}

std::string Path::getDirections() const {
	return directions;
}





