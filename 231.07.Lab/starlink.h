/***********************************************************************
 * Header File:
 *    Starlink
 * Author:
 *    McKay Larman
 * Summary:
 *    give it an inital starting position and make it draw itself.
 ************************************************************************/

#pragma once

#include "satellite.h"

class TestStarlink;

class Starlink : public Satellite
{
public:
   friend TestStarlink;
   
   // Constructors
   Starlink() : Satellite()
   {
      this->pos.setMeters(0.0, -13020000.0);
      this->vel.setDX(5800.0);
      this->vel.setDY(0.0);
      this->angularMomentum = 0.02;
      this->radius = 6;
   }
   
   // Draw
   void draw(ogstream& gout) override { gout.drawStarlink(pos, direction.getRadians()); }
};
