/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

// for add()
class Acceleration;
class Angle;

/*********************************************
 * Velocity
 * I feel the need, the need for speed
 *********************************************/
class Velocity
{

public:
	// constructors
	Velocity() : dx(0), dy(0) { }
	Velocity(double dx, double dy) : dx(dx), dy(dy) { }
	Velocity(const Velocity & vel) : dx(vel.dx), dy(vel.dy) { }

	// getters
	double getDX()       const { return dx; }
	double getDY()       const { return dy; }
	double getSpeed()    const;

	// setters
	void setDX(double dx) { this->dx = dx; }
	void setDY(double dy) { this->dy = dy; }
	void set(const Angle& angle, double magnitude);
	void addDX(double dx) { this->dx += dx; }
	void addDY(double dy) { this->dy += dy; }
	void add(const Acceleration& acceleration, double time);

private:
	double dx;           // horizontal velocity
	double dy;           // vertical velocity
};

#pragma once
