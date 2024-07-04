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

#include <Arduino.h>

#include "GFXForms.hpp"
#include "Widget.hpp"

#ifndef TEXT_H
#define TEXT_H

class Text : public Widget {
 private:
  String text;
  bool text_wrap;
  int size;

 public:
  /// @brief Create a Text widget
  /// @param _framework GFXForms framework reference
  Text(GFXForms *_framework);
  /// @brief Create a Text widget and describes it
  /// @param _framework GFXForms framework reference
  /// @param _color Text color
  /// @param _text Text string
  /// @param _size Font size in px
  /// @param _wrap Wrap the text
  /// @param _x X position
  /// @param _y Y position
  Text(GFXForms *_framework, uint16_t _color, String _text = "", uint8_t _size = 2, bool _wrap = false, int _x = 0, int _y = 0);
  ~Text();

  /// @brief Set color of margin
  /// @param _color Color of the margin
  void set_color(uint16_t _color);

  /// @brief Set font wrap
  /// @param wrap True or false
  void set_wrap(bool wrap);

  /// @brief Set position of Text
  /// @param _x X position
  /// @param _y Y position
  void set_pos(int _x, int _y);

  /// @brief Set text string
  /// @param _text Text string
  void set_text(String _text);

  /// @brief Set font size
  /// @param _size font size in px
  void set_size(uint8_t _size);

  /// @brief Display the rectangle on the screen
  void display();

  /// @brief Set dimensions of rect
  /// @param _width Width of the rect
  /// @param _heigth Height of the rect
  void set_dimension(int _width, int _heigth) {
    width = _width;
    heigth = _heigth;
  }
  /// @brief Set text selected
  /// @param _selected Selected status
  void set_selected(bool _selected) { selected = _selected; } 
  /// @brief Click the current text and execute a function.
  /// @param callback Function to execute
  void click(void callback()) {
    callback();
  }
  void click() {}
};

#endif