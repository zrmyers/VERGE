/*
 * EntitySystem.h
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */

#ifndef VERGE_ENTITYSYSTEM_ENTITYSYSTEM_H_
#define VERGE_ENTITYSYSTEM_ENTITYSYSTEM_H_

#include "../../tinyxml2/tinyxml2.h"
#include "Entity.h"
#include "../Factory.h"
#include "Component.h"
#include "Components/MeshRenderer.h"
#include <unordered_map>
#include <memory>

namespace tinyxml2 {
	class XMLElement;
}

namespace VERGE {

class EntitySystem {

public:
	static std::shared_ptr<EntitySystem> getEntitySystem();

private:
	std::unordered_map<std::string,std::shared_ptr<Entity>> entities;

	/*
	 * Component Factory Stuff
	 */
	Factory<Component> componentFactory;
	std::unordered_map<std::string,int> componentTypeIDs;

public:
	EntitySystem();
	~EntitySystem();

public:
	std::shared_ptr<Entity> loadEntityFromFile(std::string filename);

private:
	int getTypeIDForComponentName(std::string componentName);
	std::shared_ptr<Entity> loadEntityFromXML(tinyxml2::XMLElement* element);
	std::shared_ptr<Component> loadComponentFromXML(tinyxml2::XMLElement* element);

	// Systems with which this system will interact
	std::shared_ptr<ResourceSystem> resourceSystem = ResourceSystem::getResourceSystem();
};

} /* namespace VERGE */

#endif /* VERGE_ENTITYSYSTEM_ENTITYSYSTEM_H_ */
