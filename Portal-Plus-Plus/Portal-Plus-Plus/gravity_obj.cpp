#include "gravity_obj.h"

GravityObject::GravityObject(int height, int width, Posn & p) : GameObject(height, width, p) {
	m_velocity = Velocity(0, 0);
}


Velocity GravityObject::applyGravity() {
	m_velocity.setY(m_velocity.getY() + GRAV_ACCEL);
	return m_velocity;
}

Velocity GravityObject::getVelocity() {
	return m_velocity;
}

GravityObject * GravityObject::updateVel(double dx, double dy) {
	m_velocity.setX(m_velocity.getX() + dx);
	m_velocity.setY(m_velocity.getY() + dy);
	return this;
}