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

   Bullet(const SpaceObject& parent, double offset, const Velocity& kick) : SpaceObject(parent, offset, kick) {}

   void draw(ogstream& gout) override { gout.drawProjectile(pos); }


};