#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

class Circle
{
	protected:
		double radius;

	public:
		Circle();
		bool SetRadius(double r);
		double GetRadius();
		double Area();
		double Circumference();

		friend std::ostream& operator<< (std::ostream& out, Circle& c);
		friend std::istream& operator>> (std::istream& in, Circle& c);
};

#endif

