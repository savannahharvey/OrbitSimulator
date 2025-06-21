/***********************************************************************
 * Header File:
 *    PLANET
 * Author:
 *    Savannah Harvey
 * Summary:
 *    Calculate all the maths
 ************************************************************************/

#pragma once

#include "SpaceObject.h"
#include "angle.h"
#include "acceleration.h"
#include <cmath>

 /************************************
  * PLANET
  ************************************/
class Planet : public SpaceObject
{
public:
	Planet() { SpaceObject(); radius = 6378000.0; earthGravity = 9.80665; }

	Acceleration calcGravity(Position posSatalite);

private:
	double earthGravity;

	Angle calcGravityDirection(double x, double y);
	double calcHeight(double x, double y);
	double calcMagnitude(double height);
};
