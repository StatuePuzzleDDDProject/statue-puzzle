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
#include "path.h"
#include "wave.h"

class Map {
public:

	Map();

	~Map();

	Map(Path path, std::string buildableColor, std::string pathColor, double height, double width, double squareSize, vector<Wave> waves);

	/* PURPOSE: draws this map in the window along with its path
	*/
	void draw();

	/* PURPOSE: sets the coordinates of the window
	*/
	void initializeWindow();

	/* PURPOSE: figures out which squares on the map should be part of the path
	*/
	void definePathSquares();

	/* PURPOSE: draws the path in the window
	*/
	void drawPath();

	/* PURPOSE: Releases the next unit from the current wave and returns it
	*/
	EnemyUnit nextUnit();

	/* PURPOSE: removes the first wave in this map's wave vector after the wave is finished
	*/
	void removeWave();

	Path getPath();
	std::string getBuildableColor();
	std::string getPathColor();
	vector<vector<Square*> > getPositions();
	vector<Point> getPathSquares();
	vector<Wave> getWaves();
	int getOffset();

	void setPositions(vector<vector<Square*> > positions);

private:
	/* REMARKS: this map's width in squares
	*/
	double WIDTH;
	/* REMARKS: this map's height in squares
	*/
	double HEIGHT;

	/* REMARKS: the path this map uses for EnemyUnits
	*/
	Path path;

	/* REMARKS: the color for squares that the user can build towers on in this map
	*/
	std::string buildableColor;

	/* REMARKS: the color for squares that are part of the path on this map - towers can't be built on these
	*/
	std::string pathColor;

	/* REMARKS: keeps track of all of the squares on this map
	*/
	vector<vector<Square*> > positions;

	/* REMARKS: keeps track of the locations of all of the squares that are part of this map's path
	*/
	vector<Point> pathSquares;

	/* REMARKS: keeps track of all this map's waves
	*/
	vector<Wave> waves;

};


#endif /* MAP_H_ */
