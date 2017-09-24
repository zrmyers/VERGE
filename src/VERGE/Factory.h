/*
 * Factory.h
 *
 *  Created on: Sep 22, 2017
 *      Author: Zane
 */

#ifndef VERGE_FACTORY_H_
#define VERGE_FACTORY_H_

#include <unordered_map>
#include <memory>
#include <string>

#include "ID.h"

namespace VERGE {

class FactoryObject {

private:
	int objectID;
	int objectTypeID;

public:
	inline FactoryObject() {
		objectID = ID::UNKNOWN_ID;
		objectTypeID = ID::UNKNOWN_ID;
	}

	virtual ~FactoryObject() {};

	inline FactoryObject* setID(int id) {
		objectID = id;
		return this;
	}

	inline int getID() {
		return objectID;
	}

	inline FactoryObject* setTypeID(int id) {
		objectTypeID = id;
		return this;
	}

	inline int getTypeID() {
		return objectTypeID;
	}
};

template<class Abstract>
class Factory {
public:
	/*
	 * Public Class Types
	 */
	typedef FactoryObject* (*typebuilder)(void);

	/*
	 * Public Static Class Data
	 */

private:
	/*
	 * Private Instance Data
	 */
	std::unordered_map<int,typebuilder> registeredBuilders;

public:
	inline Factory() {
	}

	inline ~Factory() {
		registeredBuilders.clear();
	}

public:
	// component classes must register with the factory in order to get instantiated
	inline int registerType(typebuilder builder) {
		int typeID = ID::getID();
		registeredBuilders[typeID] = builder;
		return typeID;
	}

	inline std::shared_ptr<Abstract> create(int typeID) {
		std::shared_ptr<Abstract> instance(nullptr);
		auto builder = registeredBuilders.find(typeID);
		if (builder != registeredBuilders.end()) {
			instance = std::shared_ptr<Abstract>((Abstract*)(builder->second)()
					->setID(ID::getID())
					->setTypeID(typeID));
		}
		return instance;
	}
};

} /* namespace VERGE */

#endif /* VERGE_FACTORY_H_ */
