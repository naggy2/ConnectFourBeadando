#include "graphics.hpp"

#include "Connectfour.h"
#include "vector"
#include "utility"
#include "sstream"

using namespace genv;



Application* CreateApplication(int w, int h){
    return new Connectfour(w,h);
}

void Connectfour::initFields(){
    for (int i = 0;i< 7;i++ ){
            std::vector<Field*> f;
        for (int j = 0;j< 6;j++ ){
            Field *fi = new Field(this,75+i*50,375-j*50,50,50,none,[=](){
            _gmaster->checkNewElement(i);

            });
            f.push_back(fi);
        }
        _fields.push_back(f);
    }
}

void Connectfour::setWinnerDef(){
    for (unsigned int i = 0;i< _fields.size();i++ ){
        for (size_t j = 0;j< _fields[i].size();j++ ){
            _fields[i][j]->setWinner(false);

        }
    }
}


Connectfour::Connectfour(int w, int h): Application(w,h){
    _gmaster = new Gamemaster();
    initFields();
    _retryButton = new Button(this,355,90,70,30,[&](){ _gmaster->setFieldsDefault();setWinnerDef();});
    _retryButton->setText("Retry");
    _stext = new StaticText(this,65,50,200,30,"Let's start the game!");

}


Connectfour::~Connectfour(){}



void Connectfour::refreshBoard(){
    std::vector<std::vector<int> > vec = _gmaster->getField();
    for (unsigned int i = 0;i< _fields.size();i++ ){
        for (size_t j = 0;j< _fields[i].size();j++ ){
            _fields[i][j]->setSide(vec[i][j]);

        }
    }


}

std::string convertS(int a){
    std::stringstream ss;
    ss<<a;
    return ss.str();
}

void Connectfour::refreshApp(){

    /// A board frissítése
    refreshBoard();

    /// Ha a státusz fullBoard, akkor megtelt a pálya, csak a Retry buttonnal tudsz újra kezdeni
    if(_gmaster->getGameStatus()==fullBoard){ _stext->setText("The board is full, hit retry to start a new game!"); }
    /// Ha valaki nyert akkor "beikszeljük" a nyertes sorozatot
    else if(_gmaster->getGameStatus()==winner){

        _stext->setText("The winner is the "+convertS(_gmaster->getTurn() % 2 == 0 ? 2 : 1)+". player!");
        std::vector<std::pair<int,int> > vec = _gmaster->getWinners();

        for (unsigned int i = 0;i< vec.size();i++ ){

            _fields[vec[i].first][vec[i].second]->setWinner(true);

        }
        gout<<refresh;


    }
    else{
        _stext ->setText(convertS(_gmaster->getTurn() % 2 == 0 ? 1 : 2)+". players turn");
    }


}





