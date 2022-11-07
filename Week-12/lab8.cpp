/*
Azizbek Shokosimov
Week11 Q1
Use pointers
11/6/2022
csc121
*/

#include <iostream>                                         // file header for cin and cout
using namespace std;                                        // avoid std::

int userInput{};                                            // declare int variable

class myAccount {                                           // create class myAccount
    private:                                                // private specifier
        string name{};                                      // private data variables
        int ID{};
        double balance{};
    
    public:                                                 // public specifier
        myAccount() {                                       // constructor myAccount
            name = "Azizbek";                               // constructor variables
            ID = 123;
            balance = 0.1;
        }
        void deposit (double);                              // declare methods (functions for classes)
        void withdraw(double);
        double getBalance();
        string getName();
        int getID();
};

int main() {                                                                        // main functions
    myAccount myObj;                                                                // create object myObj
    cout << "\nBank Account Profile: ";
    cout << "\nUsername: " << myObj.getName();                                      // Dislay name
    cout << "\nID: " << myObj.getID();                                              // Display ID
    cout << "\nBalance: " << myObj.getBalance() << "\n\n";                          // Display balance

    while (true) {                                                                  // infinite loop
        cout << "Choose the corresponding number to the menu: ";                    // display menu
        cout << "\n\n\t1. Deposit \n\t2. Withdraw \n\t3. Balance \n\t4. Quit";
        cout << "\n\nChoose Number: ";
        cin >> userInput;                                                           // store userInput

        if ( userInput == 1) {                                                      // condition for depositing
            double userDeposit{};
            cout << "\nEnter Amount: ";
            cin >> userDeposit; 

            myObj.deposit(userDeposit);                                             // pass on userDeposit to the class deposit method

            cout << "\nBalance: " << myObj.getBalance() << "\n\n";                  // display new balance
        } else if ( userInput == 2 ) {                                              // condition for withdrawing
            double userWithdraw{};
            cout << "\nEnter Amount: ";
            cin >> userWithdraw; 

            myObj.withdraw(userWithdraw);                                           // pass on userWithdraw to the class withdaw method

            cout << "\nBalance: " << myObj.getBalance() << "\n\n";                  // display method
        } else if ( userInput == 3 ) {                                              // condition for displaying balance
            double userWithdraw{};
            cout << "\nUsername: " << myObj.getName();                              // display private attributes
            cout << "\nID: " << myObj.getID();
            cout << "\nBalance: " << myObj.getBalance() << "\n\n";

        } else if ( userInput == 4 ) {                                              // quit
            exit(0);
        }
    }
}

void myAccount::deposit(double newMoney) {
    balance += newMoney;                                // add to balance 
}

void myAccount::withdraw(double newMoney) {
    balance -= newMoney;                                // subtract from balance
}

double myAccount::getBalance() {
    return balance;                                     // display balance
}

string myAccount::getName() {
    return name;                                        // display name
}

int myAccount::getID() {
    return ID;                                          // display ID
}