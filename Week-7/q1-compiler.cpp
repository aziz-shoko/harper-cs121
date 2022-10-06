/*
Azizbek Shokosimov
Week 7 Q1
Protect Data
10/06/2022
csc121
*/

#include <iostream>                                                     // cout and cin file header
using namespace std;                                                    // avoid using std

int protectData(string);                                                // protect data function
int total{}, userNum{}, userNumbers[10]{}, i{0};                        // declare int vars
string input="y";                                                       // decalre input string

int main() {
    while ( input == "y") {                                             // condition for while loop
        total += protectData(input);                                    // total eqaution
    }

    int getArrayLength = sizeof(userNumbers) / sizeof(int);             // gets the array length
    for (int j = 0; j < getArrayLength; j++) {                          // for loop for printing out the userNumbers
        cout << "User #: "<< j << " Score: "<< userNumbers[j] << endl;  // Outputs users 
    }
    cout << "\nTotal Score: " << total << endl;
}

int protectData(string) {
    cout << "Enter your score: ";
    cin >> userNum;
    while (userNum < 0 || userNum > 100 || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter valid number! (1 - 100): ";
            cin >> userNum;
    }
    userNumbers[i] = userNum;
    i++;



    input = "k";
    while ( input != "n" && input != "y" ) {
        cout << "Would like to repeat? (y/n): ";
        cin >> input;
    }
    return userNum;
}
