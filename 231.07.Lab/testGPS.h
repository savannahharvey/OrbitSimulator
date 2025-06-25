/***********************************************************************
 * Header File:
 *    Test GPS : Test the GPS class
 * Author:
 *    McKay Larman and Savannah Harvey
 * Summary:
 *    All the unit tests for parent class GPS
 ************************************************************************/


#pragma once

#include "GPS.h"
#include "unitTest.h"

 /*******************************
  * TEST SPUTNIK
  * A friend class for Sputnik which contains the Sputnik Unit test
  ********************************/
class TestGPS : public UnitTest
{
public:
   void run()
   {
      // constructors
      construct_nondefault();

      report("GPS");
   }

private:
   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(0.0, -42164000.0),
    *          vel=(3100.0, 0.0),
    *          direction=(0)
    *          radius = 10
    *          isDead = false
    *          age = 0
    *          isOrbiting = True
    *          parts = 4
    *          fragments = 2
    *********************************************/
   void construct_nondefault()
   {  // Setup
      double x = 0.0;
      double y = 26560000.0;
      double dx = -3880.0;
      double dy = 0.0;
      double rad = M_PI * 0.5;

      // Exercise
      GPS test(x, y, dx, dy, rad);

      // Verify
      assertEquals(test.pos.x, 0.0);
      assertEquals(test.pos.y, 26560000.0);
      assertEquals(test.vel.dx, -3880.0);
      assertEquals(test.vel.dy, 0.0);
      assertEquals(test.direction.radians, M_PI * 0.5);
      assertEquals(test.radius, 12);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
      assertEquals(test.parts, 3);
      assertEquals(test.fragments, 2);
   }  // Teardown
};
