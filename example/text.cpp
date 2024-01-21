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

/* Update a text every 1second */

#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7735
#include <Arduino.h>
#include "GFXForms.hpp"
#include "Text.hpp"

#define TFT_CS 10
#define TFT_DC 4
#define TFT_SCLK 13
#define TFT_MOSI 11
#define TFT_RST 5

Adafruit_ST7789 *display;
GFXForms *screen;
Text *main_text;

void setup() {
  Serial.begin(115200);
  display = new Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
  screen = new GFXForms(240, 320, display);
  screen->set_rotation(1);
  screen->set_background_color(ST77XX_BLACK);
  main_text = new Text(screen, ST77XX_WHITE, "0", 2, false, 20, 20);    // Display a text of size 2 at X = 20 and Y = 20
}

void loop() {
  main_text->set_text(String(millis()));
  delay(1000);
}