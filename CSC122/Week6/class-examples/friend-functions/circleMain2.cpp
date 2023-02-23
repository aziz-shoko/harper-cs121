#include <iostream>
#include "circle2.h"

using namespace std;

int main()
{
	Circle c;
	try {
		cout << "Enter radius: ";
		cin >> c;
		if (! cin.fail()) {
			cout << c;
		}
		else {
			cerr << "Error reading in circle!\n";
		}
	}

	catch (const char* e) {
                cerr << e << endl;
        }
	return 0;
}