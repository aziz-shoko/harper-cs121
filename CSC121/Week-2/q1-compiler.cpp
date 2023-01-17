/*
Azizbek Shokosimov
q1-compiler
Using cin command to get user input on name, age, and gpa
08/29/2022
csc121
*/

#include <iostream>              // Library for cout and cin
#include <string>                // Library for declaring string variables
using namespace std;             // Used to avoid std::

string name;                     // Declared variable name but not initialized
int age{};                         // Declared variable age but not initialized
int gpa{};                         // Declared variable gpa but not initialized

int main() {                                                                                    // Start Function
    cout << "What is you name? ";                                                               // Output What is your name?
    cin >> name;                                                                                // Store user input in name variable

    cout << "what is your age? ";                                                               // Output What is your age?
    cin >> age;                                                                                 // Store user input in age variable

    cout << "What is your gpa? ";                                                               // Output What is your gpa?
    cin >> gpa;                                                                                 // Store user input in gpa

    cout << name << "'s new age is " << (age + 4) << " and new gpa is " << (gpa + 1.3) << endl; // Output name, new age, and new gpa
    return 0;                                                                                   // End function
}

/*
Useful Notes:
Initializing a variable in the syntax form of:
int x{8};
Does not work for older versions of compiler's
If you want to use this syntax, you must compile it with newer version
Command for compiling with newer version
g++ -o <some-name> <some-name>.cpp -std=c++11
Visit https://stackoverflow.com/questions/10363646/compiling-c11-with-g for more info
*/