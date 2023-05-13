#include <iostream>
#include <set>
#include "input.h"
using namespace std;

int main() {
    set<int> set1, set2, set3;

    int userInput = ReadValue<int> ("\n\t1. Enter Set One\n\t2. Enter Set Two\n\t3. Enter Set Three\n\t4. Display Union\n\t5. Display Intersection\n\t6. Display Difference\n\t7. Quit\n\nChoose Option: ");

    while (userInput != 7) {
        if (userInput == 1) {
            int alpha;
            cout << "Enter first set (separate by space): ";
            while (cin >> alpha) {
                set1.insert(alpha);
            }
        } else if (userInput == 2) {
            int alpha;
            cout << "Enter second set (separate by space): ";
            while (cin >> alpha) {
                set2.insert(alpha);
            }
        } else if (userInput == 3) {
            int alpha;
            cout << "Enter third set (separate by space): ";
            while (cin >> alpha) {
                set3.insert(alpha);
            }
        }
    }

}