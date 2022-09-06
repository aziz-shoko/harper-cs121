/*
Azizbek Shokosimov
Week 3 Q1
Use if statements for certain conditions
09/06/2022
csc121
*/

#include <iostream>
using namespace std;

void posNeg(double);
void evenOdd(int);
void divThree(int);
void multiFive(int);
void zeroHundred(double);

int main() {
    double numb{};

    cout << "Enter Number: ";
    cin >> numb;
    
    posNeg(numb);
    evenOdd(numb);
    divThree(numb);
    multiFive(numb);
    zeroHundred(numb);

}

void posNeg(double numb) {
    if ( numb > 0) {
        cout << numb << " = Positive Number\n";
    } else if ( numb < 0 ) {
        cout << numb << " = Negative Number\n";
    } else if ( numb == 0) {
        cout << numb << " = Zero\n";
    }
}

void evenOdd(int numb) {
    if ( numb % 2 == 0 ) {
        cout << numb << " = Even\n";
    } else if ( numb % 2 != 0 ) {
        cout << numb << " = Odd\n";
    }
}

void divThree(int numb) {
    if ( numb % 3 == 0 ) {
        cout << numb << " = Divisable by Three\n";
    } else if ( numb % 3 != 0 ) {
        cout << numb << " = Not Divisable by Three\n";
    }
}

void multiFive (int numb) {
    if ( numb % 5 == 0 ) {
        cout << numb << " = Multiple of Five\n";
    } else if ( numb % 5 != 0 ) {
        cout << numb << " = Not multiple of 5\n";
    }
}

void zeroHundred (double numb) {
    if ( numb >= 0 && numb <= 100 ) {
        cout << numb << " = Between 0 to 100\n";
    } else {
        cout << numb << " = Not Between 0 to 100\n";
    }
}