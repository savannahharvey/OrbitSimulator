/***********************************************************************
 * Header File:
 *    PLANET
 * Author:
 *    Savannah Harvey
 * Summary:
 *    Calculate all the maths
 ************************************************************************/

#pragma once

#include "spaceObject.h"
#include "angle.h"
#include "acceleration.h"
#include <cmath>

class TestPlanet;

/************************************
* PLANET
************************************/
class Planet : public SpaceObject
{
	friend TestPlanet;
public:
	Planet() { SpaceObject(); radiusMeters = 6378000.0;  radius = 50; earthGravity = 9.80665; angularMomentum = -0.0001; }

	// draw
	void draw(ogstream& gout) override {
		gout.drawEarth(pos, direction.getDegrees());
	}

	// all calculations together in one
	Acceleration calcGravity(Position posSatalite);

private:

	// 9.8 for earth
	double radiusMeters;
	double earthGravity;
	Angle calcGravityDirection(double x, double y);
	double calcHeight(double x, double y);
	double calcMagnitude(double height);
};
