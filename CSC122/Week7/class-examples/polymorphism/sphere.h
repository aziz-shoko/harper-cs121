#include <iostream>
#include <string>
#include "shape.h"

#ifndef SPHERE_H
#define SPHERE_H

class Sphere: public Shape
{
	protected:
		double radius;
	
	public:
		Sphere();
		std::string Name();
		double Volume();
		double Area();
		double GetRadius();
		bool SetRadius(double radius);
		void Display(std::ostream& out);
		void Input();
};

#endif
