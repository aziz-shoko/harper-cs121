#include <iostream>

using namespace std;

int main()
{
	int value=100;
	int* valuePtr=nullptr;

	cout << "    value: " << value << endl;
	cout << " valuePtr: " << valuePtr << endl;

	valuePtr=&value;
	*valuePtr=200;

	cout << "    value: " << value << endl;
	cout << " valuePtr: " << valuePtr << endl;
	cout << "*valuePtr: " << *valuePtr << endl;

	return 0;
}