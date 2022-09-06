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

int main() {
    double numb{};

    cout << "Enter Number: ";
    cin >> numb;
    
    posNeg(numb);

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