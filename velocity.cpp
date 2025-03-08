/***********************************************************************
 * Source File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#include "velocity.h"
#include "acceleration.h"
#include "angle.h"

#include <math.h>  // for sqrt()

 /*********************************************
  * VELOCITY : ADD
  *  v = v_0 + a t
  *********************************************/
void Velocity::add(const Acceleration& acceleration, double time)
{
	//double dx = getDX() + acceleration.getDDX() * time;
	//double dy = getDY() + acceleration.getDDY() * time;
	addDX((acceleration.getDDX() * time));
	addDY((acceleration.getDDY() * time));
}

/*********************************************
 * VELOCITY : GET SPEED
 *  find the magnitude of velocity
 *********************************************/
double Velocity::getSpeed() const
{
	double twoSides = pow(getDX(), 2) + pow(getDY(), 2);
	return sqrt(twoSides);
}

/*********************************************
 * VELOCITY : SET
 *  set from angle and direction
 *********************************************/
void Velocity::set(const Angle& angle, double magnitude)
{
	dx = magnitude * sin(angle.getRadians());
	dy = magnitude * cos(angle.getRadians());
}
