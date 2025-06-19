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
#include "spaceObject.h"
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
      spaceObject so;
      // Verify
      assertEquals(so.radius, 0);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST MOVE GEO UP
    * input:   pos=(0, -42164000.0)
    *          vel=(3100.0, 0.0)
    *          acc=(0, 9.8)
    * output:  pos=(0, 0),
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
      
      // Exercise
      
      // Verify
      
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET POSITION NOT ZERO
    * input:   pos=(1234, 5678)
    * output:  (1234, 5678)
    *********************************************/
   void test_getPosition_not_zero()
   {  // Setup
      
      // Exercise
      
      // Verify
      
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET RADIUS ZERO
    * input:   radius = 0
    * output:  0
    *********************************************/
   void test_getRadius_zero()
   {  // Setup
      
      // Exercise
      
      // Verify
      
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET RADIUS NOT ZERO
    * input:   radius = 42
    * output:  42
    *********************************************/
   void test_getRadius_not_zero()
   {  // Setup
      
      // Exercise
      
      // Verify
      
   }  // Teardown
   
   /*********************************************
    * name:    TEST GET AGE ZERO
    * input:   age = 0
    * output:  0
    *********************************************/
   void test_getAge_zero()
   {  // Setup
      
      // Exercise
      
      // Verify
      
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET AGE NOT ZERO
    * input:   age = 15
    * output:  15
    *********************************************/
   void test_getAge_not_zero()
   {  // Setup
      
      // Exercise
      
      // Verify
      
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET STATUS LIVING
    * input:   isDead = false
    * output:  false
    *********************************************/
   void test_getStatus_living()
   {  // Setup
      
      // Exercise
      
      // Verify
      
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST GET STATUS DEAD
    * input:   isDead = true
    * output:  ture
    *********************************************/
   void test_getStatus_dead()
   {  // Setup
      
      // Exercise
      
      // Verify
      
   }  // Teardown
};
