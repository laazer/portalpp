#include "posn.h"

int Posn::getX() {
	return x;
}

int Posn::getY() {
	return y;
}

void Posn::setX(int x) {
	this->x = x;
}

void Posn::setY(int y) {
	this->y = y;
}

void Posn::set(int x, int y) {
	setX(x);
	setY(y);
}

void Posn::move(int dx, int dy) {
	set(getX() + dx, getY() + dy);
}

bool Posn::isWithin(Posn * p, int dx, int dy) {
	return p->getX() - this->getX() <= dx;
}

// friend function to Posn
bool operator==(const Posn & p1, const Posn & p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

// friend function to Posn
bool operator!=(const Posn & p1, const Posn & p2) {
	return p1.x != p2.x || p1.y != p2.y;
}