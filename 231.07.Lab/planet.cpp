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
  *              r
  * g = g * ( ------- ) ^2
  *            r + h
  ************************************/
Acceleration Planet::calcGravity(double height, Angle a)
{
	Acceleration gravity;
	double gravityAccel;

	gravityAccel = 9.80665 * (6378000 / (6378000 + height)) * (6378000 / (6378000 + height));
	gravity.set(a, gravityAccel);

	return gravity;
}

/************************************
 * Planet : CALC GRAVITY DIRECTION
 * d = atan(xe - xs, ye - ys)
 ************************************/
Angle Planet::calcGravityDirection(int x, int y)
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
	double height = (sqrt((x * x) + (y * y))) - 6378000;
	return height;
}
