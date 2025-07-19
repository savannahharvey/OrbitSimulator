/***********************************************************************
 * Header File:
 *    SIMULATOR
 * Author:
 *    Savannah Harvey and McKay Larman
 * Summary:
 *    Do all the stuff
 ************************************************************************/

#include <vector>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "spaceObject.h"
#include "dreamChaser.h"
#include "sputnik.h"
#include "dragon.h"
#include "starlink.h"
#include "hubble.h"
#include "GPS.h"
#include "planet.h"
#include "bullet.h"
#include "star.h"

#pragma once

class TestSimulator;

/*************************************************************************
 * Simulator
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
	friend TestSimulator;
public:
   Simulator(Position ptUpperRight);
   ~Simulator();
   
   void draw();
   void moveObjects(const Interface & ui);
	void detectCollision();
	bool checkCollision(SpaceObject* &sO1, SpaceObject* &sO2);
   void run(const Interface & ui);
  
   double time;

private:
   Position ptUpperRight;

   vector<SpaceObject*> spaceObjects;

   // earth
   Planet* pEarth = new Planet();

   // stars
   vector<Star> starVect;
};
