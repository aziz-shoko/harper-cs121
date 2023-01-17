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

vector<string> names;                               // declare string vector names

int main() {
    while (true) {                                  // infinite loop
        cout << "Enter a name: ";                   // output name in text
        cin >> userInput;                           // store user input in the variable
        if (!cin.eof()) {                           // condition for ctrl+Z
            names.push_back(userInput);             // add users input into vector names
        } else {
            break;                                  // once ctrl+z, the break is applied to break out of loop
        }
    }

    sort(names.begin(), names.end());   // sort function for vectors

    cout << "\nNon Pop back Names: ";               // displays all names in vector
    for ( string items : names ){
        cout << items << " ";
    }

    names.pop_back();                               // removes the last element in vector
    cout << "\nPop back Names: ";
    for ( string items : names ){                   // display last element removed vector
        cout << items << " ";
    }

    cout << "\n";
}