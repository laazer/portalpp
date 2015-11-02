#pragma once
#include "velocity.h"
#include "posn.h"
#define GRAV_ACCEL 1
// acceleration due to gravity is in pixels per game tick


class GravityObject {
public:
	GravityObject() = default;
	Velocity applyGravity();
	Velocity getVelocity();
	Posn getPos();
	Posn updatePos();
	GravityObject * updateVel(double dx, double dy);

protected:
	GravityObject(Posn & p);

private:
	Velocity m_velocity;
	Posn m_pos;
};
