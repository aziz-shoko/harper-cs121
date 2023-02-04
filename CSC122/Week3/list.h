#include <iostream>
#include <exception>
#include <algorithm>
#include "input.h"
using namespace std;

class List
{
	private:
		double* data;
		double* copyData;
		long size;
		long newSize{0};
		int var{0};

	public:
		enum {MAX_SIZE=1000};
		
		// void SetValue(double value, long pos);
		// double GetValue(long pos);
		void Resize(long numValues, int var);
		void Clear();
		void Clear2();
		void Input();
		void Input2();
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

void List::Clear2()
{
	if (size > 0) {
		delete[] copyData;
		newSize=0;
		copyData=nullptr;
	}
}

void List::Resize(long numValues, int var)
{
	try {
		if (numValues < 1 || numValues > MAX_SIZE) {
			throw "Error! Invalid list size specified.";
		}
		if (var == 0) {
			Clear();
			data=new double[numValues];									// allocate memory for data array size of numValues
			if (data==nullptr) {
				throw "Error! Could not allocate memory for list.";
			}
			size=numValues;
		} else if (var == 1) {
			newSize = numValues;
			copyData = new double[numValues];
			if (data==nullptr) {
				throw "Error! Could not allocate memory for list.";
			}
			if (newSize <= size) {
				for (int i = 0; i < newSize; i++) {
					copyData[i] = data[i];
				}
			} else if (newSize > size) {
				for (int i = 0; i < newSize; i++) {
					copyData[i] = data[i];
				}
				for (int i = size; i < newSize; i++) {
					double userInput;
					userInput = ReadValue<double>("New Value to Add?: ");
					copyData[i] = userInput;
				}
			}
			Clear();
			
		}
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
		var=0;
		if (size==0) {
			long x=ReadValue<long>("Number of values? ");
			Resize(x, var);
		}
	
		for (double *ptr=data; ptr<data+size; ptr++) {
			*ptr=ReadValue<double>("Value? ");
		}
	}
	catch (const char* s) {
		throw s;
	}

	
}

void List::Input2(){
	try {
		var = 1;
		int userInput=ReadValue<int>("Resize array?:\n\n\t1.yes\n\t2.no \n\nUser Input: ");
		if (userInput == 1) {
			long x=ReadValue<long>("Number of values? ");
			Resize(x, var);
		}
	} 
	catch (const char* s) {
		throw s;
	}
}

void List::Display() 
{
	if (size > 0 && var == 0) {
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

	} else if (newSize > 0 && var == 1) {
		cout << "\nNew Size and Copy of Data: \n";
		for (int i = 0; i < newSize; i++) {
			cout << copyData[i] << " ";
		}
		cout << endl;
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
	Clear2();
}