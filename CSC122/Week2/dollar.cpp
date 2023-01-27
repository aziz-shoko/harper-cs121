// Currency Input Assginment

/*
Currency Input
*/

#include <iostream>
#include <cstring>
using namespace std;

char userInput[10000];
string status{"yes"};
bool currencyInput(char*);

int main() {

    while (status == "yes") {
        cout << "\nEnter dollar amount: "; 
        cin >> userInput;
        if(currencyInput(userInput)) {
            cout << "\nThe currency is valid! " << endl;
            double peaky;
            int count{0};
            char peepee[10000];
            for (int j = 0; j < strlen(userInput); j++){
                if (isdigit(userInput[j]) || userInput[j] == '.'){
                    peepee[count] = userInput[j];
                    count++;
                }
            }
            peaky = atof(peepee);
            cout << endl << peaky << endl;
        } else {
            cout << "\nThe currency is invalid! " << endl;
        }
        cout << "\nNew value? (yes/no): ";
        cin >> status;
    }
    
}

bool currencyInput(char* userInput) {
    int nums{0}, decimal{0}, dollarSign{0}, negativeSign{0};

    int len = strlen(userInput);
    
    // c = ¢: c-shit can't handle ¢ character because its too big
    if (len == 2 && isdigit(userInput[0]) && userInput[1] == 'c') {
        return true;
    } else if ( len == 2) {
        return false;
    } 
    if (len == 3 && isdigit(userInput[0]) && isdigit(userInput[1]) && userInput[2] == 'c') {
        return true;
    } else if ( len == 3) {
        return false;
    } 

    if (!isdigit(userInput[len-1]) || !isdigit(userInput[len-2]) || userInput[len-3] != '.'){
        return false;
    }

    for (int i = len-4; i >= 0; i--) {
        if (isdigit(userInput[i])) {
            nums++;
        }
        
        if (nums > 3) {
            return false;
        } else if (userInput[i] == ',' && nums != 3) {
            return false;
        } else if (userInput[i] == ',' && nums == 3 && !isdigit(userInput[i-1])) {
            return false;
        } else if (userInput[i] == ',' && nums == 3 && isdigit(userInput[i-1])) {
            nums = 0;
        } else if (userInput[i] == '-') {
            negativeSign++;
            if (negativeSign > 1) {
                return false;
            }
        } else if (userInput[i] == '$') {
            if (i == 0 && negativeSign == 0){
                return true;
            } else if (i == 1 && userInput[0] == '-' && negativeSign == 1 || negativeSign == 0) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}