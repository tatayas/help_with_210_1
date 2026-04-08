#pragma once

#include <iostream>
#include <typeinfo> 

class Shape {
public:
    
    enum COLOR {BLACK, WHITE, RED, BLUE};

protected:
    COLOR m_color; 

public:
    // Конструкторы
    Shape() : m_color(BLACK) {}
    Shape(COLOR color) : m_color(color) {}

    //вирт.деструктор
    virtual ~Shape() {}

    //чисто вирт.функции 
    virtual double area() const = 0;   
    virtual Shape* copy_() const = 0; 
    virtual void print(std::ostream& os) const = 0; 
    virtual void Inflate(int x) = 0;  

    COLOR Color_get() const 
        { return m_color; }

    // Вирт. оператор == 
    virtual bool operator==(const Shape& other) const {
        if (typeid(*this) != typeid(other)) return false;
        return m_color == other.m_color;
    }

    friend std::ostream& operator<<(std::ostream& os, const Shape& s) {
        s.print(os);
        return os;
    }
};

