/*
 * ID.h
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */

#ifndef VERGE_ID_H_
#define VERGE_ID_H_

class ID {

private:
	static int idCount;

public:
	static const int UNKNOWN_ID = -1;

	static int getID();

};

#endif /* VERGE_ID_H_ */
