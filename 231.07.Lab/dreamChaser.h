/***********************************************************************
 * Header File:
 *    DreamChaser : The user controlled shapce ship
 * Author:
 *    McKay Larman
 * Summary:
 *    The main difference is that we can control it.
 ************************************************************************/

#pragma once

#include <vector>
#include "spaceObject.h"
#include "bullet.h"

class TestDreamChaser;

class DreamChaser : public SpaceObject
{
public:
   friend TestDreamChaser;
   
   // constructor
   DreamChaser() : SpaceObject(Position(-57600000.0, 57600000.0), Velocity(0.0, -2000.0)), isThrusting(false) { radius = 10; }
   
   // Draw
   void draw(ogstream& gout) override { gout.drawShip(pos, direction.getRadians(), isThrusting); }
   
   // Move stuff
   void input(const Interface & ui, vector<SpaceObject*> &spaceObjects) override;
   void move(double time, Acceleration &gravity) override;
   void shoot(vector<SpaceObject*> &spaceObject);
   
private:
   bool isThrusting;
};
