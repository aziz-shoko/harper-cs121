#include <iostream>

#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity 
{
	private:
		double scalar;
		double radians;

	public:
		void SetVelocity(double s, double r);
		double GetScalar();
		double GetRadians();
		Velocity();
};

#endif

std::istream& operator>> (std::istream& in, Velocity& v);
std::ostream& operator<< (std::ostream& out, Velocity& v);
Velocity operator+ (Velocity& x, Velocity& y);
Velocity operator- (Velocity& x, Velocity& y);