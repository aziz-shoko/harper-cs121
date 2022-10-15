/*
Azizbek Shokosimov
Week8 Q1
Push and Pop
11/13/2022
csc121
*/

#include <iostream>                                 // cin and cout file headers
#include <vector>                                   // vector file header
using namespace std;                                // avoid using std::

string userInput{};                                 // string variable

vector<string> names;

int main() {
    while (true) {
        cout << "Enter a name: ";
        cin >> userInput;
        if (!cin.eof()) {
            names.push_back(userInput);
        } else {
            break;
        }
    }

    sort(names.begin(), names.end());

    cout << "\nNon Pop back Names: ";
    for ( string items : names ){
        cout << items << " ";
    }

    names.pop_back();
    cout << "\nPop back Names: ";
    for ( string items : names ){
        cout << items << " ";
    }

    cout << "\n";
}