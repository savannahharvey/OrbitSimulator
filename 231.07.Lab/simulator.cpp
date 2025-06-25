/***********************************************************************
 * Source File:
 *    Simulator
 * Author:
 *    McKay Larman and Savannah Harvey
 * Summary:
 *    ...
 ************************************************************************/

#include "simulator.h"

/**********************************
* SIMULATOR : CONSTRUCTOR
**********************************/
Simulator::Simulator(Position ptUpperRight) : ptUpperRight(ptUpperRight)
{
   // time
   time = 48.0;
   
   spaceObjects.push_back(new DreamChaser());

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

/**********************************
* SIMULATOR : DRAW
**********************************/
void Simulator::draw()
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

/**********************************
* SIMULATOR : MOVE OBJECTS
**********************************/
void Simulator::moveObjects(const Interface & ui)
{
   if (spaceObjects.size() > 0)
   {
      // dream chaser should be first in the list.
      spaceObjects[0]->input(ui, spaceObjects);
      for (SpaceObject* object : spaceObjects)
      {
         Acceleration gravity;
         gravity = earth.calcGravity(object->getPosition());

         object->move(time, gravity);
      }
   }
   
   earth.spin();
}

/**********************************
* SIMULATOR : RUN
**********************************/
void Simulator::run(const Interface & ui)
{
   draw();

   moveObjects(ui);
}
