#pragma once
#include "satellite.h"

class Sputnik : public Satellite
{
public:
    // Default constructor (optional if needed)
    Sputnik()
        : Satellite(Position(-36515095.13, 21082000.0), Velocity(2050.0, 2684.68), 4.0) // sample values
    {
    }

    // Constructor with position and velocity
    Sputnik(Position position, Velocity velocity)
        : Satellite(position, velocity, 4.0)
    {
    }

    void draw(ogstream& gout) const override
    {
        gout.drawSputnik(position, angle);
    }

    void update(double time) override
    {
        Satellite::update(time);
    }
};
