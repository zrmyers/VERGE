/*
 * Component.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */

#include "Component.h"
#include "../ID.h"
#include "../ResourceSystem/ResourceSystem.h"

namespace VERGE {

Component::Component() {
	entityID = ID::UNKNOWN_ID;
}

Component::~Component() {

}

void Component::setEntityID(int id) {
	entityID = id;
}

int Component::getEntityID() {
	return entityID;
}

void Component::addResourceID(std::string resourceType,int id) {
	if (id != ID::UNKNOWN_ID) {
		resourceIDs[resourceType] = id;
	}
}

void Component::addAttribute(std::string type, std::string name, std::string value) {

}
} /* namespace VERGE */
