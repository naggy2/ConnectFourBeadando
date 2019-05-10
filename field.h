#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <functional>
#include "widgets.h"

enum side {none = 0, red = 1, yellow = 2};

class Field : public Widget {

    side _side;

public:
    Field(Application* p,int x, int y, int sx, int sy);

    virtual void draw() const;

    virtual void handle(genv::event ev);

    void setSide(int n);
    void setSide(side s);
    int getSide() const;


};

#endif // FIELD_H_INCLUDED
