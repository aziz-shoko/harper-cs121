#include <iostream>
#include "velocity.h"

using namespace std;

int main()
{
	Velocity v1,v2;
	cout << "Angle 1\n";
	cin >> v1;

	cout << "Angle 2\n";
	cin >> v2;

	cout << "Angle 1\n";
	cout << v1 << endl;

	cout << "Angle 2\n";
	cout << v2 << endl;

	cout << "Addition\n";
	Velocity add=v1+v2;
	cout << add;

	cout << "Subtraction\n";
	Velocity diff=v1-v2;
	cout << diff;

	return 0;
}