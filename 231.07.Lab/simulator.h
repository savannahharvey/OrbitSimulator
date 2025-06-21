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
      // time
      time = 48.0;
      
      // Sputnik sputnik;
      spaceObjects.push_back(new Sputnik());

      // Create 50 new stars with random positions
      Position ptStar;
      for (int i = 0; i < 300; i++)
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
      ogstream gout(ptUpperRight);

      // draw the stars
      for (int i = 0; i < 300; i++)
         starVect[i].draw(gout);

      // draw the earth
      earth.draw(gout);

      // draw spaceObjects
      for (SpaceObject* object : spaceObjects)
      {
         object->draw(gout);
      }
   }

   void moveObjects()
   {
      for (SpaceObject* object : spaceObjects)
      {
         Acceleration gravity;
         gravity = earth.calcGravity(object->getPosition());

         object->move(time, gravity);
      }
   }

   void run()
   {
      draw();

      moveObjects();
   }

   Position ptUpperRight;

   double time;

   vector<SpaceObject*> spaceObjects;

   // earth
   double rotationSpeed;
   Planet earth;

   // stars
   vector<Star> starVect;
};
