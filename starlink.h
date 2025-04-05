#pragma once
#include "satellite.h"

class Starlink : public Satellite
{
public:
    // Default constructor
    Starlink()
        : Satellite(Position(0.0, 7130000.0), Velocity(0.0, 7600.0), 6.0) // example LEO values
    {
    }

    // Constructor with position and velocity
    Starlink(Position position, Velocity velocity)
        : Satellite(position, velocity, 6.0)
    {
    }

    void draw(ogstream& gout) const override
    {
        gout.drawStarlink(position, angle);
    }

    void update(double time) override
    {
        Satellite::update(time);
    }
};
