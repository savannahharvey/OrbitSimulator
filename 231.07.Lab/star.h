/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich and SH and ML
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR

 /*****************************************************
  * STAR
  * A star that twinkles
  *****************************************************/
class Star
{
private:
   Position pos;
   unsigned char phaseStar;

public:
   void reset(const Position& ptStar) {
      pos.getPixelsX();
      pos.setPixelsX(ptStar.getPixelsX());
      pos.setPixelsY(ptStar.getPixelsY());
      phaseStar = random(0, 255);
   }

   void draw(ogstream& gout) { gout.drawStar(pos, phaseStar++); }

};