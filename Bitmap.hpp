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
#include "Rect.hpp"
#include "Text.hpp"
#include "Grid.hpp"

#ifndef BITMAPUI_H
#define BITMAPUI_H

class Bitmap: public Widget
{
private:
    uint8_t *image;
    void clean_bitmap() {
        framework->tft->fillRect(x, y, width, heigth, framework->background_color);
    }
public:
    Bitmap(GFXForms *display, uint8_t *_image, uint8_t _width, uint8_t _height);
    Bitmap(GFXForms *display, uint8_t *_image, uint8_t _width, uint8_t _height, uint8_t _x, uint8_t _y);
    ~Bitmap();
    void set_pos(int _x, int _y){
        x = _x;
        y = _y;
        clean_bitmap();
        display();
    };
    void set_color(uint16_t _color){};
    void display(){
        framework->tft->drawBitmap(x, y, image, width, heigth, ST77XX_WHITE);
    };
    void set_dimension(int _width, int _heigth){
        // width = _width;
        // heigth = _heigth;
    };
    void set_selected(bool _selected) {
        selected = _selected;
        // if(selected){
        //     // box->set_color(ST77XX_BLUE);
        //     // box->display();
        // }
        // else{
        //     box->set_color(ST77XX_BLACK);
        //     box->display();
        // }
    };
    void click(void callback()) {
        callback();
    }
    void click() {
        
    }
};

#endif