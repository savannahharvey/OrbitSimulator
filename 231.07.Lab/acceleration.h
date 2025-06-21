/***********************************************************************
 * Header File:
 *    ACCELERATION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once
#include "angle.h"

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestPlanet;
class TestSpaceObject;

class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestPlanet;
   friend TestSpaceObject;

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration

public:
   // constructors
   Acceleration() : ddx(0.0), ddy(0.0) {}
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {}
   Acceleration(const Acceleration& rhs) : ddx(rhs.ddx), ddy(rhs.ddy) {}


   // getters
   double getDDX()   const { return ddx; }
   double getDDY()   const { return ddy; }

   // setters                        
   void setDDX(double ddx) { this->ddx = ddx; }
   void setDDY(double ddy) { this->ddy = ddy; }
   void set(const Angle& a, double magnitude);
   void addDDX(double ddx) { setDDX(getDDX() + ddx); }
   void addDDY(double ddy) { setDDY(getDDY() + ddy); }
   void add(const Acceleration& rhs);
};
