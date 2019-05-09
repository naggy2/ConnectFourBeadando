#include "graphics.hpp"

#include "Connectfour.h"

Application* CreateApplication(int w, int h){
    return new Connectfour(w,h);
}

Connectfour::Connectfour(int w, int h): Application(w,h){}
Connectfour::~Connectfour(){}

void Connectfour::Run(){
    genv::event ev;
    while(genv::gin >> ev && ev.keycode != genv::key_escape) {

    }


}



