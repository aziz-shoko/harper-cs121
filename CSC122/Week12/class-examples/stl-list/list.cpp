#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "input.h"

using namespace std;

void Output(list<long>& l);

void Output(list<long>& l)
{
	cout << "List size: " << l.size() << endl;
	cout << "Forward:\n";
	for (auto itr=l.begin(); itr != l.end(); itr++) 
		cout << *itr << " ";
	cout << "\n";

	cout << "Backward:\n";
	for (auto itr=l.rbegin(); itr != l.rend(); itr++) 
		cout << *itr << " ";

	cout << "\n\n";
}

int main()
{
	list<long> values;
	srand(time(0));

	int count=ReadValue<int>("How many values do you wish to generate? ",0);
	for (int i=0; i<count; i++) 
		values.push_back(rand()%1000+1);

	Output(values);

	count=ReadValue<int>("How many values do you wish to add to front? ",0);
	for (int i=0; i<count; i++) 
		values.push_front(rand()%1000+1);

	Output(values);

	cout << "Sorting values:\n";
	values.sort();
	Output(values);

	cout << "Poppling front and back:\n";
	values.pop_front();
	values.pop_back();
	Output(values);

	return 0;
}