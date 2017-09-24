/*
 * Component.h
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */

#ifndef VERGE_ENTITYSYSTEM_COMPONENT_H_
#define VERGE_ENTITYSYSTEM_COMPONENT_H_

#include "../ResourceSystem/ResourceSystem.h"
#include "../ResourceSystem/Resource.h"
#include "../Factory.h"
#include <unordered_map>

namespace VERGE {

class Component : public  FactoryObject {

public:
	Component();
	virtual ~Component();

	void setEntityID(int id);
	int getEntityID();

	void addResourceID(std::string resourceType,int id);

	void addAttribute(std::string type, std::string name, std::string value);
private:
	int entityID;

	std::unordered_map<std::string,int> resourceIDs;
	std::unordered_multimap<std::string, std::pair<std::string,std::string>> attributes;
};

} /* namespace VERGE */

#endif /* VERGE_ENTITYSYSTEM_COMPONENT_H_ */
