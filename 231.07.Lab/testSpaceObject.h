/***********************************************************************
 * Header File:
 *    Test spaceObject : Test the spaceObject class
 * Author:
 *    McKay Larman
 * Summary:
 *    All the unit tests for parent class spaceObject
 ************************************************************************/


#pragma once

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
      construct_copy();
      construct_pos_vel();
      
      // Setters
      test_move_geo_up();
      test_move_retro_angled();
      test_move_non_orbit();
      test_addAge_zero();
      test_addAge_limit();
      
      // Getters
      test_getPosition_zero();
      test_getPosition_not_zero();
      test_getRadius_zero();
      test_getRadius_not_zero();
      test_getAge_zero();
      test_getAge_not_zero();
      test_getStatus_living();
      test_getStatus_dead();
      test_getDirection();
      
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
      assertEquals(test.vel.dx, 0);
      assertEquals(test.vel.dy, 0);
      assertEquals(test.direction.radians, 0);
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
      rhs.vel.dx = 45;
      rhs.vel.dy = 45;
      rhs.direction.radians = 10;
      rhs.radius = 10;
      rhs.isDead = false;
      rhs.age = 5;
      // Exercise
      SpaceObject test(rhs);
      // Verify
      assertEquals(test.pos.x, 70000);
      assertEquals(test.pos.y, 10000);
      assertEquals(test.vel.dx, 45);
      assertEquals(test.vel.dy, 45);
      assertEquals(test.direction.radians, 10);
      assertEquals(test.radius, 10);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 5);
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
      SpaceObject test(p, v);
      // Verify
      assertEquals(test.pos.x,  50000);
      assertEquals(test.pos.y, -50000);
      assertEquals(test.vel.dx,  100);
      assertEquals(test.vel.dy, -100);
      assertEquals(test.direction.radians, 0);
      assertEquals(test.radius, 0);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST MOVE GEO UP
    * input:   pos=(0, -42164000.0)
    *          vel=(3100.0, 0.0)
    *          acc=(0, 0.169298992)
    *          time=48
    *          age = 0
    * output:  pos=(148800, -42163804.9676)
    *          vel=(3100.0, 8.126351616)
    *          age = 1
    *********************************************/
   void test_move_geo_up()
   {  // Setup
      SpaceObject s;
      s.pos.x = 0.0;
      s.pos.y = -42164000.0;
      s.vel.dx = 3100.0;
      s.vel.dy = 0.0;
      s.age = 0;
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
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST MOVE RETRO ANGLED
    * input:   pos=(-36515095.13, 21082000.0)
    *          vel=(2050.0, 2684.68)
    *          acc=(0.1943286025942485, -0.11219567100418354)
    *          time=48
    *          age = 35
    * output:  pos=(-36416471.26344, 21210735.39058)
    *          vel=(2059.327773, 2679.294608)
    *          age = 36
    *********************************************/
   void test_move_retro_angled()
   {  // Setup
      SpaceObject s;
      s.pos.x = -36515095.13;
      s.pos.y = 21082000.0;
      s.vel.dx = 2050.0;
      s.vel.dy = 2684.68;
      s.age = 35;
      RetroAngle gravity;
      double t = 48;
      // Exercise
      s.move(t, gravity);
      // Verify
      assertEquals(s.pos.x, -36416471.26344);
      assertEquals(s.pos.y, 21210735.39058);
      assertEquals(s.vel.dx, 2059.327773);
      assertEquals(s.vel.dy, 2679.294608);
      assertEquals(s.age, 36);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST MOVE NON ORBIT
    * input:   pos=(25000000.0, 25000000.0)
    *          vel=(5000.0, 5000.0)
    *          acc=(-0.22566525361795767, -0.22566525361795767)
    *          time=48
    *          age = 10000
    * output:  pos=(25239740.03362783, 25239740.03362783)
    *          vel=(4989.168068, 4989.168068)
    *          age = 0
    *********************************************/
   void test_move_non_orbit()
   {  // Setup
      SpaceObject s;
      s.pos.x = 25000000.0;
      s.pos.y = 25000000.0;
      s.vel.dx = 5000.0;
      s.vel.dy = 5000.0;
      s.age = 10000;
      NonOrbit gravity;
      double t = 48;
      // Exercise
      s.move(t, gravity);
      // Verify
      assertEquals(s.pos.x, 25239740.03362783);
      assertEquals(s.pos.y, 25239740.03362783);
      assertEquals(s.vel.dx, 4989.168068);
      assertEquals(s.vel.dy, 4989.168068);
      assertEquals(s.age, 0);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST ADD AGE : ZERO
    * input:   age = 0
    * output:  age = 1
    *********************************************/
   void test_addAge_zero()
   {  // Setup
      SpaceObject test;
      test.age = 0;
      // Exercise
      test.addAge();
      // Verify
      assertEquals(test.age, 1);
   }  // Teardown
   
   
   /*********************************************
    * name:    TEST ADD AGE : LIMIT
    * input:   age = 10000
    * output:  age = 0
    *********************************************/
   void test_addAge_limit()
   {  // Setup
      SpaceObject test;
      test.age = 10000;
      // Exercise
      test.addAge();
      // Verify
      assertEquals(test.age, 0);
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
   
   
   /*********************************************
    * name:    TEST GET DIRECTION
    * input:   direction = 20
    * output:  ture
    *********************************************/
   void test_getDirection()
   {  // Setup
      SpaceObject test;
      test.direction.radians = 20;
      // Exercise
      Angle angle = test.getDirection();
      // Verify
      assertEquals(angle.radians, 20);
   }  // Teardown
};
