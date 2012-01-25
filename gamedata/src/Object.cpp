#include <BotGame/Object.hpp>

namespace BotGame {

Object::Object() {
}

Object::~Object() {
}

void Object::setProperty(const String & name, const Value & value) {
	properties[name] = value;
}

Value Object::getProperty(const String & name) const {
	Hash::const_iterator it = properties.find(name);

	if (it == properties.end())
		return Value::undefined;
	else
		return it->second;
}

}
