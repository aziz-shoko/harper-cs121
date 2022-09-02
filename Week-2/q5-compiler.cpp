/*
Azizbek Shokosimov
q5-compiler
Use string variable and length function to output some gmails
09/01/2022
csc121
*/

#include <iostream>                         // Library for cout and cin
#include <string>                           // Library for string
using namespace std;                        // Avoid using std::

int main() {
    string first{};                         //  Declare string first
    string last{};                          //  Declare string last

    cout << "\n\tEnter first name: ";       // Output text in quotes
    cin >> first;                           // Store user input in variable first
    cout << "\tEnter last name: ";          // Output text in quotes
    cin >> last;                            // Store user input in variable last

    string firstLetter {first[0]};          // Declare firstLetter and obain first letter of name in string
    string lastLetter {last[0]};            // Declare lastLetter and obain first letter of name in string

    string x{firstLetter + lastLetter};             // Declare string x and set value to firstLetter + lastLetter
    cout << "\n\t" << x << "@company.com\n";        // Output text in quotes

    cout << "\n\t" << x << first.length() + last.length() << "@whatsInaName.com" << "\n\n";     // Combine variable x with length of first and last name combined
}