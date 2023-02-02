#include <iostream>
#include <vector>
#include "input.h"

using namespace std;

void Display(vector<int>& x);
void Insert(vector<int>&, int position, int value);
void ReverseDisplay(vector<int>& x);

void Input(vector<int>& x)
{
	int size=ReadValue<int>("Number of values? ",0);
	x.resize(size);
	vector<int>::iterator itr;
	for (itr=x.begin(); itr != x.end(); itr++) {
		*itr=ReadValue<int>("Value? ");
	}
}

void Display(vector<int>& x)
{
	cout << "Displaying list: \n";
	vector<int>::iterator itr;
	for (itr=x.begin(); itr != x.end(); itr++) {
		cout << *itr;
		cout << " ";
	}
	cout << endl << endl;
}

void ReverseDisplay(vector<int>& x)
{
	cout << "Displaying list (reverse): \n";
	vector<int>::reverse_iterator itr;
	for (itr=x.rbegin(); itr != x.rend(); itr++) {
		cout << *itr;
		cout << " ";
	}
	cout << endl << endl;
}

int main()
{
	vector<int> list;
	Input(list);
	Display(list);
	ReverseDisplay(list);

	return 0;
}