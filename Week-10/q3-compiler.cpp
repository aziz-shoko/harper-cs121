/*
Azizbek Shokosimov
Week10 Q1
Fstream
10/29/2022
csc121
*/

/*
fstream has both the capabilities of ofstream and ifstream
*/

#include <iostream>                             // file headers
#include <fstream>
#include <string>
using namespace std;

string firstName{};                             // declare string vars
string lastName{};

int main() {
    for (int i = 0; i < 3; i++) {                                           // run loop 3 times
        cout << "Enter first name: ";                                       // ask for first name
        cin >> firstName;                                                   // store user input
        cout << "Enter last name: ";                                        // ask for last name
        cin >> lastName;                                                    // store user input

        fstream file ("employee.txt", ios::app);                            // open file employee.txt and set mode to append
        file << firstName[0] << "_" << lastName << "@company.com" << endl;  // output this into file

        cout << "Saved!\n";                                                 // cout message in text
    }
}