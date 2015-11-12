#ifndef VELOCITY_H
#define VELOCITY_H

// represents a velocity with a magnitude in x and y directions
class Velocity {
public:
	Velocity() = default;
	Velocity(double x, double y) : m_x_vel(x), m_y_vel(y) { };

	// get the speed represented by this velocity
	double getMagnitude();

	// get the appropriate directional velocities
	const double getX();
	const double getY();

	// set the x and y coordinates of this velocity independently and return this Velocity
	Velocity setX(double d);
	Velocity setY(double d);

	// element-wise assignment between velocities
	Velocity operator=(Velocity & v);

private:
	double m_x_vel;
	double m_y_vel;
};

#endif