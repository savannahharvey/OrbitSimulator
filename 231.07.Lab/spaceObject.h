/***********************************************************************
 * Header File:
 *    SpaceObject : Anything that is in space and could move
 * Author:
 *    McKay Larman
 * Summary:
 *    Everything that we need to make objects move in space
 ************************************************************************/

#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include "uiDraw.h"
#include "uiInteract.h"

class TestSpaceObject;
class TestDreamChaser;
class TestSatellite;
class TestSputnik;
class TestHubble;
class TestDragon;

/*********************************************
 * SPACE OBJECT
 * An object that is in space.
 **********************************************/
class SpaceObject
{
public:
   friend TestSpaceObject;
   friend TestDreamChaser;
   friend TestSatellite;
   friend TestSputnik;
   friend TestHubble;
   friend TestDragon;
   
   // constructors
   SpaceObject(): pos(Position()), vel(Velocity()), direction(Angle()), angularMomentum(0),
                                                         radius(0), isDead(false), age(0) { }
   SpaceObject(const SpaceObject &rhs) : pos(rhs.pos), vel(rhs.vel), direction(rhs.direction), angularMomentum(rhs.angularMomentum),
                                   radius(rhs.radius), isDead(rhs.isDead), age(rhs.age) {}
   SpaceObject(const Position &position, const Velocity &velocity) : SpaceObject() { pos = position; vel = velocity; }
   
   // getters
   Position getPosition()  const { return pos; }
   double getRadius()      const { return radius; }
   bool getStatus()        const { return isDead; }
   int getAge()            const { return age; }
   Angle getDirection()    const { return direction; }
   
   // setters
   virtual void move(double time, Acceleration &gravity);
   void colided() { isDead = true; }
   void spin() { direction.add(angularMomentum);  }
   
   // handle user intput (Mostly for dreamChaser).
   virtual void input(const Interface & ui, vector<SpaceObject*> &spaceObjects) {}
   
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
   
   void addAge();
};
