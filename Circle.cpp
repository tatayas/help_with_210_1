#include "Circle.h"
#include <iostream>

//конструктор по умолчанию
Circle::Circle() {
    m_x = 0; 
    m_y = 0; 
    m_r = 5;
    m_color = WHITE;
    //std::cout << "Constructor without parameters PC(circle)" << std::endl;
}

//конструктор с параметрами
Circle::Circle(int x, int y, int r, COLOR color) : Shape(color) {
    m_x = x; m_y = y; m_r = r;
    //std::cout << "Constructor with parameters PC (circle)" << std::endl;
}

//деструктор
Circle::~Circle() {
    //std::cout << "Now I am in Circle's destructor" << std::endl;
}

// чисто вирт.функция 
void Circle::Inflate(int delta_rad) {
    m_r += delta_rad;
    if (m_r < 0) m_r = 0;
}

/*
void Circle::WhereAmI() const { std::cout << "Now I am in class Circle" << std::endl; }
void Circle::WhereAmIVirtual() const { std::cout << "Now I am in class Circle (virtual)" << std::endl; }

// Геттеры
int Circle::getX() const { return m_x; }
int Circle::getY() const { return m_y; }
int Circle::getR() const { return m_r; } */