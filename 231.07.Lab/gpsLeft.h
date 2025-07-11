/***********************************************************************
 * Header File:
 *    GPSLeft : A Global Positioning System satellite from way back in the 70s
 * Author:
 *    McKay Larman and Savannah Harvey
 * Summary:
 *    Here we add the details about orbiting and what happens when it breaks, like sputnik
 ************************************************************************/

#pragma once

#include "satellite.h"

class TestSatellite;
class TestGPS;

class GPSLeft : public SpaceObject
{
public:
   friend TestSatellite;
   friend TestGPS;

   // Constructors
   GPSLeft(const SpaceObject& parent, const Angle& direction) : SpaceObject(parent, direction)
   {
      this->age = 0;
      this->angularMomentum = 0.0;
      this->direction = direction;
      this->isDead = false;
      this->radius = 2;
   }

   // Draw
   void draw(ogstream& gout) override { gout.drawGPSLeft(pos, direction.getRadians()); }
};
