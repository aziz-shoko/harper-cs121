/*
Azizbek Shokosimov
Week11 Q2
Use pointers
11/2/2022
csc121
*/

#include <iostream>                 // file headers
#include <stdio.h>                  // file header for fopen
#include <string>                   // file header for string
using namespace std;                // avoid using std::

string userInput{};                                         // declare string variable 
FILE *fptr{};                                               // declare FILE pointer
char charArray[80];

int main() {
    while (true) {                                                      // infinite loop
        cout << "Enter your name (q to quit): ";                        // Get user name
        cin >> userInput;                   

        if (userInput == "q") {                                         // Condition for breaking out of loop
            break;
        } else {
            fptr = fopen("names.txt", "a");                             // Open file in appends mode
            fprintf (fptr, "\n %s", userInput.c_str());                 // write value of userInput into file
            fclose (fptr);                                              // close file
        }
    }
    fptr = fopen("names.txt", "r+");                                    // open file in read mode

	while ((fgets(charArray, 80, fptr)) != NULL)                        // While loop fo reading file
	{
		cout << charArray;                                              // output contents of file
	}
		fclose(fptr);                                                   // close file
}   