#include "posn.h"

double Posn::getX() {
	return m_x;
}

double Posn::getY() {
	return m_y;
}

void Posn::setX(double x) {
	this->m_x = x;
}

void Posn::setY(double y) {
	this->m_y = y;
}

void Posn::set(double x, double y) {
	setX(x);
	setY(y);
}

void Posn::move(double dx, double dy) {
	set(getX() + dx, getY() + dy);
}

void Posn::move(Velocity v) {
	set(getX() + v.getX(), getY() + v.getY());
}

bool Posn::isWithin(Posn * p, double dx, double dy) {
	return (p->getX() - this->getX() <= dx)
		|| (p->getY() - this->getY() <= dy);
}

// friend function to Posn
bool operator==(const Posn & p1, const Posn & p2) {
	return p1.m_x == p2.m_x && p1.m_y == p2.m_y;
}

// friend function to Posn
bool operator!=(const Posn & p1, const Posn & p2) {
	return p1.m_x != p2.m_x || p1.m_y != p2.m_y;
}