#include <iostream>
#include <cmath>
#include <string>
#include "input.h"
#include "prism.h"

Prism::Prism()
{
	length=0.0;
	width=0.0;
	height=0.0;
}

std::string Prism::Name()
{
	return "Prism";
}

double Prism::Volume()
{
	return length*width*height;
}

double Prism::Area()
{
	return 2.0*(length*width + length*height + width*height);
}

double Prism::GetLength()
{
	return length;
}

double Prism::GetWidth()
{
	return width;
}

double Prism::GetHeight()
{
	return height;
}

bool Prism::SetHeight(double height)
{
	bool rv=false;
	if (height >= 0.0) {
		this->height=height;
		rv=true;
	}
	return rv;
}

bool Prism::SetWidth(double width)
{
	bool rv=false;
	if (width >= 0.0) {
		this->width=width;
		rv=true;
	}
	return rv;
}

bool Prism::SetLength(double length)
{
	bool rv=false;
	if (length >= 0.0) {
		this->length=length;
		rv=true;
	}
	return rv;
}

void Prism::Display(std::ostream& out)
{
	out << Name() << std::endl;
	out << "Length: " << length << std::endl;
	out << "Width: " << width << std::endl;
	out << "Height: " << height << std::endl;
	out << "Volume: " << Volume() << std::endl;
	out << "  Area: " << Area() << std::endl;
}

void Prism::Input()
{
	length=ReadValue<double>("Enter length: ",0.0);
	width=ReadValue<double>("Enter width: ",0.0);
	height=ReadValue<double>("Enter height: ",0.0);
}