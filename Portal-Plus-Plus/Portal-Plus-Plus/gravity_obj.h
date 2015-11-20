#ifndef GRAVITY_OBJ_H
#define GRAVITY_OBJ_H
#include "velocity.h"
#include "posn.h"
#include "game_object.h"
#define GRAV_ACCEL 0.3
// acceleration due to gravity is in pixels per game tick


class GravityObject : public GameObject {
public:
	GravityObject() = default;
	Velocity applyGravity();
	Velocity getVelocity();
	Posn updatePos(bool onGround);
	GravityObject * updateVel(double dx, double dy);


protected:
	GravityObject(int height, int width, Posn & p);

private:
	Velocity m_velocity;
};

#endif