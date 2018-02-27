#include "MyLine.h"
    //MyLine(int x0,int y0,int x1,int y1) : Fl_Widget(x0,y0,x1,y1),
MyLine::MyLine() : Fl_Widget(1,1,1,1)
{
}
MyLine::MyLine(Box *b1, Box *b2) : Fl_Widget(1,1,1,1)
        //m_x0(x0),m_y0(y0),m_x1(x1),m_y1(y1)
{
    connect_boxes(b1,b2);
}
void MyLine::connect_boxes(void *b1,void *b2)
{
    this->b1= (Box *)(b1);
    this->b2= (Box *)(b2);
}
void MyLine::draw() {
    // DRAW BLACK 'X'
    fl_color(FL_BLACK);
    //int x2 = x()+w()-1, y2 = y()+h()-1;
    int x0= b1->x()+b1->w()/2;
    int y0= b1->y()+b1->h()/2;
    int x1= b2->x()+b2->w()/2;
    int y1= b2->y()+b2->h()/2;
    fl_line(x0,y0,x1,y1);
    //b1->redraw();
    //b2->redraw();
}

