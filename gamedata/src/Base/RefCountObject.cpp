/*
 * RefCountObject.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */

#include <BotGame/Base/RefCountObject.hpp>

#include <stdexcept>

namespace BotGame {
namespace Base {

RefCountObject::RefCountObject() :
		refCount(0) {
}
RefCountObject::~RefCountObject() {
}

void RefCountObject::addRef() const {
	if (!this)
		return;

	++refCount;
}

void RefCountObject::release() const {
	if (!this)
		return;

	--refCount;

	if (refCount < 0) {
		throw std::logic_error("Negative reference count");
	} else if (refCount == 0) {
		delete this;
	}
}

}
} // BotGame::Base
