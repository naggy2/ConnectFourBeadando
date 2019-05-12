 #include "graphics.hpp"
 #include "Application.h"





Application::Application(int w, int h){
    _width = w;
    _height = h;

}
Application::~Application(){

}
void Application::RegisterWidget(Widget* w){
    _widgets.push_back(w);
}

void Application::Run(){

    genv::gout.open(_width,_height);
    genv::gout<<genv::move_to(0,0)<<genv::color(137, 133, 128)<<genv::box_to(_width-1,_height-1)<<genv::refresh;
    genv::event ev;


    while(genv::gin >> ev && ev.keycode != genv::key_escape) {


        //kirajzolás
        for( auto w : _widgets){ w->draw();}
        genv::gout<<genv::refresh;

    }

}

