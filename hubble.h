#pragma once
#include "satellite.h"

class Hubble : public Satellite
{
public:
    Hubble()
        : Satellite(Position(0.0, -42164000.0), Velocity(3100.0, 0.0), 10.0) // radius = 10 pixels
    {
    }

    void draw(ogstream& gout) const override
    {
        gout.drawHubble(pos, rotation);
    }

    void update(double time) override
    {
        Satellite::update(time); // update position and rotation
    }
};
