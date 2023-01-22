#include <iostream>
#include "input.h"

using namespace std;

int main()
{
	double x=ReadValue<double>("Enter a value: ");
	cout << "Value is: " << x << endl;
	cout <<"\n\n\n";

	x=ReadValue<double>("Enter a value greater than 0: ",0.0);
	cout << "Value is: " << x << endl;
	cout <<"\n\n\n";
	
	x=ReadValue<double>("Enter a value between 1 and 100: ",1.0,100.0);
	cout << "Value is: " << x << endl;

	return 0;
}