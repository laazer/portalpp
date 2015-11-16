#ifndef PLAYER_H
#define PLAYER_H
#include "posn.h"
#include "gravity_obj.h"


class Player : public GravityObject {
public:
	// constructors
	Player() = default;
	Player(Posn p);

private:

};

#endif