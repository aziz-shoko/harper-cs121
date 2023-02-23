#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "circle2.h"

class Sphere: private Circle
{
	public:
		double Volume();
		double SurfaceArea();

		friend std::ostream& operator<< (std::ostream& out, Sphere& s);
};

#endif