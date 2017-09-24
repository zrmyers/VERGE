/*
 * Mesh.h
 *
 *  Created on: Sep 19, 2017
 *      Author: Zane
 */

#ifndef VERGE_RESOURCESYSTEM_RESOURCES_MESH_H_
#define VERGE_RESOURCESYSTEM_RESOURCES_MESH_H_

#include "../Resource.h"
#include <vector>

namespace VERGE {

/*
 * Used to decode vertex data
 */
struct VertexAttribute {
	std::shared_ptr<std::string> name;
	std::shared_ptr<int> size;
	std::shared_ptr<std::string> type;
	std::shared_ptr<bool> normalize;
	std::shared_ptr<int> stride;
	std::shared_ptr<int> offset;

	bool isValid() {
		return (name &&
				size &&
				type &&
				normalize &&
				stride &&
				offset);
	}
};

struct MeshData {
	std::vector<float> vertexData;
	std::vector<int> elementData;
};

class Mesh: public Resource {

public:
	Mesh();
	~Mesh();

	void load();

private:

	std::shared_ptr<MeshData> meshData;
};

} /* namespace VERGE */

#endif /* VERGE_RESOURCESYSTEM_RESOURCES_MESH_H_ */
