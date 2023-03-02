#include <iostream>
#include <string>
#include "shape.h"

Shape::Shape()
{
        ;
}

std::string Shape::Name()
{
        return "Shape Object:";
}

double Shape::Volume()
{
        return 0.0;
}

double Shape::Area()
{
        return 0.0;
}

void Shape::Display(std::ostream& out)
{
        out << "Volume: ";
	out << Volume() << std::endl;
        out << "Surface Area: ";
	out << Area() << std::endl;
}

void Shape::Input()
{
        std::cout << "Input dimensions from Shape Class\n";
}

