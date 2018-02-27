#ifndef __MYLINE__
#define __MYLINE__

#include <iostream>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Overlay_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Help_View.H>
#include <FL/fl_draw.H>
#include"Box.h"
class MyLine : public Fl_Widget {
    Box * b1;
    Box * b2;
    //int m_x0;
    //int m_x1;
    //int m_y0;
    //int m_y1;
public:
    //MyLine(int x0,int y0,int x1,int y1) : Fl_Widget(x0,y0,x1,y1),
    MyLine();
    MyLine(Box *b1, Box *b2) ;

    void connect_boxes(void *b1,void *b2);
    
    void draw() ;
};
#endif
