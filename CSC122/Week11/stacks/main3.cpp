#include <iostream>
#include "stack.h"

using namespace std;


int main()
{
	Stack s;
	s.Push(10);
	s.Push(20);
	s.Push(30);
	s.Push(40);
	cout << s;
	cout << endl;

	cout << "Pop: " << s.Pop() << endl;
	cout << "Pop: " << s.Pop() << endl;
	cout << s;
	cout << endl;

	return 0;
}
