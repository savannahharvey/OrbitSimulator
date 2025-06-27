/*********************************************
 * Header file:
 *    UI INTERFACE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This module will create an OpenGL window,
 *    enter the OpenGL main loop, and accept events.
 *    The main methods are:
 *    1. Constructors - Create the window
 *    2. run()        - Run the main loop
 *    3. callback     - Specified in Run, this user-provided
 *                      function will get called with every frame
 *    4. isDown()     - Is a given key pressed on this loop?
 **********************************************/

#pragma once

#include "position.h"
#include <algorithm> // used for min() and max() (specifically required by Visual Studio)
#include <cassert>
using std::min;
using std::max;

#define GL_SILENCE_DEPRECATION

/********************************************
 * INTERFACE
 * All the data necessary to keep our graphics
 * state in memory
 ********************************************/
class Interface
{
public:
   Interface() {}

   // Constructor if you want to set up the window with anything but
   // the default parameters
   Interface(int argc, char ** argv, const char * title, const Position & ptUpperRight)
   {
      initialize(argc, argv, title, ptUpperRight);
   }
   
   // Destructor, in case any housecleaning needs to occur
   ~Interface();

   // This will set the game in motion
   virtual void run(void (*callBack)(const Interface *, void *), void *p);

   // Is it time to redraw the screen
   virtual bool isTimeToDraw();

   // Set the next draw time based on current time and time period
   virtual void setNextDrawTime();

   // Retrieve the next tick time... the time of the next draw.
   virtual unsigned long getNextTick() { return nextTick; }

   // How many frames per second are we configured for?
   virtual void setFramesPerSecond(double value);
   
   // Key event indicating a key has been pressed or not.  The callbacks
   // should be the only onces to call this
   virtual void keyEvent(int key, bool fDown);
   virtual void keyEvent();

   // Current frame rate
   virtual double frameRate() const { return timePeriod;   }
   
   // Get various key events
   virtual int  isDown()      const { return isDownPress;  }
   virtual int  isUp()        const { return isUpPress;    }
   virtual int  isLeft()      const { return isLeftPress;  }
   virtual int  isRight()     const { return isRightPress; }
   virtual bool isSpace()     const { return isSpacePress; }
   
   static void *p;                   // for client
   static void (*callBack)(const Interface *, void *);

private:
   virtual void initialize(int argc, char ** argv, const char * title, const Position & ptUpperRight);

   static bool         initialized;  // only run the constructor once!
   static double       timePeriod;   // interval between frame draws
   static unsigned long nextTick;     // time (from clock()) of our next draw

   static int  isDownPress;          // is the down arrow currently pressed?
   static int  isUpPress;            //    "   up         "
   static int  isLeftPress;          //    "   left       "
   static int  isRightPress;         //    "   right      "
   static bool isSpacePress;         //    "   space      "
};


/********************************************
 * INTERFACE DUMMY
 * Just Assert false
 ********************************************/
class InterfaceDummy : public Interface
{
public:
   InterfaceDummy() {}

   // This will set the game in motion
   virtual void run(void (*callBack)(const Interface *, void *), void *p) { assert(false); }

   // Is it time to redraw the screen
   virtual bool isTimeToDraw() { assert(false); }

   // Set the next draw time based on current time and time period
   virtual void setNextDrawTime() { assert(false); }

   // Retrieve the next tick time... the time of the next draw.
   virtual unsigned long getNextTick() { assert(false); return 0; }

   // How many frames per second are we configured for?
   virtual void setFramesPerSecond(double value) { assert(false); }
   
   // Key event indicating a key has been pressed or not.  The callbacks
   // should be the only onces to call this
   virtual void keyEvent(int key, bool fDown) { assert(false); }
   virtual void keyEvent() { assert(false); }

   // Current frame rate
   virtual double frameRate() const { assert(false); return 0;   }
   
   // Get various key events
   virtual int  isDown()      const { assert(false); }
   virtual int  isUp()        const { assert(false); }
   virtual int  isLeft()      const { assert(false); }
   virtual int  isRight()     const { assert(false); }
   virtual bool isSpace()     const { assert(false); }

private:
   virtual void initialize(int argc, char ** argv, const char * title, const Position & ptUpperRight) { assert(false); }
   
};


/********************************************
 * THRUST
 * Asserts false unless you want thrusting.
 ********************************************/
class Thrust : public InterfaceDummy
{
public:
   Thrust() {}
   virtual int  isDown()      const { return 1; }
   virtual int  isUp()        const { return 0; }
   virtual int  isLeft()      const { return 0; }
   virtual int  isRight()     const { return 0; }
   virtual bool isSpace()     const { return 0; }
};


/********************************************
 * LEFT
 * Asserts false unless you want left.
 ********************************************/
class Left : public InterfaceDummy
{
public:
   Left() {}
   virtual int  isDown()      const { return 0; }
   virtual int  isUp()        const { return 0; }
   virtual int  isLeft()      const { return 1; }
   virtual int  isRight()     const { return 0; }
   virtual bool isSpace()     const { return 0; }
};


/********************************************
 * Right
 * Asserts false unless you want right.
 ********************************************/
class Right : public InterfaceDummy
{
public:
   Right() {}
   virtual int  isDown()      const { return 0; }
   virtual int  isUp()        const { return 0; }
   virtual int  isLeft()      const { return 0; }
   virtual int  isRight()     const { return 1; }
   virtual bool isSpace()     const { return 0; }
};


/********************************************
 * Thrusting Right
 * Asserts false unless you want right and thrust
 ********************************************/
class RightThrust : public InterfaceDummy
{
public:
   RightThrust() {}
   virtual int  isDown()      const { return 1; }
   virtual int  isUp()        const { return 0; }
   virtual int  isLeft()      const { return 0; }
   virtual int  isRight()     const { return 1; }
   virtual bool isSpace()     const { return 0; }
};

/************************************************************************
 * DRAW CALLBACK
 * This is the main callback from OpenGL. It gets called constantly by
 * the graphics engine to refresh and draw the window.  Here we will
 * clear the background buffer, draw on it, and send it to the forefront
 * when the appropriate time period has passed.
 *
 * Note: This and all other callbacks can't be member functions, they must
 * have global scope for OpenGL to see them.
 *************************************************************************/
void drawCallback();

/************************************************************************
 * KEY DOWN CALLBACK
 * When a key on the keyboard has been pressed, we need to pass that
 * on to the client.  Currently, we are only registering the arrow keys
 *************************************************************************/
void keyDownCallback(int key, int x, int y);

/************************************************************************
 * KEY UP CALLBACK
 * When the user has released the key, we need to reset the pressed flag
 *************************************************************************/
void keyUpCallback(int key, int x, int y);

/***************************************************************
 * KEYBOARD CALLBACK
 * Generic callback to a regular ascii keyboard event, such as
 * the space bar or the letter 'q'
 ***************************************************************/
void keyboardCallback(unsigned char key, int x, int y);

/************************************************************************
 * RUN
 * Set the game in action.  We will get control back in our drawCallback
 *************************************************************************/
void run();
