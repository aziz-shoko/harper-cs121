#include <iostream>
#include "list.h"

using namespace std;


int main()
{
	try {
		List l;
		l.Input();
		l.Display();
	}
	catch (const char* s) {
		cerr << s << endl;
	}
	return 0;
}