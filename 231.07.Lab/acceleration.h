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
#include <cassert>

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

protected:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration

public:
   // constructors
   Acceleration() : ddx(0.0), ddy(0.0) {}
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {}
   Acceleration(const Acceleration& rhs) : ddx(rhs.ddx), ddy(rhs.ddy) {}


   // getters
   virtual double getDDX()   const { return ddx; }
   virtual double getDDY()   const { return ddy; }

   // setters                        
   virtual void setDDX(double ddx) { this->ddx = ddx; }
   virtual void setDDY(double ddy) { this->ddy = ddy; }
   virtual void set(const Angle& a, double magnitude);
   virtual void addDDX(double ddx) { setDDX(getDDX() + ddx); }
   virtual void addDDY(double ddy) { setDDY(getDDY() + ddy); }
   virtual void add(const Acceleration& rhs);
};


/*********************************************
 * Acceleration Dummy
 * Let's do nothing!
 *********************************************/
class AccelerationDummy : public Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestPlanet;
   friend TestSpaceObject;

public:
   // constructors
   AccelerationDummy() : Acceleration() {}
   AccelerationDummy(double ddx, double ddy)  : Acceleration() {}
   AccelerationDummy(const Acceleration& rhs) : Acceleration() {}

   // getters
   virtual double getDDX()   const { assert(false); return ddx; }
   virtual double getDDY()   const { assert(false); return ddy; }

   // setters
   virtual void setDDX(double ddx)                    { assert(false); }
   virtual void setDDY(double ddy)                    { assert(false); }
   virtual void set(const Angle& a, double magnitude) { assert(false); }
   virtual void addDDX(double ddx)                    { assert(false); }
   virtual void addDDY(double ddy)                    { assert(false); }
   virtual void add(const Acceleration& rhs)          { assert(false); }
};



/*********************************************
 * Geo Up
 * A stub of acceleration that always returns (0, 0.169298992),
 * the gravity number when you are at (0, -42164000.0) in Geosynchronous orbit
 *********************************************/
class GeoUp : public AccelerationDummy
{
public:
   GeoUp() : AccelerationDummy() {}
   
   virtual double getDDX() const { return 0; }
   virtual double getDDY() const { return 0.169298992; }
};

/*********************************************
 * RetroAngle
 * A stub of acceleration that always returns
 *    (0.1943286025942485, -0.1121956710041835),
 * the gravity number when you are at
 *    (-36515095.13, 21082000.0) in a retrograde orbit.
 *********************************************/
class RetroAngle : public AccelerationDummy
{
public:
   RetroAngle() : AccelerationDummy() {}
   
   virtual double getDDX() const { return  0.1943286025942485; }
   virtual double getDDY() const { return -0.1121956710041835; }
};



/*********************************************
 * RetroAngle
 * A stub of acceleration that always returns
 *    (-0.22566525361795767, -0.22566525361795767),
 * the gravity number when you are at
 *    (25000000.0, 25000000.0) in floating around in space.
 *********************************************/
class NonOrbit : public AccelerationDummy
{
public:
   NonOrbit() : AccelerationDummy() {}
   
   virtual double getDDX() const { return -0.22566525361795767; }
   virtual double getDDY() const { return -0.22566525361795767; }
};
