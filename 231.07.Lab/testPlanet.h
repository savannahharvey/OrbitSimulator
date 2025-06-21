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
      // Calculations
      calcGravity_98();
      calcGravity_96();
      calcGravity_30degrees();

      report("Planet");
   }

private:
   void calcGravity_98()
   {
      // setup
      Planet earth;
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;

      Acceleration a;

      // exercise
      a = earth.calcGravity(pos);

      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 9.80665);
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
};
