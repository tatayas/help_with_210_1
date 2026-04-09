#include "Rect.h"
#include <iostream>

// Конструктор по умолчанию
Rect::Rect() {
    m_left = 0; m_top = 0; m_right = 0; m_bottom = 0;
    m_color = BLACK;
    //std::cout << "Constructor without parameters PC(rect)" << std::endl;
}

// Конструктор с параметрами
Rect::Rect(int left, int top, int right, int bottom, COLOR color) : Shape(color) {
    m_left = left; m_top = top; m_right = right; m_bottom = bottom;
    StupidUser(); // Исправляем координаты, если пользователь ошибся
    //std::cout << "Constructor with parameters PC (rect)" << std::endl;
}

// Конструктор копирования (нужен для clone())
Rect::Rect(const Rect& other) : Shape(other) {
    m_left = other.m_left;
    m_top = other.m_top;
    m_right = other.m_right;
    m_bottom = other.m_bottom;
    //std::cout << "Copy constructor Rect" << std::endl;
}

// Деструктор
Rect::~Rect() {
   // std::cout << "Now I am in Rect's destructor" << std::endl;
}

// Нормализация координат (чтобы лево было левее права)
void Rect::StupidUser() {
    if (m_left > m_right) { int x = m_right; m_right = m_left; m_left = x; }
    if (m_top > m_bottom) { int x = m_bottom; m_bottom = m_top; m_top = x; }
}

// Реализация чисто виртуальной функции из Shape
// Мы просто вызываем твой старый метод раздувания
void Rect::Inflate(int delta) {
    m_left -= delta;
    m_top -= delta;
    m_right += delta;
    m_bottom += delta;
    StupidUser();
    //std::cout << "Rect Inflate completed" << std::endl;
}

// Твои старые методы (оставляем для совместимости)
//void Rect::WhereAmI() const { std::cout << "Now I am in class Rect" << std::endl; }
//void Rect::WhereAmIVirtual() const { std::cout << "Now I am in class Rect (virtual)" << std::endl; }

// Геттеры
//int Rect::getLeft() const { return m_left; }
//int Rect::getTop() const { return m_top; }
//int Rect::getRight() const { return m_right; }
//int Rect::getBottom() const { return m_bottom; }
