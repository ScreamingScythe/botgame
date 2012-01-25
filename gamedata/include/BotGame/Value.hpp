/*
 * Value.hpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */

#ifndef VALUE_HPP_
#define VALUE_HPP_

#include <boost/any.hpp>

#include <BotGame/Types.hpp>
#include <BotGame/Base/RefCountObject.hpp>

namespace BotGame {

class Value {
public:
	enum Type {
		UNDEFINED = 0,
		BOOLEAN = 1,
		INTEGER = 2,
		DOUBLE = 3,

		STRING = 4,
		LIST = 5,
		HASH = 6,
		VECTOR = 7,
		POSITION = 8
	};
private:
	class Data;

	template<typename T>
	class PtrData;
public:
	static Value undefined;
public:
	Value();
	Value(Data * data);
	Value(const Value & value);
	~Value();

	explicit Value(Boolean v);
	explicit Value(int v);
	explicit Value(Integer v);
	explicit Value(Double v);
	explicit Value(const char * v);
	explicit Value(const String & v);
	explicit Value(const List & v);
	explicit Value(const Hash & v);
	explicit Value(const Vector & v);
	explicit Value(const Position & v);

	Value & operator =(const Value & value);

	Type type() const;

	operator bool() const {
		return data;
	}

	bool isBoolean() const {
		return type() == BOOLEAN;
	}

	bool isInteger() const {
		return type() == INTEGER;
	}

	bool isDouble() const {
		return type() == DOUBLE;
	}

	bool isString() const {
		return type() == STRING;
	}

	bool isList() const {
		return type() == LIST;
	}

	bool isHash() const {
		return type() == HASH;
	}

	bool isVector() const {
		return type() == VECTOR;
	}

	bool isPosition() const {
		return type() == POSITION;
	}

	Boolean asBoolean() const;
	Integer asInteger() const;
	Double asDouble() const;
	const String & asString() const;
	const List & asList() const;
	const Hash & asHash() const;
	const Vector & asVector() const;
	const Position & asPosition() const;

private:
	Data * data;
};

}

#endif /* VALUE_HPP_ */
