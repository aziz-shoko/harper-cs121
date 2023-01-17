/*
Azizbek Shokosimov
Week 15 Q1
Function Overloading
12/02/2022
csc121
*/

#include <iostream>                                         // file header
using namespace std;                                        // namespace

template <class overload>                                   // template overload
overload display(overload x) {return x;};                   // returns variable value no matter the data type

int numb{1};                                                // declare variables
double decimal{5.5};
char letter{'a'};

int main() {
    cout << "Int: " << display<int>(numb) << endl;              // call the display function and display the values
    cout << "Decimal: " << display<double>(decimal) << endl;    // call the display function and display the double value
    cout << "Char: " << display<char>(letter) << endl;          // call the display function and display the char value
}