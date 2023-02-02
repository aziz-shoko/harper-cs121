#include <iostream>
#include <vector>
#include "input.h"

using namespace std;

void Display(vector<int>& x);
void Insert(vector<int>&, int position, int value);
void ReverseDisplay(vector<int>& x);
void Insert(vector<int>& target, vector<int>& source, int pos, int start, int end);

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

void Insert(vector<int>& target, vector<int>& source, int pos, int start, int end)
{
	target.insert(target.begin()+pos, source.begin()+start, source.begin()+end);
}

int main()
{
	vector<int> list1;
	vector<int> list2;
	cout << "Enter the target vector.\n";
	Input(list1);
	cout << "Enter the source vector.\n";
	Input(list2);
	Display(list1);
	Display(list2);
	int pos=ReadValue<int>("Starting position (list1)? ");
	int start=ReadValue<int>("Starting position (list2)? ");
	int end=ReadValue<int>("Ending position (list2)? ");
	Insert(list1,list2,pos,start,end);
	Display(list1);

	return 0;
}