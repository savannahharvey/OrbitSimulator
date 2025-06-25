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
   }
   
   // Draw
   void draw(ogstream& gout) override { gout.drawCrewDragon(pos, direction.getRadians()); }
};
