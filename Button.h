#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <functional>
#include "widgets.h"

class Button : public Widget {

    std::string _txt;
    std::function<void()> _func;

public:
    Button(Application* p,int x, int y, int sx, int sy,std::function<void()> func);

    virtual void draw() const;
    void drawBox(int x_offset,int y_offset,int contourColor,int boxColor) const;
    void drawBox(int x_offset,int y_offset,int contour_r,int contour_g,int contour_b,int boxColor) const;
    void drawText(int x_offset,int y_offset,int textColor) const;
    void drawText(int x_offset,int y_offset,int text_r,int text_g,int text_b) const;

    virtual void handle(genv::event ev);

    void setText(std::string txt);


};

#endif // BUTTON_H_INCLUDED
