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

#include "GFXForms.hpp"
#include "Widget.hpp"

#ifndef RECT_H
#define RECT_H

class Rect : public Widget {
 private:
  int radius = 0;  // Radius of the widget
 public:
  /// @brief Initializes Rect
  /// @param framework GFXForms framework reference
  Rect(GFXForms *_framework);

  /// @brief Initializes Rect and describes it
  /// @param framework GFXForms framework reference
  /// @param _width Width of the Rect
  /// @param _heigth Height of the Rect
  /// @param _x X position of the Rect
  /// @param _y Y position of the Rect
  /// @param _radius Border radius of the Rect
  /// @param _color Margin color of the Rect
  Rect(GFXForms *_framework, int _width, int _heigth, int _x = 0, int _y = 0, int _radius = 0, uint16_t _color = ST77XX_WHITE);

  ~Rect();

  /// @brief Set position of Rect
  /// @param _x X position
  /// @param _y Y position
  void set_pos(int _x, int _y);

  /// @brief Set border radius
  /// @param _radius radius in px
  void set_radius(int _radius);

  /// @brief Set color of margin
  /// @param _color Color of the margin
  void set_color(uint16_t _color);

  /// @brief Set dimensions of rect
  /// @param _width Width of the rect
  /// @param _heigth Height of the rect
  void set_dimension(int _width, int _heigth);

  /// @brief Display the rectangle on the screen
  void display();

  /// @brief Select current rectangle
  /// @param _selected Status of selected
  void set_selected(bool _selected);


  /// @brief Fill current rect
  /// @param fill_color Color for the fill
  void fill(uint16_t fill_color) {
    /* Add some padding to fill only the empty part of Rect, not the margin */
    int y_sym = framework->tft->height() - y - height;

    if (radius == 0)  // Radius check
        framework->tft->fillRect(x + 1, y_sym + 1, width - 2, height - 2, fill_color);
    else
        framework->tft->fillRoundRect(x + 1, y_sym + 1, width - 2, height - 2, radius, fill_color);
  }

  /// @brief Click rect and execute function
  /// @param callback Function to execute
  void click(void callback()) {
    callback();
  }
  void click() {}
};

#endif