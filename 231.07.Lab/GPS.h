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
#include "fragment.h"
#include "gpsRight.h"
#include "gpsLeft.h"
#include "gpsCenter.h"

class TestSatellite;
class TestGPS;

class GPS : public Satellite
{
public:
   friend TestSatellite;
   friend TestGPS;

   // Constructors
   GPS() : Satellite()
   {
      this->pos.setMeters(0.0, 0.0);
      this->vel.setDX(0.0);
      this->vel.setDY(0.0);
      this->angularMomentum = -0.0065;
      this->direction.setRadians(0.0);
      this->radius = 12;
   }
   // Non-default Constructor
   GPS(double x, double y, double dx, double dy, double rad) : Satellite()
   {
      this->pos.setMeters(x, y);
      this->vel.setDX(dx);
      this->vel.setDY(dy);
		this->angularMomentum = -0.0065;
      this->direction.setRadians(rad);
      this->radius = 12;
   }
   
   // destroy
   void destroy(vector<SpaceObject*> &newObjects) override
   {
      // fragments
      newObjects.push_back(new Fragment(*this, Angle(0.0)));
      newObjects.push_back(new Fragment(*this, Angle(144.0)));
      // parts
      newObjects.push_back(new GPSRight(*this, Angle(72.0)));
      newObjects.push_back(new GPSLeft(*this, Angle(216.0)));
      newObjects.push_back(new GPSCenter(*this, Angle(360.0)));
   }

   // Draw
   void draw(ogstream& gout) override { gout.drawGPS(pos, direction.getRadians()); }
};
