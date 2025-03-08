/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Roy G
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
 * ANGLE : NORMALIZE
 ************************************/
double Angle::normalize(double radians) const
{
	radians = fmod(radians, TWO_PI);

	if (radians < 0) {
		radians += TWO_PI;
	}

	return radians;
}



