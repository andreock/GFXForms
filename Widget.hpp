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

#include <stdint.h>

#include "GFXForms.hpp"
#include <functional>

#ifndef WIDGET_H
#define WIDGET_H

class Widget {
 protected:
  /* Need to access TFT display */
  GFXForms *framework;
  int x = 0;               // X position
  int y = 0;               // Y position
  int width = 0;           // Width of the widget
  int heigth = 0;          // Height of the widget
  bool displayed = false;  // Whether the widget is displayed or not
  bool selected = false;   // Whether the widget
  bool clicked = false;    // Whether the widget is clicked or not
  uint16_t color;
  std::function<void()> cb = nullptr;  // Default callback
 public:
  virtual void set_pos(int _x, int _y) = 0;
  virtual void set_color(uint16_t _color) = 0;
  virtual void display() = 0;
  virtual void set_dimension(int _width, int _heigth) = 0;
  virtual void set_selected(bool _selected) = 0;
  virtual void click(void callback()) = 0;

  /// @brief Get X position
  /// @return X position
  int get_x() { return x; }

  /// @brief Get Y position
  /// @return Y position
  int get_y() { return y; }

  /// @brief Get widget width
  /// @return Width of widget
  int get_width() { return width; }

  /// @brief Get widget height
  /// @return Height of the widget
  int get_heigth() { return heigth; }
  void set_callback(std::function<void()> callback) { cb = callback; }
  virtual void click() = 0;
};

#endif