#include <iostream>
#include "input.h"
#include <stack>

using namespace std;

int main()
{
	stack<short int> s;
	long num=ReadValue<long>("Value to convert? ",0);

	cout << "Decimal Number: " << num << endl;

	while (num) {
		s.push(num % 2);
		num /= 2;
	}

	cout << "Binary Equivalent: ";
	while (s.size() > 0) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}