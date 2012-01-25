/*
 * Value.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */
#include <BotGame/Value.hpp>
#include <BotGame/Vector.hpp>
#include <BotGame/Position.hpp>
#include <BotGame/Base/RefCountObject.hpp>

#include <stdexcept>

namespace BotGame {

Value Value::undefined;

// Value data

class Value::Data: public Base::RefCountObject {
public:
	Data() :
			type(UNDEFINED) {
	}

	Data(Type type, bool boolValue) :
			type(type), boolValue(boolValue) {
		if (type != BOOLEAN)
			throw std::logic_error("Non-boolean type");
	}

	Data(Type type, long integerValue) :
			type(type), integerValue(integerValue) {
		if (type != INTEGER)
			throw std::logic_error("Non-integer type");
	}

	Data(Type type, double doubleValue) :
			type(type), doubleValue(doubleValue) {
		if (type != DOUBLE)
			throw std::logic_error("Non-double type");
	}

public:
	Type type;
	union {
		void * ptrValue;
		bool boolValue;
		long integerValue;
		double doubleValue;
	};
};

template<typename T>
class Value::PtrData: public Value::Data {
public:
	PtrData(Type t, const T * value) {
		if (t < STRING)
			throw std::logic_error("Non-pointer type");

		type = t;
		ptrValue = new T(*value);
	}

	~PtrData() {
		if (type >= STRING)
			delete (T*) ptrValue;
	}
};

// Value

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

Value::Value(Boolean v) :
		data(new Data(BOOLEAN, v)) {
	data->addRef();
}

Value::Value(int v) :
		data(new Data(INTEGER, (Integer) v)) {
	data->addRef();
}

Value::Value(Integer v) :
		data(new Data(INTEGER, v)) {
	data->addRef();
}

Value::Value(Double v) :
		data(new Data(DOUBLE, v)) {
	data->addRef();
}

Value::Value(const char * str) {
	String v(str);
	data = new PtrData<String>(STRING, &v);
	data->addRef();
}

Value::Value(const String & v) :
		data(new PtrData<String>(STRING, &v)) {
	data->addRef();
}

Value::Value(const List & v) :
		data(new PtrData<List>(LIST, &v)) {
	data->addRef();
}

Value::Value(const Hash & v) :
		data(new PtrData<Hash>(HASH, &v)) {
	data->addRef();
}

Value::Value(const Vector & v) :
		data(new PtrData<Vector>(VECTOR, &v)) {
	data->addRef();
}

Value::Value(const Position & v) :
		data(new PtrData<Position>(POSITION, &v)) {
	data->addRef();
}

Value & Value::operator =(const Value & value) {
	data->release();
	data = value.data;
	data->addRef();

	return *this;
}

Value::Type Value::type() const {
	if (!data)
		return UNDEFINED;

	return data->type;
}

Boolean Value::asBoolean() const {
	if (!isBoolean())
		throw std::logic_error("Value is not a boolean");

	return data->boolValue;
}

Integer Value::asInteger() const {
	if (!isInteger())
		throw std::logic_error("Value is not a integer");

	return data->integerValue;
}

Double Value::asDouble() const {
	if (!isDouble())
		throw std::logic_error("Value is not a double");

	return data->doubleValue;
}

const String & Value::asString() const {
	if (!isString())
		throw std::logic_error("Value is not a string");

	return *(String*) data->ptrValue;
}

const List & Value::asList() const {
	if (!isList())
		throw std::logic_error("Value is not a list");

	return *(List*) data->ptrValue;
}

const Hash & Value::asHash() const {
	if (!isHash())
		throw std::logic_error("Value is not a hash");

	return *(Hash*) data->ptrValue;
}

const Vector & Value::asVector() const {
	if (!isVector())
		throw std::logic_error("Value is not a vector");

	return *(Vector*) data->ptrValue;
}

const Position & Value::asPosition() const {
	if (!isPosition())
		throw std::logic_error("Value is not a position");

	return *(Position*) data->ptrValue;
}

}
