#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include "Field.h"
#include "vector"

class Gamemaster
{

    int _player1;
    int _player2;
    int _winner;
    bool _gameover;

public:

        Gamemaster();
        virtual ~Gamemaster();

        void setFieldsDefault(std::vector<std::vector<Field*> > &f);


};

#endif // GAMEMASTER_H
