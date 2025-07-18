/***********************************************************************
 * Header File:
 *    bullet
 * Author:
 *    McKay Larman
 * Summary:
 *    Here we add the details about orbiting and what heppens when it breaks
 ************************************************************************/

#pragma once

#include "SpaceObject.h"

class Bullet : public SpaceObject
{
public:
   Bullet() : SpaceObject() {}
   
   Bullet(const SpaceObject &parent, const Velocity &kick) : SpaceObject(parent, 19.0, kick) { age = 0; }
   
   void draw(ogstream& gout) override { gout.drawProjectile(pos); }
   
   void move(double time, Acceleration& gravity) override;
};
