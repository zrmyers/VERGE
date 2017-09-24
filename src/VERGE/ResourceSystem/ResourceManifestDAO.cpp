/*
 * ResourceManifestDAO.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: Zane
 */

#include "ResourceManifestDAO.h"
#include "../../tinyxml2/tinyxml2.h"

using namespace tinyxml2;

namespace VERGE {

ResourceManifestDAO::ResourceManifestDAO() {
	loadResourceManifest("Data/Resources/ResourceManifest.xml");
}

std::shared_ptr<ResourceManifestDAO> ResourceManifestDAO::getResourceManifest() {
	static std::shared_ptr<ResourceManifestDAO> resourceManifest(new ResourceManifestDAO());
	return resourceManifest;
}

ResourceManifestDAO::~ResourceManifestDAO() {
}

std::shared_ptr<ResourceHandle> ResourceManifestDAO::getResourceHandle(std::string handle) {
	std::shared_ptr<ResourceHandle> resourceHandle(nullptr);
	auto h = handles.find(handle);
	if (h != handles.end()) resourceHandle = h->second;
	return resourceHandle;
}

void ResourceManifestDAO::loadResourceManifest(std::string filename) {
	XMLDocument doc;
	doc.LoadFile(filename.c_str());
	XMLElement* root = doc.RootElement();
	if (root) {
		for (XMLElement* current = root->FirstChildElement();
				current != nullptr;
				current = current->FirstChildElement()) {

			std::shared_ptr<ResourceHandle> resourceHandle(new ResourceHandle());
			resourceHandle->handle = current->Attribute("handle");
			resourceHandle->type = current->Attribute("type");
			resourceHandle->file = current->Attribute("file");
			handles[resourceHandle->handle] = resourceHandle;
		}
	}

	doc.Clear();
}

} /* namespace VERGE */
