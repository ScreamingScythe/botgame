/*
 * ObjectsTest.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */
#include <BotGame/Object.hpp>
#include <BotGame/PhysicalObject.hpp>

#include <iostream>

using namespace BotGame;

int main() {
	PhysicalObject obj(Position(0, 1, 3));

	assert(obj.getProperty("position").isPosition());
	assert(obj.getProperty("position").asPosition() == Position(0,1,3));

	obj.setProperty("position", Value(Position(-1, 2, 3.5)));

	assert(obj.getProperty("position").isPosition());
	assert(obj.getProperty("position").asPosition() == Position(-1, 2, 3.5));
	assert(obj.position == Position(-1, 2, 3.5));

	std::cout << "Success!" << std::endl;

	return 0;
}
