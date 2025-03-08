/***********************************************************************
 * Header File:
 *    SPACE OBJECT
 * Author:
 *    Roy G, Joshua Maarcias
 * Summary:
 *    The base class for every object floating in space!
 ************************************************************************/

#pragma once
#include "position.h"
#include "velocity.h"

class Position;
class Velocity;

class SpaceObject 
{
public:
	SpaceObject() : radius(0.0), contact(false), broken(false) { }
	SpaceObject(double r, Position pos, Velocity vel);

	//Getters
	double GetRadius() { return radius; }
	Position GetPosition() { return position; }
	bool IsContact() { return contact; }
	bool IsBroken() { return broken; }

	//Setters
	void SetRadius(double r) { radius = r; }
	void SetPosition(Position pos) { position = pos; }
	void SetVelocity(Velocity vel) { velocity = vel; }
	void SetContact(bool cont) { contact = cont; }
	void SetBroken(bool broke) { broken = broke; }
		
	double radius;
	Position position;
	Velocity velocity;
	bool contact;
	bool broken;
};
