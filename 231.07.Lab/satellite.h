/***********************************************************************
 * Header File:
 *    Satellite : A space object that orbits larger space objects
 * Author:
 *    McKay Larman
 * Summary:
 *    Here we add the details about orbiting and what heppens when it breaks
 ************************************************************************/

#pragma once

#include "spaceObject.h"

class TestSatellite;
class TestFragment;
class TestSputnik;
class TestDragon;

class Satellite : public SpaceObject
{
public:
   friend TestSatellite;
   friend TestSputnik;
   friend TestFragment;
//   friend TestDragon;
   
   // constructors
   Satellite() : SpaceObject() { isOrbiting = true; }
   Satellite(Position p, Velocity v) : SpaceObject(p, v) { isOrbiting = true; }
   
   // getters
   bool isInOrbit()   const { return isOrbiting; }
   
   // setters
   void leftOrbit()  { isOrbiting = false; }
   
protected:
   bool isOrbiting;
};

/*****************************
* DUMMY SATELLITE
* for fragment unit test
********************************/
class DummySatellite : public Satellite
{
   friend TestFragment;
public:
   DummySatellite() : Satellite() { }
   DummySatellite(Position p, Velocity v) { }
   bool isInOrbit() { assert(false); return false; }
   void leftOrbit() { assert(false); }
};