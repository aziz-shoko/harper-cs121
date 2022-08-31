/*
Azizbek Shokosimov
q2-compiler
Do some basic math with + - * /
08/30/2022
csc121
*/

#include <iostream>             // Library for cout and cin
#include <cmath>                // Library for pow function
using namespace std;            // Prevent usage of std::

int x{1};                       // Declaring x
int y{2};                       // Declaring y

int main() {                                                                    // Start Function
    cout << "\n\n\tPlease enter two whole numbers with space in between: ";     // Outputs the output in the quotation
    cin >> x >> y;                                                              // Stores user input in variables x and y

    cout << "\n\n\tSUM: " << x + y << endl;                                     // Outputs SUM and Calculates the sum
    cout << "\tDIFFERENCE: " << x - y << endl;                                  // Outputs DIFFERENT and Calculates difference
    cout << "\tPRODUCT: " << x * y << endl;                                     // Outputs PRODUCT alculates product
    cout << "\tQUOTIENT: " << static_cast<double>(x) / y << endl;               // Calculates Quotient and the static_cast turns first inputed varaible to a double

    cout << "\n\n\t" << x << " to the power of " << y << " is: " << pow(x, y);  // Outputs x to the power of y and calculates x to the power of y
    cout << "\n\t" << y << " to the power of " << x << " is: " << pow(y, x);    // Outputs y to the power of x and calculates y to the power of x

    cout << "\n\n\t" << x << "%2 = " << x%2;                                    // Finds the remainder of x value divided by 2
    cout << "\n\t" << y << "%2 = " << y%2;                                      // Finds the remainder of y value divided by 2
    cout << "\n\t" << x << "%" << y << " = " << x%y;                            // Finds the remainder of x value divided by y value
    cout << "\n\t" << y << "%" << x << " = " << y%x;                            // Finds the remainder of y value divided by x value
    cout << "\n\n";                                                             // Makes space
    return 0;                                                                   // End function
}