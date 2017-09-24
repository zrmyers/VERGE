/*
 * ResourceManifestDAO.h
 *
 *  Created on: Sep 23, 2017
 *      Author: Zane
 */

#ifndef VERGE_RESOURCESYSTEM_RESOURCEMANIFESTDAO_H_
#define VERGE_RESOURCESYSTEM_RESOURCEMANIFESTDAO_H_

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

namespace VERGE {

struct ResourceHandle {
	std::string handle;
	std::string type;
	std::string file;
};

class ResourceManifestDAO {

private:
	ResourceManifestDAO();

public:
	static std::shared_ptr<ResourceManifestDAO> getResourceManifest();
	~ResourceManifestDAO();

	std::shared_ptr<ResourceHandle> getResourceHandle(std::string handle);

private:
	void loadResourceManifest(std::string filename);
	std::unordered_map<std::string,std::shared_ptr<ResourceHandle>> handles;

};

} /* namespace VERGE */

#endif /* VERGE_RESOURCESYSTEM_RESOURCEMANIFESTDAO_H_ */
