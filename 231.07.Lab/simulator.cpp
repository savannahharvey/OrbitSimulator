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
   
   // Dream Chaser
   spaceObjects.push_back(new DreamChaser());

   // Hubble
   spaceObjects.push_back(new Hubble());

   // Sputnik
   spaceObjects.push_back(new Sputnik());
   
   // Crew Dragon
   spaceObjects.push_back(new Dragon());
   
   // Starlink
   spaceObjects.push_back(new Starlink());

   // GPSes
	spaceObjects.push_back(new GPS(         0.0,  26560000.0, -3880.0,      0.0, M_PI * ( 1.0/2.0) ));
   spaceObjects.push_back(new GPS( 23001634.72,  13280000.0, -1940.0,  3360.18, M_PI * ( 5.0/6.0) ));
   spaceObjects.push_back(new GPS( 23001634.72, -13280000.0,  1940.0,  3360.18, M_PI * ( 7.0/6.0) ));
   spaceObjects.push_back(new GPS(         0.0, -26560000.0,  3880.0,      0.0, M_PI * ( 3.0/2.0) ));
   spaceObjects.push_back(new GPS(-23001634.72, -13280000.0,  1940.0, -3360.18, M_PI * (11.0/6.0) ));
   spaceObjects.push_back(new GPS(-23001634.72,  13280000.0, -1940.0, -3360.18, M_PI * ( 1.0/6.0) ));

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
* SIMULATOR : DESTRUCTOR
******************************/
Simulator::~Simulator()
{
   delete pEarth;
   pEarth = nullptr;

	// delete all space objects just in case
   for (SpaceObject* object : spaceObjects)
   {
      delete object;
   }
   spaceObjects.clear();
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
	pEarth->draw(gout);

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
   vector<SpaceObject*> kill;

   if (spaceObjects.size() > 0)
   {
      // dream chaser should be first in the list.
      spaceObjects[0]->input(ui, spaceObjects);
      for (SpaceObject* object : spaceObjects)
      {
         Acceleration gravity;
         gravity = pEarth->calcGravity(object->getPosition());

         object->move(time, gravity);

         if (object->getStatus())
         {
            kill.push_back(object);
         }
      }
   }

   for (SpaceObject* object : kill)
   {
      spaceObjects.erase(remove(spaceObjects.begin(), spaceObjects.end(), object), spaceObjects.end());
      delete object;
	}
   
   pEarth->spin();
}

/**********************************
* SIMULATOR : DETECT COLLISION
**********************************/
void Simulator::detectCollision()
{
   std::vector<SpaceObject*> deadedObjects;

   for (int i = 0; i < spaceObjects.size(); i++)
   {
		// Check if the Earth is colliding with any other space object
      if (checkCollision(reinterpret_cast<SpaceObject*&>(pEarth), spaceObjects[i]))
      {
			// only add the object to the deadedObjects
			deadedObjects.push_back(spaceObjects[i]);
      }

		// Check for collisions between other space objects
      for (int j = i + 1; j < spaceObjects.size() - 1; j++)
      {
         if (checkCollision(spaceObjects[i], spaceObjects[j]))
         {
				// add both objects to the deadedObjects list
            deadedObjects.push_back(spaceObjects[i]);
            deadedObjects.push_back(spaceObjects[j]);
         }
      }
   }

   vector<SpaceObject*> newObjects;
	// for every object in deaded list, destroy it and remove it from the spaceObjects vector
   for (SpaceObject* deaded : deadedObjects)
   {
		// find the deaded object in the spaceObjects vector
      auto it = find(spaceObjects.begin(), spaceObjects.end(), deaded);
      if (it != spaceObjects.end())
      {
			deaded->destroy(newObjects); // will add new objects to the newObjects vector
         spaceObjects.erase(it);
         delete deaded;
      }
	}

	// add all new objects to the spaceObjects vector
   for (SpaceObject* newObj : newObjects)
   {
      spaceObjects.push_back(newObj);
   }
}

/**********************************
* SIMULATOR : CHECK COLLISION
**********************************/
bool Simulator::checkCollision(SpaceObject* &sO1, SpaceObject* &sO2)
{
	int x1 = sO1->getPosition().getPixelsX();
	int y1 = sO1->getPosition().getPixelsY();
	int x2 = sO2->getPosition().getPixelsX();
	int y2 = sO2->getPosition().getPixelsY();
	// if hypotenuse is less than the sum of the radii, then they are colliding
	double distanceBetween = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
   if (distanceBetween < (sO1->getRadius() + sO2->getRadius()))
   {
      return true;
	}
   return false;
}

/**********************************
* SIMULATOR : RUN
**********************************/
void Simulator::run(const Interface & ui)
{
   draw();

   moveObjects(ui);

   detectCollision();
}
