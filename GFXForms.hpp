/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw or https://capibarazero.github.io/).
 * Copyright (c) 2024 Andrea Canale.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7735

#ifndef GFXFORMS_H
#define GFXFORMS_H

class GFXForms {
  private:
   Adafruit_ST7789 *tft;
   uint16_t background_color = ST77XX_BLACK;
  public:
   GFXForms(int width, int height, Adafruit_ST7789 *display);
   ~GFXForms();
   void set_background_color(uint16_t color) { 
      background_color = color;
      tft->fillScreen(color); 
   }
   void testfillrects(uint16_t color1, uint16_t color2) {
      tft->drawRoundRect(50, tft->height() - 100 - 50, 50, 50, 8, color2);
   }
   void set_rotation(int rotation) { tft->setRotation(rotation); }
   void reset() { tft->fillScreen(background_color); }
   void reset(uint16_t color) { tft->fillScreen(color); }
   friend class Text;
   friend class Rect;
   friend class Grid;
   friend class Bitmap;
};

#endif