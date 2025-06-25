/***********************************************************************
 * Source File:
 *    DreamChaser.h
 * Author:
 *    McKay Larman
 * Summary:
 *    Where we handle the details for move and input.
 ************************************************************************/

#include "dreamChaser.h"

void DreamChaser::input(const Interface & ui, vector<SpaceObject*> &spaceObjects)
{
   if (ui.isDown())
   {
      isThrusting = true;
   }
   else
      isThrusting = false;
   
   if (ui.isLeft())
      direction.add(-0.1);
   if (ui.isRight())
      direction.add( 0.1);
   
}


/**********************************************************
 * DREAM CHASER : MOVE
 * Moves the dream chaser, takes into account if we are thrusting or not.
 *********************************************************/
void DreamChaser::move(double time, Acceleration & gravity)
{
   // Do the trust.
   if (isThrusting)
   {
      Acceleration thrust;
      thrust.set(direction, 2.0);
      
      gravity.add(thrust);
   }
   
   // Update Position.
   double posX = pos.getMetersX() + (vel.getDX() * time) + (0.5 * gravity.getDDX() * (time * time));
   double posY = pos.getMetersY() + (vel.getDY() * time) + (0.5 * gravity.getDDY() * (time * time));
   pos.setMeters(posX, posY);
   // update velocity
   vel.add(gravity, time);

   this->addAge();
   this->spin();
}
