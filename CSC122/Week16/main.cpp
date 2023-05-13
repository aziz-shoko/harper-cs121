#include <iostream>
#include <set>
#include "input.h"
using namespace std;

void DisplayUnion(set<int>&, set<int>&, set<int>&);
void DisplayIntersection(set<int>&, set<int>&, set<int>&);
void DisplayDifference(set<int>&, set<int>&, set<int>&);
double Average(set<int>&);

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
        } else if (userInput == 4) {
            DisplayUnion(set1, set2, set3);

        } else if (userInput == 5) {
            DisplayIntersection(set1, set2, set3);
        } else if (userInput == 6) {
            DisplayDifference(set1, set2, set3); 
        }
    }

}

void DisplayUnion(set<int>& set1, set<int>& set2, set<int>& set3) {
    set<int> unionSet = set1;
    unionSet.insert(set2.begin(), set2.end());
    unionSet.insert(set3.begin(), set3.end());

    cout << "Union of three sets: ";
    for (int i : unionSet) {
        cout << i << " ";
    }
    cout << "\nAverage: " << Average(unionSet);
}

void DisplayIntersection(set<int>& set1, set<int>& set2, set<int>& set3) {
    set<int> intersectionSet;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersectionSet, intersectionSet.begin()));
    set_intersection(intersectionSet.begin(), intersectionSet.end(), set3.begin(), set3.end(), inserter(intersectionSet, intersectionSet.begin()));

    cout << "Union of three sets: ";
    for (int i : intersectionSet) {
        cout << i << " ";
    }
    cout << "\nAverage: " << Average(intersectionSet);
}


double Average(set<int>& listSet) {
    double total = 0;
    for (int poo : listSet) {
        total += poo;
    }

    return total/listSet.size();
}