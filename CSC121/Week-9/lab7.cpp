/*
Azizbek Shokosimov
Week9 Lab7
Use functions for different things
10/22/2022
csc121
*/

/*
cin.ignore() = cin.ignore function is basically used to clear the value of cin from input buffer
https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus 
cin.peek()   = cin.peek looks at the char input without removing it from the stream
https://www.youtube.com/watch?v=yMwA4u7eXEY
isspace()    = isspace checks to see if there is any whitespace chars 
https://www.geeksforgeeks.org/isspace-in-c-and-its-application-to-count-whitespace-characters/#:~:text=isspace()%20function%20In%20C,argument%20contains%20any%20whitespace%20characters.
getline()    = used to capture the whole user input, including spaces. For example, can be used to capture sentences
https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-getline
*/

#include <iostream>                                     // File headers
#include <string.h>                             
#include <string>
#include <vector>
using namespace std;                                    // avoid using std::

string fullName;                                        // declare var 

vector<char> firstName;                                 // declare vectors
vector<char> lastName;

void copyFirstLast(string&);                            // declare functions
void lowerCase(vector<char>&, vector<char>&);
void capitalInitial(vector<char>&, vector<char>&);

int main() {
    cout << "Enter first and last name: ";              // output text in quotes
    getline(cin, fullName);                 // get the entire user input

    copyFirstLast(fullName);                            // call functioin fullName
    lowerCase(firstName, lastName);                     // call function lowerCase
    capitalInitial(firstName, lastName);                // call function capitalInitial

    cout << "First name: ";                             
    for (char k : firstName) {                          // Output vector firstName elements
        cout << k;
    }

    cout << "\nLast name: ";
    for (char k : lastName) {                           // Output vector lastName elements
        cout << k;
    }
    cout << "\n";
}

void copyFirstLast(string& fullName) {                  // receive fullName string in function
    bool b{0};                                          // bool b false
    char j{};                                           // local empty char j
    for (int i = 0; i < fullName.length(); i++) {       // for loop for the string length
        j = fullName[i];                                // set j char to elements of fullName
        if (j != ' ' && b == 0) {                       // if j doesnt equal a space and b is false
            firstName.push_back(j);                     // then add it to vector firstName
        } else {
            lastName.push_back(j);                      // else, add it to lastName vector 
            b = 1;                                      // and set b to true
        }                                               
    }
}

void lowerCase(vector<char>& firstName, vector<char>& lastName) {
    transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);    // lowercase the firstName vector elements
    transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);       // lowercase the lastName vector elements
}

void capitalInitial(vector<char>& firstName, vector<char>& lastName) {
    firstName[0] = toupper(firstName[0]);                                           // Capitalize the first letter
    lastName[1] = toupper(lastName[1]);                                             // Capitalize the first letter
}


