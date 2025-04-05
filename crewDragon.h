#pragma once
#include "satellite.h"

class CrewDragon : public Satellite
{
public:
    // Default constructor
    CrewDragon()
        : Satellite(Position(0.0, 6750000.0), Velocity(0.0, 7500.0), 10.0) // Slightly above LEO
    {
    }

    // With position and velocity
    CrewDragon(Position position, Velocity velocity)
        : Satellite(position, velocity, 10.0)
    {
    }

    void draw(ogstream& gout) const override
    {
        gout.drawCrewDragon(position, angle);
    }

    void update(double time) override
    {
        Satellite::update(time);
    }
};
