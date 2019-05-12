#include "Gamemaster.h"


Gamemaster::Gamemaster()
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
