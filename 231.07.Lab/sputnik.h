/***********************************************************************
 * Header File:
 *    Satellite : A space object that orbits larger space objects
 * Author:
 *    McKay Larman
 * Summary:
 *    Here we add the details about orbiting and what heppens when it breaks
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "fragment.h"

class TestSatellite;

class Sputnik : public Satellite
{
public:
   friend TestSatellite;
   
   // Constructors
   Sputnik() : Satellite()
   {
      this->pos.setMeters(-36515095.13, 21082000.0);
      this->vel.setDX(2050.0);
      this->vel.setDY(2684.68);
      this->angularMomentum = 0.02;
      this->radius = 4;
      this->fragments = 4;
   }

   // destroy
   void destroy(vector<SpaceObject*>& newObjects) override
   {
      for (int i = 0; i < fragments; i++)
      {
         // create a new object
         Fragment* pF = new Fragment(*this, Angle(random(0.0, 360.0)));
         newObjects.push_back(pF);
      }
   }
   
   // Draw
   void draw(ogstream& gout) override { gout.drawSputnik(pos, direction.getRadians()); }
};
