/***********************************************************************
 * Header File:
 *    GPS : A Global Positioning System satellite from way back in the 70s
 * Author:
 *    McKay Larman and Savannah Harvey
 * Summary:
 *    Here we add the details about orbiting and what happens when it breaks, like sputnik
 ************************************************************************/

#pragma once

#include "satellite.h"

class TestSatellite;
class TestGPS;

class GPS : public Satellite
{
public:
   friend TestSatellite;
   friend TestGPS;

   // Constructors
   GPS() : Satellite() {}
   // Non-default Constructor
   GPS(double x, double y, double dx, double dy, double rad) : Satellite()
   {
      this->pos.setMeters(x, y);
      this->vel.setDX(dx);
      this->vel.setDY(dy);
      this->angularMomentum = -0.0065;
      this->direction.setRadians(rad);
      this->radius = 12;
      this->parts = 3;
      this->fragments = 2;
   }

   // Draw
   void draw(ogstream& gout) override { gout.drawGPS(pos, direction.getRadians()); }
};
