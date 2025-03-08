/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Roy G
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#define TWO_PI 6.28318530718
#include <math.h>   // for M_PI which is 3.14159

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:


	// Constructors
	Angle() : radians(0) {}
	Angle(const Angle& rhs) : radians(rhs.getRadians()) {}
	Angle(double degrees) : radians(convertToRadians(degrees)) {}

	// Getters
	double getDegrees() const {
		return radians * (180.0 / M_PI);
	}

	double getRadians() const {
		return radians;
	}

	// Setters
	void setDegrees(double degrees) {
		double rad = degrees * (M_PI / 180.0);

		rad = fmod(rad, TWO_PI);

		if (rad < 0) {
			rad += TWO_PI;
		}

		this->radians = rad;
	}

	void setRadians(double rad) {
		rad = fmod(rad, TWO_PI);

		if (rad < 0) {
			rad += TWO_PI;
		}

		this->radians = rad;
	}

	void setUp() {
		this->radians = 0;
	}

	void setDown() {
		this->radians = 180 * (M_PI / 180);
	}

	void setRight() {
		this->radians = 90 * (M_PI / 180);
	}

	void setLeft() {
		this->radians = 270 * (M_PI / 180);
	}

	void reverse() {
		this->radians = TWO_PI - radians;
	}

	Angle& add(double delta) {
		radians += delta;
		radians = normalize(radians);
		return *this;
	}

private:
	//normalize radians, defined in cpp file
	double normalize(double radians) const;

	//conversion methods
	double convertToDegrees(double radians) {
		return radians * (180 / M_PI);
	}

	double convertToRadians(double degrees) {
		return degrees * (M_PI / 180);
	}

	double radians;   // 360 degrees equals 2 PI radians
};

#pragma once
