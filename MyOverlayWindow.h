#ifndef __MYOVERLAYWINDOW__
#define __MYOVERLAYWINDOW__
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
#include"Size.h"
class Box;
using namespace std;
typedef void (OverlayCallback)(void*);
//class Box;
class MyOverlayWindow : public Fl_Overlay_Window {
    vector<OverlayCallback*> oly_callbacks;    // array of child callbacks to draw overlays
    vector<void*> oly_data;                    // array of child userdata
    vector<Box*> items;
public:
    MyOverlayWindow(int W,int H,const char *L=0);
    void AddOverlayCallback(OverlayCallback *cb, void *data) ;
    void draw_overlay() ;
    void add_item(Box * );
    void goto_start_position();
    void add_to_box_vector(Box* b);
};
#endif
