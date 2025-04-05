#pragma once
#include "position.h"
#include "uiDraw.h"
#include <cmath>

class Projectile
{
public:
    Projectile()
        : pos(), angle(0.0), alive(false) {
    }

    void fire(const Position& startPos, double startAngle)
    {
        pos = startPos;
        angle = startAngle;
        alive = true;
    }

    void move()
    {
        if (!alive) return;
        const double SPEED = 5000.0;
        pos.setMetersX(pos.getMetersX() + SPEED * sin(angle));
        pos.setMetersY(pos.getMetersY() + SPEED * cos(angle));
    }

    void draw(ogstream& gout) const
    {
        if (alive)
            gout.drawProjectile(pos);
    }

    bool isAlive() const { return alive; }

private:
    Position pos;
    double angle;
    bool alive;
};
