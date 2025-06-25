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

   // Draw
   void draw(ogstream& gout) override { gout.drawHubble(pos, direction.getRadians()); }
};
