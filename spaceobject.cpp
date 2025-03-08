/***********************************************************************
 * Source File:
 *    Space Object
 * Author:
 *    Roy G, Joshua Macias
 * Summary:
 *    The base class for every object floating in space!
 ************************************************************************/

#include "spaceobject.h"

SpaceObject::SpaceObject(double r, Position pos, Velocity vel) 
{
	SetRadius(r);
	SetPosition(pos);
	SetVelocity(vel);
	SetContact(false);
	SetBroken(false);
}