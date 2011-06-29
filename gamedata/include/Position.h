/*
 * Position.h
 *
 *  Created on: Jun 29, 2011
 *      Author: alno
 */
#ifndef _BOTGAME_POSITION_H_
#define _BOTGAME_POSITION_H_

#include "Types.h"
#include "Vector.h"

namespace BotGame {

class Position {
public:
	Position(): x(0), y(0), z(0) {}
	Position(Coord x, Coord y, Coord z): x(x), y(y), z(z) {}

	Position & operator += (const Vector & v) {
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}

	Position & operator -= (const Vector & v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}

	Position operator + (const Vector & v) const {
		return Position( x + v.x, y + v.y, z + v.z );
	}

	Position operator - (const Vector & v) const {
		return Position( x - v.x, y - v.y, z - v.z );
	}

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & x & y & z;
    }
public:
	Coord x,y,z;
};

}

#endif // _BOTGAME_POSITION_H_
