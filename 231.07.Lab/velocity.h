/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once
#include <cmath>
#include "angle.h"

 // for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestSpaceObject;
class TestDreamChaser;
class TestSatellite;
class TestSputnik;
class TestHubble;
class TestGPS;
class TestDragon;
class TestStarlink;
class TestFragment;

// for add()
class Acceleration;
//class Angle;

/*********************************************
 * Velocity
 * I feel the need, the need for speed
 *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestSpaceObject;
   friend TestDreamChaser;
   friend TestSatellite;
   friend TestSputnik;
   friend TestHubble;
   friend TestGPS;
   friend TestDragon;
   friend TestStarlink;
   friend TestFragment;

public:
   // constructors
   Velocity() : dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy) : dx(dx), dy(dy) {}
   Velocity(double speed, const Angle & direction)
   {
      dx = speed * sin(direction.getRadians());
      dy = speed * cos(direction.getRadians());
   }

   // getters
   double getDX()       const { return dx; }
   double getDY()       const { return dy; }
   double getSpeed()    const;

   // setters
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void set(const Angle& angle, double magnitude);

   // adding
   void addDX(double dx) { this->dx = this->dx + dx; }
   void addDY(double dy) { this->dy = this->dy + dy; }
   void add(const Acceleration& acceleration, double time);
   
   void operator += (const Velocity &rhs) { this->dx += rhs.dx; this->dy += rhs.dy; }

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};
