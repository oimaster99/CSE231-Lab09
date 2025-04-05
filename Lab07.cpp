#define _USE_MATH_DEFINES
#include <cassert>
#include "uiInteract.h"
#include "uiDraw.h"
#include "position.h"
#include "test.h"
#include "math.h"
using namespace std;

const double GEO = 35786000.0;
const double EARTH_RADIUS = 6371e3;
const double GEO_VELOCITY = 3100.0;
const double TIME_DILATION = 24 * 60;
const double TIME_PER_FRAME = TIME_DILATION / 10.5;

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

        ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
        ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

        angleShip = 0.0;
        angleEarth = 0.0;
        phaseStar = 0;

        orbitalRadius = EARTH_RADIUS + GEO;
        orbitalPeriod = 2 * M_PI * orbitalRadius / GEO_VELOCITY;
    }

    Position ptGPS;
    Position ptHubble;
    Position ptSputnik;
    Position ptStar;
    Position ptUpperRight;

    unsigned char phaseStar;

    double angleShip;
    double angleEarth;
    double orbitalRadius;
    double orbitalPeriod;
};

void callBack(const Interface* pUI, void* p)
{
    Demo* pDemo = (Demo*)p;

    if (pUI->isUp())
        pDemo->ptGPS.addPixelsY(1.0);
    if (pUI->isDown())
        pDemo->ptGPS.addPixelsY(-1.0);
    if (pUI->isLeft())
        pDemo->ptGPS.addPixelsX(-1.0);
    if (pUI->isRight())
        pDemo->ptGPS.addPixelsX(1.0);

    pDemo->angleShip += (2 * M_PI / pDemo->orbitalPeriod) * TIME_PER_FRAME;
    if (pDemo->angleShip >= 2 * M_PI)
        pDemo->angleShip -= 2 * M_PI;

    pDemo->ptGPS.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip),
        pDemo->orbitalRadius * cos(pDemo->angleShip));
    pDemo->ptGPS.setPixelsX(pDemo->ptGPS.getPixelsX());
    pDemo->ptGPS.setPixelsY(pDemo->ptGPS.getPixelsY());

    pDemo->ptHubble.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip + 1),
        pDemo->orbitalRadius * cos(pDemo->angleShip + 1));
    pDemo->ptHubble.setPixelsX(pDemo->ptHubble.getPixelsX());
    pDemo->ptHubble.setPixelsY(pDemo->ptHubble.getPixelsY());

    pDemo->ptSputnik.setMeters(pDemo->orbitalRadius * sin(pDemo->angleShip + 2),
        pDemo->orbitalRadius * cos(pDemo->angleShip + 2));
    pDemo->ptSputnik.setPixelsX(pDemo->ptSputnik.getPixelsX());
    pDemo->ptSputnik.setPixelsY(pDemo->ptSputnik.getPixelsY());

    pDemo->angleEarth += 0.01;
    pDemo->phaseStar++;

    Position pt;
    ogstream gout(pt);

    gout.drawGPS(pDemo->ptGPS, pDemo->angleShip);
    gout.drawHubble(pDemo->ptHubble, pDemo->angleShip);
    gout.drawSputnik(pDemo->ptSputnik, pDemo->angleShip);

    pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
    pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
    gout.drawGPSCenter(pt, pDemo->angleShip);

    gout.drawStar(pDemo->ptStar, pDemo->phaseStar);

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
    Interface ui(0, NULL, "Demo", ptUpperRight);

    Demo demo(ptUpperRight);

    ui.run(callBack, &demo);

    return 0;
}
