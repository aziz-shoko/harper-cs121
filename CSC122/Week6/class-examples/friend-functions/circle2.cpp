#include <cmath>
#include <iostream>
#include "circle2.h"


Circle::Circle()
{
	radius=0.0;
}

bool Circle::SetRadius(double r)
{
	bool rv=false;
	if (r>=0.0) {
		radius=r;
		rv=true;
	}
	return rv;
}

double Circle::GetRadius()
{
	return radius;
}

double Circle::Area()
{
	return M_PI * pow(radius,2.0);
}

double Circle::Circumference()
{
	return 2.0 * M_PI*radius;
}

std::ostream& operator<< (std::ostream& out, Circle& c)
{
	out << "       Radius: " << c.radius << std::endl;
	out << "         Area: " << c.Area() << std::endl;
	out << "Circumference: " << c.Circumference() << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Circle& c) 
{
	double r=0.0;
	in >> r;
	if (! in.fail()) {
		if (! c.SetRadius(r))
		{
			throw ("Error Could not set radius!");
		}
	}
	return in;
}