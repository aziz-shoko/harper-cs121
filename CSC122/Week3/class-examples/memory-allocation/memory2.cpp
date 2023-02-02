#include <iostream>
#include "input.h"

using namespace std;

void Input(int* array, int size);
void Display(int* array, int size);

void Input(int* array, int size)
{
	for (int* ptr=array; ptr<array+size; ptr++) {
		*ptr=ReadValue<int>("Value? ");
	}
}

void Display(int* array, int size)
{
	
	for (int* ptr=array; ptr<array+size; ptr++) {
		cout << *ptr << " ";
	}
	
	cout << endl;
}


int main()
{
	int* arrayPtr=nullptr;

	int x=ReadValue<int>("Size? ",0);
	arrayPtr=new int[x];
	if (arrayPtr==nullptr) {
		cerr << "Error!  Cannot allocate memory!\n";
	}

	else {
		Input(arrayPtr,x);
		Display(arrayPtr,x);
		delete[] arrayPtr;
	}

	return 0;
}