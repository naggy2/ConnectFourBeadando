#include "graphics.hpp"

#include "Connectfour.h"
#include "vector"

using namespace genv; //t�r�lni

Application* CreateApplication(int w, int h){
    return new Connectfour(w,h);
}

void Connectfour::initFields(){
    for (int i = 0;i< 7;i++ ){
            std::vector<Field*> f;
        for (int j = 0;j< 6;j++ ){
            Field *fi = new Field(this,95+i*30,300-j*30,30,30);
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


    if(ev.button == btn_left){

        if(_widgets[_focus] == _retryButton){ _retryButton->handle(ev);}
        else{

            int x=-1;
            for (unsigned int i = 0;i< _fields.size(); i++ ){
                for (unsigned int j = 0;j< _fields[i].size();j++ ){
                    if(_widgets[_focus] == _fields[i][j]){

                        x=i;
                        break;
                    }
                }
            }

            for (unsigned int i = 0;i < 6; i++ ){
                if(_fields[x][i]->getSide() == 0){

                    _fields[x][i]->handle(ev);
                    break;
                }
            }

        }

    }
}




