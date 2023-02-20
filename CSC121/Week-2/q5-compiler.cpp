/*
Azizbek Shokosimov
q5-compiler
Use string variable and length function to output some gmails
09/02/2022
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

    string firstLetterFirst {first[0]};          // Declare firstLetter and obain first letter of name in string
    string firstLetterLast {last[0]};            // Declare lastLetter and obain first letter of name in string

    string x{firstLetterFirst + last};              // Declare string x and set value to firstLetter + lastLetter
    cout << "\n\t" << x << "@company.com\n";        // Output text in quotes

    string y{firstLetterFirst + firstLetterLast};                                            // Declare y and set its value to first initial combined with last name initial
    cout << "\n\t" << y << first.length() + last.length() << "@whatsInaName.com" << "\n\n";  // Combine variable x with length of first and last name combined
}

// int x{0}, y{0};
//     while (x < arrSize) {
//         if (library[x] == delBook) {
//             x++;
//         } else {
//             library[y] = library[x];
//             x++;
//             y++;
//         }
//     }
//     arrSize = y;