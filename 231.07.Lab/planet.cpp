/***********************************************************************
 * Source File:
 *		PLANET
 * Author:
 *    Savannah Harvey
 * Summary:
 *    Calculate all the maths
 ************************************************************************/

#include "planet.h"

 /************************************
  * PLANET : CALC GRAVITY
  * get acceleration from gravity
  ************************************/
Acceleration Planet::calcGravity(Position posSatalite)
{
	double x = posSatalite.getMetersX();
	double y = posSatalite.getMetersY();

	Acceleration gravity;

	Angle gravityDirection = calcGravityDirection(x, y);
	double magnitude = calcMagnitude(calcHeight(x, y));

	gravity.set(gravityDirection, magnitude);

	return gravity;
}

 /************************************
  * PLANET : CALC MAGNITUDE
  *              r
  * g = g * ( ------- ) ^2
  *            r + h
  ************************************/
double Planet::calcMagnitude(double height)
{
	double gravityAccel;

	if (height > -6378000.0)
		gravityAccel = earthGravity * (radius / (radius + height)) * (radius / (radius + height));
	else
		return earthGravity;

	return gravityAccel;
}

/************************************
 * Planet : CALC GRAVITY DIRECTION
 * d = atan(xe - xs, ye - ys)
 ************************************/
Angle Planet::calcGravityDirection(double x, double y)
{
	Angle gravityDirection;

	double d = atan2(0.0 - x, 0.0 - y);
	gravityDirection.setRadians(d);

	return gravityDirection;
}

/************************************
 * Planet : CALC HEIGHT FROM EARTH
 * c^2 = a^2 + b^2
 ************************************/
double Planet::calcHeight(double x, double y)
{
	double height = (sqrt((x * x) + (y * y))) - radius;
	return height;
}
