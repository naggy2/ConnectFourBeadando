#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <functional>
#include "widgets.h"

enum side {none = 0, red = 1, yellow = 2};

class Field : public Widget {

    bool _winner;
    side _side;
    std::function<void()> _func;

public:
    Field(Application* p,int x, int y, int sx, int sy, side s,std::function<void()> func);

    void  drawDot() const;
    virtual void draw() const;

    bool is_selected(int m_x, int m_y);
    virtual void handle(genv::event ev);

    void setSide(int n);
    void setSide(side s);
    void setWinner(bool b);



};

#endif // FIELD_H_INCLUDED
