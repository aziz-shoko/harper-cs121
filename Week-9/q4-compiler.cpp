/*
Azizbek Shokosimov
Week9 Q4
Make factorial
10/22/2022
csc121
*/

#include <iostream>
using namespace std;

int factorial(int);

int main() {
    for (int i = 0; i < 11; i++) {
        cout << i << "! = " << factorial(i) << endl;
    }
}

int factorial(int i) {
    if (i > 1) {
        return i*factorial(i - 1);
    } else {
        return 1;
    }
}