/* 
Azizbek Shokosimov
q2-compiler
Using cout and printf to output some messages
08/22/2022
csc121
*/

#include <iostream>                                                   // Declares the cout << and printf command
using namespace std;                                                  // Allows us to use the cout << command without std::

int main() {                                                          // Start of program
    cout << "Hello World!! \nMy name is Azizbek Shokosimov";          // Outsputs text in the quotes with cout <<
    printf("\nThis is Q2 and I am using Visual Studio Code on Mac");  // Outsputs text in the quotes with prinf 
    return 0;                                                         // Ends the program
}

// run g++ -o <compiler-name>  <filename>.cpp to compile the code