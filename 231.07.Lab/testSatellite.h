/***********************************************************************
 * Header File:
 *    Test Satellite : Test the Satellite class
 * Author:
 *    McKay Larman
 * Summary:
 *    All the unit tests for parent class Satellite
 ************************************************************************/


#pragma once

#include "satellite.h"
#include "unitTest.h"

/*******************************
 * TEST SATELLITE
 * A friend class for Satellite which contains the Satellite unit tests
 ********************************/
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      // Constructor
      construct_default();
      construct_pos_vel();
      
      // Getter
      test_isInOrbit_orbiting();
      test_isInOrbit_not_orbiting();
      //test_getParts_zero();
      //test_getParts_ten();
      /*test_getFragments_zero();
      test_getFragments_five();*/
      
      // Setter
      test_leftOrbit();
      
      report("Satellite");
   }
private:
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(0, 0),
    *          vel=(0, 0),
    *          direction=(0)
    *          radius = 0
    *          isDead = false
    *          age = 0
    *          isOrbiting = true
    *          parts = 0
    *          fragments = 0
    *********************************************/
   void construct_default()
   {  // Setup
      
      // Exercise
      Satellite test;
      // Verify
      assertEquals(test.pos.x, 0);
      assertEquals(test.pos.y, 0);
      assertEquals(test.vel.dx, 0);
      assertEquals(test.vel.dy, 0);
      assertEquals(test.direction.radians, 0);
      assertEquals(test.radius, 0);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
   }  // Teardown
   
   
   /*********************************************
    * name:    CONSTRUCTOR WITH POSITION AND VELOCITY
    * input:   pos=(50000,-50000)
    *          vel=(100, -100)
    * output:  pos=(50000,-50000)
    *          vel=(100, -100)
    *          direction=(0)
    *          radius = 0
    *          isDead = false
    *          age = 0
    *          isOrbiting = false
    *          parts = 0
    *          fragments = 0
    *********************************************/
   void construct_pos_vel()
   {  // Setup
      Position p;
      p.x =  50000;
      p.y = -50000;
      Velocity v;
      v.dx =  100;
      v.dy = -100;
      // Exercise
      Satellite test(p, v);
      // Verify
      assertEquals(test.pos.x,  50000);
      assertEquals(test.pos.y, -50000);
      assertEquals(test.vel.dx,  100);
      assertEquals(test.vel.dy, -100);
      assertEquals(test.direction.radians, 0);
      assertEquals(test.radius, 0);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isOrbiting, true);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST IS IN ORBIT : ORBITING
    * input:   isOrbiting = true
    * output:  true
    *********************************************/
   void test_isInOrbit_orbiting()
   {  // Setup
      Satellite test;
      test.isOrbiting = true;
      // Exercise
      bool isInOrbit = test.isInOrbit();
      // Verify
      assertEquals(isInOrbit, true);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST IS IN ORBIT : OUT OF ORBIT
    * input:   isOrbiting = true
    * output:  true
    *********************************************/
   void test_isInOrbit_not_orbiting()
   {  // Setup
      Satellite test;
      test.isOrbiting = false;
      // Exercise
      bool isInOrbit = test.isInOrbit();
      // Verify
      assertEquals(isInOrbit, false);
   }  // Teardown
   
   
   ///*********************************************
   // * name:    TEST GET PARTS : ZERO
   // * input:   parts = 0
   // * output:  0
   // *********************************************/
   //void test_getParts_zero()
   //{  // Setup
   //   Satellite test;
   //   test.parts = 0;
   //   // Exercise
   //   int parts = test.getParts();
   //   // Verify
   //   assertEquals(parts, 0);
   //}  // Teardown
   //
   
   ///*********************************************
   // * name:    TEST GET PARTS : TEN
   // * input:   parts = 0
   // * output:  0
   // *********************************************/
   //void test_getParts_ten()
   //{  // Setup
   //   Satellite test;
   //   test.parts = 10;
   //   // Exercise
   //   int parts = test.getParts();
   //   // Verify
   //   assertEquals(parts, 10);
   //}  // Teardown
   
      
   ///*********************************************
   // * name:    TEST GET FRAGMENTS : ZERO
   // * input:   fragments = 0
   // * output:  0
   // *********************************************/
   //void test_getFragments_zero()
   //{  // Setup
   //   Satellite test;
   //   test.fragments = 0;
   //   // Exercise
   //   int fragments = test.getFragments();
   //   // Verify
   //   assertEquals(fragments, 0);
   //}  // Teardown
   
   
   ///*********************************************
   // * name:    TEST GET FRAGMENTS : FIVE
   // * input:   fragments = 5
   // * output:  5
   // *********************************************/
   //void test_getFragments_five()
   //{  // Setup
   //   Satellite test;
   //   test.fragments = 5;
   //   // Exercise
   //   int fragments = test.getFragments();
   //   // Verify
   //   assertEquals(fragments, 5);
   //}  // Teardown
   
   
   /*********************************************
    * name:    TEST LEFT ORBIT
    * input:   inOrbit = True
    * output:  isOrbit = false
    *********************************************/
   void test_leftOrbit()
   {  // Setup
      Satellite test;
      test.isOrbiting = true;
      // Exercise
      test.leftOrbit();
      // Verify
      assertEquals(test.isOrbiting, false);
   }  // Teardown
};
