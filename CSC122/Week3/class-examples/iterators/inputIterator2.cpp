#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	cout << "Enter an integer: ";
	istream_iterator<int> inputInt{cin};

	int x,y,z;

	x=*inputInt;
	cout << "x=" << x << endl;

	inputInt++;
	y=*inputInt;
	cout << "y=" << y << endl;

	inputInt++;
	z=*inputInt;
	cout << "z=" << z << endl;

	return 0;
}