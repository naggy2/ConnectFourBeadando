#include "field.h"
#include "graphics.hpp"



using namespace genv;


Field::Field(Application* p,int x, int y, int sx, int sy,side s, std::function<void()> func)
    : Widget(p,x,y,sx,sy), _winner(false), _side(s), _func(func){

}
/// példa megoldás, mapbe eltárolni a 4 nyertes field helyét és azokon végig menni és rajzolni.
void Field::drawX() const {

       // gout<<color(0,0,0)<<move_to(_x,_y)<<box(5,5);
        gout<<color(0,0,0)<<move_to(_x+10,_y+7)<<line_to(_x+_sx-10,_y+_sy-7);
        gout<<move_to(_x+10,_y+_sy-7)<<line_to(_x+_sx-10,_y+7);

}
void Field::setWinner(bool b){
    _winner = b;
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

    if(_winner) drawX();




}

void Field::handle(event ev)
{
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left)
        {_func();}
}


void Field::setSide(int n){

    if(n == 0){ _side = none;}
    else if(n == 1) {_side = red;}
    else if(n == 2){_side = yellow;}

}
void Field::setSide(side s){ _side = s; }




