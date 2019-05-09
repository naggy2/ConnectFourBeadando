#include "button.h"
#include "graphics.hpp"

#include <iostream>
#include <sstream>

using namespace genv;
using namespace std;

Button::Button(Application* p,int x, int y, int sx, int sy,bool dir,function<void()> func)
    : Widget(p,x,y,sx,sy), _func(func){

}

void Button::drawBox(int x_offset,int y_offset,int contourColor,int boxColor) const{
    genv::gout<<genv::color(contourColor,contourColor,contourColor)<<genv::move_to(_x + x_offset,_y + y_offset)  <<genv::box(_size_x,_size_y);
    genv::gout<<genv::color(boxColor,boxColor,boxColor) <<genv::move_to(_x+x_offset +1, _y+1 +y_offset)<<genv::box(_size_x-2,_size_y-2);
}
void Button::drawBox(int x_offset,int y_offset,int contour_r,int contour_g,int contour_b,int boxColor) const{
    genv::gout<<genv::color(contour_r,contour_g,contour_b)<<genv::move_to(_x + x_offset,_y + y_offset)  <<genv::box(_size_x,_size_y);
    genv::gout<<genv::color(boxColor,boxColor,boxColor) <<genv::move_to(_x+x_offset +1, _y+1 +y_offset)<<genv::box(_size_x-2,_size_y-2);
}
void Button::drawText(int x_offset,int y_offset,int contourColor,int boxColor) const{
}
void Button::drawText(int x_offset,int y_offset,int contour_r,int contour_g,int contour_b,int boxColor) const{
}


void Button::draw() const{

    drawBox(0,0,60,60);
    drawText(0,0,60,60);

}
void Button::handle(event ev)
{
    if((ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left) ||(ev.type==ev_key && ev.keycode==key_enter)) { _func(); }

}

void Button::setText(std::string txt){ _txt = txt;}
