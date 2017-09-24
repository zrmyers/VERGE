/*
 * ResourceSystem.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: Zane
 */

#include "ResourceSystem.h"
#include "../ID.h"
#include "Resources/Mesh.h"

namespace VERGE {

std::shared_ptr<ResourceSystem> ResourceSystem::getResourceSystem() {
	static std::shared_ptr<ResourceSystem> resourceSystem(new ResourceSystem());
	return resourceSystem;
}

ResourceSystem::ResourceSystem() {
	resourceTypeIDs[ResourceNames::MESH] =
			resourceFactory.registerType([](){ return (FactoryObject*) new Mesh();});


	resourceManifest = ResourceManifestDAO::getResourceManifest();
}

ResourceSystem::~ResourceSystem() {

}


int ResourceSystem::getResourceID(std::string resourceType, std::string resourceHandleString) {
	int resourceID = ID::UNKNOWN_ID;
	/*
	 * Check to see that the resource type is registered with our resource factory.  If it isn't
	 * we can't create this resource.
	 */
	auto resourceTypeID_iter = resourceTypeIDs.find(resourceType);
	if (resourceTypeID_iter != resourceTypeIDs.end()) {
		int resourceTypeID = resourceTypeID_iter->second;

		/*
		 * The resource is registered with our factory, so we can now check to see if it is in our manifest.  We'll
		 * have to add a new resource to the manifest if it doesn't exist.
		 */
		std::shared_ptr<ResourceHandle> handle = resourceManifest->getResourceHandle(resourceHandleString);
		if (!handle) {
			handle = std::shared_ptr<ResourceHandle>(new ResourceHandle);
			handle->handle = resourceHandleString;
			handle->type = resourceType;
			/*
			 *  We can only add it to the resource manifest, if there is a file we can save it to.  Because there is
			 *  no such file, we won't be setting the file field in the resource handle.
			 */
		}

		/*
		 *
		 */
		std::shared_ptr<Resource> resource = resourceFactory.create(resourceTypeID);
		resourceID = resource->getID();
	}

	return resourceID;
}

int ResourceSystem::getResourceTypeID(std::string resourceTypeString) {
	int typeID = ID::UNKNOWN_ID;
	auto id = resourceTypeIDs.find(resourceTypeString);
	if (id != resourceTypeIDs.end()) typeID = id->second;
	return typeID;
}

} /* namespace VERGE */
