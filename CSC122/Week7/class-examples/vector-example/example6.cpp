#include <iostream>
#include <vector>
#include "input.h"
#include "sphere2.h"
#include "prism.h"
using namespace std;

void Display(vector<Shape*>& v);

void Display(vector<Shape*>& v)
{
	if (v.empty()) {
		cout << "List is empty\n";
	}
	else {
		long len=v.size();
		for (long i=0; i<len; i++) {
			v[i]->Display(cout);
			cout<<endl;
		}
	}
}

int main()
{
	int choice=0;
	vector<Shape*> shapeList;

	do {
		choice=ReadValue<int>("1. Sphere\n2. Prism\n3. Quit\n",1,3);
		switch (choice) {
			case 1: shapeList.push_back(new Sphere);
				shapeList[shapeList.size()-1]->Input();
				break;

			case 2: shapeList.push_back(new Prism);
				shapeList[shapeList.size()-1]->Input();
				break;

			case 3:
				Display(shapeList);
				cout << "Bye!\n";
				break;
		}
	} while (choice != 3);

	return 0;
}