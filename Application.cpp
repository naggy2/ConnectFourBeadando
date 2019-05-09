 #include "graphics.hpp"
 #include "Application.h"





Application::Application(int w, int h){
    _width = w;
    _height = h;
    genv::gout.open(_width,_height);
}
Application::~Application(){

}

void Application::Run(){
    genv::event ev;
    while(genv::gin >> ev && ev.keycode != genv::key_escape) {

    }

}

