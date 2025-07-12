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
      //this->fragments = 2;
   }

   // destroy
   void destroy(vector<SpaceObject*>& newObjects) override
   {    
      // fragments
      newObjects.push_back(new Fragment(*this, Angle(60.0)));
      newObjects.push_back(new Fragment(*this, Angle(240.0)));
      // parts
      newObjects.push_back(new HubbleTelescope(*this, Angle(0.0)));
      newObjects.push_back(new HubbleComputer(*this, Angle(120.0)));
      newObjects.push_back(new HubbleLeft(*this, Angle(180.0)));
      newObjects.push_back(new HubbleRight(*this, Angle(300.0)));
   }

   // Draw
   void draw(ogstream& gout) override { gout.drawHubble(pos, direction.getRadians()); }
};
