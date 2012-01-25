/*
 * Object.hpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <BotGame/Value.hpp>

namespace BotGame {

class Object {
public:
	Object();
	virtual ~Object();

	virtual void setProperty(const String & name, const Value & value);
	virtual Value getProperty(const String & name) const;

private:
	Hash properties;
};

}

#endif /* OBJECT_HPP_ */
