/***********************************************************************
 * Source File:
 *    SpaceObject : Anything that is in space and could move
 * Author:
 *    McKay Larman
 * Summary:
 *    Everything that we need to make objects move in space
 ************************************************************************/

#include "spaceObject.h"

SpaceObject::SpaceObject(const SpaceObject &parent, const Angle &direction) :
SpaceObject(parent)
{
   double speed = random(1000.0, 3000.0);
#ifndef NDEBUG
   speed = 3000.0;
#endif
   Velocity kick(speed, direction);
   vel+=kick;
   
   // compute offset.
   Position posKick;
   posKick.setMetersX(radius * sin(direction.getRadians()));
   posKick.setMetersY(radius * cos(direction.getRadians()));
//   posKick.setPixelsX(4.0 * sin(direction.getRadians()));
//   posKick.setMetersY(4.0 * cos(direction.getRadians()));
   pos.addMetersX(posKick.getMetersX());
   pos.addMetersY(posKick.getMetersY());
}

/**********************************
 * SPACE OBJECT : MOVE
 * Move an object in space given an amount of time
 * and a force of gravity
 **********************************/
void SpaceObject::move(double time, Acceleration &gravity)
{
   double posX = pos.getMetersX() + (vel.getDX() * time) + (0.5 * gravity.getDDX() * (time * time));
   double posY = pos.getMetersY() + (vel.getDY() * time) + (0.5 * gravity.getDDY() * (time * time));
   pos.setMeters(posX, posY);
   
   vel.add(gravity, time);
   
   this->addAge();
   this->spin();
}


/**********************************
 * SPACE OBJECT : ADD AGE
 * Add to the age of an object.
 * If we are at 10000 or more we can rest
 **********************************/
void SpaceObject::addAge()
{
   if (this->age < 10000)
      this->age ++;
   else
      this->age = 0;
}
