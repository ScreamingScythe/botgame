/*
 * Types.h
 *
 *  Created on: Jun 29, 2011
 *      Author: alno
 */
#ifndef _BOTGAME_TYPES_H_
#define _BOTGAME_TYPES_H_

#include <string>
#include <vector>

#include <boost/unordered_map.hpp>

namespace BotGame {

class Value;
class Vector;
class Position;

typedef bool Boolean;
typedef long Integer;
typedef double Double;
typedef std::string String;
typedef std::vector<Value> List;
typedef boost::unordered_map<String,Value> Hash;

}

#endif // _BOTGAME_TYPES_H_
