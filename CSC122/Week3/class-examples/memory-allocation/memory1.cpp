#include <iostream>
#include "input.h"

using namespace std;


int main()
{
	int* intPtr=nullptr;
	intPtr=new int;

	*intPtr=ReadValue<int>("Value? ");
	cout << " intPtr="<<intPtr<<endl;
	cout << "*intPtr="<<*intPtr<<endl;
	delete intPtr;

	return 0;
}