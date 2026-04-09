#pragma once

#include "Shape.h"



class Circle : public Shape {
    int m_x, m_y, m_r;

public:
    Circle();
    Circle(int x, int y, int r, COLOR color);
    ~Circle();

    virtual double area() const {
        return 3.14 * m_r * m_r;
    }

    virtual Shape* copy_() const {
        return new Circle(*this);
    }

    virtual bool operator==(const Shape& other) const {
        if (!Shape::operator==(other)) 
            return false;
        if (typeid(*this) != typeid(other))
            return false;
        const Circle& c = static_cast<const Circle&>(other);
        return m_x == c.m_x && m_y == c.m_y && m_r == c.m_r;
    }

    virtual void print(std::ostream& os) const {
        os << "Circle:  color=" << mass_color[m_color] << " area=" << area()
            << " cnt= (" << m_x << "," << m_y << ")  rd=" << m_r << "\n";
    }

    virtual void Inflate(int delta_rad);
};


