#include <iostream>
#include "linkedlist.h"

using namespace std;


int main()
{
	List l;
	cout << "Adding 10 to 0\n";
	l.AddValue(10,0);
	cout << l;
	cout << endl;
	
	cout << "Adding 20 to 1\n";
	l.AddValue(20,1);
	cout << l;
	cout << endl;
	
	cout << "Adding 30 to 2\n";
	l.AddValue(30,2);
	cout << l;
	cout << endl;

	cout << "Adding 40 to 3\n";
	l.AddValue(40,3);
	cout << l;
	cout << endl;

	cout << "Adding 50 to 0\n";
	l.AddValue(50,0);
	cout << l;
	cout << endl;

	cout << "Adding 60 to 2\n";
	l.AddValue(60,2);
	cout << l;
	cout << endl;

	return 0;
}
