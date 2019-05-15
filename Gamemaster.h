#ifndef GAMEMASTER_H
#define GAMEMASTER_H


#include "vector"
#include "utility"

enum gameStatus{inGame, fullBoard, winner};

class Gamemaster
{


    gameStatus _status;
    int _turn;
    std::vector<std::vector<int> > _players;
    std::vector<std::pair<int, int>> _winnerFields;

    bool isRowFull(int x);
    bool isFieldFull();



public:

    Gamemaster();
    virtual ~Gamemaster();

    std::vector<std::vector<int> > getField() const{return _players;}
    std::vector<std::pair<int, int>>  getWinners() const{return _winnerFields;}
    gameStatus getGameStatus() const{return _status;}
    void checkNewElement(int x);
    void setFieldsDefault();

};

#endif // GAMEMASTER_H
