#pragma once
#include "satellite.h"

class GPS : public Satellite
{
public:
    GPS(Position position, Velocity velocity)
        : Satellite(position, velocity, 12.0) // radius = 12px
    {
    }

    void draw(ogstream& gout) const override
    {
        gout.drawGPS(position, angle);
    }


    void update(double time) override
    {
        Satellite::update(time);
    }

    void nudge(double dx, double dy)
    {
        position.addPixelsX(dx);
        position.addPixelsY(dy);
    }

    GPS() : Satellite(Position(), Velocity(), 12.0) {}

};
