/*
 * Mesh.cpp
 *
 *  Created on: Sep 19, 2017
 *      Author: Zane
 */

#include "Mesh.h"

#include <iostream>
#include "../../../tinyxml2/tinyxml2.h"
namespace VERGE {

Mesh::Mesh() {


}

Mesh::~Mesh() {

}

void Mesh::load() {
	if (!handle->file.empty()) {
		tinyxml2::XMLDocument doc;
		doc.LoadFile(handle->file.c_str());


	}
}

} /* namespace VERGE */
