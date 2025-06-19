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

class spaceObject
{
public:
   friend TestSpaceObject;
   
   // constructors
   spaceObject() { pos = Position(); radius = 0; isDead = false; age = 0; }
   
   // getters
   Position getPosition() { return pos; }
   double getRadius()     { return radius; }
   int getAge() { return age; }
   bool getStatus() { return isDead; }
   
   // setters
//   void move(double time, Acceleration gravity) {}
   void colided() { isDead = true; }
   
protected:
   Position pos;
   double radius;
   bool isDead;
   int age;
   
};
