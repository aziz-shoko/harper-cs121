#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

class Circle
{
	private:
		double radius;

	public:
		Circle();
		bool SetRadius(double r);
		double GetRadius();
		double Area();
		double Circumference();
};

#endif

std::ostream& operator<< (std::ostream& out, Circle& c);
std::istream& operator>> (std::istream& in, Circle& c);
