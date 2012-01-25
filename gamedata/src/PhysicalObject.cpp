/*
 * PhysicalObject.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */

#include <BotGame/PhysicalObject.hpp>

namespace BotGame {

String PhysicalObject::positionPropertyName = "position";

PhysicalObject::PhysicalObject(const Position & pos) : position(pos) {
}

void PhysicalObject::setProperty(const String & name, const Value & value) {
	if (name == positionPropertyName)
		position = value.asPosition();
	else
		Object::setProperty(name, value);
}

Value PhysicalObject::getProperty(const String & name) const {
	if (name == positionPropertyName)
		return Value(position);
	else
		return Object::getProperty(name);
}

}
