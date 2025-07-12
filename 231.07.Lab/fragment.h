/***********************************************************************
 * Header File:
 *    Fragment : A Global Positioning System satellite from way back in the 70s
 * Author:
 *    McKay Larman and Savannah Harvey
 * Summary:
 *    Here we add the details about orbiting and what happens when it breaks, like sputnik
 ************************************************************************/

#pragma once

#include "satellite.h"

class TestSatellite;
class TestFragment;

class Fragment : public SpaceObject
{
public:
   friend TestSatellite;
   friend TestFragment;

   // Constructors
   Fragment(const SpaceObject& parent, const Angle& direction) : SpaceObject(parent, direction)
   {
      this->age = 0;
      this->angularMomentum = 0.0;
		this->direction = direction;
		this->isDead = false;
      this->radius = 2;
   }

   /**********************************
    * SPACE OBJECT : MOVE
    * Move an object in space given an amount of time
    * and a force of gravity (but override it)
    **********************************/
   void move(double time, Acceleration& gravity)
   {
      double posX = pos.getMetersX() + (vel.getDX() * time) + (0.5 * gravity.getDDX() * (time * time));
      double posY = pos.getMetersY() + (vel.getDY() * time) + (0.5 * gravity.getDDY() * (time * time));
      pos.setMeters(posX, posY);

      vel.add(gravity, time);

      this->addAge();
      if (age > 50)
         isDead = true;
      this->spin();
   }

   // Draw
   void draw(ogstream& gout) override { gout.drawFragment(pos, direction.getRadians()); }
};
