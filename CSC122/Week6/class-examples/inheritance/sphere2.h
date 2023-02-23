#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "circle2.h" // located in ingeritance file

class Sphere: public Circle
{
	public:
		double Volume();
		double SurfaceArea();

		friend std::ostream& operator<< (std::ostream& out, Sphere& s);
};

#endif