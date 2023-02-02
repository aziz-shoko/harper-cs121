#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	istream_iterator<int> inputInt{cin};
	ostream_iterator<int> outputInt{cout};

	int x,y,z;

	x=*inputInt;
	cout << "x=";
	*outputInt=x;
	cout << endl;

	++inputInt;
	y=*inputInt;
	cout << "y=";
	*outputInt=y;
	cout << endl;

	++inputInt;
	z=*inputInt;
	cout << "z=";
	*outputInt=z;
	cout << endl;

	return 0;
}