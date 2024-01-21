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

List::List(GFXForms *display, const char *text, int font_size, uint16_t font_color, int _heigth, uint16_t rect_color)
{
  color = rect_color;
  box = new Rect(display, 0 , _heigth , 0, 0, 8, rect_color);
  heigth = _heigth;
  text_widget = new Text(display, font_color, text);
  text_widget->set_size(font_size);
  text_widget->set_wrap(true);
}

List::~List()
{
}