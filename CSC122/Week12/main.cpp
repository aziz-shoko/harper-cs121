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
        6. Add Value Operator Overload\n\t7. Prime/Factorization Calculator\n\t8. Quit\n\nChoose Option: ";
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
            int userIndex = ReadValue<int>("\nEnter Index for value: ");
            cout << "\n" << obj[userIndex] << "\n\n";
        } else if( userChoice == 6) {
            double userInput = ReadValue<double>("\nEnter number value to add: ");
            obj = obj + userInput;
            cout << "\n\nValue added, choose display options ot see it!\n\n";
        } else if ( userChoice == 7 ) {
            int userInput = ReadValue<int>("\nEnter value to factorize: ");
            
        } else if (userChoice == 8) {
            obj.~List();
            cout << "\nExiting..." << endl;
            break;
        } else {
            cout << "Choose the proper option!" << endl;
        }
    }
}