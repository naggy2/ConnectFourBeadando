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

void Connectfour::drawFields() const{
    for (int i = 0;i< 7;i++ ){

        for (int j = 0;j< 6;j++ ){
            _fields[i][j]->draw();
        }

    }
}

void Connectfour::setFieldsDefault(){
    for (int i = 0;i< 7;i++ ){
        for (int j = 0;j< 6;j++ ){
            _fields[i][j]->setSide(none);
        }

    }
}


Connectfour::Connectfour(int w, int h): Application(w,h){
    initFields();
    _retryButton = new Button(this,300,30,70,30,[&](){ setFieldsDefault();});



}
Connectfour::~Connectfour(){}





