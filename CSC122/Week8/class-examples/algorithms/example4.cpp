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
        return dre() % 50 + 1;
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

	int num=0;
	cout << "Enter number to find: ";
	cin >> num;

	vector<int>::iterator numFound=find(list1.begin(),list1.end(),num);
	if (numFound != list1.end()) {
		cout << "Number found at position " << distance(list1.begin(),numFound) << "!\n\n";
	}
	else {
		cout << "Number not found!\n\n";
	}

	sort(list1.begin(),list1.end());
	Display("list1 after sorting: ", list1);

	cout << "Enter number to find: ";
	cin >> num;

	if (binary_search(list1.begin(),list1.end(),num)) {
		cout << "Number found!\n\n";
	}
	else {
		cout << "Number not found!\n\n";
	}

	vector<int>::iterator newEnd=unique(list1.begin(),list1.end());
	Display("List with only unique values before erase:",list1);
	cout << "Duplicate values begin at position " << distance(list1.begin(),newEnd) << endl;
	list1.erase(newEnd,list1.end());
	Display("List with only unique values:",list1);

	return 0;
}