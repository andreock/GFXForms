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

#ifndef LISTUI_H
#define LISTUI_H

#define MARGIN 3
#define MARGIN_X 5

class List: public Widget
{
private:
    Rect *box;
    Text *text_widget;
public:
    List(GFXForms *display, const char *text, int font_size, uint16_t font_color, int _heigth, uint16_t rect_color);
    ~List();
    void set_pos(int _x, int _y){
        x = _x;
        y = _y;
        box->set_pos(x, y);
        text_widget->set_pos(x + MARGIN_X, y + MARGIN);
    };
    void set_color(uint16_t _color){};
    void display(){
        box->display();
        text_widget->display();
    };
    void set_dimension(int _width, int _heigth){
        width = _width;
        heigth = _heigth;
        box->set_dimension(_width, heigth);
    };
    void set_selected(bool _selected) {
        selected = _selected;
        if(selected){
            box->set_color(ST77XX_BLUE);
            box->display();
        }
        else{
            box->set_color(ST77XX_BLACK);
            box->display();
        }
    };
    void click(void callback()) {
        callback();
    }
};

#endif