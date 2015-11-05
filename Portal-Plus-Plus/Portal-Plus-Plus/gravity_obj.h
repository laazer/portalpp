#pragma once
#include "velocity.h"
#include "posn.h"
<<<<<<< HEAD
#include "game_object.h"
#define GRAV_ACCEL -1.0
=======
#define GRAV_ACCEL 1
>>>>>>> 598d3532ecedc39d2fc02a6fa0d93eb1393aeb00
// acceleration due to gravity is in pixels per game tick


class GravityObject : public GameObject {
public:
<<<<<<< HEAD
	GravityObject();
=======
	GravityObject() = default;
>>>>>>> 598d3532ecedc39d2fc02a6fa0d93eb1393aeb00
	Velocity applyGravity();
	Velocity getVelocity();
	Posn getPos();
	Posn updatePos();
	GravityObject * updateVel(double dx, double dy);

protected:
	GravityObject(int height, int width, Posn & p);

private:
	Velocity m_velocity;
};
