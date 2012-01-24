/*
 * Values.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */
#include <BotGame/Io/Values.hpp>

#include <BotGame/Base/RefCountObject.hpp>

#include <vector>
#include <boost/unordered_map.hpp>

using BotGame::Base::RefCountObject;

namespace BotGame {
namespace Io {

class Value::Data: public RefCountObject {
public:
	virtual ~Data() {
	}
};

class NumberData: public Value::Data {
public:
	NumberData(Number value) :
			value(value) {
	}
	virtual ~NumberData() {
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

	String value;
};

class List::Data: public Value::Data {
public:
	virtual ~Data() {
	}

	std::vector<Value> value;
};

class Map::Data: public Value::Data {
public:
	virtual ~Data() {
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

Value::~Value() {
	data->release();
}

Value & Value::operator =(const Value & value) {
	data->release();
	data = value.data;
	data->addRef();

	return *this;
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

}
}
