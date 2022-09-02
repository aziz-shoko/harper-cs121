/*
Azizbek Shokosimov
q4-compiler
Use length funtion in program
09/01/2022
csc121
*/

#include <iostream>                     // Library for cin and cout
#include <string>                       // Library for using string
using namespace std;                    // Avoid using std::

int main() {                                                            // Start function

    string name{};                                                      // Declare name string variable

    cout << "\n\nEnter your name: ";                                    // Output text in quotes
    cin >>  name;                                                       // Store user input in name

    cout << "\n\n\nNumber of characters: " << name.length();            // Calculate character length using length function
    cout << "\nFirst character: " << name[0];                           // Gets the first letter of name
    cout << "\nLast character: " << name[name.length()-1] << "\n\n";    // Gets the last letter of name
    return 0;                                                           // End function
}   