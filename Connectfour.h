#ifndef CONNECTFOUR_H_INCLUDED
#define CONNECTFOUR_H_INCLUDED

#include "Application.h"
#include "Field.h"
#include "Statictext.h"
#include "Button.h"
#include "Gamemaster.h"
#include "vector"

class Connectfour : public Application
{
    Gamemaster* _gmaster;
    std::vector<std::vector<Field*> > _fields;
    Button* _retryButton;
    StaticText* _stext;

    void initFields();
    void refreshField();


public:
    Connectfour(int w, int h);

    ~Connectfour();

    virtual void refreshApp();


};




#endif // CONNECTFOUR_H_INCLUDED
