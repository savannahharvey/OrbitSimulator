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
#include "starlinkBody.h"
#include "starlinkArray.h"

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
//      this->fragments = 2;
   }
   
   // Draw
   void draw(ogstream& gout) override { gout.drawStarlink(pos, direction.getRadians()); }
   
   // destroy
   void destroy(vector<SpaceObject*> &newObjects) override
   {
      for (int i = 0; i < 2; i++)
      {
         // create a new object
         Fragment* pF = new Fragment(*this, Angle(random(0.0, 360.0)));
         newObjects.push_back(pF);
      }
      newObjects.push_back(new StarlinkBody(*this, Angle(random(0.0, 360.0))));
      newObjects.push_back(new StarlinkArray(*this, Angle(random(0.0, 360.0))));
   }
};
