/*
Azizbek Shokosimov
Week 3 Q1
Use if statements for certain conditions
09/06/2022
csc121
*/

#include <iostream>                                         // Library for using cout and cin
using namespace std;                                        // Avoid using std::

void posNeg(double);                                        // Declaring posNeg function
void evenOdd(int);                                          // Declaring evenOdd function
void divThree(int);                                         // Declaring divThree function
void multiFive(int);                                        // Declaring multiFive function
void zeroHundred(double);                                   // Declaring zeroHundred function

int main() {                                                // Main function start
    double numb{};                                          // Declaring the numb variable

    cout << "Enter Whole Number: ";                         // Ask user input a number
    cin >> numb;                                            // Store the user input in numb variable
    
    posNeg(numb);                                           // Call function posNeg
    evenOdd(numb);                                          // Call function evenOdd
    divThree(numb);                                         // Call function divThree
    multiFive(numb);                                        // Call function multiFive
    zeroHundred(numb);                                      // Call Function zeroHundred

}

void posNeg(double numb) {                                  
    if ( numb > 0) {                                        // check condition for positive
        cout << numb << " = Positive Number\n";
    } else if ( numb < 0 ) {                                // check condition for negative
        cout << numb << " = Negative Number\n";
    } else if ( numb == 0) {                                // check condition for zero
        cout << numb << " = Zero\n";
    }
}

void evenOdd(int numb) {
    if ( numb % 2 == 0 ) {                                  // check condition for even 
        cout << numb << " = Even\n";
    } else if ( numb % 2 != 0 ) {                           // check condition for odd
        cout << numb << " = Odd\n";
    }
}

void divThree(int numb) {
    if ( numb % 3 == 0 ) {                                  // check condition if number is divisable by 3
        cout << numb << " = Divisable by Three\n";
    } else if ( numb % 3 != 0 ) {                           // check condition if number is not divisable by 3
        cout << numb << " = Not Divisable by Three\n";
    }
}

void multiFive (int numb) {
    if ( numb % 5 == 0 ) {                                  // check condition to see if multiple of 5
        cout << numb << " = Multiple of Five\n";
    } else if ( numb % 5 != 0 ) {                           // check condition to see if not multiple of 5
        cout << numb << " = Not multiple of 5\n";
    }
}

void zeroHundred (double numb) {
    if ( numb >= 0 && numb <= 100 ) {                       // check condition if number is between 0 to 100
        cout << numb << " = Between 0 to 100\n";
    } else {                                                // check condition if number is not between 0 to 100
        cout << numb << " = Not Between 0 to 100\n";
    }
}