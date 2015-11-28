#ifndef PORTAL_H
#define PORTAL_H
#include "velocity.h"
#include "game_object.h"
#include "posn.h"

#define PORTAL_SPEED 0.5

class Portal : public IGameObject {

public:
	Portal(Texture &image, float x, float y, float target_x, float target_y, bool is_blue);

	// represents whether or not this portal is currently traveling
	bool is_projectile;
	// represents whether this portal is displayed vertically or horizontally
	bool is_vertical;
	
	void update(float time);
	void Collision();

private:
	bool m_is_blue;
};








#endif
