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

#include "List.hpp"

List::List(GFXForms *display, const char *text, int font_size, uint16_t font_color, int _heigth, uint16_t rect_color, std::function<void()> _cb)
{
  color = rect_color;
  box = new Rect(display, 0 , _heigth , 0, 0, 8, rect_color);
  heigth = _heigth;
  text_widget = new Text(display, font_color, text);
  text_widget->set_size(font_size);
  text_widget->set_wrap(true);
  cb = _cb;
}

List::List(GFXForms *display, const char *text, int font_size, uint16_t font_color, int _heigth, Bitmap *icon, uint16_t rect_color, std::function<void()> _cb)
{
  color = rect_color;
  box = new Rect(display, 0 , _heigth , 0, 0, 8, rect_color);
  heigth = _heigth;
  grid_widget = new Grid(display, 1, 2);
  text_widget = new Text(display, font_color, text, font_size);
  text_widget->set_wrap(true);
  grid_widget->add(icon);
  grid_widget->add(text_widget);
  grid_widget->set_space_between(10); // Add some spacing between the icons and the text
  cb = _cb;
}

List::~List()
{
}