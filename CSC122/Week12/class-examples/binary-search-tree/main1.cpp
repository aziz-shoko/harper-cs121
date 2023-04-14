#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tree.h"

using namespace std;

int main()
{
	Tree t;
	srand(time(0));
	for (int i=0; i< 30; i++) {
		long value=rand() % 100 + 1;
		if (!t.Exists(value)) 
			cout << "Adding value " << value << endl;
			if (!t.AddValue(value)) {
				cerr << "Error! Unable to add value to tree!\n";
			}
	}
	cout << t << endl;
	return 0;
}