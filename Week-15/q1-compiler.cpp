/*
Azizbek Shokosimov
Week 15 Q1
Function Overloading
12/02/2022
csc121
*/

#include <iostream>                                         // file header
using namespace std;                                        // namespace

int overload(int);                                          // declare functions
double overload(double);
char overload(char);

int numb{1};                                                // declare variables
double decimal{5.5};
char letter{'a'};

int main() {
    cout << "Int: " << overload(numb) << endl;              // call the overload function and display the values
    cout << "Decimal: " << overload(decimal) << endl;
    cout << "Char: " << overload(letter) << endl;
}

int overload(int numb) {                                    // returns int numb
    return numb;
}

double overload(double decimal) {                           // returns double decimal 
    return decimal;
}

char overload(char letter) {                                // returns char letter
    return letter;
}