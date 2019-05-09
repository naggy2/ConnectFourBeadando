 #include "graphics.hpp"
 #include "Application.h"





Application::Application(int w, int h){
    _width = w;
    _height = h;

}
Application::~Application(){

}
void Application::RegisterWidget(Widget* w){
    widgets.push_back(w);
}

void Application::Run(){
    genv::gout.open(_width,_height);
    genv::event ev;
    while(genv::gin >> ev && ev.keycode != genv::key_escape) {

    }

}

