#ifndef __SIZE__
#define __SIZE__

class Size 
{
    int m_w;
    int m_h;
public:
    Size(int w = 0,int h = 0) : m_w(w),m_h(h)
    {
    }
    Size(const Size &s)
        :m_w(s.m_w) , m_h(s.m_h)
    {
    }
    Size& operator= (const Size &s)
    {
        this->m_w = s.m_w;
        this->m_h = s.m_h;
        return *this;
    }
    void w(int w) { this->m_w = w;}
    void h(int h) { this->m_h = h;}
    int  w()      { return m_w;}
    int  h()      { return m_h;}

};

#endif
