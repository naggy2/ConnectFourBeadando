#include "graphics.hpp"

#include "Connectfour.h"
#include "vector"
#include "iostream" //törölni

using namespace genv; // törölni
using namespace std; // törölni

Application* CreateApplication(int w, int h){
    return new Connectfour(w,h);
}

void Connectfour::initFields(){
    for (int i = 0;i< 7;i++ ){
            std::vector<Field*> f;
        for (int j = 0;j< 6;j++ ){
            Field *fi = new Field(this,95+i*30,150+j*30,30,30);
            fi->setSide(0);
            f.push_back(fi);
        }
        _fields.push_back(f);
    }
}



Connectfour::Connectfour(int w, int h): Application(w,h){
    initFields();
    _retryButton = new Button(this,300,30,70,30,[&](){ _gmaster->setFieldsDefault(_fields);});
    _gmaster = new Gamemaster();



}
Connectfour::~Connectfour(){}


void Connectfour::Run(){

    genv::gout.open(_width,_height);
    genv::gout<<genv::move_to(0,0)<<genv::color(137, 133, 128)<<genv::box_to(_width-1,_height-1)<<genv::refresh;
    genv::event ev;


    while(genv::gin >> ev && ev.keycode != genv::key_escape) {

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



        //if (_focus!=-1) { _widgets[_focus]->handle(ev); }
        if (_focus!=-1) {

            if(_widgets[_focus] == _retryButton){ _retryButton->handle(ev);break;}
            else{

                int x=-1,y=-1;
                for (int i = 0;i< _fields.size(); i++ ){
                    for (int j = 0;j< _fields[i].size();j++ ){
                        if(_widgets[_focus] == _fields[i][j]){

                            x=i;
                            y=j;

                            break;
                        }
                    }
                }


                int cnt=y;
                for (int i = 5;i>= 0;i-- ){
                    if(_fields[x][i]->getSide() == 0){

                        cnt=i;
                        break;
                    }
                }

                _fields[x][cnt]->handle(ev);




            }
        }


        //kirajzolás
        for( auto w : _widgets){ w->draw();}
        genv::gout<<genv::refresh;

    }

}
