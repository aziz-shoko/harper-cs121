/*
Azizbek Shokosimov
Week13 Q1
UML for Q1 
CSC121
11/18/2022
*/

#include <iostream>                 // file header for cout and cin commands
#include "q1-class.h"               // file header for importing the q1-class file
using namespace std;                // setting namespace std to avoid using std::

int main() {                        // main function
    student myObj;                  // create object myObj
    myObj.display();                // call method display 
    myObj.setGpa();                 // call method setGpa
    myObj.setName();                // call method setName
    cout << "\n";
    myObj.display();                // call method display
}