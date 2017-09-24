/*
 * MeshRenderer.h
 *
 *  Created on: Sep 17, 2017
 *      Author: Zane
 */

#ifndef VERGE_ENTITYSYSTEM_COMPONENTS_MESHRENDERER_H_
#define VERGE_ENTITYSYSTEM_COMPONENTS_MESHRENDERER_H_

#include "../Component.h"
#include "../../ResourceSystem/Resources/Mesh.h"

namespace VERGE {

class MeshRenderer: public Component {
public:
	MeshRenderer();
	~MeshRenderer();

	void receiveMeshData(VERGE::MeshData* meshData);

};

} /* namespace VERGE */

#endif /* VERGE_ENTITYSYSTEM_COMPONENTS_MESHRENDERER_H_ */
