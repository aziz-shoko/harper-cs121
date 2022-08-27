/*
Azizbek Shokosimov
q3-compiler
Using cout and printf to output some messages
08/22/2022
csc121
*/

#include <iostream>                                   // Declares the cout << and printf command
using namespace std;                                  // Allows us to use the cout << command without std::

int main() {                                          // Start of program
    cout << "Hello User\n";                           // Outsputs text in the quotes with cout <<
    printf("Azizbek Shokosimov \n08/22/2022");        // Outsputs text in the quotes with printf
    return 0;                                         // Exits program
}

// run g++ -o <compiler-name>  <filename>.cpp to compile the code