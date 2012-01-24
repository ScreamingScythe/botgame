#include <BotGame/Io/Values.hpp>
#include <iostream>

#define assert(x) do { if (!(x)) std::cerr << "FAILED: " #x << std::endl; } while (false)

using namespace BotGame::Io;

int main() {
	Value a;

	assert(!a.isNumber());
	assert(!a.isString());
	assert(!a.isList());
	assert(!a.isMap());
	assert(a.isNull());

	a = 11;

	assert(a.isNumber());
	assert(!a.isString());
	assert(!a.isList());
	assert(!a.isMap());
	assert(!a.isNull());
	assert(a.asNumber() == 11);

	a = "123";

	assert(!a.isNumber());
	assert(a.isString());
	assert(!a.isList());
	assert(!a.isMap());
	assert(!a.isNull());
	assert(a.asString() == "123");

	List b;
	b.add(11);
	b.add("111");

	a = b;

	b.add(34);

	assert(b.size() == 3);

	assert(a.isList());
	assert(a.asList().size() == 2);

	Map m;
	m.put("aa", 12);
	m.put("bb", 11);

	a = m;

	m.remove("bb");

	assert(m.size() == 1);
	assert(m.get("aa").asNumber() == 12);
	assert(m.get("bb").isNull());
	assert(a.isMap());
	assert(a.asMap().size() == 2);

	std::cout << "Success!" << std::endl;

	return 0;
}
