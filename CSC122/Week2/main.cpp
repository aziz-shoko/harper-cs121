/* Currency Input */

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

char userInput[100];
string status{"yes"};

bool centValidator(char*);
bool dollarValidator(char*);
double doubleConvertor(char*);

int main() {
    while (status == "yes") {
        cout << "Enter dollar amount: ";                                                                            // ask user for their input
        cin >> userInput;
        int len = strlen(userInput);                                                                                // get the string length and set it to a variable

        // c is used instead of ¢ because c++ cant handle ¢ and gives error
        if (userInput[len - 1] == 'c') {                                                                            // condition for cents    
            if (centValidator(userInput)) {                                                                         // call centValiadator and pass on userInput
                cout << "\nValid Format!";
                cout << "\nDouble Format: " << defaultfloat << doubleConvertor(userInput) << endl;                  // defaultfloat is used to reset the seprecision function (we dont want set precision here)
            } else {
                cout << "Invalid Format!";
            }
        } else if (userInput[0] == '$' || userInput[1] == '$') {                                                    // condition for dollars
            if (dollarValidator(userInput)) {                                                                       // call dollarValidator function and pass on userInput
                cout << "\nValid Format!";                                  
                cout << "\nDouble Format: " << fixed << setprecision(2) << doubleConvertor(userInput) << endl;      // use set precision to get the last two decimal values when converting to double
            } else {
                cout << "Invalid Format!";
            }
        } else {
            cout << "Invalid Format!";
        }

        cout << "\nNew value? (yes/no): ";                                                                          // loop through again for a new value
        cin >> status;
    }
}

bool centValidator(char* userInput) {                                               // cent validator function
    int negativeSign{0}, num{0};
    int len = strlen(userInput);
    if (len > 4) {return false;}                                                    // the cents can't have more than 4 chars

    for (int i = 0; i < len-1; i++) {                                               // loop through the userInput but ignore the last entry (last entry reserved for c)
        if(userInput[i] == '-') {                                                   // condition for cheking to see if any negatives
            negativeSign++;
            if (negativeSign > 1) {                                                 // if more than 1 negative, return false
                return false;
            }
        } else if (isdigit(userInput[i])) {                                         // condition for making sure the chars are digits
            num++;
            if (num > 2) {
                return false;
            }
        } else if (!isdigit(userInput[i]) && userInput[i] != '-') {
            return false;
        } 
    }

    return true;                                                                    // return true if all conditions are passed
}

bool dollarValidator(char* userInput) {                                             // dollarValidator function
    bool comma{false}, decimal{false}; 
    int nums{0}, negativeSign{0}, dollarSign{0};
    int len = strlen(userInput);

    for (int i = 0; i < len; i++) {                                                 // check for any decimals or commas
        if (userInput[i] == '.') {decimal = true;} 
        if (userInput[i] == ',') {comma = true;}
    }

    if (comma == false && decimal == false) {                                       // condition for no commas or decimals
        for (int i = 2; i < len; i++) {                                             // makre sure every digit after the second position is a digit (first two are for - and $ signs)
            if (!isdigit(userInput[i])) {
                return false;
            }
        }
    
        if (userInput[0] == '-' && userInput[1] == '$') {                           // condition for a negative input
            return true;    
        } else if (userInput[0] == '$' && isdigit(userInput[1])) {                  // condition for no negative input
            return true;
        }
    }

    if (decimal == true && comma == false) {                                                                // condition for decimal but no comma
        if (!isdigit(userInput[len-1]) || !isdigit(userInput[len-2]) || userInput[len-3] != '.'){           // condition for making sure the last three spots are for two digits and a decimal
            return false;
        }
        for (int i = 2; i < len-3; i++) {                                                                   // loop for numbers between the $ and - sign and the decimal sign
            if (!isdigit(userInput[i])) {                                                                   // check to see if digit
                return false;
            }
        }
        if (userInput[0] == '-' && userInput[1] == '$') {                                                   // condition for negative value
            return true;
        } else if (userInput[0] == '$' && isdigit(userInput[1])) {                                          // condition for non negative value
            return true;
        }
    }

    if (decimal == true && comma == true) {                                                                 // condition if both decimal and comma exist
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
            } else if (userInput[i] == '$') {                                                               // condition for $ in the first position without a negative
                if (i == 0 && nums <= 3) {
                    return true;
                } else if (i == 1 && userInput[0] == '-' && nums <= 3) {                                    // condition for the negative sign
                    return true;
                } else if (userInput[0] != '$' || userInput[0] != '-') {
                    return false;
                } else {
                    return false;
                }
            }
        }

    }
    return false;
}

double doubleConvertor(char* userInput) {                                                          // double convertor function
    double doubleDisplay;
    int count{0};
    char peaky[100];
    for (int j = 0; j < strlen(userInput); j++){                                                    // loop through the entire userInput
        if (isdigit(userInput[j]) || userInput[j] == '.' || userInput[j] == '-'){                   // condition to see if the userInput char in position j is a digit or a decimal
            peaky[count] = userInput[j];                                                            // set peaky = to the contents of userInput that are a digit or a decimal
            count++;                                                                                // increase count because it represents the position of peaky
        }
    }
    doubleDisplay = atof(peaky);                                                                    // convert the contents of peaky to a double type char and return it (atof function)
    return doubleDisplay;
}