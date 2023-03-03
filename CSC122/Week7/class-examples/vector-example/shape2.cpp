#include <iostream>
#include <string>
#include "shape2.h"

Shape::Shape()
{
        ;
}

std::string Shape::Name()
{
        return "Shape Object:";
}

void Shape::Display(std::ostream& out)
{
    out << "Volume: ";
	out << Volume() << std::endl;
    out << "Surface Area: ";
	out << Area() << std::endl;
}
