//
//  spaceObject.h
//  Lab07
//
//  Created by Mckay Larman on 6/19/25.
//

#pragma once

#include <iostream>
#include <cmath>
#include "position.h"


class Position;
class Acceleration;
class TestSpaceObject;

/*********************************************
 * SPACE OBJECT
 * An object that is in space.
 **********************************************/
class SpaceObject
{
public:
   friend TestSpaceObject;
   
   // constructors
   SpaceObject(): pos(Position()), radius(0), isDead(false), age(0) { }
   SpaceObject(SpaceObject &rhs) : pos(rhs.pos), radius(rhs.radius), isDead(rhs.isDead), age(rhs.age) {}
   
   // getters
   Position getPosition()  const { return pos; }
   double getRadius()      const { return radius; }
   bool getStatus()        const { return isDead; }
   int getAge()            const { return age; }
   
   // setters
//   void move(double time, Acceleration gravity) {}
   void colided() { isDead = true; }
   
protected:
   Position pos;
//   Velocity vel;
   double radius;
   bool isDead;
   int age;
   
};
