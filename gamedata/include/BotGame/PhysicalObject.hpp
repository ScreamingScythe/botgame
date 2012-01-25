/*
 * PhysicalObject.hpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */

#ifndef PHYSICALOBJECT_HPP_
#define PHYSICALOBJECT_HPP_

#include <BotGame/Object.hpp>
#include <BotGame/Position.hpp>

namespace BotGame {

class PhysicalObject : public Object {
public:
	static String positionPropertyName;
public:
	PhysicalObject(const Position & pos);

	virtual void setProperty(const String & name, const Value & value);
	virtual Value getProperty(const String & name) const;
public:
	Position position;
};

}

#endif /* PHYSICALOBJECT_HPP_ */
