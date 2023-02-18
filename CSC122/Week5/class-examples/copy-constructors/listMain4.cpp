#include <iostream>
#include "list2.h"

using namespace std;

void Display(List x)
{
	x.Display();
}


int main()
{
	try {
		List l1;
		l1.Input();

		Display(l1);
	}
	catch (const char* s) {
		cerr << s << endl;
	}
	return 0;
}