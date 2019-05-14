#ifndef STATICTEXT_H_INCLUDED
#define STATICTEXT_H_INCLUDED


#include "widgets.h"


class StaticText : public Widget {
    std::string _txt;
public:
    StaticText(Application* p,int x, int y, int sx, int sy,std::string txt);
    virtual void draw() const;
    virtual void handle(genv::event ev);

    void setText(std::string tmp);
    void addText(std::string tmp);
    std::string getText() const;
    virtual bool is_focusable();

};

#endif // STATICTEXT_H_INCLUDED
