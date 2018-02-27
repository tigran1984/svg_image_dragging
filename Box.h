#ifndef __BOX__H__
#define __BOX__H__
#include "MyOverlayWindow.h"
#include "Size.h"
#include "Point.h"

class MyOverlayWindow;

class Box : public Fl_Box {
public:
    static double percent;
    //Box(int X, int Y, int W, int H, const char *L) ; 
    Box(MyOverlayWindow *win,int x0,int y0,int x1,int y1,const char *L=0);
    Box(MyOverlayWindow *win,Point p1,Point p2, const char *L=0);
    Box(MyOverlayWindow *win, Point p1, Point p2,
        Size s1, Size s2, const char *L=0);

    void draw();

    static void OverlayCallback(void *data);
    void set_m_x0(int x) { this->m_x0 = x;};
    void set_m_y0(int y) { this->m_y0 = y;};
    void set_m_x1(int x) { this->m_x1 = x;};
    void set_m_y1(int y) { this->m_y1 = y;};
    int get_m_x0() {return this->m_x0;};
    int get_m_y0() {return this->m_y0;};
    int get_m_x1() {return this->m_x1;};
    int get_m_y1() {return this->m_y1;};
    Size get_start_size() {return this->start_size;};
    Size get_end_size() {return this->end_size;};
    static void move_box_cb(void *userdata);
    void set_start_size(Size s);
    void set_end_size(Size s);
    static void change_size(void *userdata);
    void set_size_animation(Size s1, Size s2);
    static void animate_size(void *userdata);

protected:
    int handle(int e);
private:
    MyOverlayWindow *oly;
    double m_x0;
    double m_y0;
    double m_x1;
    double m_y1;
    Size start_size;
    Size end_size;
};
#endif
