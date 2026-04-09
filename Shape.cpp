#include "Shape.h"
#include <iostream>

//конструктор по умолчанию
//Shape::Shape() : m_color(WHITE)
//{
//    std::cout << "Default constructor BC (Shape)" << std::endl;
//}

//конструктор с параметром
//Shape::Shape(COLOR color) : m_color(color) {}

//вирт.деструктор
//Shape::~Shape() {}


//Shape::COLOR Shape::Color_get() const
//{
//    return m_color;
//}

//оператора сравнения 
//bool Shape::operator==(const Shape& other) const
//{
//    if (typeid(*this) != typeid(other))
//    {return false;}
//    return m_color == other.m_color;
//}

/*
void Shape::WhereAmI() const
{
    std::cout << "Now I am in class Shape" << std::endl;
}

void Shape::WhereAmIVirtual() const
{
    std::cout << "Now I am in class Shape (virtual)" << std::endl;
}
*/

//std::ostream& operator<<(std::ostream& os, const Shape& s)
//{
//    s.print(os);
//    return os;
//}