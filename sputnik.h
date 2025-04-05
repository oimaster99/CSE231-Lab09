// sputnik.h
#pragma once

#include "satellite.h"

class Sputnik : public Satellite
{
public:
    Sputnik() : Satellite(Position(-36515095.13, 21082000.0),
        Velocity(2050.0, 2684.68),
        4.0) {
    } // radius in pixels

    void draw(ogstream& gout) const override
    {
        gout.drawSputnik(pos, rotation);
    }
};
