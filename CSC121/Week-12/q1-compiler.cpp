/*
Azizbek Shokosimov
Week12 Q1
Public, Private, and Protected Data
11/10/2022
csc121
*/

/*
Public specifier is available to the whole world
Protected specifier is available to other classes through inheritance
Private specifier makes all data to be only available inside the class
*/

#include <iostream>                                                 // file header for cin and cout
#include "q1-class.h"                                               // file header for our class

using namespace std;

int main() {
    publicData car;                                                 // create object| className objName;

    cout << "New car of 2023: " << car.carRelease << endl;          // Call public data| objName.dataName;
}