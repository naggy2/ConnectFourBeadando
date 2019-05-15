#include "Gamemaster.h"




std::vector<std::vector<int> > initPlayers(){
    std::vector<std::vector<int> > players;
    for (int i = 0;i< 7;i++ ){
        std::vector<int> vec;
        for (int j = 0;j< 6;j++ ){
            vec.push_back(0);
        }
        players.push_back(vec);
    }

    return players;
}


Gamemaster::Gamemaster() : _status(inGame), _turn(0),_players(initPlayers())
{

}

Gamemaster::~Gamemaster()
{

}
bool Gamemaster::isRowFull(int x){
    if(_players[x][5] == 0){ return false;}
    return true;

}

bool Gamemaster::isFieldFull(){
    for (unsigned int i = 0;i< _players.size();i++ ){
        for (unsigned int j = 0;j< _players[i].size();j++ ){
            if(_players[i][j] == 0) return false;
        }
    }
    return true;

}

void Gamemaster::setFieldsDefault(){

    for (int i = 0;i< 7;i++ ){ for (int j = 0;j< 6;j++ ){
            _players[i][j]=0;
    } }
    _status=inGame;

}

void Gamemaster::checkNewElement( int x){


    if(_status!=fullBoard){

        if(!isRowFull(x)){

            _turn++;
            for (unsigned int i = 0;i< _players[x].size();i++ ){
                if(_players[x][i] == 0) { _players[x][i] = _turn % 2==0 ? 1 : 2; break; }
            }

            if(isFieldFull()){   _status = fullBoard;}
            else{


            }

        }

    }




}


