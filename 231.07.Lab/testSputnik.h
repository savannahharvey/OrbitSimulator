/***********************************************************************
 * Header File:
 *    Test Sputnik : Test the Sputnik class
 * Author:
 *    McKay Larman
 * Summary:
 *    All the unit tests for parent class Sputnik
 ************************************************************************/


#pragma once

#include "sputnik.h"
#include "unitTest.h"

/*******************************
 * TEST SPUTNIK
 * A friend class for Sputnik which contains the Sputnik Unit test
 ********************************/
class TestSputnik : public UnitTest
{
public:
   void run()
   {
      // constructors
      construct_default();
      
      report("Sputnik");
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
      Sputnik test;
      // Verify
      assertEquals(test.pos.x, -36515095.13);
      assertEquals(test.pos.y, 21082000.0);
      assertEquals(test.vel.dx, 2050.0);
      assertEquals(test.vel.dy, 2684.68);
      assertEquals(test.direction.radians, 0);
      assertEquals(test.radius, 4);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
      assertEquals(test.parts, 0);
      assertEquals(test.fragments, 4);
   }  // Teardown
};
