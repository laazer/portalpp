#include "velocity.h"
#include <math.h>

double Velocity::getMagnitude() {
	return sqrt(m_x_vel * m_x_vel + m_y_vel * m_y_vel);
}

Velocity Velocity::operator=(Velocity & v) {
	m_x_vel = v.getX();
	m_y_vel = v.getY();
	return *this;
}

const double Velocity::getX() {
	return m_x_vel;
}

const double Velocity::getY() {
	return m_y_vel;
}

Velocity Velocity::setX(double d) {
	m_x_vel = d;
	return (*this);
}

Velocity Velocity::setY(double d) {
	m_y_vel = d;
	return (*this);
}