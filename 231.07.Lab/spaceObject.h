/***********************************************************************
 * Header File:
 *    SpaceObject : Anything that is in space and could move
 * Author:
 *    McKay Larman
 * Summary:
 *    Everything that we need to make objects move in space
 ************************************************************************/

#pragma once

#include <iostream>
#include <cmath>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include "uiDraw.h"

class TestSpaceObject;
class TestSatellite;
class TestSputnik;

/*********************************************
 * SPACE OBJECT
 * An object that is in space.
 **********************************************/
class SpaceObject
{
public:
   friend TestSpaceObject;
   friend TestSatellite;
   friend TestSputnik;
   
   // constructors
   SpaceObject(): pos(Position()), vel(Velocity()), direction(Angle()), angularMomentum(0),
                                                         radius(0), isDead(false), age(0) { }
   SpaceObject(SpaceObject &rhs) : pos(rhs.pos), vel(rhs.vel), direction(rhs.direction), angularMomentum(rhs.angularMomentum),
                                   radius(rhs.radius), isDead(rhs.isDead), age(rhs.age) {}
   SpaceObject(Position &position, Velocity &velocity) : SpaceObject() { pos = position; vel = velocity; }
   
   // getters
   Position getPosition()  const { return pos; }
   double getRadius()      const { return radius; }
   bool getStatus()        const { return isDead; }
   int getAge()            const { return age; }
   Angle getDirection()    const { return direction; }
   
   // setters
   void move(double time, const Acceleration &gravity);
   void colided() { isDead = true; }
   void spin() { direction.add(angularMomentum);  }
   
   // Draw
   virtual void draw(ogstream& gout) {}
   
protected:
   Position pos;
   Velocity vel;
   Angle direction;
   double angularMomentum;
   double radius;
   bool isDead;
   int age;
   
private:
   void addAge();
};
