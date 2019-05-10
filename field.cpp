#include "field.h"
#include "graphics.hpp"

#include <iostream>
#include <sstream>

using namespace genv;
using namespace std;

Field::Field(Application* p,int x, int y, int sx, int sy)
    : Widget(p,x,y,sx,sy), _side(none){

}



void Field::draw() const{



}
int Field::getSide() const{

    if(_side == red) {return 1;}
    else if(_side == blue){return 2;}
    return 0;
}
void Field::setSide(int n){

    if(n == 0){ _side = none;}
    else if(n == 1) {_side = red;}
    else if(n == 2){_side = blue;}

}
void Field::setSide(side s){ _side = s; }

void Field::handle(event ev)
{
    if((ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left) ||(ev.type==ev_key && ev.keycode==key_enter)) {  }

}


