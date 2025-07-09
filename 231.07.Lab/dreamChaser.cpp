/***********************************************************************
 * Source File:
 *    DreamChaser.h
 * Author:
 *    McKay Larman
 * Summary:
 *    Where we handle the details for move and input.
 ************************************************************************/

#include "dreamChaser.h"


/**********************************************************
 * DREAM CHASER : INPUT
 * Takes input from the user and applies it to the dream chaser.
 * allowing us to steer, thrust, and shoot.
 *********************************************************/
void DreamChaser::input(const Interface & ui, vector<SpaceObject*> &spaceObjects)
{
   // Thrust
   if (ui.isDown())
      isThrusting = true;
   else  // make sure to turn the thruster off.
      isThrusting = false;
   
   // steering
   if (ui.isLeft())
      direction.add(-0.1);
   if (ui.isRight())
      direction.add( 0.1);
   
   // shoot
   if (ui.isSpace())
   {
      
   }
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
   
   // do the move
   SpaceObject::move(time, gravity);
}
