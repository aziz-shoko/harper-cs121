/*
Azizbek Shokosimov
Week13 Q2
Class but with fruits
csc121
10/19/2022
*/

#include <iostream>                     // file headers
#include "q2-class.h"                   // file header for class
using namespace std;                    // namespace to avoid using std::

int main() {
    fruit obj;                          // create class obj

    cout << "Initial: " << endl;        // output the text in quotes
    int x = 0;                          // declare variable x
    obj.display(x);                     // call display method and pass on x
    obj.setFruitColor();                // call setFruitColor method 
    obj.setNumberPrice();               // call setNumberPrice method
    cout << "\n\nChanged: " << endl;    // output changed 
    x = 1;                              // change value of x to 1
    obj.display(x);                     // call method display once more and pass on x

}