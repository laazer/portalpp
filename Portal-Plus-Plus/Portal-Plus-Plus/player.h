#ifndef PLAYER_H
#define PLAYER_H
#include "posn.h"
#include "gravity_obj.h"
#define PLAYER_HEIGHT 50
#define PLAYER_WIDTH 30


class Player : public GravityObject {
public:
	// constructors
	Player() = default;
	Player(Posn & p);

private:

};

#endif