/*
 * Entity.h
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */

#ifndef VERGE_ENTITY_H_
#define VERGE_ENTITY_H_

#include "../ID.h"
#include "Component.h"

#include <string>
#include <unordered_map>
#include <memory>

namespace VERGE {

class Entity {

public:
	Entity();
	~Entity();

	void setID(int id);
	int getID();

	void addComponent(std::shared_ptr<Component> component);

private:
	int entityID;
	std::unordered_map<int,std::shared_ptr<Component>> components;

};

} /* namespace VERGE */

#endif /* VERGE_ENTITY_H_ */
