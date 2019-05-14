#include "Gamemaster.h"


Gamemaster::Gamemaster() : _turn(1)
{

}

Gamemaster::~Gamemaster()
{

}

void Gamemaster::setFieldsDefault(std::vector<std::vector<Field*> > &f){

    for (int i = 0;i< 7;i++ ){
        for (int j = 0;j< 6;j++ ){
            f[i][j]->setSide(none);
        }
    }
}


bool Gamemaster::isRowFull(std::vector<std::vector<Field*> > &f,int row){
    if( f[row][0]->getSide() == 0) return false;
    return true;

}
void Gamemaster::setTurn(){
//    if(_turn==2) _turn-=1;
//    else _turn+=1;
}



