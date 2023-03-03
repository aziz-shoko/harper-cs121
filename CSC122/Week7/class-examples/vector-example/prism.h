#include <iostream>
#include <string>
#include "shape2.h"

#ifndef PRISM_H
#define PRISM_H

class Prism: public Shape
{
	protected:
		double length,width,height;
	
	public:
		Prism();
		std::string Name();
		double Volume();
		double Area();
		double GetLength();
		double GetWidth();
		double GetHeight();
		bool SetLength(double length);
		bool SetWidth(double width);
		bool SetHeight(double height);
		void Display(std::ostream& out);
		void Input();
};

#endif
