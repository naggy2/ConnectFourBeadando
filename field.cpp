#include "field.h"
#include "graphics.hpp"

#include <iostream>
#include <sstream>

using namespace genv;
using namespace std;

void drawcircle(int r, int x, int y){
    for (int i = -r;i< r;i++ ){
        for (int j = -r;j< r;j++ ){
            if(i*i+j*j<=r*r){
                gout<<move_to(x+i,y+j)<<dot;
            }
        }

    }

}

Field::Field(Application* p,int x, int y, int sx, int sy)
    : Widget(p,x,y,sx,sy), _side(none){

}



void Field::draw() const{

    int r = _sx/2-5;
    gout<<move_to(_x,_y)<<color(0,0,200)<<box(_sx,_sy);


    if(_side == none){ gout<<color(137, 133, 128);}
    else if(_side == red) { gout<<color( 190, 42, 35);}
    else if(_side == yellow){ gout<<color(222, 229, 25);}

    for (int i = -r;i< r;i++ ){
        for (int j = -r;j< r;j++ ){
            if(i*i+j*j<r*r){
                gout<<move_to(_x+ (_sx/2)+i,_y+ (_sy/2)+j)<<dot;
            }
        }

    }

}
int Field::getSide() const{

    if(_side == red) {return 1;}
    else if(_side == yellow){return 2;}
    return 0;
}
void Field::setSide(int n){

    if(n == 0){ _side = none;}
    else if(n == 1) {_side = red;}
    else if(n == 2){_side = yellow;}

}
void Field::setSide(side s){ _side = s; }

void Field::handle(event ev)
{
    if((ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left) ||(ev.type==ev_key && ev.keycode==key_enter))
        {  }

}


