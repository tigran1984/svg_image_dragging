#ifndef __POINT__
#define __POINT__
class Point 
{
    int m_x;
    int m_y;
public:
    Point(int x = 0,int y = 0) : m_x(x),m_y(y)
    {
    }
    void x(int x) { this->m_x = x;}
    void y(int y) { this->m_y = y;}
    int  x()      { return m_x;}
    int  y()      { return m_y;}

};

#endif
