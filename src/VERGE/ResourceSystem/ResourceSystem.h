/*
 * ResourceSystem.h
 *
 *  Created on: Sep 18, 2017
 *      Author: Zane
 */

#ifndef VERGE_RESOURCESYSTEM_RESOURCESYSTEM_H_
#define VERGE_RESOURCESYSTEM_RESOURCESYSTEM_H_

#include "Resource.h"
#include "../Factory.h"
#include "ResourceManifestDAO.h"
#include <string>
#include <unordered_map>
#include <memory>

namespace VERGE {

namespace ResourceNames {
	static std::string MESH = "Mesh";
}

class ResourceSystem {

private:
	ResourceSystem();

public:
	static std::shared_ptr<ResourceSystem> getResourceSystem();

public:


	~ResourceSystem();

public:
	int getResourceID(std::string resourceType, std::string resourceHandleString);
	int getResourceTypeID(std::string resourceTypeString);

private:

	Factory<Resource> resourceFactory;
	std::unordered_map<std::string,int> resourceTypeIDs;
	std::unordered_map<std::string,std::unordered_map<std::string,std::shared_ptr<Resource>>> resources;
	std::shared_ptr<ResourceManifestDAO> resourceManifest;
};

} /* namespace VERGE */

#endif /* VERGE_RESOURCESYSTEM_RESOURCESYSTEM_H_ */
