/*
Azizbek Shokosimov
Week 7 Q1
Protect Data
10/03/2022
csc121
*/

#include <iostream>
using namespace std;

int protectData(string);
int total, userNum, userNumbers[10], i=0;
string input="y";

int main() {
    while ( input == "y") {
        total += protectData(input);
    }

    int getArrayLength = sizeof(userNumbers) / sizeof(int);
    for (int j = 0; j < getArrayLength; j++) {
        int u = j;
        u++;
        cout << "User #: "<< u << " Score: "<< userNumbers[j] << endl;
    }
    cout << "\nTotal Score: " << total << endl;
}

int protectData(string) {
    userNum = -1;
    while ( userNum < 0 || userNum > 100) {
        cout << "Enter your score: ";
        cin >> userNum;
        while (userNum < 0 || userNum > 100 || cin.fail()) {
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
            }
            cout << "Enter valid number! (1 - 100): ";
            cin >> userNum;
        }
        userNumbers[i] = userNum;
        i++;
    } 


    input = "k";
    while ( input != "n" && input != "y" ) {
        cout << "Would like to repeat? (y/n): ";
        cin >> input;
    }
    return userNum;
}
