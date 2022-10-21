/*
Azizbek Shokosimov
Week9 Q3
Global, Local, and Static counters
10/21/2022
csc121
*/

#include <iostream>                                     // cout and cin file headers
using namespace std;                                    // avoid using std::

void A();                                               // declare functions
void B();
void C(int);

int global{1};                                          // declare global var

int main() {
    int local{1};                                       // declare local var

    while (true) {
        string userInput{};                             // declare userInput var
        cout << "Enter A, B, C, or Q to quit: ";        // output text in quotes
        cin >> userInput;                               // store user input in quotes / command below transforms everything to lower
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); 
        if ( userInput == "a") {                        // conditions for which function to call
            A();
        } else if (userInput == "b") {
            B();
        } else if (userInput == "c") {
            C(local);
            local++;
        } else if ( userInput == "q") {
            break;
        }
        cout << "\n";
    }
}

void A() {
    for (int i = 0; i < global; i++) {                  // Increment output of A by 1 everytime its called
        cout << "A";
    }
    global++;
}

void B() {  
    static int statVar{1};                              // declare static var statVar
    for ( int i = 0; i < statVar; i++) {                // Increment output of B by 1 everytime its called
        cout << "B";
    }
    statVar++;
}

void C(int local) {
    for (int i = 0; i < local; i++) {                   // Increment output of C by 1 everytime its called
        cout << "C";
    }
}