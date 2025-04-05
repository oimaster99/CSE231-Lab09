#pragma once

#include "position.h"
#include "velocity.h"
#include "uiDraw.h"

class ogstream;

class Satellite
{
public:
    Satellite() :
        position(), velocity(), radius(0.0), angle(0.0),
        angularVelocity(0.0), alive(true)
    {
    }

    Satellite(Position position, Velocity velocity, double radius) :
        position(position), velocity(velocity), radius(radius),
        angle(0.0), angularVelocity(0.0), alive(true)
    {
    }

    virtual ~Satellite() {}

    // Getters
    Position getPosition() const { return position; }
    Velocity getVelocity() const { return velocity; }
    double getRadius() const { return radius; }
    double getAngle() const { return angle; }
    double getAngularVelocity() const { return angularVelocity; }
    bool isAlive() const { return alive; }

    // Setters
    void kill() { alive = false; }

    // Update satellite movement
    virtual void update(double time)
    {
        position.addPixelsX(velocity.getDX() * time);
        position.addPixelsY(velocity.getDY() * time);
        angle += angularVelocity * time;
    }

    // Draw the satellite
    virtual void draw(ogstream& gout) const = 0;

protected:
    Position position;
    Velocity velocity;
    double radius;
    double angle;
    double angularVelocity;
    bool alive;
};
