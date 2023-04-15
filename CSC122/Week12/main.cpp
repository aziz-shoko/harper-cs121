#include <iostream>
#include "doubly.h"
#include "input.h"
using namespace std;

// main function to simply display a menu and call doubly class functions
int main() {
    int userChoice;
    double userInput;
    List obj;

    while (true) {
        string prompt = "Choose Options: \n\n\t1. Add Value\n\t2. Delete Value\n\t3. Display List Forward\n\t4. Display List Backwards\n\t5. Index Query\n\
        6. Number adder by operator overload but also shows the factorization or prime\n\t7. Quit\n\nChoose Option: ";
        double userChoice = ReadValue<int>(prompt);

        if (userChoice == 1) {
            double userInput = ReadValue<double>("Enter number value to add: ");
            obj.InsertNode(userInput);
            cout << "\nValue added, choose display options to see it!\n\n";
        } else if (userChoice == 2) {
            cout << endl;
            obj.DisplayForward();
            cout << endl;
            double userInput = ReadValue<double>("Enter value to remove: ");
            obj.RemoveNode(userInput);
        } else if (userChoice == 3) {
            cout << endl;
            obj.DisplayForward();
            cout << endl;
        } else if (userChoice == 4) {
            cout << endl;
            obj.DisplayBackward();
            cout << endl;
        } else if( userChoice == 5) {
            obj.DisplayForward();
            int userInput = ReadValue<int>("\nEnter Index for value: ");
            cout << "\n" << obj[userInput] << "\n\n";
        } else if( userChoice == 6) {
            
        } else if (userChoice == 7) {
            obj.~List();
            cout << "\nExiting..." << endl;
            break;
        } else {
            cout << "Choose the proper option!" << endl;
        }
    }
}