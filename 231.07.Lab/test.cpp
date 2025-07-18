/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testSpaceObject.h"
#include "testPlanet.h"
#include "testDreamChaser.h"
#include "testSatellite.h"
#include "testSputnik.h"
#include "testDragon.h"
#include "testStarlink.h"
#include "testHubble.h"
#include "testGPS.h"
#include "testFragment.h"
#include "testSimulator.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   TestPosition().run();
   TestVelocity().run();
   TestSpaceObject().run();
   TestPlanet().run();
   TestDreamChaser().run();
   TestSatellite().run();
   TestSputnik().run();
   TestDragon().run();
   TestStarlink().run();
   TestHubble().run();
   TestGPS().run();
   TestFragment().run();
   TestSimulator().run();
}
