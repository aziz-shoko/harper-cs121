#include <iostream>
#include <cmath>
#include <string>
#include "input.h"
#include "sphere.h"

Sphere::Sphere()
{
	radius=0.0;
}

std::string Sphere::Name()
{
	return "Sphere";
}

double Sphere::Volume()
{
	return 4.0/3.0 * M_PI * pow(radius,3.0);
}

double Sphere::Area()
{
	return 4.0 * M_PI * pow(radius,2.0);
}

double Sphere::GetRadius()
{
	return radius;
}

bool Sphere::SetRadius(double radius)
{
	bool rv=false;
	if (radius >= 0.0) {
		this->radius=radius;
		rv=true;
	}
	return rv;
}

void Sphere::Display(std::ostream& out)
{
	out << Name() << std::endl;
	out << "Radius: " << radius << std::endl;
	out << "Volume: " << Volume() << std::endl;
	out << "  Area: " << Area() << std::endl;
}

void Sphere::Input()
{
	double r=ReadValue<double>("Enter radius: ",0.0);
	while (! SetRadius(r))
	{
		std::cerr << "Error setting radius!\n";
		double r=ReadValue<double>("Enter radius: ",0.0);
	}
}