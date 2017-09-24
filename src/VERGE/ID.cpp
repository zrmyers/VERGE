/*
 * ID.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */

#include "ID.h"

int ID::idCount = 0;

int ID::getID() {
	return idCount++;
}


