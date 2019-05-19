#include "widgets.h"
#include "graphics.hpp"
#include "Application.h"


Widget::Widget(Application* p,int x, int y, int sx, int sy) : _x(x), _y(y), _sx(sx), _sy(sy), _parent(p), _infocus(false){
    _parent->RegisterWidget(this);
}

bool Widget::is_selected(int m_x, int m_y){
    return m_x>_x && m_x<_x+_sx && m_y>_y && m_y<_y+_sy;
}

void Widget::changefocus(){
    _infocus= !_infocus;
}
void Widget::changefocusdefault(){
    _infocus = false;
}
bool Widget::returnfocus(){
    return _infocus;
}
bool Widget::is_focusable(){
    return true;
}






