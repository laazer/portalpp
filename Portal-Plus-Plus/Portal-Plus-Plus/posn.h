#pragma once
#include "velocity.h"

// represents a position on screen in pixel coordinates
class Posn {
public:
	// constructors
	Posn() = default;
	Posn(int x, int y) : m_x(x), m_y(y) { }

	// return this Posn's x and y coordinates respectively
	int getX();
	int getY();
	
	// change this Posn's x and y coordinates respectively
	void setX(int x);
	void setY(int y);
	
	// change both the x and y coordinates of this Posn
	void set(int x, int y);

	// move this posn by some fixed amounts dx and dy
	void move(int dx, int dy);

	// move this posn by the velocity vector for one time unit
	void move(Velocity v);

	// return true if this posn is within dx and dy of this given Posn
	bool isWithin(Posn * p, int dx, int dy);

	// overload operators
	friend bool operator==(const Posn & p1, const Posn & p2);
	friend bool operator!=(const Posn & p1, const Posn & p2);

private:
	int m_x;
	int m_y;
};