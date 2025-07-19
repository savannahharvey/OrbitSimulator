/***********************************************************************
 * Header File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    Savannah Harvey
 * Summary:
 *    All the unit tests for parent class Satellite
 ************************************************************************/


#pragma once

#include "simulator.h"
#include "unitTest.h"

 /*******************************
  * TEST SATELLITE
  * A friend class for Satellite which contains the Satellite unit tests
  ********************************/
class TestSimulator : public UnitTest
{
public:
   void run()
   {
      // Constructor
      construct_default();

		// detectCollision
      detectCollision_0();
      detectCollision_2();

		// checkCollision
		checkCollision_false();
      checkCollision_true();

      report("Simulator");
   }
private:
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  nothing
    *********************************************/
   void construct_default()
   {
      // Setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);

      // Exercise
      Simulator sim(ptUpperRight);

      // Verify
      assertEquals(sim.spaceObjects.size(), 11); // 11 items in spaceObjects vector, no collisions

      assertUnit(dynamic_cast<DreamChaser*>(sim.spaceObjects[0]) != nullptr, true);
      assertUnit(dynamic_cast<Hubble*>     (sim.spaceObjects[1]) != nullptr, true);
      assertUnit(dynamic_cast<Sputnik*>    (sim.spaceObjects[2]) != nullptr, true);
      assertUnit(dynamic_cast<Dragon*>     (sim.spaceObjects[3]) != nullptr, true);
      assertUnit(dynamic_cast<Starlink*>   (sim.spaceObjects[4]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[5]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[6]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[7]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[8]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[9]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[10]) != nullptr, true);

   }

   /*********************************************
	 * name:    DETECT COLLISION, 0 COLLISIONS
    *********************************************/
   void detectCollision_0()
   {
      // Setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);

      Simulator sim(ptUpperRight);

      // Exercise
      sim.detectCollision();

      // Verify
      assertEquals(sim.spaceObjects.size(), 11); // 11 items in spaceObjects vector, no collisions

      assertUnit(dynamic_cast<DreamChaser*>(sim.spaceObjects[0]) != nullptr, true);
      assertUnit(dynamic_cast<Hubble*>     (sim.spaceObjects[1]) != nullptr, true);
      assertUnit(dynamic_cast<Sputnik*>    (sim.spaceObjects[2]) != nullptr, true);
      assertUnit(dynamic_cast<Dragon*>     (sim.spaceObjects[3]) != nullptr, true);
      assertUnit(dynamic_cast<Starlink*>   (sim.spaceObjects[4]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[5]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[6]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[7]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[8]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[9]) != nullptr, true);
      assertUnit(dynamic_cast<GPS*>        (sim.spaceObjects[10]) != nullptr, true);

      // Teardown
   }

   /*********************************************
    * name:    DETECT COLLISION, 2 COLLISIONS
    *********************************************/
   void detectCollision_2()
   {
      // Setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);

      Simulator sim(ptUpperRight);

		sim.spaceObjects[1]->pos.setPixelsX(10000000.0); // Hubble
		sim.spaceObjects[1]->pos.setPixelsY(10000000.0); // Hubble
		sim.spaceObjects[2]->pos.setPixelsX(10000000.0); // Sputnik
		sim.spaceObjects[2]->pos.setPixelsY(10000000.0); // Sputnik

      // Exercise
      sim.detectCollision();

      // Verify
      assertEquals(sim.spaceObjects.size(), 19); // 19 items in spaceObjects vector now

      assertUnit(dynamic_cast<DreamChaser*>    (sim.spaceObjects[0]) != nullptr);
      assertUnit(dynamic_cast<Dragon*>         (sim.spaceObjects[1]) != nullptr);
      assertUnit(dynamic_cast<Starlink*>       (sim.spaceObjects[2]) != nullptr);
      assertUnit(dynamic_cast<GPS*>            (sim.spaceObjects[3]) != nullptr);
      assertUnit(dynamic_cast<GPS*>            (sim.spaceObjects[4]) != nullptr);
      assertUnit(dynamic_cast<GPS*>            (sim.spaceObjects[5]) != nullptr);
      assertUnit(dynamic_cast<GPS*>            (sim.spaceObjects[6]) != nullptr);
      assertUnit(dynamic_cast<GPS*>            (sim.spaceObjects[7]) != nullptr);
      assertUnit(dynamic_cast<GPS*>            (sim.spaceObjects[8]) != nullptr);

      // Hubble debris (2 fragments + 4 specific parts)
      assertUnit(dynamic_cast<Fragment*>       (sim.spaceObjects[9]) != nullptr);
      assertUnit(dynamic_cast<Fragment*>       (sim.spaceObjects[10]) != nullptr);
      assertUnit(dynamic_cast<HubbleTelescope*>(sim.spaceObjects[11]) != nullptr);
      assertUnit(dynamic_cast<HubbleComputer*> (sim.spaceObjects[12]) != nullptr);
      assertUnit(dynamic_cast<HubbleLeft*>     (sim.spaceObjects[13]) != nullptr);
      assertUnit(dynamic_cast<HubbleRight*>    (sim.spaceObjects[14]) != nullptr);

      // Sputnik debris (4 fragments)
      assertUnit(dynamic_cast<Fragment*>(sim.spaceObjects[15]) != nullptr);
      assertUnit(dynamic_cast<Fragment*>(sim.spaceObjects[16]) != nullptr);
      assertUnit(dynamic_cast<Fragment*>(sim.spaceObjects[17]) != nullptr);
      assertUnit(dynamic_cast<Fragment*>(sim.spaceObjects[18]) != nullptr);

      // Teardown
   }

   /*********************************************
    * name:    CHECK COLLISION, FALSE
    *********************************************/
   void checkCollision_false()
   {
      // Setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);

      Simulator sim(ptUpperRight);
		SpaceObject* pObj1 = sim.spaceObjects[1]; // Hubble
		SpaceObject* pObj2 = sim.spaceObjects[2]; // Sputnik

		bool isCollided = true;

		// Exercise
		isCollided = sim.checkCollision(pObj1, pObj2);

      // Verify
		assertEquals(isCollided, false); // No collision detected
      
		// Teardown
   }

   /*********************************************
    * name:    CHECK COLLISION, TRUE
    *********************************************/
   void checkCollision_true()
   {
      // Setup
      Position ptUpperRight;
      ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
      ptUpperRight.setPixelsX(1000.0);
      ptUpperRight.setPixelsY(1000.0);

      Simulator sim(ptUpperRight);
      SpaceObject* pObj1 = sim.spaceObjects[1]; // Hubble
      sim.spaceObjects[1]->pos.setPixelsX(10000000.0);
      sim.spaceObjects[1]->pos.setPixelsY(10000000.0);
      SpaceObject* pObj2 = sim.spaceObjects[2]; // Sputnik
      sim.spaceObjects[2]->pos.setPixelsX(10000000.0);
      sim.spaceObjects[2]->pos.setPixelsY(10000000.0);

      bool isCollided = false;

      // Exercise
      isCollided = sim.checkCollision(pObj1, pObj2);

      // Verify
      assertEquals(isCollided, true); // collision detected

      // Teardown
   }
};
