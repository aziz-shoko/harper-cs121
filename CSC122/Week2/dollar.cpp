// Currency Input Assginment

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

char userInput[100];
string status{"yes"};

bool currencyInput(char*);
double doubleConvertor(char*);

int main() {

    while (status == "yes") {                                                               // while loop for yes condition
        cout << "\nEnter dollar amount: ";                                                  // ask user to input dollar amount
        cin >> userInput;   
        if(currencyInput(userInput)) {                                                      // condition if currencyInput function returns true
            cout << "\nThe currency is valid! " << endl;                                    
            cout << "Currency double format: " << fixed << setprecision(2) << doubleConvertor(userInput) << endl;       // call double convertor function if the dollar input is validated
        } else {    
            cout << "\nThe currency is invalid! " << endl;                                  // declare invalid if the currencyInput function returns false
        }
        cout << "\nNew value? (yes/no): ";                                                  // Loop back again if yes and if anything else, exit program
        cin >> status;
    }
    
}

bool currencyInput(char* userInput) {
    int nums{0}, decimal{0}, dollarSign{0}, negativeSign{0};

    int len = strlen(userInput);                                                                    // get length of userInput
    
    // c = ¢: c-shit can't handle ¢ character because its too big
    if (len == 2 && isdigit(userInput[0]) && userInput[1] == 'c') {                                 // condition for cents, if the length equals two and first position is a digit and second is a cent symbol, return true
        return true;
    } else if ( len == 2) {
        return false;
    } 
    if (len == 3 && isdigit(userInput[0]) && isdigit(userInput[1]) && userInput[2] == 'c') {        // check if the first position and second position is digit and last position is a cent symbol, 
        return true;
    } else if ( len == 3) {
        return false;
    } 

    if (!isdigit(userInput[len-1]) || !isdigit(userInput[len-2]) || userInput[len-3] != '.'){       // condition if the last 3 positions in userInput aren't a digit or a decimal
        return false;
    }

    for (int i = len-4; i >= 0; i--) {                                                                  // loop backwards starting from the 4th to last position
        if (isdigit(userInput[i])) {                                                                    // if the userInput[i] is a digit, increment nums by 1
            nums++;
        }
        
        if (nums > 3) {                                                                                 // condition for making sure the numbers don't go over 3
            return false;
        } else if (userInput[i] == ',' && nums != 3) {                                                  // condition for reaching a comma and not having 3 digits before it
            return false;
        } else if (userInput[i] == ',' && nums == 3 && !isdigit(userInput[i-1])) {                      // condition for reaching a comma and the 3 entryies not being a digit
            return false;
        } else if (userInput[i] == ',' && nums == 3 && isdigit(userInput[i-1])) {                       // condition for reaching a comma and having 3 digits before it
            nums = 0;                                                                                   // once the comma is reached, the bums of digit is reset to 0 until it reaches 3 again
        } else if (userInput[i] == '-') {                                                               // condition to make sure there is only one negative sign
            negativeSign++;
            if (negativeSign > 1) {
                return false;
            }
        } else if (userInput[i] == '$') {                                                               // condition for $ in the first position without a negative
            if (i == 0 && negativeSign == 0){
                return true;
            } else if (i == 1 && userInput[0] == '-' && negativeSign == 1 || negativeSign == 0) {       // condition for the negative sign
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

double doubleConvertor(char* userInput) {                               // double convertor function
    double doubleDisplay;
    int count{0};
    char peaky[100];
    for (int j = 0; j < strlen(userInput); j++){                        // loop through the entire userInput
        if (isdigit(userInput[j]) || userInput[j] == '.'){              // condition to see if the userInput char in position j is a digit or a decimal
            peaky[count] = userInput[j];                                // set peaky = to the contents of userInput that are a digit or a decimal
            count++;                                                    // increase count because it represents the position of peaky
        }
    }
    doubleDisplay = atof(peaky);                                        // convert the contents of peaky to a double type char and return it (atof function)
    return doubleDisplay;
}