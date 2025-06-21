/*************************************************************
 * Main
 * Authors: Savanah Harvey & McKay Larman
 *****************************************************************/

#include <cassert>      // for ASSERT
#include <vector>       // for starVect
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "SpaceObject.h"
#include "planet.h"
#include "star.h"
#include "test.h"
using namespace std;


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
      //
      // draw everything
      //

      Position pt;
      ogstream gout(pt);

      // draw the stars
      for (int i = 0; i < 50; i++)
         starVect[i].draw(gout);

      // draw the earth
      Position earthPos(0.0, 0.0);
      rotationSpeed+= -0.004; // arbitrary for now...
      gout.drawEarth(earthPos, rotationSpeed);
   }

   Position ptUpperRight;

   double rotationSpeed;

   Position ptStar;
   unsigned char phaseStar;
   vector<Star> starVect;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator* pSim = (Simulator*)p;

   pSim->draw();
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulator sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim);

   return 0;
}
