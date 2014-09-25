/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             type.h
 PURPOSE:          A class for keeping track of a unit or tower's type, which indicates whether bonus damage may be dealt
 COMPILER:         gcc version 4.2.1
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef TYPE_H_
#define TYPE_H_

#include <string>

class Type {
public:
	Type ();

	Type (std::string name, std::string weakness, std::string strength, double multiplier);

	std::string getName();
	std::string getWeakness();
	std::string getStrength();

	/* RETURNS: The number the attack damage of a tower of this type is
	 * multiplied by when it attacks a unit of a type weak to this type
	*/
	double getMultiplier();

private:
	std::string name;
	std::string weakness;
	std::string strength;
	double multiplier;
};


#endif /* TYPE_H_ */
