/*
 * EntitySystem.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "../ResourceSystem/ResourceSystem.h"
#include "EntitySystem.h"
#include "Entity.h"
#include "Components/MeshRenderer.h"

namespace VERGE {



std::shared_ptr<EntitySystem> EntitySystem::getEntitySystem() {
	static std::shared_ptr<EntitySystem> entitySystem(new EntitySystem());
	return entitySystem;
}

EntitySystem::EntitySystem() {
	// initialize the component factory
	componentTypeIDs["MeshRenderer"] =
			componentFactory.registerType([](){ return (FactoryObject*) new MeshRenderer();});
}

EntitySystem::~EntitySystem() {
}

/*
 * Factory Method for Entity
 */
std::shared_ptr<Entity> EntitySystem::loadEntityFromFile(std::string filename) {
	std::shared_ptr<Entity> entity;
	if (entities.count(filename)) {
		entity = entities.at(filename);
	} else {
		tinyxml2::XMLDocument doc;
		doc.LoadFile(filename.c_str());

		tinyxml2::XMLElement* root =  doc.RootElement();
		if (root) {
			entity = loadEntityFromXML(root);

			// done building entity, time to add it to table
			entities[filename] = entity;
		}

		doc.Clear();
	}
	return entity;
}

std::shared_ptr<Entity> EntitySystem::loadEntityFromXML(tinyxml2::XMLElement* root) {
	std::shared_ptr<Entity> entity = std::shared_ptr<Entity>(new Entity());

	entity->setID(ID::getID());
	std::cout << root->Value() << std::endl;
	for (tinyxml2::XMLElement* currentElement = root->FirstChildElement();
		currentElement != nullptr;
		currentElement = currentElement->NextSiblingElement()) {

		std::string value = currentElement->Value();

		if (!std::strcmp(value.c_str(),"Component")) {

			std::shared_ptr<Component> component = loadComponentFromXML(currentElement);

			component->setEntityID(entity->getID());
			if (component) {
				entity->addComponent(component);
			}
		} else {
			std::cout << "UNKOWN Element!" << std::endl;
		}
	}

	return entity;
}

std::shared_ptr<Component> EntitySystem::loadComponentFromXML(tinyxml2::XMLElement* element) {
	int componentType = getTypeIDForComponentName(element->Attribute("type"));
	std::shared_ptr<Component> component = componentFactory.create(componentType);

	if (component) {
		for (tinyxml2::XMLElement* currentElement = element->FirstChildElement();
								currentElement != nullptr;
								currentElement = currentElement->NextSiblingElement()) {
			std::string elementName = currentElement->Value();
			if (!strcmp( elementName.c_str(), "Resource")) {
				std::string typeName = currentElement->Attribute("type");
				std::string handleName = currentElement->Attribute("handle");

				int resourceID = resourceSystem->getResourceID(typeName,handleName);

				component->addResourceID(typeName,resourceID);
			} else if (!strcmp( elementName.c_str(), "Attribute")) {
				std::string typeName = currentElement->Attribute("type");
				std::string name = currentElement->Attribute("name");
				std::string value = currentElement->Attribute("value");

				component->addAttribute(typeName,name,value);
			}
		}
	}
	return component;
}

int EntitySystem::getTypeIDForComponentName(std::string componentName) {
	int typeID = ID::UNKNOWN_ID;
	auto id = componentTypeIDs.find(componentName);
	if (id != componentTypeIDs.end()) typeID = id->second;
	return typeID;
}

} /* namespace VERGE */
