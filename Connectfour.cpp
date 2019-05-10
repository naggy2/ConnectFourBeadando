#include "graphics.hpp"

#include "Connectfour.h"

Application* CreateApplication(int w, int h){
    return new Connectfour(w,h);
}

Connectfour::Connectfour(int w, int h): Application(w,h){

}
Connectfour::~Connectfour(){}

void Connectfour::Run(){

    genv::gout.open(_width,_height);
    genv::gout<<genv::move_to(0,0)<<genv::color(137, 133, 128)<<genv::box_to(_width-1,_height-1)<<genv::refresh;
    genv::event ev;

    while(genv::gin >> ev && ev.keycode != genv::key_escape) {

    }


}



