/*
 * Resource.h
 *
 *  Created on: Sep 19, 2017
 *      Author: Zane
 */

#ifndef VERGE_RESOURCESYSTEM_RESOURCE_H_
#define VERGE_RESOURCESYSTEM_RESOURCE_H_

#include "../Factory.h"
#include "ResourceManifestDAO.h"

namespace VERGE {

class Resource : public FactoryObject {
public:
	Resource();
	virtual ~Resource() {};

	void setResourceHandle(std::shared_ptr<ResourceHandle> handle);
	std::shared_ptr<ResourceHandle> getResourceHandle();

	virtual void load();

private:
	std::shared_ptr<ResourceHandle> handle;

};

} /* namespace VERGE */

#endif /* VERGE_RESOURCESYSTEM_RESOURCE_H_ */
