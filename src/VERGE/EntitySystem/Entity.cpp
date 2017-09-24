/*
 * Entity.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */

#include "Entity.h"
#include "EntitySystem.h"

#include <iostream>

namespace VERGE {

Entity::Entity() {
	this->entityID = ID::UNKNOWN_ID;
}

Entity::~Entity() {

}

void Entity::setID(int id) {
	entityID = id;
}

int Entity::getID() {
	return entityID;
}

void Entity::addComponent(std::shared_ptr<Component> component) {
	components[component->getTypeID()] = component;
}

} /* namespace VERGE */
