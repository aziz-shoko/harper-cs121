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

	y=*inputInt;
	cout << "y=" << y << endl;

	z=*inputInt;
	cout << "z=" << z << endl;

	return 0;
}