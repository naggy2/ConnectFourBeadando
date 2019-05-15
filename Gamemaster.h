#ifndef GAMEMASTER_H
#define GAMEMASTER_H


#include "vector"



class Gamemaster
{

    int _turn;
    int _currentx;
    int _currenty;
    std::vector<std::vector<int> > _players;

public:

    Gamemaster();
    virtual ~Gamemaster();

    int getTurn() const {return _turn;}
    int getX() const{return _currentx;}
    int getY() const{return _currenty;}
    bool isRowFull(int x);
    void checkNewElement(int x);
    void setFieldsDefault();

};

#endif // GAMEMASTER_H
