#include <iostream>
#include <exception>
#include <algorithm>
#include "input.h"
using namespace std;

class List
{
	private:
		double* data;
		long size;

	public:
		enum {MAX_SIZE=1000};
		
		// void SetValue(double value, long pos);
		// double GetValue(long pos);
		void Resize(long numValues);
		void Clear();
		void Input();
		void Display();
        double Average();
        double Medium();
		List();
		~List();
};

void List::Clear()
{
	if (size > 0) {
		delete[] data;
		size=0;
		data=nullptr;
	}
}

void List::Resize(long numValues)
{
	try {
		if (numValues < 1 || numValues > MAX_SIZE) {
			throw "Error! Invalid list size specified.";
		}
		Clear();
		data=new double[numValues];
		if (data==nullptr) {
			throw "Error! Could not allocate memory for list.";
		}
		size=numValues;
	}
	catch (exception& e) {
		throw "Error! Could not allocate memory for list.";
	}
}

// void List::SetValue(double value, long pos)
// {
// 	if (pos < 0 || pos >= size) {
// 		throw "Error! Invalid position in list specified.";
// 	}
// 	data[pos]=value;
// }

// double List::GetValue(long pos)
// {
// 	if (pos < 0 || pos >= size) {
// 		throw "Error! Invalid position in list specified.";
// 	}
// 	return data[pos];
// }

void List::Input()
{
	try {
		if (size==0) {
			long x=ReadValue<long>("Number of values? ");
			Resize(x);
		}
	
		for (double *ptr=data; ptr<data+size; ptr++) {
			*ptr=ReadValue<double>("Value? ");
		}
	}
	catch (const char* s) {
		throw s;
	}

	
}

void List::Display() 
{
	if (size > 0) {
		cout << "List values:\n";
		for (double *ptr=data; ptr<data+size; ptr++) {
			cout << *ptr << " ";
		}
		cout << "\nList ordered values:\n";
        sort(data, data+size);
        for (double *ptr=data; ptr<data+size; ptr++) {
			cout << *ptr << " ";
		}

        cout << "\nAverage: " << Average() << endl;
        cout << "Medium: " << Medium() << endl;
	}
	else {
		cout << "List is empty.\n";
	}
}

double List::Average() {
    double total;
    double average;
    for (double *ptr=data; ptr<data+size; ptr++) {
        total += *ptr;
        average = total/size;
    }
    return average;
}

double List::Medium() {
    double medium;
    if (size%2 == 0) {
        medium = (data[size/2 -1] + data[size/2])/2.0;
        return medium;
    } else if (size%2 == 1) {
        medium = data[size/2];
        return medium;
    }
    return 0;
}

List::List()
{
	data=nullptr;
	size=0;
}

List::~List()
{
	Clear();
}