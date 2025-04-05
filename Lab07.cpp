#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>
#include "uiInteract.h"
#include "uiDraw.h"
#include "position.h"
#include "test.h"
#include "gps.h"
#include "hubble.h"
#include "sputnik.h"
#include "starlink.h"
#include "crewdragon.h"
#include "dreamchaser.h"
using namespace std;

const double GEO = 35786000.0;
const double EARTH_RADIUS = 6371e3;
const double GEO_VELOCITY = 3100.0;
const double TIME_DILATION = 24 * 60;
const double TIME_PER_FRAME = TIME_DILATION / 10.5;
const int STAR_COUNT = 200;

class Demo
{
public:
    Demo(Position ptUpperRight) : ptUpperRight(ptUpperRight)
    {
        ptGPS.setPixelsX(0);
        ptGPS.setMetersY(GEO);
        ptGPS.setPixelsY(ptGPS.getPixelsY());

        ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
        ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

        ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
        ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

        ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
        ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

        ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
        ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

        ptDreamChaser.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
        ptDreamChaser.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

        for (int i = 0; i < STAR_COUNT; ++i)
        {
            ptStars[i].setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
            ptStars[i].setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
            phaseStars[i] = random(0, 255);
        }

        angleShip = 0.0;
        angleEarth = 0.0;
        isThrusting = false;

        orbitalRadius = EARTH_RADIUS + GEO;
        orbitalPeriod = 2 * M_PI * orbitalRadius / GEO_VELOCITY;
    }

    Position ptGPS;
    Position ptHubble;
    Position ptSputnik;
    Position ptStarlink;
    Position ptCrewDragon;
    Position ptDreamChaser;

    Position ptStars[STAR_COUNT];
    unsigned char phaseStars[STAR_COUNT];

    Position ptUpperRight;

    double angleShip;
    double angleEarth;
    double orbitalRadius;
    double orbitalPeriod;
    bool isThrusting;
};

void callBack(const Interface* pUI, void* p)
{
    Demo* pDemo = (Demo*)p;

    if (pUI->isUp())    pDemo->ptGPS.addPixelsY(1.0);
    if (pUI->isDown())  pDemo->ptGPS.addPixelsY(-1.0);
    if (pUI->isLeft())  pDemo->ptGPS.addPixelsX(-1.0);
    if (pUI->isRight()) pDemo->ptGPS.addPixelsX(1.0);

    pDemo->isThrusting = pUI->isUp();

    pDemo->angleShip += (2 * M_PI / pDemo->orbitalPeriod) * TIME_PER_FRAME;
    if (pDemo->angleShip >= 2 * M_PI)
        pDemo->angleShip -= 2 * M_PI;

    pDemo->ptGPS.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip),
        pDemo->orbitalRadius * cos(pDemo->angleShip));
    pDemo->ptHubble.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip + 1),
        pDemo->orbitalRadius * cos(pDemo->angleShip + 1));
    pDemo->ptSputnik.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip + 2),
        pDemo->orbitalRadius * cos(pDemo->angleShip + 2));
    pDemo->ptStarlink.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip + 3),
        pDemo->orbitalRadius * cos(pDemo->angleShip + 3));
    pDemo->ptCrewDragon.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip + 4),
        pDemo->orbitalRadius * cos(pDemo->angleShip + 4));
    pDemo->ptDreamChaser.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip + 5),
        pDemo->orbitalRadius * cos(pDemo->angleShip + 5));

    pDemo->angleEarth += 0.01;

    ogstream gout;

    gout.drawGPS(pDemo->ptGPS, pDemo->angleShip);
    gout.drawHubble(pDemo->ptHubble, pDemo->angleShip);
    gout.drawSputnik(pDemo->ptSputnik, pDemo->angleShip);
    gout.drawStarlink(pDemo->ptStarlink, pDemo->angleShip);
    gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
    gout.drawShip(pDemo->ptDreamChaser, pDemo->angleShip, pDemo->isThrusting);

    for (int i = 0; i < STAR_COUNT; ++i)
    {
        pDemo->phaseStars[i]++;
        gout.drawStar(pDemo->ptStars[i], pDemo->phaseStars[i]);
    }

    Position pt;
    pt.setMeters(0.0, 0.0);
    gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
    testRunner();

    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0);
    ptUpperRight.setPixelsX(1000.0);
    ptUpperRight.setPixelsY(1000.0);

    Interface ui(0, NULL, "Orbit Simulator", ptUpperRight);
    Demo demo(ptUpperRight);
    ui.run(callBack, &demo);

    return 0;
}
