#include <iostream>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Overlay_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Help_View.H>
#include <FL/fl_draw.H>
#include "Box.h"
#include "MyOverlayWindow.h"
class Box;
using namespace std;
#define BOXWIDTH  160
#define BOXHEIGHT 100
//typedef void (OverlayCallback)(void*);
//class Box;
MyOverlayWindow::MyOverlayWindow(int W,int H,
        const char *L):Fl_Overlay_Window(W,H,L) 
{
}
// SETUP AN OVERLAY DRAWING CALLBACK
    //     Called by child widgets to arrange callback to draw into overlay plane.
    //
void MyOverlayWindow::AddOverlayCallback(OverlayCallback *cb, void *data) {
    oly_callbacks.push_back(cb);        // add callback to array
    oly_data.push_back(data);           // add userdata to array
}
// INVOKE CHILDREN'S CALLBACKS TO DRAW OVERLAYS
void MyOverlayWindow::draw_overlay() {
    // Invoke all the children's overlay callbacks
    for ( unsigned int t=0; t<oly_callbacks.size(); t++ ) {
        (*oly_callbacks[t])(oly_data[t]);
    }
    //int x=items[0]->x();
    //fl_line(items[0]->x(),items[0]->y(),items[1]->x(),items[1]->y());
}
void MyOverlayWindow::add_item(Box * b)
{
    items.push_back(b);
}

void MyOverlayWindow::goto_start_position()
{
    for(int i = 0; i < items.size(); i++) {
        int x = items[i]->get_m_x0();
        int y = items[i]->get_m_y0();
        Size start_s = items[i]->get_start_size();
        int w = start_s.w();
        int h = start_s.h();
        items[i]->position(x,y);
        items[i]->size(w,h);
    }
}

void MyOverlayWindow::add_to_box_vector(Box *b)
{
    items.push_back(b);
}
