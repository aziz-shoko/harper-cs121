#include <iostream>
#include <array>
using namespace std;

int main() {
    int userSize, userInput;
    array<int, 50> numList;
    array<int, 50> evenList;

    cout << "Enter number of values you want to add: ";
    cin >> userSize;

    for (auto it = numList.begin(); it != numList.begin() + userSize; it++) {
        cout << "Enter the value to add: ";
        cin >> userInput;
        *it = userInput;
    } 

    cout << "List of values: ";
    for (auto it = numList.begin(); it != numList.begin() + userSize; it++) {
        cout << *it << " ";
    }

    auto evenIt = evenList.begin();
    for (auto it = numList.begin(); it != numList.begin() + userSize; it++) {
        if (*it%2 == 0) {
            *evenIt = *it;
            evenIt++;
        }
    } 

    cout << "\nList of even values: ";
    for (auto it = evenList.begin(); it != evenIt; it++) {
        cout << *it << " ";
    }
    cout << endl;
}