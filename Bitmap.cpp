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

#include "Bitmap.hpp"

Bitmap::Bitmap(GFXForms *display, uint8_t *_image, uint8_t _width, uint8_t _height)
{
    framework = display;
    image = _image;
    width = _width;
    heigth = _height;
}

Bitmap::Bitmap(GFXForms *display, uint8_t *_image, uint8_t _width, uint8_t _height, uint8_t _x, uint8_t _y) {
    framework = display;
    image = _image;
    width = _width;
    heigth = _height;
    x = _x;
    y = _y;
}
Bitmap::~Bitmap()
{
}