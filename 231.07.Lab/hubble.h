/***********************************************************************
 * Header File:
 *    Hubble : A telescope from way back in the 90s
 * Author:
 *    McKay Larman and Savannah Harvey
 * Summary:
 *    Here we add the details about orbiting and what happens when it breaks, like sputnik
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "fragment.h"
#include "hubbleTelescope.h"
#include "hubbleComputer.h"
#include "hubbleLeft.h"
#include "hubbleRight.h"

class TestSatellite;
class TestHubble;

class Hubble : public Satellite
{
public:
   friend TestSatellite;
   friend TestHubble;

   // Constructors
   Hubble() : Satellite()
   {
      this->pos.setMeters(0.0, -42164000.0);
      this->vel.setDX(3100.0);
      this->vel.setDY(0.0);
      this->angularMomentum = 0.00;
      this->radius = 10;
      this->parts = 4;
      this->fragments = 2;
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
      newObjects.push_back(new HubbleTelescope(*this, Angle(random(0.0, 360.0))));
      newObjects.push_back(new HubbleComputer(*this, Angle(random(0.0, 360.0))));
      newObjects.push_back(new HubbleLeft(*this, Angle(random(0.0, 360.0))));
      newObjects.push_back(new HubbleRight(*this, Angle(random(0.0, 360.0))));
   }

   // Draw
   void draw(ogstream& gout) override { gout.drawHubble(pos, direction.getRadians()); }
};
