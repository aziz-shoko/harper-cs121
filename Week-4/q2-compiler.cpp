/*
Azizbek Shokosimov 
Week 4 Q2 
Use Switch and Case to determine grade average
09/14/2022
csc121
*/

#include <iostream> 
using namespace std;

int num{1}, num1{2}, num2{3}, average{}, final{};


void caseSwitch(int);
void validator(int);

int main() {
    cout << "Please enter your first score: ";
    cin >> num;

    validator(num);
    caseSwitch(num);

    cout << "Please enter your second score: ";
    cin >> num1;

    validator(num1);
    caseSwitch(num1);

    cout << "Please enter your third score: "; 
    cin >> num2;

    validator(num2);
    caseSwitch(num2);
    
    int average{(num + num1 + num2)/3};
    
    cout << "Your final grade is ";
    caseSwitch(average);
}

void validator(int num, int num1, int num2) {              
    if ( num < 0 ) {                                              // Check to see if num is less than 100
        cout << "\t\nPlease enter a valid num next time!\n\n";    // Output text in quotes
        exit(0);                                                  // Exit 
    } else if (num > 100 ) {                                      // Check to see if num is more than 100
        cout << "\t\nPlease enter a valid score next time!\n\n";  // Output text in quotes
        exit(0);                                                  // Exit
    }
}

void caseSwitch(int num, int num1, int num2, int average){
    switch (num/10 ) {
        case (10):
            cout << "Congratulations, A+\n";
            break;
        case (9): 
            cout << "A\n";
            break;
        case (8):
            cout << "B\n";
            break;
        case (7):
            cout << "C\n";
            break;
        case (6):
            cout << "D\n";
            break;
        default:
            cout << "F\n";
    }
}

