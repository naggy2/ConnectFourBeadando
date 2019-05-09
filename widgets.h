#ifndef WIDGETS_H_INCLUDED
#define WIDGETS_H_INCLUDED

#include "graphics.hpp"

class Application;

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    Application *_parent;
public:

    Widget(Application *p,int x, int y, int sx, int sy);
    virtual bool is_selected(int mx, int my);
    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_H_INCLUDED
