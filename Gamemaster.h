#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include "Field.h"
#include "vector"

class Gamemaster
{

    std::vector<std::vector<int> > _players;

public:

    Gamemaster();
    virtual ~Gamemaster();


    void leheteodarakni();
    void setFieldsDefault();

};

#endif // GAMEMASTER_H
