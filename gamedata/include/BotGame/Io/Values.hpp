/*
 * Values.h
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */

#ifndef VALUES_H_
#define VALUES_H_

#include <string>

namespace BotGame {
namespace Io {

typedef unsigned int Size;
typedef std::string String;
typedef double Number;
class List;
class Map;

class Value {
public:
	class Data;
public:
	Value();
	Value(Data * data);
	Value(const Value & value);
	Value(Number num);
	Value(const char * str);
	Value(const String & str);
	Value(const List & list);
	Value(const Map & map);
	~Value();

	Value & operator =(const Value & value);
	Value & operator =(const char * str) {
		return (*this) = String(str);
	}

	bool isNumber() const;
	bool isString() const;
	bool isList() const;
	bool isMap() const;
	bool isNull() const;

	Number asNumber() const;
	String asString() const;
	List asList() const;
	Map asMap() const;

private:
	Data * data;
};

class List {
public:
	class Data;
public:
	List();
	List(Data * data);
	List(const List & data);
	~List();

	List & operator =(const List & value);

	/**
	 * Implicit conversion to value
	 */
	operator Value() const {
		return Value(*this);
	}

	/**
	 * Get count o elements in list
	 */
	Size size() const;

	/**
	 * Get element in list by index
	 */
	Value get(Size index) const;

	/**
	 * Add element to the end of list
	 */
	void add(Value value);

	/**
	 * Insert element into list with given index
	 */
	void insert(Size index, Value value);

	/**
	 * Remove element with given index
	 */
	void remove(Size index);
private:
	void prepareWrite();
private:
	Data * data;

	friend class Value;
};

class Map {
public:
	class Data;
public:
	Map();
	Map(Data * data);
	Map(const Map & data);
	~Map();

	Map & operator =(const Map & value);

	/**
	 * Implicit conversion to value
	 */
	operator Value() const {
		return Value(*this);
	}

	/**
	 * Get count of pairs in map
	 */
	Size size() const;

	/**
	 * Get element in map by key
	 */
	Value get(String key) const;

	/**
	 * Put key-value pair to map
	 */
	void put(String key, Value value);

	/**
	 * Remove element with given key
	 */
	void remove(String key);
private:
	void prepareWrite();
private:
	Data * data;

	friend class Value;
};

}
}

#endif /* VALUES_H_ */
