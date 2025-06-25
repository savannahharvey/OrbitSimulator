/***********************************************************************
 * Header File:
 *    Test starlink : Test the starlink class
 * Author:
 *    McKay Larman
 * Summary:
 *    All the unit tests for starlink
 ************************************************************************/


#pragma once

#include "starlink.h"
#include "unitTest.h"

/*******************************
 * TEST starlink
 * A friend class for Starlink which contains the Starlink Unit test
 ********************************/
class TestStarlink : public UnitTest
{
public:
   void run()
   {
      // constructors
      construct_default();
      
      report("Starlink");
   }
   
private:
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(-36515095.13, 21082000.0),
    *          vel=(2050.0, 2684.68),
    *          direction=(0)
    *          radius = 4
    *          isDead = false
    *          age = 0
    *          isOrbiting = True
    *          parts = 0
    *          fragments = 4
    *********************************************/
   void construct_default()
   {  // Setup
      
      // Exercise
      Starlink test;
      // Verify
      assertEquals(test.pos.x, 0.0);
      assertEquals(test.pos.y, -13020000.0);
      assertEquals(test.vel.dx, 5800.0);
      assertEquals(test.vel.dy, 0.0);
      assertEquals(test.direction.radians, 0);
      assertEquals(test.radius, 6);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
   }  // Teardown
};
