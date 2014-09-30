/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             map.h
 PURPOSE:          Keeps track of the visuals concerning constructed Towers, paths, and EnemyUnits
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef MAP_H_
#define MAP_H_

#include <string>
#include <vector>
#include "Square.h"
//#include "path.h"
//#include "wave.h"

class Map {
public:

	Map();

	~Map();

	Map(std::string buildableColor, double height, double width, double squareSize);

	/* PURPOSE: draws this map in the window along with its path
	*/
	void draw();

	void drawSquares();

	bool isSquareLoc(int row, int col);

	bool endSquare(int row, int col);

	/* PURPOSE: sets the coordinates of the window
	*/
	void initializeWindow();

	/* PURPOSE: figures out which squares on the map should be part of the path
	*/

	std::string getBuildableColor();
	vector<vector<Square*> > getPositions();

	void setPositions(vector<vector<Square*> > positions);

private:
	/* REMARKS: this map's width in squares
	*/
	double WIDTH;
	/* REMARKS: this map's height in squares
	*/
	double HEIGHT;

	Square* mapSquares[6][5];

	/* REMARKS: the color for squares that the user can build towers on in this map
	*/
	std::string buildableColor;
	std::string endSquareColor;
	std::string playerColor;
	std::string statueColor;

	/* REMARKS: keeps track of all of the squares on this map
	*/
	vector<vector<Square*> > positions;

};


#endif /* MAP_H_ */
