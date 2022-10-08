/*
Azizbek Shokosimov
Week7 Q3
Number Palindrome
10/8/2022
csc121 
*/

#include <iostream>                                             // file header for cin and cout
#include <vector>                                               // vector file header
#include <string>                                               // string file header
using namespace std;                                            // avoid using std::

int i{};                                                        // declare int i
string userInput{}, input{"k"};                                 // declare string userInput and input

int main() {
    while ( input == "k") {                                                     // while loop runs as long as input == k
        cout << "Enter 5 digit number: ";                                       // output in quotes
        cin >> userInput;                                                       // store user input in userInput
        vector<char> num(userInput.begin(), userInput.end());                   // store all chars in string in a vector

        for (i=0; i < num.size(); i++) {                                        // for loop that runs as long as i is less than the size of vector num
            if ( num[i] != num[num.size()-1-i]) {                               // condition for palindrome
                cout << "Number is not a palidrome, try another number! \n";    // output text in qoutes
                break;                                                          // break out of for loop and go back to while loop
            } else {
                cout << "Number is palidrome!";                                 // output text in quotes
                cout << "\nMiddle number is: " << num[i/2 + 2] << endl;         // calculate middle number
                input = "x";                                                    // set input to x, this breaks out of the while loop
                break;                                                          // break out of the for loop
            }
        }
  
    }
}