/*
Azizbek Shokosimov
Week13 Q3
Class but with fruits
csc121
10/19/2022
*/

#include <iostream>                         // file headers for cin and cout
#include "q3-class.h"                       // file header for importing the q3-class.h file
using namespace std;

int main() {
    employee obj;                           // create object obj out of employee class

    cout << "Initial: " << endl;            // output the inital values by calling the display method
    obj.display();

    cout << "\n\nChanged: " << endl;        // output the text in quotes 
    obj.setSalaryNameID();                  // call the setter method
    obj.display();                          // cakk the display method again
}