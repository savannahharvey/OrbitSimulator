/***********************************************************************
 * Header File:
 *    Test spaceObject : Test the spaceObject class
 * Author:
 *    McKay Larman
 * Summary:
 *    All the unit tests for parent class spaceObject
 ************************************************************************/


#pragma once

#include "position.h"
#include "SpaceObject.h"
#include "unitTest.h"

/*******************************
 * TEST spaceObject
 * A friend class for spaceObject which contains the spcaeObject unit tests
 ********************************/
class TestSpaceObject : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_default();
      construct_copy();
      
      // Setters
      test_move_geo_up();
      
      // Getters
      test_getPosition_zero();
      test_getPosition_not_zero();
      test_getRadius_zero();
      test_getRadius_not_zero();
      test_getAge_zero();
      test_getAge_not_zero();
      test_getStatus_living();
      test_getStatus_dead();
      
      report("Space Object");
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
    *********************************************/
   void construct_default()
   {  // Setup
      
      // Exercise
      SpaceObject test;
      // Verify
      assertEquals(test.pos.x, 0);
      assertEquals(test.pos.y, 0);
//      assertEquals(test.direction, 10);
      assertEquals(test.radius, 0);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
   }  // Teardown
   
   /*********************************************
    * name:    COPY CONSTRUCTOR
    * input:   RHS
    *          pos=(70000, 10000)
    *          vel=(45, 45)
    *          direction=(10)
    *          radius = 10
    *          isDead = false
    *          age = 5
    * output:  pos=(70000, 10000)
    *          vel=(45, 45)
    *          direction=(10)
    *          radius = 10
    *          isDead = false
    *          age = 5
    *********************************************/
   void construct_copy()
   {  // Setup
      SpaceObject rhs;
      rhs.pos.x = 70000;
      rhs.pos.y = 10000;
//      rhs.direction = 10;
      rhs.radius = 10;
      rhs.isDead = false;
      rhs.age = 5;
      // Exercise
      SpaceObject test(rhs);
      // Verify
      assertEquals(test.pos.x, 70000);
      assertEquals(test.pos.y, 10000);
//      assertEquals(test.direction, 10);
      assertEquals(test.radius, 10);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 5);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST MOVE GEO UP
    * input:   pos=(0, -42164000.0)
    *          vel=(3100.0, 0.0)
    *          acc=(0, 9.8)
    * output:  pos=(0, 0), ??
    *********************************************/
   void test_move_geo_up()
   {  // Setup
      
      // Exercise
      
      // Verify
      
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET POSITION ZERO
    * input:   pos=(0, 0)
    * output:  (0, 0)
    *********************************************/
   void test_getPosition_zero()
   {  // Setup
      SpaceObject test;
      test.pos.x = 0;
      test.pos.y = 0;
      // Exercise
      Position p = test.getPosition();
      // Verify
      assertEquals(p.x, 0);
      assertEquals(p.y, 0);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET POSITION NOT ZERO
    * input:   pos=(123.4, 567.8)
    * output:  (123.4, 567.8)
    *********************************************/
   void test_getPosition_not_zero()
   {  // Setup
      SpaceObject test;
      test.pos.x = 123.4;
      test.pos.y = 567.8;
      // Exercise
      Position p = test.getPosition();
      // Verify
      assertEquals(p.x, 123.4);
      assertEquals(p.y, 567.8);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET RADIUS ZERO
    * input:   radius = 0.0
    * output:  0.0
    *********************************************/
   void test_getRadius_zero()
   {  // Setup
      SpaceObject test;
      test.radius = 0.0;
      // Exercise
      double r = test.getRadius();
      // Verify
      assertEquals(r, 0.0);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET RADIUS NOT ZERO
    * input:   radius = 42.1
    * output:  42.1
    *********************************************/
   void test_getRadius_not_zero()
   {  // Setup
      SpaceObject test;
      test.radius = 42.1;
      // Exercise
      double r = test.getRadius();
      // Verify
      assertEquals(r, 42.1);
   }  // Teardown
   
   /*********************************************
    * name:    TEST GET AGE ZERO
    * input:   age = 0
    * output:  0
    *********************************************/
   void test_getAge_zero()
   {  // Setup
      SpaceObject test;
      test.age = 0;
      // Exercise
      int age = test.getAge();
      // Verify
      assertEquals(age, 0);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET AGE NOT ZERO
    * input:   age = 15
    * output:  15
    *********************************************/
   void test_getAge_not_zero()
   {  // Setup
      SpaceObject test;
      test.age = 15;
      // Exercise
      int age = test.getAge();
      // Verify
      assertEquals(age, 15);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET STATUS LIVING
    * input:   isDead = false
    * output:  false
    *********************************************/
   void test_getStatus_living()
   {  // Setup
      SpaceObject test;
      test.isDead = false;
      // Exercise
      bool isDead = test.getStatus();
      // Verify
      assertEquals(isDead, false);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET STATUS DEAD
    * input:   isDead = true
    * output:  ture
    *********************************************/
   void test_getStatus_dead()
   {  // Setup
      SpaceObject test;
      test.isDead = true;
      // Exercise
      bool isDead = test.getStatus();
      // Verify
      assertEquals(isDead, true);
   }  // Teardown
};
