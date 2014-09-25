/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             path.h
 PURPOSE:          A class for keeping track of the shape of a path in a map
 COMPILER:         gcc version 4.2.1
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef PATH_H_
#define PATH_H_

#include "ccc_win.h"
#include <string>

class Path {
public:

	Path();

	Path(Point startingPos, std::string path);

	/* RETURNS: the x coordinate of path's starting location
	 */
	double getStartingXPos() const;

	/* RETURNS: the y coordinate of path's starting location
	 */
	double getStartingYPos() const;

	/* RETURNS: the string representation of the path shape
	 */
	std::string getDirections() const;


private:
	Point startingPos;
	std::string directions;

};


#endif /* PATH_H_ */
