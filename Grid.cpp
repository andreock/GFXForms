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

#include "Grid.hpp"

#include <type_traits>

Grid::Grid(GFXForms *_framework, int _rows, int _cols) {
  framework = _framework;
  rows = _rows;
  cols = _cols;
  width = framework->tft->width();
  heigth = framework->tft->height();
  element_size = (framework->tft->width() / cols) - 10;
}

Grid::Grid(GFXForms *_framework, int _rows, int _cols, vector<Widget *> _widgets) {
  framework = _framework;
  rows = _rows;
  cols = _cols;
  widgets = _widgets;
  width = framework->tft->width();
  heigth = framework->tft->height();
  element_size = (framework->tft->width() / cols) - 10;
}

Grid::~Grid() {
}

void Grid::display() {
  int current_element = 0;
  int padding_x = 0;
  int padding_y = 0;
  /* Iterate each widget */
  for (Widget *widget : widgets) {
    widget->set_dimension(element_size, widget->get_heigth());  // Set element dimension
    widget->set_pos(x + padding_x, y + padding_y);              // Set widget position
    padding_x += widget->get_width() + space_between;           // Add spacing between elements

    widget->display();  // Display the element

    /* Check if current_element is the last in the row */
    if (++current_element % cols == 0) {
      padding_x = 0;                           // Reset x padding for the new row
      padding_y += widget->get_heigth() + y_spacing + initial_padding_y;  // Add padding for the new row
    };
  }
  displayed = true;
}

void Grid::add(Widget *widget) {
  widgets.push_back(widget);
}

void Grid::remove(size_t index) {
  widgets.erase(widgets.begin() + index);
}
