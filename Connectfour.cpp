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

}

Connectfour::~Connectfour(){}

void Connectfour::setFieldSide(int x, int y, int turn){
    ///ÍRD ÁT ÚGY,HOGY MEGKAPJA AZ EGÉSZ MAÁTRIXOT ÉS ASZERINT FRISSÍT MINDENT, MIVEL A MÁTRIX 0,1,2 TUDNI FOGJA MILYEN SZÍNŰ!!
    /// ÉS AKKOR NEM IS KELL GETX SE CURRENT X MERT A MÁTRIX TÁROL MINDENT!
    /// VAAAAGY KAPJON A GAMEMASTER EGY APP PARENTET ÉS EGYBŐL HÍVJA MEG HOZZÁ EZT A FÜGGVÉNYT ÉS AKKOR NEM IS KELL A REFRESH APP;
    if(x!=-1 && y!=-1 && turn!=0){ _fields[x][y]->setSide(turn % 2==0 ? 1 : 2); }
}

void Connectfour::refreshApp(){

    setFieldSide(_gmaster->getX(),_gmaster->getY(),_gmaster->getTurn());
}





