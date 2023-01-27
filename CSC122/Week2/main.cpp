/*
Currency Input
*/

#include <iostream>                                                         // file headers                                       
#include <cstring>
using namespace std;

char userInput[100];                                                        // variable for user input
bool currencyInput(char*);                                                  // currency validator function

int main() {                                                                
    cout << "Enter dollar amount: ";                                        // ask user to enter dollar amount
    cin >> userInput;                                                       // store user input in var userInput

    if(currencyInput(userInput)) {                                          // if statement for checking to see if currency is valid or not
        cout << "The currency is valid! " << endl;      
    }   else {
        cout << "The currency is invalid! " << endl;
    }
}

bool currencyInput(char* userInput) {                                       // currency validator function, returns true if currency valid and false if invalid
    bool comma{false};
    int decimal{0}, twoDecimals{0}, bravo{0}, peaky{0};                     // necessary int variables                                        
    char dollarSign{0}, negativeSign{0};                                    // char variables for checking dollar and negative signs

    
    for (int i = 0; i < strlen(userInput); i++) {                           // for loop for looping though each char inside the userInput array
         if (userInput[i] == ',' && !comma) {
            comma = true;
            bravo = 0;
         } else if ( dollarSign == 1 && (isdigit(userInput[i]) || userInput[i] == ',')) {                                // if statement for checking to see if comma exists and there is no decimal after
            if ( isdigit(userInput[i]) ) {                                  // condition for checking to see if the given char is a digit                  
                bravo++;                                                    // if it is a digit, then bravo increments by one
            } 
            if (bravo == 3 && (userInput[i+1] != ',' && userInput[i+1] != '.')) {
                return false;
            } else if (bravo == 3 && userInput[i] == ',') {
                bravo = 0;
            } 
            /*else if (bravo < 3 && userInput[i] == ',') {
                
            } */
         } else if (userInput[i] == '.') {
            if (bravo < 3 && comma) {
                return false;
            }
            decimal++;
            if (decimal > 1) {
                return false;
            } 
        } else if (userInput[i] == '$') {
            dollarSign++;
            if (dollarSign > 1 ) {
                return false;
            }
        } else if (userInput[i] == '-') {
            negativeSign++;
            if (negativeSign > 1 ) {
                return false;
            }
        } else if (decimal == 1) {
            twoDecimals++; 
            if (twoDecimals > 2) {
                return false;
            }
        }
    }
    
    if ( negativeSign == 1 && userInput[0] != '-') {
        return false;
    }
    if (decimal == 1 && dollarSign == 1 && (userInput[0] == '$' || userInput[1] == '$') && !isdigit(userInput[0])) {
        return true;
    } else {
        return false;
    }
}