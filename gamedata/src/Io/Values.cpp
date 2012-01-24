/*
 * Values.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */
#include <BotGame/Io/Values.hpp>

#include <BotGame/Base/RefCountObject.hpp>

#include <stdexcept>
#include <vector>
#include <boost/unordered_map.hpp>

using BotGame::Base::RefCountObject;

namespace BotGame {
namespace Io {

class Value::Data: public RefCountObject {
public:
	virtual ~Data() {
	}

	virtual bool isNumber() const = 0;
	virtual bool isString() const = 0;
	virtual bool isList() const = 0;
	virtual bool isMap() const = 0;
};

class NumberData: public Value::Data {
public:
	NumberData(Number value) :
			value(value) {
	}
	virtual ~NumberData() {
	}

	virtual bool isNumber() const {
		return true;
	}
	virtual bool isString() const {
		return false;
	}
	virtual bool isList() const {
		return false;
	}
	virtual bool isMap() const {
		return false;
	}

	Number value;
};

class StringData: public Value::Data {
public:
	StringData(const String & value) :
			value(value) {
	}
	virtual ~StringData() {
	}

	virtual bool isNumber() const {
		return false;
	}
	virtual bool isString() const {
		return true;
	}
	virtual bool isList() const {
		return false;
	}
	virtual bool isMap() const {
		return false;
	}

	String value;
};

class List::Data: public Value::Data {
public:
	virtual ~Data() {
	}

	virtual bool isNumber() const {
		return false;
	}
	virtual bool isString() const {
		return false;
	}
	virtual bool isList() const {
		return true;
	}
	virtual bool isMap() const {
		return false;
	}

	std::vector<Value> value;
};

class Map::Data: public Value::Data {
public:
	virtual ~Data() {
	}

	virtual bool isNumber() const {
		return false;
	}
	virtual bool isString() const {
		return false;
	}
	virtual bool isList() const {
		return false;
	}
	virtual bool isMap() const {
		return true;
	}

	boost::unordered_map<String, Value> value;
};

// Value class

Value::Value() :
		data(0) {
}

Value::Value(Value::Data * data) :
		data(data) {
	data->addRef();
}

Value::Value(const Value & value) :
		data(value.data) {
	data->addRef();
}

Value::Value(Number num) :
		data(new NumberData(num)) {
	data->addRef();
}

Value::Value(const char * str) :
		data(new StringData(str)) {
	data->addRef();
}

Value::Value(const String & str) :
		data(new StringData(str)) {
	data->addRef();
}

Value::Value(const List & list) :
		data(list.data) {
	data->addRef();
}

Value::Value(const Map & map) :
		data(map.data) {
	data->addRef();
}

Value::~Value() {
	data->release();
}

Value & Value::operator =(const Value & value) {
	data->release();
	data = value.data;
	data->addRef();

	return *this;
}

bool Value::isNumber() const {
	return data && data->isNumber();
}

bool Value::isString() const {
	return data && data->isString();
}

bool Value::isList() const {
	return data && data->isList();
}

bool Value::isMap() const {
	return data && data->isMap();
}

bool Value::isNull() const {
	return !data;
}

Number Value::asNumber() const {
	if (!isNumber())
		throw std::logic_error("Value is not a number");

	return static_cast<NumberData*>(data)->value;
}

String Value::asString() const {
	if (!isString())
		throw std::logic_error("Value is not a string");

	return static_cast<StringData*>(data)->value;
}

List Value::asList() const {
	if (!isList())
		throw std::logic_error("Value is not a list");

	return List(static_cast<List::Data*>(data));
}

Map Value::asMap() const {
	if (!isMap())
		throw std::logic_error("Value is not a map");

	return Map(static_cast<Map::Data*>(data));
}

// List class

List::List() :
		data(0) {
}

List::List(List::Data * data) :
		data(data) {
	data->addRef();
}

List::List(const List & value) :
		data(value.data) {
	data->addRef();
}

List::~List() {
	data->release();
}

List & List::operator =(const List & value) {
	data->release();
	data = value.data;
	data->addRef();

	return *this;
}

Size List::size() const {
	return data ? data->value.size() : 0;
}

Value List::get(Size index) const {
	return index < size() ? data->value.at(index) : Value();
}

void List::prepareWrite() {
	if (!data) {
		data = new Data();
		data->addRef();
	} else if (data->getRefCount() > 1) {
		data->release();
		data = new Data(*data);
		data->addRef();
	}
}

void List::add(Value value) {
	prepareWrite();
	data->value.push_back(value);
}

void List::insert(Size index, Value value) {
	prepareWrite();
	data->value.insert(data->value.begin() + index, value);
}

void List::remove(Size index) {
	prepareWrite();
	data->value.erase(data->value.begin() + index);
}

// Map class

Map::Map() :
		data(0) {
}

Map::Map(Map::Data * data) :
		data(data) {
	data->addRef();
}

Map::Map(const Map & value) :
		data(value.data) {
	data->addRef();
}

Map::~Map() {
	data->release();
}

Map & Map::operator =(const Map & value) {
	data->release();
	data = value.data;
	data->addRef();

	return *this;
}

Size Map::size() const {
	return data ? data->value.size() : 0;
}

Value Map::get(String key) const {
	if (data) {
		boost::unordered_map<String, Value>::const_iterator it =
				data->value.find(key);

		if (it != data->value.end())
			return it->second;
	}

	return Value();
}

void Map::prepareWrite() {
	if (!data) {
		data = new Data();
		data->addRef();
	} else if (data->getRefCount() > 1) {
		data->release();
		data = new Data(*data);
		data->addRef();
	}
}

void Map::put(String key, Value value) {
	prepareWrite();
	data->value.insert(std::make_pair(key, value));
}

void Map::remove(String key) {
	prepareWrite();
	data->value.erase(key);
}

}
}
