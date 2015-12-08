#ifndef PORTAL_H
#define PORTAL_H
#include "game_object.h"
#include "player.h"

#define PORTAL_SPEED 15.0

// enumeration for the type of wall that a portal may contact
enum Wall
{
	TOP, LEFT, BOTTOM, RIGHT, NONE
};

// class for a portal object that acts as a projectile until it contacts
// various types of game objects
class Portal : public IGameObject {
public:
	// construct a portal with at the given x and y coordinates and set its
	// velocity towards the given target coordinates
	Portal(Texture &image, float x, float y, float target_x, float target_y, bool is_blue);

	// represents whether or not this portal is currently traveling
	bool is_projectile;
	
	// represents which wall the portal is sitting on
	Wall wall;
	
	// update the portal based on the given time duration since the last
	// clock tick
	virtual void update(float time);

	// update the portal based on whether or not is is colliding with any
	// other game objects right now
	void Collision();

	// teleport the given player through this portal and to the given portal
	void teleport(Player * player, Portal * to_portal);

private:
	// true if this portal should be rendered as blue, false if orange
	bool m_is_blue;
};







#endif
