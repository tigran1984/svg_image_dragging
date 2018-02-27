#include"Box.h"
#include"MyOverlayWindow.h"
//Box::Box(int X, int Y, int W, int H, const char *L=0) : Fl_Box(X,Y,W,H,L) {
//        label("hellooo");
//        Fl_Help_View html(10,10,30,40, "html text");
//        html.value("hi HTML");
//        box(FL_ROUNDED_BOX);
//        color(FL_WHITE);
//    }
Box::Box(MyOverlayWindow *win,int x0,int y0,int x1,int y1, const char *L)
        :Fl_Box(x0,y0,600,600,L), m_x0(x0),m_y0(y0),m_x1(x1),m_y1(y1)

    {
    oly = win;
    //win->AddOverlayCallback(OverlayCallback, (void*)this);
    win->AddOverlayCallback(move_box_cb , (void*)this);
    //win->AddOverlayCallback(change_size , (void*)this);
    win->add_to_box_vector(this);
    label("Some Text ");
    box(FL_ROUNDED_BOX);
    color(FL_WHITE);
    oly->AddOverlayCallback(OverlayCallback, (void*)this);
    start_size = Size(100,100);
    end_size = Size(200,200);
    //end();
}

Box::Box(MyOverlayWindow *win,Point p1,Point p2, const char *L)
        :Fl_Box(p1.x(),p1.y(),100,100,L),
         m_x0(p1.x()),m_y0(p1.y()),m_x1(p2.x()),m_y1(p2.y())

    {
    oly = win;
    //win->AddOverlayCallback(OverlayCallback, (void*)this);
    win->AddOverlayCallback(move_box_cb , (void*)this);
    //win->AddOverlayCallback(change_size , (void*)this);
    win->add_to_box_vector(this);
    label(L);
    box(FL_ROUNDED_BOX);
    color(FL_WHITE);
    //oly->AddOverlayCallback(OverlayCallback, (void*)this);
    start_size = Size(100,100);
    end_size = Size(200,200);
    //end();
}

Box::Box(MyOverlayWindow *win, Point p1, Point p2,
        Size s1, Size s2, const char *L)
        :Fl_Box(p1.x(),p1.y(),100,100,L),
         m_x0(p1.x()),m_y0(p1.y()),m_x1(p2.x()),m_y1(p2.y()),
         start_size(s1), end_size(s2)

    {
    oly = win;
    //win->AddOverlayCallback(OverlayCallback, (void*)this);
    win->AddOverlayCallback(move_box_cb , (void*)this);
    win->AddOverlayCallback(animate_size , (void*)this);
    //win->AddOverlayCallback(change_size , (void*)this);
    win->add_to_box_vector(this);
    //label("Some Text ");
    box(FL_ROUNDED_BOX);
    color(FL_WHITE);
    label("some text");
    //oly->AddOverlayCallback(OverlayCallback, (void*)this);
    //end();
}


void Box::draw() {
    Fl_Box::draw();
    oly->redraw_overlay();          // tell parent to redraw child overlays
}

int Box::handle(int e) {
    static int offset[2] = { 0, 0 };
    int ret = Fl_Box::handle(e);
    switch ( e ) {
        case FL_PUSH:
            offset[0] = x() - Fl::event_x(); 
            // save where user clicked for dragging
            offset[1] = y() - Fl::event_y();
            return(1);
        case FL_RELEASE:
            return(1);
        case FL_DRAG:
            this->m_x0 = offset[0]+Fl::event_x();
            this->m_y0 = offset[1]+Fl::event_y();
            position(offset[0]+Fl::event_x(), offset[1]+Fl::event_y());
            // handle dragging
            //G_win->redraw();
            oly->redraw_overlay();  
            redraw();
            return(1);
    }
    return(ret);
}

// DRAW THE OVERLAY GRAPHIC FOR THIS INSTANCE OF CHILD
void Box::OverlayCallback(void *data) {
     Box *o = (Box *)data;
    ////o->Fl_Help_View html(10,10,30,40, "html text");
    ////o->html.value("hi HTML");
    //o->box(FL_ROUNDED_BOX);
    o->redraw();
}

void Box::move_box_cb(void *userdata) {
    Box *o = (Box *)userdata;
    //o->redraw();
    //Fl::repeat_timeout(0.25, move_box_cb, userdata);
    //for(int i=0; i < 360; i++){
    //    Fl::add_timeout(0.25, Timer_CB, userdata);
    //}
    double x = o->m_x0 + Box::percent * (o->m_x1 - o->m_x0);
    double y = o->m_y0 + Box::percent * (o->m_y1 - o->m_y0);
    o->position(x, y);
    o->redraw();
}

void Box::change_size(void *userdata)
{
    Box *o = (Box *)userdata;
    double w = o->start_size.w() + Box::percent *
        (o->end_size.w() - o->start_size.w());
    double h = o->start_size.h() + Box::percent *
        (o->end_size.h() - o->start_size.h());
    o->size(w, h);
    o->redraw();
}

void Box::set_start_size(Size s)
{
    start_size = s;
}

void Box::set_end_size(Size s)
{
    end_size = Size(s);
}

void Box::set_size_animation(Size s1, Size s2)
{
    start_size = s1;
    end_size   = s2;
    oly->AddOverlayCallback(animate_size, (void*)this);
}

void Box::animate_size(void *userdata)
{
    Box *o = (Box *)userdata;
    double w = o->start_size.w() + Box::percent *
        (o->end_size.w() - o->start_size.w());
    double h = o->start_size.h() + Box::percent *
        (o->end_size.h() - o->start_size.h());
    o->size(w, h);
    o->redraw();
}
