#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED



class Application
{
    int _width, _height;
public:
    Application(int w, int h);
    virtual ~Application();
    virtual void Run();
};


extern Application* CreateApplication(int w, int h);


#endif // APPLICATION_H_INCLUDED
