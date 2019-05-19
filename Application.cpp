 #include "graphics.hpp"
 #include "Application.h"


using namespace genv;


Application::Application(int w, int h) : _width(w), _height(h), _focus(-1){

}

Application::~Application(){

}
void Application::RegisterWidget(Widget* w){
    _widgets.push_back(w);
}

void Application::Run(){

    gout.open(_width,_height);
    gout<<move_to(0,0)<<color(137, 133, 128)<<box_to(_width-1,_height-1)<<refresh;
    event ev;


    while(gin >> ev && ev.keycode != key_escape) {

         if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<_widgets.size();i++) {_widgets[i]->changefocusdefault();}

            for (size_t i=0;i<_widgets.size();i++) {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    _focus = i;
                    if(_widgets[_focus]->is_focusable())
                        {_widgets[i]->changefocus();}
                }
            }
        }

        if (_focus!=-1) {_widgets[_focus]->handle(ev);}

        if (ev.type == ev_mouse && ev.button==btn_left) { refreshApp(); }

        for( auto w : _widgets){ w->draw();}
        gout<<refresh;

    }

}

