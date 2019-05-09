#include "widgets.h"
#include "graphics.hpp"
#include "Application.h"


Widget::Widget(Application* p,int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy), _parent(p)
{
    _parent->RegisterWidget(this);
}

bool Widget::is_selected(int m_x, int m_y)
{
    return m_x>_x && m_x<_x+_size_x && m_y>_y && m_y<_y+_size_y;
}






