/*
Azizbek Shokosimov
Week11 Q2
Fopen and File pointers
11/5/2022
csc121
*/

/*
Fopen commands is used to open files. The syntax is as follows:
fopen("filename", "mode");
*/

#include <iostream>                 // file headers
#include <stdio.h>
#include <string>
using namespace std;                // avoid using std::

string userInput{};                                         // declare string variable 
FILE *fptr{};                                               // declare FILE pointer

int main() {
    while (true) {                                          // infinite loop
        cout << "Enter your name: ";                        // Get user name
        cin >> userInput;                   

        fptr = fopen("names.txt", "a");                     // Open file in appends mode
        fprintf (fptr, "\n %s", userInput.c_str());         // write value of userInput into file
        fclose (fptr);                                      // close file
    }
}