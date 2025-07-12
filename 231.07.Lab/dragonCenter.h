/***********************************************************************
 * Header File:
 *    Starlink Body : Part of SpaceX Starlink.
 * Author:
 *    McKay Larman and Savannah Harvey
 * Summary:
 *    Here we add the details about orbiting and what happens when it breaks, like sputnik
 ************************************************************************/

#pragma once

#include "satellite.h"

class TestSatellite;

class DragonCenter : public SpaceObject
{
public:
   friend TestSatellite;

   // Constructors
   DragonCenter(const SpaceObject& parent, const Angle& direction) : SpaceObject(parent, direction)
   {
      this->age = 0;
      this->angularMomentum = 0.0;
      this->direction = direction;
      this->isDead = false;
      this->radius = 6;
//      this->fragments = 3;
   }

   // Draw
   void draw(ogstream& gout) override { gout.drawCrewDragonCenter(pos, direction.getRadians()); }
   
   void destroy(vector<SpaceObject*> &newObjects) override
   {
      for (int i = 0; i < 4; i++)
      {
         // create a new object
         Fragment* pF = new Fragment(*this, Angle(random(0.0, 360.0)));
         newObjects.push_back(pF);
      }
   }
};
