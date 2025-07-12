//
//  bullet.cpp
//  Lab07
//
//  Created by Mckay Larman on 7/12/25.
//

#include "bullet.h"

void Bullet::move(double time, Acceleration& gravity)
{
   double posX = pos.getMetersX() + (vel.getDX() * time) + (0.5 * gravity.getDDX() * (time * time));
   double posY = pos.getMetersY() + (vel.getDY() * time) + (0.5 * gravity.getDDY() * (time * time));
   pos.setMeters(posX, posY);

   vel.add(gravity, time);

   this->addAge();
   if (age > 70)
      isDead = true;
   this->spin();
}
