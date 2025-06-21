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
      this->radius = 4;
      this->fragments = 4;
   }
   
   // Draw
   void draw() override {}
};
