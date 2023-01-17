/*
Azizbek Shokosimov
Week 3 Q2
Using if and else statements
09/06/2022
csc121
*/

#include <iostream>                                 // Library for cin and cout
using namespace std;                                // Avoid using std:: 

void sizeFunction(int, int);                        // Declare function sizeFunction
void divisibleFunction(int, int);                   // Declare function divisibleFunction

int main() {
    int num1{}, num2{};                             // Declare variable num1 and num2

    cout << "\nPlease enter two numbers: ";         // Output text in quotes
    cin >> num1 >> num2;                            // Store user input in num1 and num2

    sizeFunction(num1, num2);                       // Call function sizeFunction
    divisibleFunction(num1, num2);                  // Call function divisibleFunction
}

void sizeFunction(int num1, int num2) {                                 
    if ( num1 > num2 ) {                                                // Condition for checking if num1 is bigger than num2
        cout << "\n" << num1 << " is larger than " << num2 << "\n"; 
    } else if ( num1 < num2 ) {                                         // Condition for checking if num1 is smaller than num2
        cout << "\n" << num1  << " is smaller than " << num2 << "\n";
    } else if ( num1 == num2 ) {                                        // Conditionn for checking if num1 equals num2
        cout << "\n" << num1 << " is Equal to " << num2 << "\n";
    }
}

void divisibleFunction(int num1, int num2) {
    if ( num1 % num2 == 0 ) {                                                   // Checking to see if num1 is divisiable by num2
        cout << "\n" << num1 << " is divisible by " << num2 << " \n";
    } else {
        cout << "\n" << num1 << " is not divisible by " << num2 << "\n";        // Output in text if num1 is not divisable by num2
    }
    if ( num2 % num1 == 0 ) {                                                   // Checking to see if num2 is divisible by num1
        cout << "\n" << num2 << " is divisible by " << num1 << " \n\n";
    } else {
        cout << "\n" << num2 << " is not divisible by " << num1 << "\n\n";      // Output in text if num2 is not divisable by num1
    }
}
