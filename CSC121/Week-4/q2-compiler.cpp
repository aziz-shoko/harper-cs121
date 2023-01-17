/*
Azizbek Shokosimov 
Week 4 Q2 
Use Switch and Case to determine grade average
09/14/2022
csc121
*/

#include <iostream>                                 // File header for cin and cout       
using namespace std;                                // avoid suing std

int num{1}, num1{2}, num2{3}, average{};            // declare variables num num1 num2 average


void caseSwitch(int);                               // declare caseSwich function
void validator(int);                                // declare validator function 

int main() {
    cout << "Please enter your first score: ";      // Output text in quotes
    cin >> num;                                     // store user input in num

    validator(num);                                 // call function validator and pass variable num
    caseSwitch(num);                                // call function caseSwitch and pass variable num

    cout << "Please enter your second score: ";     // Output text in quotes
    cin >> num1;                                    // store user input in num1

    validator(num1);                                // call function validator and pass variable num1
    caseSwitch(num1);                               // call function caseSwitch and pass variable num1

    cout << "Please enter your third score: ";      // Output text in quotes
    cin >> num2;                                    // store user input in num2

    validator(num2);                                // call function validator and pass variable num2                
    caseSwitch(num2);                               // call function caseSwitch and pass variable num2
    
    int average{(num + num1 + num2)/3};             // declare variable average and set value to average of 3 nums                    
    
    cout << "Your final grade is ";                 // Output text in quotes
    caseSwitch(average);                            // call function caseSwitch  
}

void validator(int num) {              
    if ( num < 0 ) {                                              // Check to see if num is less than 100
        cout << "\t\nPlease enter a valid num next time!\n\n";    // Output text in quotes
        exit(0);                                                  // Exit 
    } else if (num > 100 ) {                                      // Check to see if num is more than 100
        cout << "\t\nPlease enter a valid score next time!\n\n";  // Output text in quotes
        exit(0);                                                  // Exit
    }
}

void caseSwitch(int num){
    switch (num/10 ) {                                  // declare switch condition (take num/10)
        case (10):                                      // case for perfect score
            cout << "Congratulations, A+\n";            // Output in text in quotes
            break;                                      // Exit switch/case function
        case (9):                                       // Case for letter grade A
            cout << "A\n";                              // Output in text in quotes
            break;                                      // Exit switch function
        case (8):                                       // Case for letter grade B
            cout << "B\n";                              // Output text in quotes
            break;                                      // exit switch funciton
        case (7):                                       // case for letter grade C
            cout << "C\n";                              // Output in text in quotes
            break;                                      // Exit switch function
        case (6):                                       // case for letter grade D
            cout << "D\n";                              // Output in text in quotes
            break;                                      // Exit function
        default:                                        // if all cases fail, then default to letter F
            cout << "F\n";                              // Output in text in quotes
    }
}

