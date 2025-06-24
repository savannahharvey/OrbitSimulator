/***********************************************************************
 * Header File:
 *    Test Planet : Test the Planet class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include "planet.h"
#include "unitTest.h"
#include "position.h"

 /*******************************
  * TEST Planet
  * A friend class for Planet which contains the Planet unit tests
  ********************************/
class TestPlanet : public UnitTest
{

public:
	void run()
	{
		// calcGravity
		calcGravity_98();
		calcGravity_96();
		calcGravity_30degrees();

		// calcGravityDirection
		calcGravityDirection_314();
		calcGravityDirection_366();

		// calcHeight
		calcHeight_surface();
		calcHeight_GEO();
		calcHeight_random();

		// calcMagnitude
		calcMagnitude_surface();
		calcMagnitude_GEO();
		calcMagnitude_random();
		report("Planet");
	}
private:
	// calcGravity
	void calcGravity_98()
	{
		// setup
		Planet earth;
		Position pos;
		pos.x = 0.0;
		pos.y = 6378000.0; // surface
		Acceleration a;
		// exercise
		a = earth.calcGravity(pos);
		// verify
		assertEquals(a.ddx, 0.0);
		assertEquals(a.ddy, -9.80665);
		// teardown
	}
	void calcGravity_96()
	{
		// setup
		Planet earth;
		Position pos;
		pos.x = 0.0;
		pos.y = 6413786.0; // GEO
		Acceleration a;
		// exercise
		a = earth.calcGravity(pos);
		// verify
		assertEquals(a.ddx, 0.0);
		assertEquals(a.ddy, -9.69752202717);
		// teardown
	}
	void calcGravity_30degrees()
	{
		// setup
		Planet earth;
		Position pos;
		pos.x = 21082000.0;
		pos.y = 36515095.0;
		Acceleration a;
		// exercise
		a = earth.calcGravity(pos);
		// verify
		assertEquals(a.ddx, -0.1122);
		assertEquals(a.ddy, -0.1943);
		// teardown
	}
	// calcGravityDirection
	void calcGravityDirection_314()
	{
		// setup
		Planet earth;
		double x = 0.0;
		double y = 6413786.0; // GEO
		Angle a;
		// exercise
		a = earth.calcGravityDirection(x, y);
		// verify
		assertEquals(a.radians, 3.14159);
		// teardown
	}
	void calcGravityDirection_366()
	{
		// setup
		Planet earth;
		double x = 21082000.0;
		double y = 36515095.0;
		Angle a;
		// exercise
		a = earth.calcGravityDirection(x, y);
		// verify
		assertEquals(a.radians, 3.6651914307);
		// teardown
	}
	// calcHeight
	void calcHeight_surface()
	{
		// setup
		Planet earth;
		double x = 0.0;
		double y = 6378000.0; // GEO
		double h;
		// exercise
		h = earth.calcHeight(x, y);
		// verify
		assertEquals(h, 0.0);
		// teardown
	}
	void calcHeight_GEO()
	{
		// setup
		Planet earth;
		double x = 0.0;
		double y = 6413786.0; // GEO
		double h;
		// exercise
		h = earth.calcHeight(x, y);
		// verify
		assertEquals(h, 35786.0);
		// teardown
	}
	void calcHeight_random()
	{
		// setup
		Planet earth;
		double x = 21082000.0;
		double y = 36515095.0;
		double h;
		// exercise
		h = earth.calcHeight(x, y);
		// verify
		assertEquals(h, 35785999.8916);
		// teardown
	}
	// calcMagnitude
	void calcMagnitude_surface()
	{
		// setup
		Planet earth;
		double x = 0.0;
		double y = 6378000.0; // surface
		double height = 0;
		double m;
		// exercise
		m = earth.calcMagnitude(height);
		// verify
		assertEquals(m, 9.80665);
		// teardown
	}
	void calcMagnitude_random()
	{
		// setup
		Planet earth;
		double x = 21082000.0;
		double y = 36515095.0;
		double height = 35785999.8916;
		double m;
		// exercise
		m = earth.calcMagnitude(height);
		// verify
		assertEquals(m, 0.224391343229);
		// teardown
	}
	void calcMagnitude_GEO()
	{
		// setup
		Planet earth;
		double x = 0.0;
		double y = 6413786.0;
		double height = 35786.0;
		double m;
		// exercise
		m = earth.calcMagnitude(height);
		// verify
		assertEquals(m, 9.69752202717);
		// teardown
	}
};
