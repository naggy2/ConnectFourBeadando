#include "graphics.hpp"

#include "Connectfour.h"
#include "vector"

Application* CreateApplication(int w, int h){
    return new Connectfour(w,h);
}

void Connectfour::initFields(){
    for (int i = 0;i< 7;i++ ){
            std::vector<Field*> f;
        for (int j = 0;j< 6;j++ ){
            Field *fi = new Field(this,95+i*30,150+j*30,30,30);
            fi->setSide(none);
            f.push_back(fi);
        }
        _fields.push_back(f);
    }
}



Connectfour::Connectfour(int w, int h): Application(w,h){
    initFields();
    _retryButton = new Button(this,300,30,70,30,[&](){ _gmaster->setFieldsDefault(_fields);});
    _gmaster = new Gamemaster();
}
Connectfour::~Connectfour(){}

void Connectfour::handleWidgets(genv::event ev){

    _widgets[_focus]->handle(ev);
}




