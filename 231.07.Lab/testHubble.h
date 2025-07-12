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
  * TEST HUBBLE
  * A friend class for Sputnik which contains the Sputnik Unit test
  ********************************/
class TestHubble : public UnitTest
{
public:
   void run()
   {
      // constructors
      construct_default();

      // destroy
		destroy_6();

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
   }  // Teardown

   /*********************************************
    * name:    DESTROY
    * input:   nothing
    * output:
    *********************************************/
   void destroy_6()
   {
      // Setup
      Hubble test;
      vector<SpaceObject*> newObjects;

      // Exercise
      test.destroy(newObjects);

      // Verify
      assertEquals(newObjects.size(), 6);

      assertEquals(dynamic_cast<Fragment*>(newObjects[0]) != nullptr, true);
      assertEquals(dynamic_cast<Fragment*>(newObjects[1]) != nullptr, true);
      assertEquals(dynamic_cast<HubbleTelescope*>(newObjects[2]) != nullptr, true);
      assertEquals(dynamic_cast<HubbleComputer*>(newObjects[3]) != nullptr, true);
      assertEquals(dynamic_cast<HubbleLeft*>(newObjects[4]) != nullptr, true);
      assertEquals(dynamic_cast<HubbleRight*>(newObjects[5]) != nullptr, true);

      // Teardown
      delete newObjects[0];
      delete newObjects[1];
      delete newObjects[2];
      delete newObjects[3];
      delete newObjects[4];
      delete newObjects[5];
   }
};
