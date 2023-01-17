/*
Azizbek Shokosimov
Week12 Q4
Methods
11/11/2022
csc121
*/

#include <iostream>                                     // file hearders
#include "q4-class.h"                                   // call file q2-class.h
using namespace std;

int main() {
    bmwData carObj("BMW-2023", "February 1st, 2023");  // create object carObj and initial the data with these values

    cout << "Car 2023: " << carObj.bmw;                         // output the bmw value
    cout << "\nRelease date: " << carObj.release << endl;       // output the release value
}