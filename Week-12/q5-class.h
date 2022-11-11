#include <iostream>
using namespace std;

class myAccount {                                           // create class myAccount
    private:                                                // private specifier
        string name{};                                      // private data variables
        double balance{};
    
    public:                                                 // public specifier
        myAccount(string x, double y) {                                       // constructor myAccount
            name = x;                               // constructor variables
            balance = y;
        }
        void deposit (double);                              // declare methods (functions for classes)
        void withdraw(double);
        double getBalance();
        string getName();
        void setName(string);
        void setBalance(int);
};


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

void myAccount::setName(string i) {                     // name setter
    name = i;
}

void myAccount::setBalance(int j) {                     // balance setter
    balance = j;
}

