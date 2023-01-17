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
int total{}, userNum{}, userNumbers[10]{0}, i{0}, getArrayLength{};     // declare int vars
string input="y";                                                       // decalre input string

int main() {
    while ( input == "y") {                                             // condition for while loop
        total += protectData(input);                                    // total equation
    }

    getArrayLength = sizeof(userNumbers) / sizeof(int);                 // gets the array length
    for (int j = 0; j < getArrayLength; j++) {                          // for loop for printing out the userNumbers
        cout << "User #: "<< j << " Score: "<< userNumbers[j] << endl;  // Outputs users 
    }
    cout << "\nTotal Score: " << total << endl;                         // output the total score
}

int protectData(string) {                       
    cout << "Enter your score: ";                                       // Output text in quotes
    cin >> userNum;                                                     // store user input in userNum
    while (userNum < 0 || userNum > 100 || cin.fail()) {                // Conditions for protecting data
        cin.clear();                                                    // resets the buffer and clears the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');            // prevent infite loop and ignore multiple char inputs
        cout << "Enter valid number! (1 - 100): ";                      // output text in quotes
        cin >> userNum;                                                 // store user input in userNum
    }
    userNumbers[i] = userNum;                                           // set first element in userNumbers to userNum
    i++;                                                                // increment i by +1



    input = "k";                                                        // simply changes value for input to k (bc default is y)
    while ( input != "n" && input != "y" ) {                            // if input doesn't equal n or y, keep asking user if they want to repeat
        cout << "Would like to repeat? (y/n): ";                        // output text in quotes
        cin >> input;                                                   // store user input in input
    }
    return userNum;                                                     // return userNum value
}
