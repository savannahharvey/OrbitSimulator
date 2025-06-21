/***********************************************************************
 * Source File:
 *    SpaceObject : Anything that is in space and could move
 * Author:
 *    McKay Larman
 * Summary:
 *    Everything that we need to make objects move in space
 ************************************************************************/

#include "SpaceObject.h"

/**********************************
 * SPACE OBJECT : MOVE
 * Move an object in space given an amount of time
 * and a force of gravity
 **********************************/
void SpaceObject::move(double time, const Acceleration &gravity)
{
   double posX = pos.getMetersX() + (vel.getDX() * time) + (0.5 * gravity.getDDX() * (time * time));
   double posY = pos.getMetersY() + (vel.getDY() * time) + (0.5 * gravity.getDDY() * (time * time));
   pos.setMeters(posX, posY);
   
   vel.add(gravity, time);
}
