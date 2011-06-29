/*
 * Types.h
 *
 *  Created on: Jun 29, 2011
 *      Author: alno
 */
#ifndef _BOTGAME_TYPES_H_
#define _BOTGAME_TYPES_H_

#include <string>
#include <map>

#include <boost/any.hpp>

namespace BotGame {

// Base types
typedef int Int;
typedef double Real;
typedef std::string String;
typedef boost::any Any;
typedef std::map<String,Any> Hash;

// Semantic types
typedef Int Coord;

}

#endif // _BOTGAME_TYPES_H_
