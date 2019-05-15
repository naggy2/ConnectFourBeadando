#include "graphics.hpp"

#include "Connectfour.h"
#include "vector"


using namespace genv; //törölni

Application* CreateApplication(int w, int h){
    return new Connectfour(w,h);
}

void Connectfour::initFields(){
    for (int i = 0;i< 7;i++ ){
            std::vector<Field*> f;
        for (int j = 0;j< 6;j++ ){
            Field *fi = new Field(this,95+i*30,300-j*30,30,30,none,[=](){
            _gmaster->checkNewElement(i);

            });
            f.push_back(fi);
        }
        _fields.push_back(f);
    }
}




Connectfour::Connectfour(int w, int h): Application(w,h){
    _gmaster = new Gamemaster();
    initFields();
    _retryButton = new Button(this,300,30,70,30,[&](){ _gmaster->setFieldsDefault();});
    _stext = new StaticText(this,50,50,200,30,"Hello");

}


Connectfour::~Connectfour(){}



void Connectfour::refreshField(){
    std::vector<std::vector<int> > vec = _gmaster->getField();
    for (unsigned int i = 0;i< _fields.size();i++ ){
        for (size_t j = 0;j< _fields[i].size();j++ ){
            _fields[i][j]->setSide(vec[i][j]);

        }
    }


}
void Connectfour::refreshApp(){

    refreshField();

    if(_gmaster->getGameStatus()==fullBoard){ _stext->setText("A palya betelt"); }
    else if(_gmaster->getGameStatus()==winner){ _stext->setText("gyoztes"); }
    else{ _stext ->setText("Hello");}


}





