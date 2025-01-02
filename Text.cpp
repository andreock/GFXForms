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

#include "Text.hpp"

Text::Text(GFXForms *_framework) {
  framework = _framework;
}

Text::~Text() {
}

Text::Text(GFXForms *_framework, uint16_t _color, String _text, uint8_t _size, bool _wrap, int _x, int _y) {
  framework = _framework;
  set_color(_color);
  set_wrap(_wrap);
  set_text(_text);
  set_pos(_x, _y);
  set_size(_size);
}

void Text::set_color(uint16_t _color) {
  color = _color;
  if (displayed) {
    display();
  }
}
void Text::set_wrap(bool wrap) {
  text_wrap = wrap;
}
void Text::set_pos(int _x, int _y) {
  x = _x;
  y = _y;
}
void Text::set_text(String _text) {
  int length = text.length();
  text = _text;
  if (displayed){
    width = (length * size * (size * 6));
    // Font size is actually size*6 and size*8
    framework->tft->fillRect(x, y, (length * size * (size * 6)), size * 8, framework->background_color); // Cleanup old text
    display();  // Display updated text
  }
}
void Text::set_size(uint8_t _size) {
  size = _size;
  heigth = size * 8;
}
void Text::display() {
  framework->tft->setTextColor(color);
  framework->tft->setTextWrap(text_wrap);
  framework->tft->setCursor(x, y);
  framework->tft->setTextSize(size);
  framework->tft->println(text);
  displayed = true;
}
