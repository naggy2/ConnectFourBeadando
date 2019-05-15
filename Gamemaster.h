#ifndef GAMEMASTER_H
#define GAMEMASTER_H


#include "vector"

enum gameStatus{inGame, fullBoard, winner};

class Gamemaster
{

    gameStatus _status;
    int _turn;
    std::vector<std::vector<int> > _players;


public:

    Gamemaster();
    virtual ~Gamemaster();

    std::vector<std::vector<int> > getField() const{return _players;}
    gameStatus getGameStatus() const{return _status;}
    bool isRowFull(int x);
    bool isFieldFull();
    void checkNewElement(int x);
    void setFieldsDefault();

};

#endif // GAMEMASTER_H
