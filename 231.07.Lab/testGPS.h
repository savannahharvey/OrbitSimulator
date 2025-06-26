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
      construct_nondefault_up();
      construct_nondefault_leftUp();
      construct_nondefault_left();

      report("GPS");
   }

private:
   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(0.0, 26560000.0),
    *          vel=(-3880.0, 0.0),
    *          direction=(0)
    *          radius = 12
    *          isDead = false
    *          age = 0
    *          isOrbiting = True
    *          parts = 3
    *          fragments = 2
    *********************************************/
   void construct_nondefault_up()
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

   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(23001634.72, 13280000.0),
    *          vel=(-1940.0, 3360.18),
    *          direction=(0)
    *          radius = 12
    *          isDead = false
    *          age = 0
    *          isOrbiting = True
    *          parts = 3
    *          fragments = 2
    *********************************************/
   void construct_nondefault_leftUp()
   {  // Setup
      double x = 23001634.72;
      double y = 13280000.0;
      double dx = -1940.0;
      double dy = 3360.18;
      double rad = M_PI * 0.83333;

      // Exercise
      GPS test(x, y, dx, dy, rad);

      // Verify
      assertEquals(test.pos.x, 23001634.72);
      assertEquals(test.pos.y, 13280000.0);
      assertEquals(test.vel.dx, -1940.0);
      assertEquals(test.vel.dy, 3360.18);
      assertEquals(test.direction.radians, M_PI * 0.83333);
      assertEquals(test.radius, 12);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
      assertEquals(test.parts, 3);
      assertEquals(test.fragments, 2);
   }  // Teardown

   /*********************************************
    * name:    NON-DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(-26560000, 0.0),
    *          vel=(0.0, -3880.0),
    *          direction=(0)
    *          radius = 12
    *          isDead = false
    *          age = 0
    *          isOrbiting = True
    *          parts = 3
    *          fragments = 2
    *********************************************/
   void construct_nondefault_left()
   {  // Setup
      double x = -26560000.0;
      double y = 0.0;
      double dx = 0.0;
      double dy = -3880.0;
      double rad = M_PI;

      // Exercise
      GPS test(x, y, dx, dy, rad);

      // Verify
      assertEquals(test.pos.x, -26560000.0);
      assertEquals(test.pos.y, 0.0);
      assertEquals(test.vel.dx, 0.0);
      assertEquals(test.vel.dy, -3880.0);
      assertEquals(test.direction.radians, M_PI);
      assertEquals(test.radius, 12);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
      assertEquals(test.parts, 3);
      assertEquals(test.fragments, 2);
   }  // Teardown
};
