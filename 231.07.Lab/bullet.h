/***********************************************************************
 * Header File:
 *    bullet
 * Author:
 *    McKay Larman
 * Summary:
 *    Here we add the details about orbiting and what heppens when it breaks
 ************************************************************************/

# pragma once

#include "spaceObject.h"

class Bullet : public SpaceObject
{
public:
   Bullet() : SpaceObject() {}
   
   Bullet(const SpaceObject &parent, const Velocity &kick) : SpaceObject(parent, 30.0, kick) { age = 0; }
   
   void draw(ogstream& gout) override { gout.drawProjectile(pos); }
   
   void destroy(vector<SpaceObject*> &newObjects) override
   {
      if (age > 90)
         isDead = true;
   }
};
