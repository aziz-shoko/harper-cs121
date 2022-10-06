/*
Azizbek Shokosimov
Week 7 Q1
Protect Data
10/03/2022
csc121
*/

#include <iostream>
#include <vector>
using namespace std; 

int protectData(string);

int total{}, userNum{-1};
vector<int> nums; 
string input{"y"};

int main() {
    while ( input == "y") {
        total += protectData(input);
    }
    cout << total << endl;

    for (int j = 0; j < nums.size(); j++) {
        cout << nums[j] << endl;

    }
}

int protectData(string) {
    cout << "Enter your score: ";
    cin >> userNum;
    while (userNum < 0 || userNum > 100 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter valid number! (1 - 100): ";
        cin >> userNum;
    }

    nums.push_back(userNum);
    input = "k";
    while ( input != "n" && input != "y" ) {
        cout << "Would like to repeat? (y/n): ";
        cin >> input;
    }
    
    return userNum;
}




