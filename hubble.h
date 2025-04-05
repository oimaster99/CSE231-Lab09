#pragma once
#include "satellite.h"

class Hubble : public Satellite
{
public:
    // Default constructor
    Hubble()
        : Satellite(Position(0.0, -42164000.0), Velocity(3100.0, 0.0), 10.0)
    {
    }

    // New constructor to match the argument list
    Hubble(Position position, Velocity velocity)
        : Satellite(position, velocity, 10.0)
    {
    }

    void draw(ogstream& gout) const override
    {
        gout.drawHubble(position, angle);
    }

    void update(double time) override
    {
        Satellite::update(time);
    }
};
