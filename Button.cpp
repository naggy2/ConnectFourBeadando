#include "button.h"
#include "graphics.hpp"


using namespace genv;


Button::Button(Application* p,int x, int y, int sx, int sy ,std::function<void()> func)
    : Widget(p,x,y,sx,sy), _func(func){

}

void Button::drawBox(int x_offset,int y_offset,int contourColor,int boxColor) const{
    gout<<color(contourColor,contourColor,contourColor)<<move_to(_x + x_offset,_y + y_offset)  <<box(_sx,_sy);
    gout<<color(boxColor,boxColor,boxColor) <<move_to(_x+x_offset +1, _y+1 +y_offset)<<box(_sx-2,_sy-2);
}
void Button::drawBox(int x_offset,int y_offset,int contour_r,int contour_g,int contour_b,int boxColor) const{
    gout<<color(contour_r,contour_g,contour_b)<<move_to(_x + x_offset,_y + y_offset)  <<box(_sx,_sy);
    gout<<color(boxColor,boxColor,boxColor) <<move_to(_x+x_offset +1, _y+1 +y_offset)<<box(_sx-2,_sy-2);
}
void Button::drawText(int x_offset,int y_offset,int textColor) const{
    gout<<color(textColor,textColor,textColor) <<move_to(_x+x_offset +1, _y+1 +y_offset)<<text(_txt);
}
void Button::drawText(int x_offset,int y_offset,int text_r,int text_g,int text_b) const{
    gout<<color(text_r,text_g,text_b) <<move_to(_x+x_offset +1, _y+1 +y_offset)<<text(_txt);
}


void Button::draw() const{

    drawBox(0,0,30,60);
    drawText(13,18,255);

}
void Button::handle(event ev)
{
    if((ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left) ||(ev.type==ev_key && ev.keycode==key_enter))
        { _func(); }

}

void Button::setText(std::string txt){ _txt = txt;}
