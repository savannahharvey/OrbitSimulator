/***********************************************************************
 * Header File:
 *    Test Sputnik : Test the dragon class
 * Author:
 *    McKay Larman
 * Summary:
 *    All the unit tests for Crew Dragon
 ************************************************************************/


#pragma once

#include "dragon.h"
#include "unitTest.h"

/*******************************
 * TEST SPUTNIK
 * A friend class for Sputnik which contains the Sputnik Unit test
 ********************************/
class TestDragon : public UnitTest
{
public:
   void run()
   {
      // constructors
      construct_default();
      
      report("Crew Dragon");
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
      Dragon test;
      // Verify
      assertEquals(test.pos.x, 0.0);
      assertEquals(test.pos.y, 8000000.0);
      assertEquals(test.vel.dx, -7900.0);
      assertEquals(test.vel.dy, 0.0);
      assertEquals(test.direction.radians, 0);
      assertEquals(test.radius, 7);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
   }  // Teardown
};
