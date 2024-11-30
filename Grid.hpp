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

#include <vector>

#include "GFXForms.hpp"
#include "Widget.hpp"

using namespace std;

#ifndef GRID_H
#define GRID_H

class Grid : public Widget {
 private:
  int rows = 0;           // Number of rows
  int cols = 0;           // Number of columns
  int space_between = 0;  // Space between elements
  int element_size = 0;   // Size(width) of elements
  int initial_padding_x = 0; // Padding between elements on X axis
  int initial_padding_y = 0; // Padding between elements on Y axis
  int selected_widget = -1; // Selected widget
  int y_spacing = 10; // Spacing between elements on Y axis
  vector<Widget *> widgets; // All the widgets
  size_t pushed_el = 0;
  size_t removed_el = 0;
  bool dropped = false;

 public:
  /// @brief Create a grid widget
  /// @param _framework GFXForms framework reference
  /// @param _rows Rows of the grid
  /// @param _cols Columns of the grid
  Grid(GFXForms *_framework, int _rows, int _cols);

  /// @brief Create a grid widget and assign list of widgets to id
  /// @param _framework GFXForms framework reference
  /// @param _rows Rows of the grid
  /// @param _cols Columns of the grid
  /// @param _widgets List of widgets
  Grid(GFXForms *_framework, int _rows, int _cols, vector<Widget *> _widgets);

  ~Grid();

  /// @brief Add widget to grid
  /// @param widget Widget to add
  void add(Widget *widget);
  
  /// @brief Remove widget at index from grid
  /// @param index index of widget to remove
  void remove(size_t index);

  /// @brief Display the grid on TFT screen
  void display();
  
  void display(vector<Widget *> _widgets);

  void set_y_spacing(int _y_spacing){
    y_spacing = _y_spacing;
  };

  /// @brief Set position of grid
  /// @param _x X position
  /// @param _y Y position
  void set_pos(int _x, int _y) {
    x = _x;
    y = _y;
  };

  /// @brief Unimplemented setter for color. Grid doesn't need it
  /// @param _color Color to set
  void set_color(uint16_t _color){};

  /// @brief Set element dimension
  /// @param _width Width of element
  /// @param _height Height of element
  void set_dimension(int _width, int _height) {
    element_size = _width;
    width = _width;
    heigth = _height;
  };

  /// @brief Set space between for every element
  /// @param _space Spacing in px
  void set_space_between(int _space) {
    space_between = _space;
  }

  /// @brief Set padding of the grid in the GUI
  /// @param _x X padding
  /// @param _y Y padding
  void set_padding(int _x, int _y) {
    initial_padding_x = _x;
    initial_padding_y = _y;
  }

  /// @brief Set selected element
  /// @param pos Position of element to set selected
  /// @param _selected State of selected property of element
  void set_selected(int pos, bool _selected);

  /// @brief Mock set_selected. NOT USE
  /// @param _selected state
  void set_selected(bool _selected) { selected = _selected; }
  
  /// @brief Return the currenly selected widget
  /// @return Currenly selected widget
  int get_selected() { return selected_widget; }

  /// @brief Mock click. It only executes callback. NOT USE
  /// @param callback function to be called
  void click(void callback()) {
    callback();
  }

  // TODO: Deprecate it
  /// @brief Propagate click to widget at pos and execute callback
  /// @param pos Position of element to click
  /// @param callback function to be called
  /// @deprecated
  void click(int pos, void callback()) {
    if(widgets.size() == 0)
      return;
    widgets[pos]->click(callback);
  }


  /// @brief Click element at pos without execute callback
  /// @param pos element position
  void click(int pos) {
    if(widgets.size() == 0)
      return;
    widgets[pos]->click();
  }

  void click() {
    if(widgets.size() == 0)
      return;
    widgets[selected_widget]->click();
  }

  /// @brief Set callback on widget at pos
  /// @param pos Widget position
  /// @param callback function to be set
  void set_callback(int pos, void callback()) {
    if(widgets.size() == 0)
      return;
    widgets[pos]->set_callback(callback);
  }

  /// @brief Get the selected widget
  /// @return Reference to the selected widget
  Widget *get_current_widget(){
    return widgets[selected_widget];
  }
};

#endif
