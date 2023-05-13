#include <iostream>
#include <set>
#include <algorithm>
#include "input.h"
using namespace std;

void DisplayUnion(set<int>&, set<int>&, set<int>&);                             // declare functions
void DisplayIntersection(set<int>&, set<int>&, set<int>&);
void DisplayDifference(set<int>&, set<int>&, set<int>&);
double Average(set<int>&);

int main() {
    set<int> set1, set2, set3;                                                  // declare sets
    int userInput;

    while (userInput != 7) {                                                    // while loop menu
        userInput = ReadValue<int> ("\n\t1. Enter Set One\n\t2. Enter Set Two\n\t3. Enter Set Three\n\t4. Display Union\n\t5. Display Intersection\n\t6. Display Difference\n\t7. Quit\n\nChoose Option: ");

        if (userInput == 1) {
            int size;
            cout << "Enter how many numbers to add: ";
            cin >> size;
            for (int i = 0; i < size; i++) {
                int alpha = ReadValue<int> ("Enter Number: ");
                set1.insert(alpha);
            }
        } else if (userInput == 2) {
            int size;
            cout << "Enter how many numbers to add: ";
            cin >> size;
            for (int i = 0; i < size; i++) {
                int alpha = ReadValue<int> ("Enter Number: ");
                set1.insert(alpha);
            }
        } else if (userInput == 3) {
            int size;
            cout << "Enter how many numbers to add: ";
            cin >> size;
            for (int i = 0; i < size; i++) {
                int alpha = ReadValue<int> ("Enter Number: ");
                set1.insert(alpha);
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
    set<int> unionSet = set1;                                                           // make duplicate set
    unionSet.insert(set2.begin(), set2.end());                                          // use algorithm functions to combine the sets for Union
    unionSet.insert(set3.begin(), set3.end());

    cout << "Union of three sets: ";                                                    // Display the results
    for (int i : unionSet) {
        cout << i << " ";
    }
    cout << "\nAverage: " << Average(unionSet) << endl;
}

void DisplayIntersection(set<int>& set1, set<int>& set2, set<int>& set3) {
    set<int> intersectionSet;                                                           // make new intersectionSet to store the new values

    // Store the common values using the set intersection function and algorithm functions
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersectionSet, intersectionSet.begin()));
    set_intersection(intersectionSet.begin(), intersectionSet.end(), set3.begin(), set3.end(), inserter(intersectionSet, intersectionSet.begin()));

    cout << "Intersection of three sets: ";                                             // display
    for (int i : intersectionSet) {
        cout << i << " ";
    }
    cout << "\nAverage: " << Average(intersectionSet) << endl;
}

// The same as the functions above but use difference specific set functions for this one
void DisplayDifference(set<int>& set1, set<int>& set2, set<int>& set3) {
    set<int> differenceSet;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(differenceSet, differenceSet.begin()));
    set_difference(differenceSet.begin(), differenceSet.end(), set3.begin(), set3.end(), inserter(differenceSet, differenceSet.begin()));

    cout << "Difference of three sets: ";
    for (int i : differenceSet) {
        cout << i << " ";
    }
    cout << "\nAverage: " << Average(differenceSet) << endl;
}

double Average(set<int>& listSet) {                                                     // average calculator function
    double total = 0;
    for (int poo : listSet) {
        total += poo;
    }

    return total/listSet.size();
}