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
class TestSputnik;
class TestDragon;

class Satellite : public SpaceObject
{
public:
   friend TestSatellite;
   friend TestSputnik;
//   friend TestDragon;
   
   // constructors
   Satellite() : SpaceObject() { isOrbiting = true; parts = 0; fragments = 0; }
   Satellite(Position p, Velocity v) : SpaceObject(p, v) { isOrbiting = true; parts = 0; fragments = 0; }
   
   // getters
   bool isInOrbit()   const { return isOrbiting; }
   int getParts()     const { return parts; }
   int getFragments() const { return fragments; }
   
   // setters
   void leftOrbit()  { isOrbiting = false; }
   
protected:
   bool isOrbiting;
   int parts;
   int fragments;
};
