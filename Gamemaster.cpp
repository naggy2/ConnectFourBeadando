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


Gamemaster::Gamemaster() : _players(initPlayers())
{

}

Gamemaster::~Gamemaster()
{

}

void Gamemaster::leheteodarakni(){}

void Gamemaster::setFieldsDefault(){


    for (int i = 0;i< 7;i++ ){
        for (int j = 0;j< 6;j++ ){
            _players[i][j]=0;
        }

    }

}
