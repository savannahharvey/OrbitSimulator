/***********************************************************************
 * Header File:
 *    Test Hubble : Test the Hubble class
 * Author:
 *    McKay Larman and Savannah Harvey
 * Summary:
 *    All the unit tests for parent class Hubble
 ************************************************************************/


#pragma once

#include "hubble.h"
#include "unitTest.h"

 /*******************************
  * TEST SPUTNIK
  * A friend class for Sputnik which contains the Sputnik Unit test
  ********************************/
class TestHubble : public UnitTest
{
public:
   void run()
   {
      // constructors
      construct_default();

      report("Hubble");
   }

private:
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
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
   void construct_default()
   {  // Setup

      // Exercise
      Hubble test;

      // Verify
      assertEquals(test.pos.x, 0.0);
      assertEquals(test.pos.y, -42164000.0);
      assertEquals(test.vel.dx, 3100.0);
      assertEquals(test.vel.dy, 0.0);
      assertEquals(test.direction.radians, 0);
      assertEquals(test.radius, 10);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
      assertEquals(test.parts, 4);
      assertEquals(test.fragments, 2);
   }  // Teardown
};
