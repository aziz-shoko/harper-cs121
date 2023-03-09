#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void Display(string header,vector<int>& l);

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
	vector<int> list1(10);
	fill(list1.begin(),list1.end(),-1);
	Display("list1:",list1);
	fill_n(list1.begin()+3,5,0);
	Display("list1 after fill_n:",list1);

	vector<int> list2(5);
	copy(list1.begin(), list1.begin()+5, list2.begin());
	Display("list2 after copy:",list2);
	Display("list1 after copy:",list1);

	vector<int>::iterator newEnd;
	newEnd=remove(list1.begin(),list1.end(),0);
	Display("list1 after removing 0 before delete:",list1);
	list1.erase(newEnd,list1.end());
	Display("list1 after removing 0:",list1);

	replace(list1.begin(),list1.end(),-1,0);
	Display("list1 after replaceing -1 with 0:",list1);

	return 0;
}