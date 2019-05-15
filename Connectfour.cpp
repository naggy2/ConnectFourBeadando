#include "graphics.hpp"

#include "Connectfour.h"
#include "vector"
#include "utility"

/*TODO:
Pontosabb kattintás érzékelés
Players turn felirat
*/

using namespace genv;

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
    _retryButton = new Button(this,300,30,70,30,[&](){ _gmaster->setFieldsDefault();setWinnerDef();});
    _retryButton->setText("Retry");
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
    else if(_gmaster->getGameStatus()==winner){

        _stext->setText("gyoztes");
        std::vector<std::pair<int,int> > vec = _gmaster->getWinners();

        for (unsigned int i = 0;i< vec.size();i++ ){

            _fields[vec[i].first][vec[i].second]->setWinner(true);

        }
        gout<<refresh;


    }
    else{ _stext ->setText("Hello");}


}





