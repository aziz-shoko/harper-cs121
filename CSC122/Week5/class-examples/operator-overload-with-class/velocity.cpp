#include <iostream>
#include <string>
#include <cmath>
#include "velocity.h"

using namespace std;

Velocity::Velocity()
{
	scalar=0.0;
	radians=0.0;
}

double Velocity::GetScalar()
{
	return scalar;
}

double Velocity::GetRadians()
{
	return radians;
}

void Velocity::SetVelocity(double s, double r)
{
	scalar=s;
	radians=r;
}


istream& operator>> (istream& in, Velocity& v)
{
	double scalar, degrees;
	cout << "Enter scalar value: ";
	cin >> scalar;
	cout << "Enter angle in degrees: ";
	cin >> degrees;
	v.SetVelocity(scalar, degrees*M_PI/180.0);
	return in;
}

ostream& operator<< (ostream& out, Velocity& v)
{
	out << " Scalar: " << v.GetScalar() << endl;
	out << "Degrees: " << v.GetRadians()*180.0/M_PI << endl;
	out << "Radians: " << v.GetRadians() << endl;
	return out;
}

Velocity operator+ (Velocity& x, Velocity& y) 
{
	Velocity result;
	double rx=x.GetScalar()*cos(x.GetRadians()) + y.GetScalar()*cos(y.GetRadians());
	double ry=x.GetScalar()*sin(x.GetRadians()) + y.GetScalar()*sin(y.GetRadians());
	double scalar=sqrt(pow(rx,2.0)+pow(ry,2.0));
	double radians=atan2(ry,rx);

	result.SetVelocity(scalar,radians);
	return result;
}

Velocity operator- (Velocity& x, Velocity& y) 
{
	Velocity result;
	double rx=x.GetScalar()*cos(x.GetRadians()) - y.GetScalar()*cos(y.GetRadians());
	double ry=x.GetScalar()*sin(x.GetRadians()) - y.GetScalar()*sin(y.GetRadians());
	double scalar=sqrt(pow(rx,2.0)+pow(ry,2.0));
	double radians=atan2(ry,rx);

	result.SetVelocity(scalar,radians);
	return result;
}
