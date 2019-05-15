#include "Statictext.h"
#include "graphics.hpp"


StaticText::StaticText(Application* p,int x, int y, int sx, int sy, std::string txt)
    : Widget(p,x,y,sx,sy), _txt(txt){
        _sx = genv::gout.twidth(_txt)+10;
    }

void StaticText::draw() const{
    genv::gout<<genv::color(137, 133, 128)<<genv::move_to(_x ,_y )  <<genv::box(_sx,_sy);
    genv::gout<<genv::color(255,255,255)<<genv::move_to(_x+10,_y+_sy/2)<<genv::text(_txt);
}

void StaticText::setText(std::string tmp){
    _sx = genv::gout.twidth(_txt)+10;
    _txt=tmp;

}

void StaticText::addText(std::string tmp){
    _txt+=tmp;
}

std::string StaticText::getText() const{
    return _txt;
}
bool StaticText::is_focusable(){
    return false;
}

void StaticText::handle(genv::event ev){}

