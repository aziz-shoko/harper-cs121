#include <iostream>
#include "input.h"
#include "stack.h"

using namespace std;

int main()
{
	Stack s;
	long num=ReadValue<long>("Value to convert? ",0);

	cout << "Decimal Number: " << num << endl;

	while (num) {
		s.Push(num % 2);
		num /= 2;
	}

	cout << "Binary Equivalent: ";
	while (s.Size() > 0) {
		cout << s.Pop();
	}
	cout << endl;
	return 0;
}