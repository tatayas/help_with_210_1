#pragma once

#include "Shape.h"

class Rect : public Shape {
    int m_left, m_top, m_right, m_bottom;

public:
    Rect();
    Rect(int left, int top, int right, int bottom, COLOR color);
    Rect(const Rect& other);
    ~Rect();

    virtual double area() const {
        double w = (m_right > m_left) ? (m_right - m_left) : (m_left - m_right);
        double h = (m_bottom > m_top) ? (m_bottom - m_top) : (m_top - m_bottom);
        return (w * h);
    }

    virtual Shape* copy_() const {
        return new Rect(*this);
    }

    // вирт.оператор ==
    virtual bool operator==(const Shape& other) const {
        if (!Shape::operator==(other)) 
            return false;
        const Rect& r = static_cast<const Rect&>(other);
        return m_left == r.m_left && m_top == r.m_top &&
            m_right == r.m_right && m_bottom == r.m_bottom;
    }

    virtual void print(std::ostream& os) const {
        os << "Rect: \n color=" << mass_color[m_color] << "\n area: " << area()
            << "\n l=" << m_left << "\n t=" << m_top << "\n r=" << m_right << "\n b=" << m_bottom << "\n";
    }

    virtual void Inflate(int delta_hor);
    void StupidUser(); 
};


