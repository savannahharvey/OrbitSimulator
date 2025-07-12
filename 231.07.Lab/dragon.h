/***********************************************************************
 * Header File:
 *    Crew Dragon
 * Author:
 *    McKay Larman
 * Summary:
 *    Here we add the details about orbiting and what heppens when it breaks
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "dragonLeft.h"
#include "dragonCenter.h"
#include "dragonRight.h"

class TestDragon;

class Dragon : public Satellite
{
public:
   friend TestDragon;
   
   // Constructors
   Dragon() : Satellite()
   {
      this->pos.setMeters(0.0, 8000000.0);
      this->vel.setDX(-7900.0);
      this->vel.setDY(0.0);
      this->angularMomentum = 0.02;
      this->radius = 7;
//      this->fragments = 2;
   }
   
   // Draw
   void draw(ogstream& gout) override { gout.drawCrewDragon(pos, direction.getRadians()); }
   
   // destroy
   void destroy(vector<SpaceObject*> &newObjects) override
   {
      for (int i = 0; i < 2; i++)
      {
         // create a new object
         Fragment* pF = new Fragment(*this, Angle(random(0.0, 360.0)));
         newObjects.push_back(pF);
      }
      newObjects.push_back(new DragonLeft(*this, Angle(random(0.0, 360.0))));
      newObjects.push_back(new DragonCenter(*this, Angle(random(0.0, 360.0))));
      newObjects.push_back(new DragonRight(*this, Angle(random(0.0, 360.0))));
   }
};
