#pragma once
#include "velocity.h"
#include "posn.h"
#define GRAV_ACCEL -1.0
// acceleration due to gravity is in pixels per game tick


class GravityObject {
public:
	Velocity applyGravity();
	Velocity getVelocity();
	GravityObject * updateVel(double dx, double dy);

protected:
	GravityObject(Posn & p);

private:
	Velocity m_velocity;
	Posn m_pos;
};
