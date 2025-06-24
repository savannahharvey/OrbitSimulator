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

 /************************************
  * PLANET
  ************************************/
class Planet : public SpaceObject
{
public:
   Planet() : SpaceObject()
   {
      radius = 6378000.0;
      earthGravity = 9.80665;
      double td = 24.0 * 60.0;
      angularMomentum = -(2.0 * M_PI / 30.0) * (td / 86400.0 );
   }

	void draw(ogstream& gout) override { gout.drawEarth(pos, direction.getDegrees()); }

	Acceleration calcGravity(Position posSatalite);

private:
	double earthGravity;

	Angle calcGravityDirection(double x, double y);
	double calcHeight(double x, double y);
	double calcMagnitude(double height);
};
