/***********************************************************************
 * Header File:
 *    SIMULATOR
 * Author:
 *    Savannah Harvey and McKay Larman
 * Summary:
 *    Do all the stuff
 ************************************************************************/

#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "SpaceObject.h"
#include "sputnik.h"
#include "planet.h"
#include "star.h"

#pragma once

/*************************************************************************
 * Simulator
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
   Simulator(Position ptUpperRight) : ptUpperRight(ptUpperRight)
   {
      // Create 50 new stars with random positions
      for (int i = 0; i < 50; i++)
      {
         ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
         ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

         Star newStar;
         newStar.reset(ptStar);
         starVect.push_back(newStar);
      }
   }

   void draw()
   {
      Position pt;
      ogstream gout(pt);

      // draw the stars
      for (int i = 0; i < 50; i++)
         starVect[i].draw(gout);

      // draw the earth
      Position earthPos(0.0, 0.0);
      rotationSpeed += -0.004; // arbitrary for now...
      gout.drawEarth(earthPos, rotationSpeed);
   }

   void run()
   {
      draw();
   }

   Position ptUpperRight;

   double rotationSpeed;

   Position ptStar;
   unsigned char phaseStar;
   vector<Star> starVect;
};