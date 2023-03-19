#include<iostream>
#include<vector>
#include "list.h"
using namespace std;

int main() {
    List obj;
    vector<string> names = {"Dave", "Bob", "Timmy", "Arthur"};

    obj.SetName(names);

    cout << "Before sort: ";
    obj.Display();
    cout << "\n\n";

    cout << "After Sort: ";
    obj.SortName();
    obj.Display();
    cout << "\n\n";

    cout << "First name based on the alphabetical order: " << obj.First() << endl;
    cout << "Last name based on the alphabetical order: " << obj.Last() << endl;


}