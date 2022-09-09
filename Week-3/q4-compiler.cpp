/*
Azizbek Shokosimov
q4-compiler
Use conditional operators to redo q1
09/09/2022
csc121
*/

#include <iostream>                         // Libary for cout and cin
using namespace std;                        // avoid using std::


int main() {
    int num{1};                                                                                                         // Declare var num

    cout << "Enter Integer: ";                                                                                          // Ask user for integer
    cin >> num;                                                                                                         // Store user input in num
    cout << "Number: " << num << endl;                                                                                  // Output user number

    string positive{ (num >= 0) ? "Positve Number" : "Negative Number" };                                                // Variable for checking if num is pos or neg
    string zero{ (num == 0) ? "Zero" : "Not Zero"};                                                                     // Variable for checking if num is zero or non zero
    string even{ (num%2 == 0) ? "Even Number" : "Odd Number" };                                                         // Variable for checking if num is even or odd
    string divThree{ (num%3 == 0) ? "Divisable by 3" : "Not divisable by 3" };                                          // Variable for cheking if num is divisable by 3
    string five{ (num%5 == 0) ? "Multiple of 5" : "Not multiple of 5"};                                                 // Varaible for checking if num if multiple of 5
    string zeroHund{ (num < 0) ? "Not Between 0 to 100" : (num > 100) ? "Not Between 0 to 100" : "Between 0 to 100" };  // Variable for checking to see if num is 0 to 100

    cout << positive << "\n" << zero << "\n" << even << "\n" << divThree << "\n" << five <<  "\n" << zeroHund << "\n";  // Output results of every variable
}