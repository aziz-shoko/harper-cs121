#include <iostream>
#include "list3.h"

using namespace std;


int main()
{
	try {
		List l1;
		l1.Input();
		cout << "\nl1 Contents\n";
		l1.Display();

		List l2=l1;

		cout << "\nl2 Contents\n";
		l2.Display();

		l1.SetValue(1000.0,0);

		cout << "\nl1 Contents\n";
		l1.Display();
		cout << "\nl2 Contents\n";
		l2.Display();
	}
	catch (const char* s) {
		cerr << s << endl;
	}
	return 0;
}