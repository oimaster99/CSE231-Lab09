/***********************************************************************
 * Source File:
 *    ACCELERATION
 * Author:
 *    Roy G
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>

 /*********************************************
  * ACCELERATION : ADD
  *  a += a
  *********************************************/
void Acceleration::add(const Acceleration& acceleration)
{
	this->ddx += acceleration.getDDX();
	this->ddy += acceleration.getDDY();
}

/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
	this->ddx = magnitude * sin(angle.getRadians());
	this->ddy = magnitude * cos(angle.getRadians());
	//this->setDDX(ddx);
	//this->setDDY(ddy);
}
