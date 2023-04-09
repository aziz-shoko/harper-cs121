#include <iostream>
#include "doubly.h"
#include "input.h"
using namespace std;

int main() {
    int userChoice;
    double userInput;
    List obj;

    while (true) {
        double userChoice = ReadValue<int>("Choose Options: \n\n\t1. Add Value\n\t2. Delete Value\n\t3. Display List Forward\n\t4. Display List Backwards\n\t5. Quit\n\nChoose Option: ");

        if (userChoice == 1) {
            double userInput = ReadValue<double>("Enter number value to add: ");
            obj.InsertNode(userInput);
            cout << "\nValue added, choose display options to see it!";
        } else if (userChoice == 2) {
            cout << "working on it" << endl;
        } else if (userChoice == 3) {
            cout << endl;
            obj.DisplayForward();
            cout << endl;
        } else if (userChoice == 4) {
            cout << endl;
            obj.DisplayBackward();
            cout << endl;
        } else if (userChoice == 5) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Choose the proper option!" << endl;
        }
    }
}