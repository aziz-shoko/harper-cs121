/*
Azizbek Shokosimov
Week9 Q2
Call by reference and Call by value
10/21/2022
csc121
*/

#include <iostream>                                                 // File headers for cin and cout
using namespace std;                                                // avoid using std::

int x{}, y{}, z{0};                                                 // declare vars

int xFunction(int, int);                                            // declare functions
int yFunction(int&, int);

int main() {

    cout << "Enter value x: ";                                      // ask user input for x
    cin >> x;
    cout << "Call by value: " << xFunction(x, z) << endl;           // output x*x

    cout << "Enter value y: ";                                      // ask user input for y
    cin >> y;
    cout << "Call by reference: " << yFunction(y, z) << endl;       // output y*y

    cout << "Initial x: " << x << endl;                             // shows the new values
    cout << "Initial y: " << y << endl;                             // show the new values

    z = 1;                                                          // set z = 1
    cout << "Momory location x: " << &x << endl;                    // output the memory location of each var
    cout << "Momory location y: " << &y << endl;
    xFunction(x, z);                        
    yFunction(y, z);
}

int xFunction(int i, int z) {
    i *= i;                                                         // x*x calculate
    if ( z == 1) {                                                  // if z == 1
        cout << "Momory location i: " << &i << endl;                // output the memory location of i
    }
    return i;                                                       // return i
}

int yFunction(int& j, int z) {                                      
    j *= j;                                                         // calculate y*y
    if ( z == 1) {                                                  // if z == 1
        cout << "Momory location j: " << &j << endl;                // output the memory location of j
    }
    return j;
}