/*
Azizbek Shokosimov
Account
Week12 Q5
11/11/2022
csc121
*/

#include <iostream>                                         // file header for cin and cout
#include "q5-class.h"                                       // class file header
using namespace std;                                        // avoid std::

int userInput{};                                            // declare int variable

int main() {                                                // main functions
    myAccount myObj("Azizbek", 0.1);                        // create object myObj, and pass on values
    
    cout << "Name: " << myObj.getName();                    // get name from class myAccount

    cout << "\nBalance: " << myObj.getBalance();            // get balance from class myAccount

    myObj.setName("Sam");                                   // set name to Sam

    cout << "\nNew Name: " << myObj.getName();              // output new name

    myObj.setBalance(100000);                               // set balance to 100000

    cout << "\nNew Balance: " << myObj.getBalance();        // output new balance

    myObj.deposit(100000);                                  // deposit 100000

    cout << "\nNew Balance: " << myObj.getBalance();        // output new balance 

    myObj.withdraw(150000);                                 // withdraw 150000

    cout << "\nNew Balance: " << myObj.getBalance() << endl; // output new balance
}