#ifndef WIDGETS_H_INCLUDED
#define WIDGETS_H_INCLUDED

#include "graphics.hpp"

class Application;

class Widget {
protected:
    int _x, _y, _sx, _sy;
    Application *_parent;
    bool _infocus;

public:

    Widget(Application *p,int x, int y, int sx, int sy);
    virtual bool is_selected(int mx, int my);
    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;
    virtual int getX() const{return _x;}
    virtual int getY() const{return _y;}
    virtual int getSizeX() const{return _sx;}
    virtual int getSizeY() const{return _sx;}

    virtual void changefocus();
    void changefocusdefault();
    bool returnfocus();
    virtual bool is_focusable();

};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_H_INCLUDED
