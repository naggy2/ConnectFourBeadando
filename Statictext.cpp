#include "Statictext.h"
#include "graphics.hpp"


StaticText::StaticText(Application* p,int x, int y, int sx, int sy, std::string txt)
    : Widget(p,x,y,genv::gout.twidth(_txt)+10,sy), _txt(txt){}

void StaticText::draw() const{

    genv::gout<<genv::color(255,255,255)<<genv::move_to(_x+10,_y+_sy/2)<<genv::text(_txt);
}

void StaticText::setText(std::string tmp){
    _txt=tmp;
}

void StaticText::addText(std::string tmp){
    _txt+=tmp;
}

std::string StaticText::getText() const{
    return _txt;
}

void StaticText::handle(genv::event ev){}

