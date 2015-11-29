#ifndef PORTAL_H
#define PORTAL_H
#include "velocity.h"
#include "game_object.h"
#include "posn.h"
#include "player.h"

#define PORTAL_SPEED 15.0

enum Wall
{
	TOP, LEFT, BOTTOM, RIGHT, NONE
};

class Portal : public IGameObject {

public:
	Portal(Texture &image, float x, float y, float target_x, float target_y, bool is_blue);

	// represents whether or not this portal is currently traveling
	bool is_projectile;
	// represents which wall the portal is sitting on
	Wall wall;
	
	void update(float time);
	void Collision();

	// teleport the given player through this portal and to the given portal
	void teleport(Player * player, Portal * to_portal);

private:
	bool m_is_blue;
};







#endif
