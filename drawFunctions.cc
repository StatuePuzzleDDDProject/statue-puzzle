#include "drawFunctions.h"
#include "ccc_win.h"
#include <cmath>
#include <string>
#include <sstream>


std::string intToString(int i) {
	ostringstream strm;
	strm << i;
	return strm.str();
}

void drawRectangle(double given_width, double given_height, Point llcorner, std::string color) {
	double startingXPos = llcorner.get_x();
	double endingXPos = startingXPos + given_width;
	double bottomYPos = llcorner.get_y();
	double topYPos = llcorner.get_y() + given_height;

	Point ulcorner(startingXPos, topYPos);
	Line ll_to_ul(llcorner, ulcorner, color);
	cwin << ll_to_ul;

	Point lrcorner(endingXPos, bottomYPos);
	Line ll_to_lr(llcorner, lrcorner, color);
	cwin << ll_to_lr;

	Point urcorner(endingXPos, topYPos);
	Line lr_to_ur(lrcorner, urcorner, color);
	cwin << lr_to_ur;

	Line ul_to_ur(ulcorner, urcorner, color);
	cwin << ul_to_ur;
}

Line drawRadialSegment(double inner_radius, double outer_radius, double angle, Point center, std::string color) {
	double xOffset = center.get_x();
	double yOffset = center.get_y();

	double xPosSegInner = inner_radius * sin(angle);
	double yPosSegInner = inner_radius * cos(angle);
	Point segmentPosInner(xPosSegInner + xOffset, yPosSegInner + yOffset);

	double xPosSegOuter = outer_radius * sin(angle);
	double yPosSegOuter = outer_radius * cos(angle);
	Point segmentPosOuter(xPosSegOuter + xOffset, yPosSegOuter + yOffset);

	Line segment(segmentPosInner, segmentPosOuter, color);
	return segment;
}

void drawSector(double given_radius, double startingAngle, double endingAngle, Point center, double angleIncrement, std::string color) {

	Point outerEdge(given_radius * cos(startingAngle), given_radius * sin(startingAngle));
	for (double angle = startingAngle; angle <= endingAngle; angle += angleIncrement) {
	    cwin << drawRadialSegment(0, given_radius, angle, center, color);
	}
}

void drawSolidCircle(double given_radius, Point center, double radiusIncrement, std::string color) {
	for (double radius = 0.0; radius <= given_radius; radius += radiusIncrement) {
	    cwin << Circle(center, radius, color);
	}
}

void drawSolidRectangle(double givenWidth, double givenHeight, Point llcorner, double widthIncrement, std::string color) {
	Point rectPos(llcorner.get_x(), llcorner.get_y());

	for (double width = 0; width < givenWidth / 2; width += widthIncrement) {
		rectPos.move(widthIncrement,0);
	    drawRectangle(width, givenHeight, rectPos, color);
	}
}

int max(int a, int b) {
	if (a >= b) {
		return a;
	} else {
		return b;
	}
}

void drawMapTower(double squareSize, Point llcorner, std::string primaryColor, std::string secondaryColor) {
	llcorner = Point (llcorner.get_x(), llcorner.get_y());
	Point llcornerAdj(llcorner.get_x() + 0.01, llcorner.get_y() + 0.01);
	drawSolidRectangle(squareSize, squareSize, llcorner, WIDTH_INCREMENT, primaryColor);

	drawSolidRectangle(squareSize / 4, squareSize / 4, llcornerAdj, WIDTH_INCREMENT, secondaryColor);
	Point ulsquare(llcornerAdj.get_x(),llcornerAdj.get_y() + squareSize * 0.75);
	drawSolidRectangle(squareSize / 4, squareSize / 4, ulsquare, WIDTH_INCREMENT, secondaryColor);
	Point ursquare(llcornerAdj.get_x() + squareSize * 0.75,llcornerAdj.get_y() + squareSize * 0.75);
	drawSolidRectangle(squareSize / 4, squareSize / 4, ursquare, WIDTH_INCREMENT, secondaryColor);
	Point lrsquare(llcornerAdj.get_x() + squareSize * 0.75,llcornerAdj.get_y());
	drawSolidRectangle(squareSize / 4, squareSize / 4, lrsquare, WIDTH_INCREMENT, secondaryColor);
}



