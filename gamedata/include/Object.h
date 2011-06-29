/*
 * Object.h
 *
 *  Created on: Jun 29, 2011
 *      Author: alno
 */
#ifndef _BOTGAME_OBJECT_H_
#define _BOTGAME_OBJECT_H_

#include "Position.h"

namespace BotGame {

class Object {
public:

    const Position & position() const { return _position; }
private:
    Position _position;
};

}

#endif // _BOTGAME_OBJECT_H_
