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
	~Value();

	Value & operator =(const Value & value);

	bool isNumber() const;
	bool isString() const;
	bool isList() const;
	bool isMap() const;
	bool isNull() const;

	Number asNumber();
	String asString();
	List asList();
	Map asMap();

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
	operator Value();
private:
	Data * data;
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
	operator Value();
private:
	Data * data;
};

}
}

#endif /* VALUES_H_ */
