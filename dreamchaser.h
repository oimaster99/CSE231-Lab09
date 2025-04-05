#pragma once
#include "satellite.h"

class DreamChaser : public Satellite
{
public:
    DreamChaser(Position pos, Velocity vel)
        : Satellite(pos, vel, 10.0) {}

    void draw(ogstream& gout) const override
    {
        gout.drawShip(position, angle, false); // or true if you want thrust on

    }
};
