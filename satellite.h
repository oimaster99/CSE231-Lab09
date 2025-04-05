// satellite.h
#pragma once

#include "position.h"
#include "velocity.h"
#include "uiDraw.h"

class ogstream;

class Satellite
{
public:
    Satellite(Position pos, Velocity vel, double radius)
        : pos(pos), vel(vel), radius(radius), rotation(0.0), alive(true) {
    }

    virtual ~Satellite() {}

    // Getters
    Position getPosition() const { return pos; }
    Velocity getVelocity() const { return vel; }
    double getRadius() const { return radius; }
    double getRotation() const { return rotation; }
    bool isAlive() const { return alive; }

    // Setters
    void kill() { alive = false; }

    // Update satellite movement
    virtual void update(double time)
    {
        pos.addPixelsX(vel.getDX() * time);
        pos.addPixelsY(vel.getDY() * time);
        rotation += 0.01; // optional rotation
    }

    // Draw the satellite
    virtual void draw(ogstream& gout) const = 0;

protected:
    Position pos;
    Velocity vel;
    double radius;
    double rotation;
    bool alive;

};

