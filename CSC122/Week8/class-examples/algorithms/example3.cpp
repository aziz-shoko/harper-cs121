#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

void Display(string header,vector<int>& l);
int Random();

default_random_engine dre;

int Random()
{
	return dre() % 20 + 1;
}

void Display(string header,vector<int>& l)
{
	cout << header << endl;
	for (vector<int>::iterator x=l.begin(); x!=l.end(); x++) { 
		cout << *x << ' ';
	}
	cout << endl << endl;
}

int main()
{
	vector<int> list1(30);
	dre.seed(time(0));

	generate(list1.begin(),list1.end(),Random);
	Display("list1 after generate:",list1);

	cout << "The number 5 appears " << count(list1.begin(),list1.end(),5) << " times\n";
	cout << "The number 7 appears " << count(list1.begin(),list1.end(),7) << " times\n";

	vector<int>::iterator max,min;
	max=max_element(list1.begin(),list1.end());
	min=min_element(list1.begin(),list1.end());
	
	cout << "The max value is " << *max << endl;
	cout << "The min value is " << *min << endl;
	cout << "The max value appears at position " << distance(list1.begin(),max) << endl;
	cout << "The min value appears at position " << distance(list1.begin(),min) << endl;

	sort(list1.begin(),list1.end());
	Display("list1 after sorting: ", list1);
	
	return 0;
}