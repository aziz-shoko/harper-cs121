#include <iostream>
#include <cmath>
#include "sphere2.h"

double Sphere::Volume()
{
	return 4.0/3.0 * M_PI * pow(radius,3.0);
}

double Sphere::SurfaceArea()
{
	return 4.0 * M_PI * pow(radius,2.0);
}

std::ostream& operator<< (std::ostream& out, Sphere& s)
{
        out << "       Radius: " << s.radius << std::endl;
        out << "       Volume: " << s.Volume() << std::endl;
        out << "      Surface: " << s.SurfaceArea() << std::endl;
        return out;
}
