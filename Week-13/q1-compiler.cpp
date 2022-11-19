/*
Azizbek Shokosimov
Week13 Q1
UML for Q1 
CSC121
11/18/2022
*/

#include <iostream>
#include "q1-class.h"
using namespace std;

int main() {
    student myObj;
    myObj.display();
    myObj.setGpa();
    myObj.setName();
    cout << "\n";
    myObj.display();
}