#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "widgets.h"
#include "vector"

class Application
{
protected:
    int _width, _height;
    int focus;
    std::vector<Widget*> widgets;
public:
    Application(int w, int h);
    virtual ~Application();
    virtual void Run();
    virtual void RegisterWidget(Widget* w);
};


extern Application* CreateApplication(int w, int h);


#endif // APPLICATION_H_INCLUDED
