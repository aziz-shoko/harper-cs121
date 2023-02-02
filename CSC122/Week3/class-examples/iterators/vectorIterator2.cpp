#include <iostream>
#include <vector>
#include "input.h"

using namespace std;

void Input(vector<int>& x);
void Display(vector<int>& x);
void ReverseDisplay(vector<int>& x);

void Insert(vector<int>&, int position, int value);
void Delete(vector<int>& x, int position);

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

void Insert(vector<int>& list, int position, int value) 
{
	vector<int>::iterator itr=list.begin();
	list.insert(itr+position,value);
}

void Delete(vector<int>& list, int position)
{
	//vector<int>::iterator itr=list.begin();
	//list.erase(itr+position);
	list.erase(list.begin()+position);
}

void Delete(vector<int>& list, int start, int end)
{
	//deletes [start,end)
	vector<int>::iterator itr=list.begin();
	list.erase(itr+start,itr+end);
}

int main()
{
	vector<int> list1;
	Input(list1);
	Display(list1);

	int x=ReadValue<int>("Value to insert? ");
	int pos=ReadValue<int>("Position to insert? ");
	Insert(list1,pos,x);
	Display(list1);

	pos=ReadValue<int>("Position to delete? ");
	Delete(list1,pos);
	Display(list1);

	int start=ReadValue<int>("Starting position to delete? ");
	int end=ReadValue<int>("Ending position to delete? ");
	Delete(list1,start,end);
	Display(list1);


	return 0;
}