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
		
		// destroy
		destroy_4();
      
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
   }  // Teardown

   /*********************************************
    * name:    DESTROY
    * input:   nothing
    * output:  
    *********************************************/
   void destroy_4()
   {  
      // Setup
      Sputnik test;
      test.pos.x = -36515095.13;
      test.pos.y = 21082000.0;
		vector<SpaceObject*> newObjects;

      // Exercise
      test.destroy(newObjects);

      // Verify
		assertEquals(newObjects.size(), 4);

      assertEquals(dynamic_cast<Fragment*>(newObjects[0]) != nullptr, true);
      assertEquals(newObjects[0]->getPosition().x, -36514935.13); // -36515095.13 + (4.0 * 40)
      assertEquals(newObjects[0]->getPosition().y, 21082000.0); // 21082000.0 + (0 * 40)
      assertEquals(newObjects[0]->getDirection().radians, 0.0);
      assertEquals(dynamic_cast<Fragment*>(newObjects[1]) != nullptr, true);
      assertEquals(newObjects[1]->getPosition().x, -36515095.13); // -36515095.13 + ( * 40)
      assertEquals(newObjects[1]->getPosition().y, 21082160.0); // 21082000.0 + ( * 40)
      assertEquals(newObjects[1]->getDirection().radians, 1.5707963268);
      assertEquals(dynamic_cast<Fragment*>(newObjects[2]) != nullptr, true);
      assertEquals(newObjects[2]->getPosition().x, -36515255.13); // -36515095.13 + ( * 40)
      assertEquals(newObjects[2]->getPosition().y, 21082000.0); // 21082000.0 + ( * 40)
      assertEquals(newObjects[2]->getDirection().radians, 3.1415926536);
      assertEquals(dynamic_cast<Fragment*>(newObjects[3]) != nullptr, true);
      assertEquals(newObjects[3]->getPosition().x, -36515095.13); // -36515095.13 + ( * 40)
      assertEquals(newObjects[3]->getPosition().y, 21081840.0); // 21082000.0 + ( * 40)
      assertEquals(newObjects[3]->getDirection().radians, 4.7123889804);

      // Teardown
      delete newObjects[0];
      delete newObjects[1];
      delete newObjects[2];
      delete newObjects[3];
   }
};
