#include "graphics.hpp"

#include "Connectfour.h"
#include "vector"

Application* CreateApplication(int w, int h){
    return new Connectfour(w,h);
}

void Connectfour::setFields(){
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
    setFields();
    _retryButton = new Button(this,300,30,70,30,[&](){ setFieldsDefault();});



}
Connectfour::~Connectfour(){}

void Connectfour::Run(){

    genv::gout.open(_width,_height);
    genv::gout<<genv::move_to(0,0)<<genv::color(137, 133, 128)<<genv::box_to(_width-1,_height-1)<<genv::refresh;
    genv::event ev;


    drawFields();
    genv::gout<<genv::refresh;

    while(genv::gin >> ev && ev.keycode != genv::key_escape) {

    }


}



