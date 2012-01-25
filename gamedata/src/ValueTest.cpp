#include <BotGame/Value.hpp>
#include <iostream>

using namespace BotGame;

int main() {
	Value a;

	assert(!a.isInteger());
	assert(!a.isString());
	assert(!a.isList());
	assert(!a.isHash());
	assert(a.type() == Value::UNDEFINED);
	assert(!a);

	a = Value(11);

	assert(a.isInteger());
	assert(!a.isString());
	assert(!a.isList());
	assert(!a.isHash());
	assert(a);
	assert(a.asInteger() == 11);

	a = Value("123");

	assert(!a.isInteger());
	assert(a.isString());
	assert(!a.isList());
	assert(!a.isHash());
	assert(a);
	assert(a.asString() == "123");

	List b;
	b.push_back(Value(11));
	b.push_back(Value("111"));

	a = Value(b);

	b.push_back(Value(34));

	assert(b.size() == 3);

	assert(a.isList());
	assert(a.asList().size() == 2);

	Hash m;
	m["aa"] = Value(12);
	m["bb"] = Value(11);

	a = Value(m);

	m.erase("bb");

	assert(m.size() == 1);
	assert(m["aa"].asInteger() == 12);
	assert(m.find("bb") == m.end());
	assert(a.isHash());
	assert(a.asHash().size() == 2);

	std::cout << "Success!" << std::endl;

	return 0;
}
