#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

void Display(string header,vector<int>& l);
int Sequence();

int Sequence()
{
	static int value=0;
	return value++;
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
	vector<int> list1(15);
	generate(list1.begin(),list1.end(),Sequence);
	Display("list1 after generate:",list1);
	
	default_random_engine randGen;
	cout << "Generate random numbers between " << randGen.min() << " and " << randGen.max() << endl;
	randGen.seed(time(0));
	shuffle(list1.begin(),list1.end(),randGen);
	Display("list1 after shuffling:",list1);

	return 0;
}