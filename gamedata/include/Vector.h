/*
 * Vector.h
 *
 *  Created on: Jun 29, 2011
 *      Author: alno
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "Types.h"

namespace BotGame {

class Vector {
public:
	Vector(): x(0), y(0), z(0) {}
	Vector( Coord x, Coord y, Coord z ): x(x), y(y), z(z) {}

	Vector & operator += (const Vector & v) {
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}

	Vector & operator -= (const Vector & v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}

	Vector & operator *= (Coord m) {
		x *= m;
		y *= m;
		z *= m;

		return *this;
	}

	Vector & operator /= (Coord m) {
		x /= m;
		y /= m;
		z /= m;

		return *this;
	}

	Vector operator + (const Vector & v) const {
		return Vector( x + v.x, y + v.y, z + v.z );
	}

	Vector operator - (const Vector & v) const {
		return Vector( x - v.x, y - v.y, z - v.z );
	}

	Vector operator * (Coord m) const {
		return Vector( x * m, y * m, z * m );
	}

	Vector operator / (Coord m) const {
		return Vector( x / m, y / m, z / m );
	}

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & x & y & z;
    }
public:
	Coord x,y,z;
};

}

#endif /* VECTOR_H_ */
