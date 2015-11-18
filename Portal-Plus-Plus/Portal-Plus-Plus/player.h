#ifndef PLAYER_H
#define PLAYER_H
#include "posn.h"
#include "gravity_obj.h"
#define PLAYER_HEIGHT 60
#define PLAYER_WIDTH 30


class Player : public GravityObject {
public:
	// constructors
	Player() = default;
	Player(Posn & p);

	bool isJumping();
	void setJumping(bool jumping);
private:
	bool m_is_jumping;
};

#endif