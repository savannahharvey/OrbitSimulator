/***********************************************************************
 * Header File:
 *    PLANET
 * Author:
 *    Savannah Harvey
 * Summary:
 *    Calculate all the maths
 ************************************************************************/

#pragma once

#include "angle.h"
#include "acceleration.h"
#include <cmath>

 /************************************
  * PLANET
  ************************************/
class Planet
{
public:
	Planet() {}

	Acceleration calcGravity(double height, Angle a);
	Angle calcGravityDirection(int x, int y);
	double calcHeight(double x, double y);
};
