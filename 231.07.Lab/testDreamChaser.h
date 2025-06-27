/***********************************************************************
 * Header File:
 *    Test Dream Chaser
 * Author:
 *    McKay Larman
 * Summary:
 *    All the unit tests for the dream chaser
 ************************************************************************/


#pragma once

#include "dreamChaser.h"
#include "unitTest.h"

/*******************************
 * TEST SPUTNIK
 * A friend class for Sputnik which contains the Sputnik Unit test
 ********************************/
class TestDreamChaser : public UnitTest
{
public:
   void run()
   {
      // constructors
      construct_default();
      
      // move
      test_move_thrust();
      test_move_no_thrust();
      
      // input
      test_input_thrust();
      test_input_left();
      test_input_right();
      test_input_right_and_thrust();
      test_input_shooting();
      
      report("DreamChaser");
   }
   
private:
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  pos=(-57600000.0, 57600000.0),
    *          vel=(0.0, -2000.0),
    *          direction=(0)
    *          radius = 10
    *          isDead = false
    *          age = 0
    *          isThrusting = 0
    *********************************************/
   void construct_default()
   {  // Setup
      
      // Exercise
      DreamChaser test;
      // Verify
      assertEquals(test.pos.x, -57600000.0);
      assertEquals(test.pos.y,  57600000.0);
      assertEquals(test.vel.dx, 0.0);
      assertEquals(test.vel.dy, -2000.0);
      assertEquals(test.direction.radians, 0);
      assertEquals(test.radius, 10);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
      assertEquals(test.isThrusting, false);
   }  // Teardown
   
   
   /***************************************
    * name:    Test Move No Thrust        same numbers as SpaceObject : TEST MOVE GEO UP
    * input:   pos=(0, -42164000.0)
    *          vel=(3100.0, 0.0)
    *          acc=(0, 0.169298992)
    *          time=48
    *          age = 0
    *          isThrusting = false
    * output:  pos=(148800, -42163804.9676)
    *          vel=(3100.0, 8.126351616)
    *          age = 1
    **************************************/
   void test_move_no_thrust()
   {  // Setup
      DreamChaser s;
      s.pos.x = 0.0;
      s.pos.y = -42164000.0;
      s.vel.dx = 3100.0;
      s.vel.dy = 0.0;
      s.age = 0;
      s.isThrusting = false;
      GeoUp gravity;
      double t = 48;
      // Exercise
      s.move(t, gravity);
      // Verify
      assertEquals(s.pos.x, 148800);
      assertEquals(s.pos.y, -42163804.9676);
      assertEquals(s.vel.dx, 3100.0);
      assertEquals(s.vel.dy, 8.126351616);
      assertEquals(s.age, 1);
      assertEquals(s.isThrusting, false);
   }  // Teardown
   
   
   /***************************************
    * name:    Test Move Thrust        same numbers as SpaceObject : TEST MOVE GEO UP
    * input:   pos=(0, -42164000.0)
    *          vel=(3100.0, 0.0)
    *          acc=(0, 0.169298992)
    *          direction = pi/2
    *          time=1
    *          age = 0
    *          isThrusting = true
    * output:  pos=(3101.0,−42163999.915350504)
    *          vel=(3102.0, 0.169298992)
    *          age = 1
    **************************************/
   void test_move_thrust()
   {  // Setup
      DreamChaser s;
      s.pos.x = 0.0;
      s.pos.y = -42164000.0;
      s.vel.dx = 3100.0;
      s.vel.dy = 0.0;
      s.direction.radians = M_PI_2;
      s.age = 0;
      s.isThrusting = true;
      GeoUpThrust gravity;
      double t = 1;
      // Exercise
      s.move(t, gravity);
      // Verify
      assertEquals(s.pos.x, 3101.0);
      assertEquals(s.pos.y, -42163999.915350504);
      assertEquals(s.vel.dx, 3102.0);
      assertEquals(s.vel.dy, 0.169298992);
      assertEquals(s.age, 1);
      assertEquals(s.isThrusting, true);
   }  // Teardown
   
   /***************************************
    * Name: Input thrust
    * Input:   direction   = 0
    *          isThrusting = false
    *          ui.isDown() = 1
    *          ui.isUp()   = 0
    *          isLeft()    = 0
    *          isRight()   = 0
    *          isSpace()   = 0
    * output:  direction   = 0
    *          isThrusting = True
    *          SpaceObjects.size() = 0
    **************************************/
   void test_input_thrust()
   {  // setup
      DreamChaser ship;
      ship.direction.radians = 0;
      ship.isThrusting = false;
      Thrust ui;
      vector<SpaceObject*> SpaceObjects;
      // exercise
      ship.input(ui, SpaceObjects);
      // verify
      assertEquals(ship.direction.radians, 0);
      assertEquals(ship.isThrusting, true);
      assertEquals(SpaceObjects.size(), 0);
   }  // teardown
   
   
   /***************************************
    * Name: Input LEFT
    * Input:   direction   = 1.0
    *          isThrusting = false
    *          ui.isDown() = 0
    *          ui.isUp()   = 0
    *          isLeft()    = 1
    *          isRight()   = 0
    *          isSpace()   = 0
    * output:  direction   = 0.9
    *          isThrusting = false
    *          SpaceObjects.size() = 0
    **************************************/
   void test_input_left()
   {  // setup
      DreamChaser ship;
      ship.direction.radians = 1.0;
      ship.isThrusting = false;
      Left ui;
      vector<SpaceObject*> SpaceObjects;
      // exercise
      ship.input(ui, SpaceObjects);
      // verify
      assertEquals(ship.direction.radians, 0.90);
      assertEquals(ship.isThrusting, false );
      assertEquals(SpaceObjects.size(), 0);
   }  // teardown
   
   
   /***************************************
    * Name: Input Right
    * Input:   direction   = 0
    *          isThrusting = false
    *          ui.isDown() = 0
    *          ui.isUp()   = 0
    *          isLeft()    = 0
    *          isRight()   = 1
    *          isSpace()   = 0
    * output:  direction   = 0.1
    *          isThrusting = false
    *          SpaceObjects.size() = 0
    **************************************/
   void test_input_right()
   {  // setup
      DreamChaser ship;
      ship.direction.radians = 0;
      ship.isThrusting = false;
      Right ui;
      vector<SpaceObject *> SpaceObjects;
      // exercise
      ship.input(ui, SpaceObjects);
      // verify
      assertEquals(ship.direction.radians, 0.1);
      assertEquals(ship.isThrusting, false);
      assertEquals(SpaceObjects.size(), 0);
   }  // teardown
   
   
   /***************************************
    * Name: Input right and thrust
    * Input:   direction   = 0
    *          isThrusting = false
    *          ui.isDown() = 1
    *          ui.isUp()   = 0
    *          isLeft()    = 0
    *          isRight()   = 1
    *          isSpace()   = 0
    * output:  direction   = 0.1
    *          isThrusting = True
    *          SpaceObjects.size() = 0
    **************************************/
   void test_input_right_and_thrust()
   {  // setup
      DreamChaser ship;
      ship.direction.radians = 0;
      ship.isThrusting = false;
      RightThrust ui;
      vector<SpaceObject *> SpaceObjects;
      // exercise
      ship.input(ui, SpaceObjects);
      // verify
      assertEquals(ship.direction.radians, 0.1);
      assertEquals(ship.isThrusting, true);
      assertEquals(SpaceObjects.size(), 0);
   }  // teardown
   
   
   /***************************************
    *
    **************************************/
   void test_input_shooting()
   {
      
   }
};
