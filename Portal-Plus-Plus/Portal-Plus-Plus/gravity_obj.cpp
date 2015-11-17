#include "gravity_obj.h"
#include <math.h>

GravityObject::GravityObject(int height, int width, Posn & p) : GameObject(height, width, p) {
	Velocity v = Velocity(0, 0);
	m_velocity = v;
}


Velocity GravityObject::applyGravity() {
	m_velocity.setY(m_velocity.getY() + GRAV_ACCEL);
	return m_velocity;
}

Velocity GravityObject::getVelocity() {
	return m_velocity;
}

Posn GravityObject::updatePos() {
	m_pos.move(m_velocity);
	return m_pos;
}

GravityObject * GravityObject::updateVel(double dx, double dy) {
	m_velocity.setX(m_velocity.getX() + dx);
	m_velocity.setY(m_velocity.getY() + dy);
	return this;
}