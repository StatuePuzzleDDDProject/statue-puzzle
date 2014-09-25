/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             category.h
 PURPOSE:          Categories keep track of player stats, like score, health, and gold
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef CATEGORY_H_
#define CATEGORY_H_

#include <string>
#include <vector>
#include "ccc_win.h"

class Category {
public:

	Category();
	Category(std::string name, int quantity);

	std::string getName() const;

	int getQuantity() const;

	/* PURPOSE: Increases or reduces the quantity of this category by the specified amount;
	 * a negative value decreases the quantity, and a positive value increases it
	*/
	void changeQuantity(int change);

	void setQuantity(int quantity);

private:

	std::string name;

	int quantity;

};


#endif /* CATEGORY_H_ */
