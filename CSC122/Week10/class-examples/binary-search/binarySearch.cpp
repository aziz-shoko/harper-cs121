#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "input.h"

using namespace std;

ostream& operator << (ostream& out, vector<int> x);
void PopulateList(vector<int>& x);
int BinarySearch(vector<int>& list, int value, int left, int right);
int BinarySearch(vector<int>& list, int value);

ostream& operator << (ostream& out, vector<int> x)
{
	long len=x.size();
	for (long i=0;i<len;i++) {
		out << x[i] << " ";
	}
	out << endl;
	return out;
}

void PopulateList(vector<int>& x)
{
	int num=ReadValue<int>("Number of values? ");

	for (int i=0;i<num;i++) {
		x.push_back(rand() % 100 + 1);
	}
	sort(x.begin(),x.end());
	vector<int>::iterator newEnd=unique(x.begin(),x.end());
        x.erase(newEnd,x.end());
}

int BinarySearch(vector<int>& list, int value)
{
	if (list.empty())
		return -1;
	return BinarySearch(list,value,0,list.size()-1);
}

int BinarySearch(vector<int>& list, int value, int left, int right)
{
	if (left > right)
		return -1;

	int mid=(left+right)/2;
	if (list[mid]==value)
		return mid;

	else if (list[mid] > value)
		return BinarySearch(list,value,left,mid-1);
	
	else 
		return BinarySearch(list,value,mid+1,right);

	return -1;
}



int main()
{
	vector<int> values;
	srand(time(0));
	PopulateList(values);

	cout << values << endl;
	
	int searchValue=ReadValue<int>("Number to search for? ");
	int pos=BinarySearch(values,searchValue);
	if (pos > -1) 
		cout << "Value found at position " << pos << endl;
	else
		cout << "Value not found\n";
	

	return 0;
}