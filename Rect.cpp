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

#include "Rect.hpp"

Rect::Rect(GFXForms *_framework) {
  framework = _framework;
}

Rect::Rect(GFXForms *_framework, int _width, int _heigth, int _x, int _y, int _radius, uint16_t _color) {
  framework = _framework;
  width = _width;
  heigth = _heigth;
  x = _x;
  y = _y;
  radius = _radius;
  color = _color;
}

Rect::~Rect() {}

void Rect::set_pos(int _x, int _y) {
  x = _x;
  y = _y;
}
void Rect::set_dimension(int _width, int _heigth) {
  width = _width;
  heigth = _heigth;
}
void Rect::set_radius(int _radius) {
  radius = _radius;
}

void Rect::set_color(uint16_t _color) {
  color = _color;
}

void Rect::display() {
  if (radius != 0)
    framework->tft->drawRoundRect(x, y, width, heigth, radius, color);
  else
    framework->tft->drawRect(x, y, width, heigth, color);
  
  displayed = true;
}

void Rect::set_selected(bool _selected) {
  selected = _selected;
  set_color(ST77XX_BLUE);
  display();
}