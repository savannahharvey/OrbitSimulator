/***********************************************************************
 * Header File:
 *    Test Fragment : Test the Satellite class
 * Author:
 *    McKay Larman
 * Summary:
 *    All the unit tests for parent class Fragment
 ************************************************************************/

#pragma once

#include "fragment.h"
#include "satellite.h" // for dummy satellite
#include "unitTest.h"

 /*******************************
  * TEST FRAGMENT
  * A friend class for Fragment which contains the Fragment unit tests
  ********************************/
class TestFragment : public UnitTest
{
public:
   void run()
   {
      // Constructor
      construct_sat_angle();

      // Move
      move_alive();
      move_dead();

      report("Fragment");
   }
private:
   /*********************************************
    * name:    CONSTRUCTOR WITH SATELLITE AND ANGLE OBJECTS
    * input:   satellite, angle
    * output:  ...
    *********************************************/
   void construct_sat_angle()
   {  
      // Setup
      DummySatellite parent;
      parent.pos.x = 0.0;
      parent.pos.y = 0.0;
      parent.vel.dx = 0.0;
      parent.vel.dy = 0.0;
      parent.direction = 0.0;
      parent.angularMomentum = 0.0;
      parent.radius = 10;
      parent.isDead = true;
      parent.age = 0;
      Angle a;
      a.radians = 0.0;

      // Exercise
      Fragment test(parent, a);

      // Verify
      assertEquals(test.pos.x, 400.0); // radius * sin(direction.getRadians()) * 40.0(meters from pixels)
      assertEquals(test.pos.y, 0.0); // radius * cos(direction.getRadians()) * 40.0
      assertEquals(test.vel.dx, 0.0); // dx = cos(0.0) * 3000
      assertEquals(test.vel.dy, 3000.0); // dy = sin(0.0) * 3000
      assertEquals(test.direction.radians, 0.0);
      assertEquals(test.angularMomentum, 0.0);
      assertEquals(test.radius, 2);
      assertEquals(test.isDead, false);
      assertEquals(test.age, 0);
   }  // Teardown

   /*********************************************
    * name:    MOVE ALIVE
    * input:   pos=(0, -42164000.0)
    *          vel=(3100.0, 0.0)
    *          direction = 0
    *          angular momentum = 0
    *          acc=(0, 0.169298992)
    *          time=48
    *          age = 0
    * output:  pos=(148800, -42163804.9676)
    *          vel=(3100.0, 8.126351616)
    *          direction = 0
    *          angular momentum = 0
    *          age = 1
    *********************************************/
   void move_alive()
   {  
      // Setup
      Satellite parent;
      parent.pos.x = 0.0;
      parent.pos.y = -42164000.0;
      parent.vel.dx = 3100.0;
      parent.vel.dy = 0.0;
		parent.radius = 10.0;
      parent.direction.radians = 3.14159;
      parent.angularMomentum = 0;
      parent.age = 0;
      Angle a;
      a.radians = 0.0;

      Fragment f(parent, a);

      GeoUp gravity;
      double t = 48;

      // Exercise
      f.move(t, gravity);

      // Verify
      assertEquals(f.pos.x, 149200.0); // radius * sin(direction.getRadians()) * 40.0 + 400.0
      assertEquals(f.pos.y, -42019804.96756); // radius * cos(direction.getRadians()) * 40.0 - 42164000.0
      assertEquals(f.vel.dx, 3100.0); // dx = (cos(pi) * 3000) + 3100.0
      assertEquals(f.vel.dy, 3008.12635); // dy = (sin(pi) * 3000) + 3000.0
      assertEquals(f.direction.radians, 0);
      assertEquals(f.angularMomentum, 0);
      assertEquals(f.age, 1);
      assertEquals(f.radius, 2);
      assertEquals(f.isDead, false);
   }  // Teardown

   /*********************************************
    * name:    MOVE ALIVE
    * input:   pos=(0, -42164000.0)
    *          vel=(3100.0, 0.0)
    *          direction = 0
    *          angular momentum = 0
    *          acc=(0, 0.169298992)
    *          time=48
    *          age = 49
    * output:  pos=(148800, -42163804.9676)
    *          vel=(3100.0, 8.126351616)
    *          direction = 0
    *          angular momentum = 0
    *          age = 50
    *********************************************/
   void move_dead()
   {
      // Setup
      Satellite parent;
      parent.pos.x = 0.0;
      parent.pos.y = -42164000.0;
      parent.vel.dx = 3100.0;
      parent.vel.dy = 0.0;
      parent.direction.radians = 0;
      parent.angularMomentum = 0;
      parent.age = 0;
      Angle a;
      a.radians = 0.0;

      Fragment f(parent, a);
		f.age = 49;

      GeoUp gravity;
      double t = 48;

      // Exercise
      f.move(t, gravity);
      // Verify
      assertEquals(f.pos.x, 148800.0); // radius * sin(direction.getRadians()) * 40.0 + 400.0
      assertEquals(f.pos.y, -42019804.96756); // radius * cos(direction.getRadians()) * 40.0 - 42164000.0
      assertEquals(f.vel.dx, 3100.0); // dx = (cos(pi) * 3000) + 3100.0
      assertEquals(f.vel.dy, 3008.12635); // dy = (sin(pi) * 3000) + 3000.0
      assertEquals(f.direction.radians, 0);
      assertEquals(f.angularMomentum, 0);
      assertEquals(f.radius, 2);
      assertEquals(f.age, 50);
      assertEquals(f.isDead, true);
   }  // Teardown

};
