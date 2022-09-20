/*
Azizbek Shokosimov
Week5 Q1
We will use counters
09/19/2022
csc121
*/

#include <iostream>                         // cin and cout file header
#include <string>                           // string input file header
using namespace std;                        // avoid using std::

void up(string);                            // Declare function up
void down(string);                          // Declare funciton down

int i{};                                    // Declare int variable i
string userInput{};                         // Declare string varaible userInput

int main() {
    cout << "Enter up or down: ";           // Output text in quotes
    cin >> userInput;                       // Store user input in userInput

    if ( userInput == "up") {               // condition for if user chooses up
        up(userInput);                      // calls function up and passes userInput into the function
    } else if ( userInput == "down" ) {     // condition for if user chooses down
        down(userInput);                    // call function down and passes userInput into the function
    }

}

void down(string) {                                                                 //  down function
    for ( i = 1; i <= 100; i++) {                                                   // for loop for outputting numbers between 1 and 100 (up)
        if ( i >= 10) {                                                             // condition for cheacking if i is greater than 10
            if ( i%2 != 0 && i%3 != 0 && i%5 != 0 && i%7 != 0 && i%9 !=0) {         // if i isn't even, divisible by 3, 5, 7, 9 then its prime
            continue;                                                               // skips the prime numbers
            }
            cout << i << endl;                                                      // outputs 10 to 100 without prime numbers
        } else if ( i <= 10 && i != 1 && i != 2 && i != 3 && i != 5 && i != 7) {    // condition for checking if i is less than 10 and not = to 1,2,3,5,7
            cout << i << endl;                                                      // output i that is not prime for numbers 1 to 10
        }
    }
}

void up(string) {                                                                   // up function
    for ( i = 100; i >= 1; i-- ) {                                                  // for loop for outputting numbers between 1 to 100 (down)
        if ( i >= 10) {                                                             // condition for i greater than or equal to 10
            if ( i%2 != 0 && i%3 != 0 && i%5 != 0 && i%7 != 0 && i%9 !=0) {         // condition for prime numbers
                cout << "\n" << i;                                                  // out prime numbers in new line
            } else {                                                                    
                cout << " " << i;                                                   // output every other number besides prime
            }
        } else if ( i < 10 ) {                                                      // condition for i less than 10
            if ( i == 1 || i ==2 || i == 3 || i == 5 || i == 7){                    // condition for i equaling either 1, 2, 3, 5, 7
                cout << "\n" << i;                                                  // output prime in new line
            } else {
                cout << " " << i;                                                   // output other numbers besides prime
            }
        }
    }
}